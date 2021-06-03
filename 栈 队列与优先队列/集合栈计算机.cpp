#include<set>
#include<stack>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
using namespace std;
const int maxn = 2000;
typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
int ID(Set x)
{
	if (IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() - 1;
}
int main()
{
	string ge[maxn];
	int k=0;
	stack<int> ma;
	while (cin>>ge[++k])
	{
		if (ge[k][0] == 'P')ma.push(ID(Set()));
		else if (ge[k][0] == 'D')ma.push(ma.top());
		else {
			Set x;
			Set x1 = Setcache[ma.top()]; ma.pop();
			Set x2 = Setcache[ma.top()]; ma.pop();
			if (ge[k][0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));
			if (ge[k][0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
			if (ge[k][0] == 'A') { x = x2; x.insert(ID(x1)); }
			ma.push(ID(x));
		}
		cout << Setcache[ma.top()].size() << endl;
	}
	return 0;
}