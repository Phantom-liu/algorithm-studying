#include<bits/stdc++.h>
#include<Windows.h> 
using namespace std;
long long search(vector<int> &s, const int &p) {
	long long sum = 0;
	for (int k = p; k > 0; k--) {
		for (int i = k - 1; i >= 0; i--) {
			if (s[i] < s[k])sum += s[i];
		}
	}
	return sum;
}
// 无法理解我自己写的 当然这是错误的(包括答案) 时间复杂度为O(2^n);
/*void search2(vector<int>&s, const int &p,long long &sum) {
	if (p == 0)return;
	for (int i = p-1; i >= 0; i--) {
		if (s[i] < s[p]); {
			sum += s[i];
			search2(s, i, sum);
		}
	}
}*/
void merge(vector<int>&s, const int a, const int mid, const int b, long long &sum) {
	int c[100000];
	int pa = a, pb = mid + 1, help = 0;
	while (pa <= mid && pb <= b) {
		if (s[pa] < s[pb])
			sum += s[pa] * (b - pb + 1);
		c[help++] = (s[pa] < s[pb]) ? s[pa++] : s[pb++];
		
	}
	while (pa <= mid)c[help++] = s[pa++];
	while (pb <= b)c[help++] = s[pb++];
	for (int i = 0; i <= b - a; i++)s[a + i] = c[i];
}
void search3(vector<int>&s, const int &a, const int &b, long long &sum)
{
	if (a == b)return;
	int mid = (a + b) / 2;
	search3(s, a, mid, sum);
	search3(s, mid + 1, b, sum);
	merge(s, a, mid, b, sum);
}
int main()
{
	srand(time(NULL));
	vector<int> arr;
	for (int i = 0; i < 10000; i++)arr.push_back(rand()%33);
	int m = arr.size()-1;
	DWORD start_time = GetTickCount();
	long long k=search(arr, m);
	DWORD end_time = GetTickCount();
	cout << k<<endl;
	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;
	long long a = 0;
	DWORD start2_time = GetTickCount();
	search3(arr, 0, m, a);
	DWORD end2_time = GetTickCount();
	cout << a << endl;
	cout << "The run time is:" << (end2_time - start2_time) << "ms!" << endl;
	return 0;
}