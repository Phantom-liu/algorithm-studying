#include<bits/stdc++.h>
using namespace std;
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
vector<int> partation_removeSame(vector<int> &arr, const int &a, const int &b) {
	int num = arr[b];
	int less = a - 1, more = b + 1;
	int cur = a;
	while (cur < more) {
		if (arr[cur] < num) swap(arr, cur++, ++less);
		else if (arr[cur] > num)swap(arr, cur, --more);
		else cur++;
	}
	vector<int> m = { less ,more };
	return m;
}
// 经典快排
int partation(vector<int> &arr, const int &a, const int &b) {
	int num = arr[b];
	int less = a - 1, more = b;
	int cur = a;
	while (cur < more) {
		if (arr[cur] <= num) swap(arr, cur++, ++less);
		else swap(arr, cur, --more);
	}
	swap(arr, more, b);
	return more;
}
void quicksort(vector<int> &arr, const int&a, const int &b) {
	if (a >= b)return;
	int p = partation(arr, a, b);
	quicksort(arr, a, p - 1);
	quicksort(arr, p + 1, b);
}
void quicksort_removeSame(vector<int> &arr, const int &a, const int &b) {
	if (a >= b)return;
	vector<int> p = partation_removeSame(arr, a, b);
	quicksort(arr, a, p[0]);
	quicksort(arr, p[1], b);
}
//非递归快速排序 还不会写
/*void quicksort2(vector<int> &arr, int a, int b) {
	while (a < b) {


	}





}*/
int main() {
	vector<int> arr;
	srand(time(NULL));
	for (int i = 0; i <= 100; i++) {
		arr.push_back(rand());
	}
	quicksort_removeSame(arr, 0, 100);
	//quicksort(arr, 0, 100);
	for (auto z : arr) {
		cout << z << " ";
	}
	return 0;
}