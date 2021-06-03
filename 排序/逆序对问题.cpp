#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;
void mergeprint(vector<int> &s, const int &a, const int &mid, const int &b) {
	int c[maxn];
	int help = 0;
	int pa = a, pb = mid + 1, pc = a;
	while (pa <= mid && pb <= b) {
		if (s[pa] > s[pb])cout << "(" << s[pa] << "," <<s[pb] << ")" << endl;
		c[help++] = (s[pa] < s[pb]) ? s[pa++] : s[pb++];
	}

	while (pa <= mid) {
		cout << "(" << s[pa] << "," << s[pb-1] << ")" << endl;
		c[help++] = s[pa++];
	}
	while (pb <= b)c[help++] = s[pb++];
	for (int i = 0; i <= b - a; i++)s[a + i] = c[i];
}
void print(vector<int>&s, const int&a, const int&b)
{
	if (a == b)return;
	int mid = (a + b) / 2;
	print(s, a, mid);
	print(s, mid + 1, b);
	int c[maxn];
	int help = 0;
	int pa = a, pb = mid + 1, pc = a;
	while (pa <= mid && pb <= b) {
		if (s[pa] > s[pb]&&s[pa-1]<=s[pb])
			for (int i = mid + 1; i <= pb; i++)
				cout << "(" << s[pa] << "," << s[i] << ")" << endl;
		else if(s[pa]>s[pb]&&s[pa-1]<s[pb]) cout << "(" << s[pa] << "," << s[pb] << ")" << endl;
		c[help++] = (s[pa] <= s[pb]) ? s[pa++] : s[pb++];
	}
	while (pa <= mid) {
		for(int i=mid+1;i<=b;i++) if(pa+1<=mid)
		cout << "(" << s[pa+1] << "," << s[i] << ")" << endl;
		c[help++] = s[pa++];
	}
	while (pb <= b)c[help++] = s[pb++];
	for (int i = 0; i <= b - a; i++)s[a + i] = c[i];
}
int main()
{
	vector<int> ss= { 1,2,3,5,2,1,1,4 };
	print(ss, 0, 7);
	return 0;
}