#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
void swap(vector<int> &arr, const int &a,const int &b) {
	int s;
	s = arr[a];
	arr[a] = arr[b];
	arr[b] = s;
}
void heapinsert(vector<int> &arr, int index) {
	while (arr[index] > arr[(index - 1) / 2]) {
		swap(arr, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}
void heapify(vector<int> &arr, int index,int heapsize) {
	int left = 2 * index + 1;
	while (left < heapsize) {
		int largest = (left+1<heapsize&&arr[left+1] > arr[left]) ? left+1: left;
		largest = (arr[largest] > arr[index]) ? largest : index;
		if (largest == index)break;
		swap(arr, largest, index);
		index = largest;
		left = 2 * index + 1;
	}
	/*int largest = (left + 1 < heapsize&&arr[left + 1] > arr[left]) ? left + 1 : left;
	largest = (arr[largest] > arr[index]) ? largest : index;
	if (largest == index)return;
	swap(arr, largest, index);
	heapify(arr, largest, heapsize);*/
}
void heapsort(vector<int> &arr, int heapsize) {
	while (heapsize) {
		swap(arr, --heapsize, 0);
		heapify(arr, 0, heapsize);
	}
}
int main()
{
	vector<int> arr;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)arr.push_back(rand() % 33);
	DWORD start1 = GetTickCount();
	heapinsert(arr, m-1);
	heapsort(arr, m);
	DWORD end1 = GetTickCount();
	cout << end1 - start1 <<"ms"<< endl;
/*	for (int i = 0; i < 50; i++)cout << arr[i] << "  ";*/
	return 0;
}