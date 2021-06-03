#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e3 + 1;
struct item {
	int cost;
	int product;
	//item(int a, int b):cost(a), product(b) {}
};
struct cmp1{ 
	bool operator()(item &a, item &b) {
	return a.cost < b.cost;
}
};
struct cmp2 {
	bool operator()(item &a, item &b) {
		return b.product < a.product;
	}
};
int main()
{
	freopen("zzc.txt", "r", stdin);
	int cur,n,k;
	cin >> cur>>n>>k;
	vector<item> it;
	it.resize(1000);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &it[i].cost, &it[i].product);
	}
	priority_queue<item,vector<item>, cmp1> cost;
	priority_queue<item, vector<item>, cmp2> product;
	for (int i = 0; i < n;i++) {
		cost.push(it[i]);
		product.push(it[i]);
	}
	while (k--) {
		while (!cost.empty()&&cost.top().cost < cur) {
			product.push(cost.top());
			cost.pop();
		}
		cur += product.top().product;
		product.pop();
	}
	cout << cur;
	return 0;
}