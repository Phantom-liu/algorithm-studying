#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
// d为因数个数，num为当前数最小因数的次数，sd与sp同理
int d[N],num[N],phi[N], prime[N], mob[N],mark[N],sd[N],sp[N];
int cnt;
void primeset(int n)
{
	cnt = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (!mark[i]) prime[cnt++] = i;
		for (int j = 0; j < cnt&&i*prime[j] <= n; j++) {
			mark[i*prime[j]] = 1;
			if (!(i%prime[j]))break;
		}
	}
}
void eulor(int n)
{
	cnt = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!mark[i]) {
			prime[cnt++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < cnt&&i*prime[j] <= n; j++){
			mark[i*prime[j]] = 1;
			if (!(i%prime[j])) {
				phi[i*prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i*prime[j]] = phi[i] * (prime[j]-1);
		}
	}
}
void viscnt(int n)
{
	cnt = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!mark[i]) {
			prime[cnt++] = i;
			d[i] = 2;
			num[i] = 1;
		}
		for (int j = 0; j < cnt&&i*prime[j] <= n; j++) {
			if (!(i%prime[j])) {
				num[i*prime[j]] = num[i] + 1;
				d[i*prime[j]] = d[i] * (num[i*prime[j]]+1) / (num[i] + 1);
				break;
			}
			d[i*prime[j]] = 2 * d[i];
			num[i*prime[j]] = 1;
		}
	}
}
void sumvis(int n)
{
	cnt = 0;
	sd[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!mark[i]) {
			prime[cnt++] = i;
			sd[i] = i+1;
			sp[i] = i+1;
		}
		for (int j = 0; j < cnt&&i*prime[j] <= n; j++) {
			if (!(i%prime[j])) {
				sp[i*prime[j]] = sp[i] * prime[j] + 1;
				sd[i*prime[j]] = sd[i] * sp[i*prime[j]] / sp[i];
				break;
			}
			sp[i*prime[j]] = prime[j]+ 1;
			sd[i*prime[j]] = sd[i] * sp[prime[j]];	

		}
	}
}
void mobius(int n)
{
	cnt = 0;
	mob[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!mark[i]) {
			prime[cnt++] = i;
			mob[i] = -1;
		}
		for (int j = 0; j < cnt&&i*prime[j] <= n; j++) {
			if (!(i%prime[j])) {
				mob[i*prime[j]] = 0;
				break;
			}
			mob[i*prime[j]] = -mob[i];
		}
	}
}
int main()
{
	int n;
	cin >> n;
	eulor(n);
	mobius(n);
	viscnt(n);
	sumvis(n);
	cout << phi[10] << "	" << mob[10] << "	" << d[10] << "	" << sd[10] << "\n";
	return 0;
}
