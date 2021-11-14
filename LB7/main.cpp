#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>
using namespace std;

int** create_arr(int n)
{
	int s = 1;
	int** Arr;

	Arr = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		Arr[i] = (int*)malloc(n * sizeof(int));
		Arr[i][i] = 0;

		for (int j = s; j < n; j++)
		{
			if (rand() % 100 > 70)
			{
				Arr[i][j] = 0;
			}
			else
			{
				Arr[i][j] = rand() % n;
			}
		}
		s++;
	}
	s = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = s; j < n; j++)
			Arr[j][i] = Arr[i][j];
		s++;
	}

	for (int i = 0; i < n; i++)
		printf("V%d ", i + 1);

	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", Arr[i][j]);
		}
	}
	return Arr;
}

int** create_arr2(int n)
{
	int** Arr2 = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		Arr2[i] = (int*)malloc(n * sizeof(int));

		for (int j = 0; j < n; j++)
		{
			if (rand() % 100 > 70)
			{
				Arr2[i][j] = 0;
			}
			else
			{
				Arr2[i][j] = rand() % n;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		Arr2[i][i] = 0;
		for (int j = 0; j < n; j++)
		{
			if (Arr2[i][j] > 0)
				Arr2[j][i] = 0;
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("V%d ", i + 1);
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
			printf("%2d ", Arr2[i][j]);
	}
	return Arr2;
}

void BFSD(int x, int* dist, int** Arr, int n)
{
	queue<int> que;
	que.push(x);
	dist[x] = 0;
	while (!que.empty())
	{
		x = que.front();
		que.pop();
		for (int i = 0; i < n; i++)
		{
			if (Arr[x][i] > 0 && dist[i] > dist[x] + Arr[x][i])
			{
				que.push(i);
				dist[i] = dist[x] + Arr[x][i];
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");
	int n, ** t, x, ** q;
	printf("Введите размер матрицы: ");
	scanf("%d", &n);

	printf("Введите, с какой вершины хотите начать: ");
	scanf("%d", &x);
	while (x < 1 || x > n)
	{
		printf("С этой вершины нельзя начинать! Выберите другю вершину: ");
		scanf("%d", &x);
	}
	x--;
	t = create_arr(n);


	int* dist = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		dist[i] = n;
	printf("\n\n");
	BFSD(x, dist, t, n);
	for (int i = 0; i < n; i++)
	{
		if (dist[i] != n)
			printf("\nРасстояние до %d - ой вершины: %d ", i + 1, dist[i]);
		else
			printf("\nДо вершины %d - нет расстояния", i + 1);
	}


	printf("\n\n");
	q = create_arr2(n);
	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX;
	BFSD(x, dist, q, n);
	for (int i = 0; i < n; i++)
	{
		if (dist[i] != INT_MAX)
			printf("\nРасстояние до %d - ой вершины: %d ", i + 1, dist[i]);
		else
			printf("\nДо вершины %d - нет расстояния", i + 1);
	}
	system("pause");
}