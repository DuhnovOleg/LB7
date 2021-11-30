#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<time.h>
#include<stack>
#include<queue>
using namespace std;

int** neor_vz(int n)
{
	int s = 1;
	int** Arr;

	Arr = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i <n; i++)
	{
		Arr[i] = (int*)malloc(n * sizeof(int));
		Arr[i][i] = 0;

		for (int j = s; j <n; j++)
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
	for (int i = 0; i <n; i++)
	{
		for (int j = s; j <n; j++)
			Arr[j][i] = Arr[i][j];
		s++;
	}

	for (int i = 0; i <n; i++)
		printf("V%d ", i + 1);

	for (int i = 0; i <n; i++)
	{
		printf("\n");
		for (int j = 0; j <n; j++)
		{
			printf("%2d ", Arr[i][j]);
		}
	}
	return Arr;
}

int** orent_vz(int n)
{
	int** Arr2 = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i <n; i++)
	{
		Arr2[i] = (int*)malloc(n * sizeof(int));

		for (int j = 0; j <n; j++)
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
	for (int i = 0; i <n; i++)
	{
		Arr2[i][i] = 0;
		for (int j = 0; j <n; j++)
		{
			if (Arr2[i][j] > 0)
				Arr2[j][i] = 0;
		}
	}
	printf("\n");
	for (int i = 0; i <n; i++)
		printf("V%d ", i + 1);
	for (int i = 0; i <n; i++)
	{
		printf("\n");
		for (int j = 0; j <n; j++)
			printf("%2d ", Arr2[i][j]);
	}
	return Arr2;
}

int** neor_nevz(int n)
{
	int s = 1;
	int** Arr;

	Arr = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i <n; i++)
	{
		Arr[i] = (int*)malloc(n * sizeof(int));
		Arr[i][i] = 0;

		for (int j = s; j <n; j++)
		{
			if (rand() % 100 > 70)
			{
				Arr[i][j] = 0;
			}
			else {
				Arr[i][j] = 1;
			}
		}
		s++;
	}
	s = 1;
	for (int i = 0; i <n; i++)
	{
		for (int j = s; j <n; j++)
			Arr[j][i] = Arr[i][j];
		s++;
	}

	for (int i = 0; i <n; i++)
		printf("V%d ", i + 1);

	for (int i = 0; i <n; i++)
	{
		printf("\n");
		for (int j = 0; j <n; j++)
		{
			printf("%2d ", Arr[i][j]);
		}
	}
	return Arr;
}

int** orent_nevz(int n)
{
	int** Arr2 = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i <n; i++)
	{
		Arr2[i] = (int*)malloc(n * sizeof(int));

		for (int j = 0; j <n; j++)
		{
			if (rand() % 100 > 70)
			{
				Arr2[i][j] = 0;
			}
			else
			{
				Arr2[i][j] = 1;
			}
		}
	}
	for (int i = 0; i <n; i++)
	{
		Arr2[i][i] = 0;
		for (int j = 0; j <n; j++)
		{
			if (Arr2[i][j] > 0)
				Arr2[j][i] = 0;
		}
	}
	printf("\n");
	for (int i = 0; i <n; i++)
		printf("V%d ", i + 1);
	for (int i = 0; i <n; i++)
	{
		printf("\n");
		for (int j = 0; j <n; j++)
			printf("%2d ", Arr2[i][j]);
	}
	return Arr2;
}

void BFSD(int x, int* dist, int** Arr, int n, int** distX)
{
	int j = 0;
	queue<int> que;
	que.push(x);
	dist[x] = 0;
	while (!que.empty())
	{
		x = que.front();
		que.pop();
		for (int i = 0; i <n; i++)
		{
			if (Arr[x][i] > 0 &&dist[i] >dist[x] + Arr[x][i])
			{
				que.push(i);
				dist[i] = dist[x] + Arr[x][i];
				j = 0;
				while (distX[j][x] != 0)
				{
					distX[j][i] = distX[j][x];
					j++;
				}
				distX[j][i] = i + 1;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");
	int n, ** n_v, x, ** o_v, ** n_n, ** o_n;
	char* d;
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
	int* dist = (int*)malloc(n * sizeof(int));
	int** distX = (int**)malloc(sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		distX[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
			distX[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		distX[0][i] = 1;
	}

		printf("\n");
		n_v = neor_vz(n);
		for (int i = 0; i < n; i++)
			dist[i] = n;
		BFSD(x, dist, n_v, n, distX);
		for (int i = 0; i < n; i++)
		{
			if (dist[i] != n)
				printf("\nРасстояниедо %d - ойвершины: %d ", i + 1, dist[i]);
			else
				printf("\nДо вершины %d - нет расстояния", i + 1);
		}
		printf("\n");

		for (int i = 0; i < n; i++)
		{
			printf("\n");

			for (int j = 0; j < n; j++)
				printf("%d ", distX[i][j]);
		}
		for (int j = 0; j < n; j++)
		//printf("\n");
		//o_n = orent_nevz(n);
		//for (int i = 0; i < n; i++)
		//	dist[i] = INT_MAX;
		//BFSD(x, dist, o_n, n, distX);
		//for (int i = 0; i < n; i++)
		//{
		//	if (dist[i] != INT_MAX)
		//		printf("\nРасстояние до %d - ой вершины: %d ", i + 1, dist[i]);
		//	else
		//		printf("\nДо вершины %d - нет расстояния", i + 1);
		//}
		//printf("\n");


		//printf("\n");
		//n_n = neor_nevz(n);
		//for (int i = 0; i < n; i++)
		//	dist[i] = INT_MAX;
		//BFSD(x, dist, n_n, n, distX);
		//for (int i = 0; i < n; i++)
		//{
		//	if (dist[i] != INT_MAX)
		//		printf("\nРасстояние до %d - ой вершины: %d ", i + 1, dist[i]);
		//	else
		//		printf("\nДо вершины %d - нет расстояния", i + 1);
		//}
		//printf("\n");


		//printf("\n");
		//o_v = orent_vz(n);
		//for (int i = 0; i < n; i++)
		//	dist[i] = INT_MAX;
		//BFSD(x, dist, o_v, n, distX);
		//for (int i = 0; i < n; i++)
		//{
		//	if (dist[i] != INT_MAX)
		//		printf("\nРасстояние до %d - ой вершины: %d ", i + 1, dist[i]);
		//	else
		//		printf("\nДо вершины %d - нет расстояния", i + 1);
		//}
		//printf("\n");


	system("pause");
}
