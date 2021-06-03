#include<bits/stdc++.h>
using namespace std;
#include<Windows.h>
void swap(vector<int> &arr, const int &a, const int&b) {
	int ss;
	ss=arr[a];
	arr[a] = arr[b];
	arr[b] = ss;
}
//给定一个数 小于等于他的在左边 大于他的在右边
void partation1(vector<int> &arr, const int &a, const int &b,const int &num) {
	int less = a - 1, more = b + 1;
	int cur = a;
	while (cur < more) {
		if (arr[cur] <= num)swap(arr, cur++, ++less);
		else swap(arr, cur, --more);
	}
}
//给定一个数 小于在左 等于在中 大于在右
vector<int> partation2(vector<int> &arr, const int &a, const int &b, const int &num) {
	int less = a - 1, more = b + 1;
	int cur = a;
	while (cur < more) {
		if (arr[cur] < num) swap(arr, cur++, ++less);
		else if (arr[cur] > num)swap(arr, cur, --more);
		else cur++;
	}
	vector<int> m = { less + 1,more - 1 };
	return m;
}
vector<int> partation3(vector<int> &arr, const int &a, const int &b) {
	int less = a - 1, more = b + 1;
	int cur = a;
	int num = arr[b];
	while (cur < more) {
		if (arr[cur] < num) swap(arr, cur++, ++less);
		else if (arr[cur] > num)swap(arr, cur, --more);
		else cur++;
	}
	vector<int> m = { less + 1,more - 1 };
	return m;
}
// 4为经典快排
int partation4(vector<int> &arr, const int &a, const int &b) {
	int less = a - 1, more = b + 1;
	int cur = a;
	int num = arr[b];
	while (cur < more-1) {
		if (arr[cur] <= num) swap(arr, cur++, ++less);
		else swap(arr, cur, --more);
	}
	int m = less;
	return m;
}
void quicksort4(vector<int> &arr, const int&a, const int &b) {
	if (a >= b)return;
	quicksort4(arr, a, partation4(arr, a, b));
	quicksort4(arr, partation4(arr, a, b) + 2,b);
}
void quicksort(vector<int> &arr, const int &a, const int &b) {
	if (a >= b)return;
	quicksort(arr, a, partation3(arr, a, b)[0]-1);
	quicksort(arr, partation3(arr, a, b)[1] + 1, b);
}
//非递归快速排序 还不会写
/*void quicksort2(vector<int> &arr, int a, int b) {
	while (a < b) {
		int l = partation3(arr, a,b)[0] - 1;
		int r = partation3(arr, a, b)[1] + 1;

	}





}*/
int main() {
	vector<int> arr;
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)arr.push_back(rand());
	int m = arr.size() - 1,num;
	/*cin>> num;*/
	DWORD start1 = GetTickCount();
	quicksort(arr, 0, m);
	DWORD end1 = GetTickCount();
	/*for (int i = 0; i < 1000;i++)cout << arr[i] << "  ";*/
	cout << "改进后快速排序  time:" << end1 - start1 << "ms" << endl;
	puts("");
	DWORD start4 = GetTickCount();
	quicksort4(arr, 0, m);
	DWORD end4 = GetTickCount();
	/*for (int i = 0; i < 10000; i++)cout << arr[i] << "  ";*/
	cout << "经典快速排序    time:" << end4 - start4 << "ms" << endl;
	puts("");
	return 0;
}