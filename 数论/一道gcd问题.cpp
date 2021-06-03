#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int main()
{
	int n;
	vector<int> a;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)cin >> a[i]; 
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	int mini = a[1] - a[0]; 
	for (int i = 0; i <a.size()-1; i++)if (a[i + 1] - a[i] < mini)mini = a[i + 1] - a[i];
	int gcd, k, m;
	for (int i = mini; i > 0; i--) {
		bool ok = true;
		m = a[0] % i;
		for (int j = 1; j < a.size(); j++) {
			if (a[j] % i != m) {
				ok = false;
				break;
			}
		}
		if (ok) {
			gcd = i; break;
		}
	}
	k = gcd-m;
	cout << gcd << " " << k << endl;
	return 0;
}