#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int nxt[maxn];
void getnxtarr(string str) {
	memset(nxt, 0, sizeof(nxt));
	int n = str.length();
	nxt[0] = -1;
	nxt[1] = 0;
	for (int i = 1; i < n-1; ++i) {
		int j = i;
		while (j&&str[j] != str[nxt[j]]) {
			j = nxt[j];
		}
		nxt[i+1] = nxt[j] + 1;
	}
}
// 返回在str2在str1中第一次出现的位置 未出现返回-1
int KMP(string str1,string str2) {
	int n1 = str1.length();
	int n2 = str2.length();
	int cur1 = 0,cur2=0;
	getnxtarr(str2);
	/*for (cur1 = 0; cur1 < n1; cur1++) {
		while (cur2&&str1[cur1] != str2[cur2]) {
			cur2 = nxt[cur2];
		}
		if (str1[cur1] == str2[cur2])cur2++;
		if (cur2 == n2) {
			return cur1 - n2 + 2;
		}
	}*/
	while (cur1 < n1) {
		int i;
		for (i =cur1; i <cur1+n2-cur2&&i<n1; i++) {
			if (str1[i] != str2[i-cur1+cur2]) {
				cur2 = nxt[i-cur1+cur2];
				cur1 = i;
				if (cur2 == -1) {
					cur1++;
					cur2 = 0;
				}
				break;
			}
		}
		if (i ==cur1+n2-cur2)return cur1+1;
		if (i >= n1)break;

	}
	return -1;
}
int main()
{
	string s1 = "acxsxx";
	string s2 = "sxx";
	cout<<KMP(s1, s2);
}