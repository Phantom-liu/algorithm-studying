/*
	eps=1e-8;		//终止温度 接近于0 用于控制精度
	T=100;			//初始温度 应该是高温 以100为例
	delta=0.98;		//降温系数 控制退火的快慢 小于1 以0.98为例
	g(x);			//状态x时的评价函数 例如物理意义上的能量
	now,next;		//当前状态和新状态
	while(T>eps){				//如果温度未降到eps
		g(next),g(now);			//计算能量
		dE=g(next)-g(now);		//能量差
		if(dE>=0) now=next;		//新状态更优 接受新状态
		else if(exp(dE/T)>rand()) now=next;		//如果新状态更差 则以一定概率接受新状态
		T*=delta;			//降温 模拟退火过程
	}
*/
#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double y;
double func(double x) {
	return 6 * pow(x, 7.0) + 8 * pow(x, 6.0) + 7 * pow(x, 3.0) + 5 * pow(x, 2.0) - y * x;
}
double solve()
{
	double T = 100;
	double delta = 0.99;
	double x = 50.0;
	double now = func(x);
	double ans = now;
	while (T > eps) {
		int f[2] = { 1,-1 };
		double newx = x + f[rand() % 2] * T;
		if (newx >= 0 && newx <= 100) {
			double next = func(newx);
			ans = min(next, now);
			if (now - next > 0) {
				x = newx;
				now = next;
			}
			else if (exp((now - next)/T) > (double)rand() / RAND_MAX) {
				x = newx;
				now = next;
			}
		}
		T *= delta;
	}
	return ans;
}
int main()
{
	int cas;
	cin >> cas;
	while (cas--) {
		cin >> y;
		printf("%.4f\n", solve());
	}
	return 0;
}
