#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9;
const int minn = -1e9;
struct bucket {
	int max=minn;
	int min=maxn;
	bool num = false;
	bucket operator=(int a) {
		if (!num)num=true;
		if (a < min)min = a;
		if (a > max)max = a;
		return *this;
	}
};
int find(vector<int>&arr) {
	int max = minn;
	int min = maxn;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > max)max = arr[i];
		if (arr[i] < min)min = arr[i];
	}
	bucket m[100];
	for (int i = 0; i < arr.size(); i++) {
		int x = (arr[i] - min)*arr.size() / (max - min);
		m[x] = arr[i];
	}
	int res=0;
	for (int i = 0; i < arr.size(); i++) {
		if (!m[i].num)continue;
		int j = i+1;
		for (; j < arr.size(); j++)
			if (m[j].num)break;
		res = (res >m[j].min-m[i].max) ? res :  m[j].min-m[i].max;
	}
	return res;
}
int main()
{
	srand(time(NULL));
	vector<int> arr = { 1,3,5,7,9,11,16,21,20,14,34,36};
	int s=find(arr);
	cout << s;
}