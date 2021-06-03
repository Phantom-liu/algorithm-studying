#include<bits/stdc++.h>
using namespace std;
void insert(int a[10000],int p) {
	int x = a[p];
	for (int i = p; i >= 1; i--) {
		if (a[i - 1] >= a[p] && a[i] <= a[p]) {
			for (int j = p; j > i; j--)a[j] = a[j - 1];
			a[i] = x;
			return;
		}
	}
	for (int j = p; j > 0; j--)a[j] = a[j - 1];
	a[0] = x;
}
int main()
{
	priority_queue<int,vector<int>,greater<int>> s1;
	int sum = 0,n,a[100000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i]=rand()%10;
	}
	int b[100000];
	memcpy(b, a, sizeof(a));
	clock_t start = clock();
	for (int i = 0; i < n; i++)s1.push(a[i]);
	while (s1.size() != 1) {
		int a = s1.top(); s1.pop();
		sum += s1.top() + a;
		s1.push(s1.top() + a);
		s1.pop();
	}
	clock_t end = clock();
	cout << sum<<"  time: "<<end-start<<"ms\n";
	/*start = clock();
	sum = 0;
	for (int i = 0; i < n-1; i++) {
		sort(a, a + n-i, [](int a, int b) {
			return a > b; });
		a[n - 2 - i] = a[n - 2 - i] + a[n - 1 - i];
		sum += a[n - 2 - i];
	}
	end = clock();
	cout<< sum << "  time: " << end - start << "ms\n";*/
	//插入排序(数据量约在2e4时 时间长于堆结构)
	start = clock();
	sum = 0;
	sort(b, b + n, [](int a, int b) {
		return a > b; }); 
	for (int i = 0; i < n - 1; i++) {
		b[n - 2 - i] = b[n - 2 - i] + b[n - 1 - i];
		sum += b[n - 2 - i];
		insert(b,n - 2 - i);
	}
	end = clock();
	cout << sum << "  time: " << end - start << "ms\n";
}