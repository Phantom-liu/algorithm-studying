#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int coeff[3] = { 2,3,5 };
int main()
{
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	set<ll> s;
	pq.push(1);
	s.insert(1);
	for (int i = 1;; i++)
	{
		ll x = pq.top(); pq.pop();
		if (i == 1500) {
			cout << "look at this " << x << "\n";
			break;
		}
		for (int j = 0; j < 3; j++)
		{
			ll m = coeff[j] * x;
			if (s.count(m) == 0)
			{
				s.insert(m);
				pq.push(m);
			}
		}
	}
	return 0;
}