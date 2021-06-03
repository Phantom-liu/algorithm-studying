#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
class Node{
public:
	list<int> edge;
	int value;
	int sum1,sum2;
};
Node v[1005];
int n,m;
int father[1005];
void ini(int head)
{
	list<int>::iterator it;
	if (v[head].edge.front() == father[head]) {
		v[head].edge.erase(v[head].edge.begin());
	}
	for (it = v[head].edge.begin(); it != v[head].edge.end(); ++it) {
		if (*it == father[head]) {
			v[head].edge.erase(it--); continue;
		}
		father[*it] = head;
		ini(*it);
	}
}
void returnmaxsum(Node &head) {
	if (head.edge.empty()) {
		head.sum1 = head.value;
		head.sum2 = 0;
	}
	int mx1=head.value, mx2=0;
	for (auto z : head.edge) {
		returnmaxsum(v[z]);
		mx1 += v[z].sum2;
		mx2 += v[z].sum1;
	}
	head.sum1 = mx1;
	head.sum2 = mx2;
}
//设置返回值可写为
pii returnmaxsum2(Node head) {
	if (head.edge.empty()) {
		return make_pair(head.value, 0);
	}
	int mx1 = head.value, mx2 = 0;
	for (auto z : head.edge) {
		pii tmp=returnmaxsum2(v[z]);
		mx1 += tmp.second;
		mx2 += tmp.first;
	}
	return make_pair(mx1, mx2);
}
int main()
{
	freopen("zz.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> v[i].value;
	for (int i = 1; i <= n-1; i++) {
		int f,t;
		cin >> f >> t;
		v[f].edge.push_back(t);
		v[t].edge.push_back(f);
	}
	ini(1);
	returnmaxsum(v[1]);
	pii tmp=returnmaxsum2(v[1]);
	int res = max(tmp.first, tmp.second);
	cout << v[1].sum1 << "  " << v[1].sum2 << endl;
	cout << tmp.first << "  " << tmp.second << endl;
	return 0;
}