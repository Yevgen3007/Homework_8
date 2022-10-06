#include <iostream>
using namespace std;
void FillRand(int arr[], const int N);
void PrintArr(int arr[], const int N);
void Search(int arr[], const int N);
void main()
{
	setlocale(LC_ALL, "");
	const int N = 15;
	int arr[N];
	FillRand(arr, N);
	PrintArr(arr, N);
	cout << endl;
	Search(arr, N);
}
void FillRand(int arr[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % (N - 3);
	}
}
void PrintArr(int arr[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
bool AlreadyDone(int arr[], int i)
{
	for (int k = 0; k < i; k++)
	{
		if (arr[i] == arr[k]) return true;
	}
	return false;
}
void Search(int arr[], const int N)
{
	int total;
	for (int i = 0; i < N; i++)
	{
		if (AlreadyDone(arr, i)) continue; //Если число уже учтено, то его нужно пропустить
		total = 0;
		for (int j = i; j < N; j++)
		{
			if (arr[i] == arr[j])
			{
				total++;
			}
		}
		if (total!=1) cout << "Число: " << arr[i] << "\t\t" << "Количество повторений в массиве: " << total << endl;
		else cout << "Число: " << arr[i] << "\t\t" << "Не повторяется в массиве" << endl; //Можно убрать, по условию задачи не нужна
	}
}