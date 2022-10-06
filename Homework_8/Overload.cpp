#include <iostream>
using namespace std;
void FillRand(int arr[], const int N);
void PrintArr(int arr[], const int N);
void ReversPrintArr(int arr[], const int N);
int SummArr(int arr[], const int N);
double AvgArr(int arr[], const int N);
int minValueInArr(int arr[], const int N);
int maxValueInArr(int arr[], const int N);
void shiftLeft(int arr[], const int N, int step);
void shiftRight(int arr[], const int N, int step);
void Sort(int arr[], const int n);
void UniqueRand(int arr[], const int n);
void main()
{
	setlocale(LC_ALL, "");
	const int N = 10;
	int arr[N];
	FillRand(arr, N);
	PrintArr(arr, N);
	ReversPrintArr(arr, N);
	cout << "Сумма элементов массива: " << SummArr(arr, N) << endl;
	cout << "Среднее арифметическое элементов массива: " << AvgArr(arr, N) << endl;
	cout << "Минимальный элемент массива: " << minValueInArr(arr, N) << endl;
	cout << "Максимальный элемент массива: " << maxValueInArr(arr, N) << endl;
	int step;
	cout << "На сколько двигаем? "; cin >> step;
	while (step > N) step -= N; // Чтобы двигать с шагом больше, чем N
	cout << endl;
	cout << "\t\t\t" << "Сдвиг влево" << endl;
	shiftLeft(arr, N, step);
	PrintArr(arr, N);
	cout << endl;
	cout << "\t\t\t" << "Сдвиг вправо" << endl;
	shiftRight(arr, N, step);
	PrintArr(arr, N);
	cout << endl;
	cout << "\t\t\t" << "Массив уникальных чисел" << endl;
	UniqueRand(arr, N);
	PrintArr(arr, N);
	Sort(arr, N);
	PrintArr(arr, N);
}
void FillRand(int arr[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
}
void PrintArr(int arr[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
}
void ReversPrintArr(int arr[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[N - i - 1] << '\t';
	}
	cout << endl;
}
int SummArr(int arr[], const int N)
{
	int summ = 0;
	for (int i = 0; i < N; i++)
	{
		summ += arr[i];
	}
	return summ;
}
double AvgArr(int arr[], const int N)
{
	return (double)SummArr(arr, N) / N;
}
int minValueInArr(int arr[], const int N)
{
	int min = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < min) min = arr[i];
	}
	return min;
}
int maxValueInArr(int arr[], const int N)
{
	int max = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
void shiftLeft(int arr[], const int n, int step)
{
	for (int i = 0; i < step; i++)
	{
		int temp = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = temp;
	}
}
void shiftRight(int arr[], const int n, int step)
{
	shiftLeft(arr, n, n - step );
}
void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//arr[i] - выбранный элемент
			//arr[j] - перебираемый элемент
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
void UniqueRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		bool unique;
		do
		{
			arr[i] = rand() % (n+2);
			unique = true;
			for (int j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					unique = false;
					break;
				}
			}
		} while (!unique);
	}
}