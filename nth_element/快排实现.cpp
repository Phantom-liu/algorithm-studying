#include<bits/stdc++.h>
using namespace std;
template<typename T>
void partition(T array[], int left, int right, int& mid)
{
	srand(time(0));
	int i = left, j = right, move = rand() % (right - left + 1) + left;
	T temp = array[move];
	array[move] = array[left];
	while (i != j)
	{
		while (array[j] > temp&&j > i) j--;
		if (i < j) array[i++] = array[j];
		while (array[i] < temp&&i < j) i++;
		if (i < j) array[j--] = array[i];

	}
	array[i] = temp;
	mid = i;
}

template<typename T>
T random_quick_sort(T array[], int left, int right, int k)
{

	if (k > right) exit(7);
	int i;
	partition(array, left, right, i);
	if (k == i) return array[i];
	else if (k > i ) return random_quick_sort(array, i + 1, right, k);
	else return random_quick_sort(array, left, i - 1, k);
}
int main()
{
	int arr[10];
	for (int i = 1; i <= 9; i++) {
		arr[i] = i * i - 4 * i;
	}
	cout<<random_quick_sort(arr, 1, 9, 9);
	return 0;
}