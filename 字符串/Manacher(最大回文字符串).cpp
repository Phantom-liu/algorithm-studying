#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
	string manastring(string str) {
		string res;
		int index = 0;
		int len = 2 * str.length() + 1;
		for (int i = 0; i < len; i++) {
			res+=(i % 2) ?'#': str[index++] ;
		}
		return res;
	}
	 int maxhuiwenlength(string str){
		int len =2*str.length()+1;
		if (len== 0)return 0;
		string res = manastring(str);
		int p[maxn];  //p数组为以当前下标为中心可扩出的最大回文半径
		int C =-1,R=-1;
		//p[0] = 1;
		int mx = -0x3f3f3f;
		for (int i = 0; i < len; i++) {
			p[i] = R > i ? min(p[2 * C - i], R - i) : 1;
			while (i + p[i] < len&&i - p[i] >= 0) {
				if (res[i + p[i]] == res[i - p[i]]) {
					p[i]++;
				}
				else{
					break;
				}
			}
			if (i + p[i] > R) {
				R = i + p[i];
				C = i;
			}
			mx = max(mx, p[i]);
		}
		return mx - 1;
	}
int main()
{
	string s1 = "sssasadadda";
	cout<<maxhuiwenlength(s1);
}