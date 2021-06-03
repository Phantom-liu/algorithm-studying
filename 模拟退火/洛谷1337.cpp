#include<bits/stdc++.h>
//模拟退火的exp无用？ 先睡了 此代码不是最终版
using namespace std;
int n;long double xsum, ysum;
const int maxn = 1005;
const long double eps = 1e-14;
long double x[maxn], y[maxn], w[maxn];
long double func(long double x1, long double y1) {
	long double res = 0;
	for (int i = 1; i <= n; i++) {
		res += w[i] * (sqrt((x[i] - x1)*(x[i] - x1) + (y[i] - y1)*(y[i] - y1)));
	}
	return res;
}
pair<long double, long double> solve()
{
	long double T = 10000, delta = 0.99;
	long double nowx = xsum / n;
	long double nowy = ysum / n;
	long double bestx, besty;
	long double now = func(nowx, nowy);
	long double ans, next = func(nowx, nowy);
	ans = next;
	while (T > eps) {
		int dx[3] = { -1,0,1 };
		int dy[3] = { -1,0,1 };
		long double nextx = nowx +dx[rand()%3]*T;
		long double nexty = nowy + dy[rand() % 3] * T;
		if (nextx >= -10000 && nextx <= 10000 && nexty >= -10000 && nexty <= 10000) { //nextx >= -10000 && nextx <= 10000 && nexty >= -10000 && nexty <= 10000
			next = func(nextx, nexty);
			if (next < ans) {
				bestx = nextx;
				besty = nexty;
				ans = next;
			}
			else if (next<now||exp((now - next) / T) > (long double)rand()/RAND_MAX ) {
				nowx = nextx;
				nowy = nexty;
				now = next;
			}
		}
		T *= delta;
	}
	return make_pair(bestx, besty);
}
int main()
{
	srand(time(NULL));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> w[i];
		xsum += x[i];
		ysum += y[i];
	}
	printf("%.3f %.3f", solve().first, solve().second);
	return 0;
}