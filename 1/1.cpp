#include <iostream>
using namespace std;
const int N = 7;
const float inf = INFINITY;
int main()
{
	setlocale(LC_ALL, "Russian");
	bool f = false;
	int i, j, k = 0, n = 1, m = N - 1, S[N] = { 0 }, V[N - 1], w, A[N][N] = { 0 }, p[N] = { 0 }, a, b;
	float obm, min, D[N], C[N][N] = {
		/*0, 25, 15, 7, 2,
		25, 0, 6, inf, inf,
		15, 6, 0, 4, inf,
		7, inf, 4, 0, 3,
		2, inf, inf, 3, 0,*/

		/*0, 1, 6, 2, inf, inf,
		inf, 0, 4, inf, 2, inf,
		inf, inf, 0, inf, inf, 3,
		inf, inf, inf, 0, 5, inf,
		inf, inf, inf, inf, 0, 4,
		inf, inf, inf, inf, inf, 0,*/

		0, 3, 4, 3, inf, inf, inf,
		3, 0, 1, inf, inf, inf, 2,
		4, 1, 0, 2, 1, inf, 1,
		3, inf, 2, 0, 2, 4, inf,
		inf, inf, 1, 2, 0, 1, 3,
		inf, inf, inf, 4, 1, 0, 6,
		inf, 2, 1, inf, 3, 6, 0,
	};
	cout << " Из точки: ";
	cin >> a;
	if ((a < 0) || (a >= N))
		return 1;
	for (i = 0; i < N; i++)
	{
		if (C[0][i] != 0 && C[a][i] != 0)
		{
			obm = C[0][i];
			C[0][i] = C[a][i];
			C[a][i] = obm;
		}
		else
		{
			obm = C[0][i];
			C[0][i] = C[i][0];
			C[i][0] = obm;
		}
	}
	for (i = 0; i < N; i++)
	{
		if (C[i][0] != 0 && C[i][a] != 0)
		{
			obm = C[i][0];
			C[i][0] = C[i][a];
			C[i][a] = obm;
		}
	}
	/*for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << " " << C[i][j];
		cout << endl;
	}*/

	cout << " В точку: ";
	cin >> b;
	if (b == a)
		b = 0;
	else if (b == 0)
		b = a;
	for (i = 0; i < N; i++)
	{
		D[i] = C[0][i];
		if (i != 0)
			V[i - 1] = i;
	}
	for (i = 0; i < N; i++)
	{
		if (i == 0)
			cout << " " << D[a];
		else if (i == a)
			cout << " " << D[0];
		else
			cout << " " << D[i];
	}
	cout << endl;
	while (n < N)
	{
		for (i = 0; i < m; i++)
		{
			if ((i == 0) || (min >= D[V[i]]))
			{
				min = D[V[i]];
				w = V[i];
			}
		}
		m--;

		S[n++] = w;
		for (i = 0; V[i] != w; i++);
		for (; i < m; i++)
			V[i] = V[i + 1];

		for (i = 0; i < m; i++)
		{
			if (D[V[i]] >= D[w] + C[w][V[i]])
			{
				D[V[i]] = D[w] + C[w][V[i]];
				A[k][V[i]] = w;
			}
		}
		f = false;
		for (i = 0; i < N; i++)
		{
			if (A[k][i] != 0)
			{
				f = true;
				break;
			}
		}
		if (f)
			k++;

		for (i = 0; i < N; i++)
		{
			if (i == 0)
				cout << " " << D[a];
			else if (i == a)
				cout << " " << D[0];
			else
				cout << " " << D[i];
		}
		cout << endl;
	}
	
	cout << endl;
	if ((b >= 0) && (b < N) && (D[b] != inf))
	{
		/*for (i = 0; i < k; i++)
		{
			for (j = 0; j < N; j++)
				cout << " " << A[i][j];
			cout << endl;
		}*/
		cout << " Путь:";
		p[0] = b;
		p[0] = b;
		f = false;
		for (i = k - 1, j = 1; i >= 0; i--, j++)
		{
			if (!f && A[i][b] == 0)
			{
				j--;
				continue;
			}
			else
				f = true;
			if (j == 0)
				p[j] = A[i][b];
			else
				p[j] = A[i][p[j - 1]];
		}
		for (i = N - 1; i >= 0; i--)
		{
			if (p[i] == 0)
				p[i] = a;
			else if (p[i] == a)
				p[i] = 0;
		}
		for (i = N - 1; i >= 0; i--)
		{
			if ((i == N - 1) || (p[i] != p[i + 1]))
				cout << " " << p[i];
		}
	}
	return 0;
}