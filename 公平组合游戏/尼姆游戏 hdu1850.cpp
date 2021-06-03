#include<bits/stdc++.h>
using namespace std;
int m;
int a[105];
int main()
{
	while (cin >> m) {
		if (m == 0)break;
		for (int i = 1; i <= m; i++) {
			cin >> a[i];
		}
		int nimsum = 0;
		for (int i = 1; i <= m; i++) {
			nimsum ^= a[i];
		}
		int ans=0;
		if (nimsum) {
			for (int i = 1; i <= m; i++) {
				if ((nimsum^a[i]) < a[i])ans++;
			}
			cout << ans << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}