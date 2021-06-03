#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

typedef double db;
typedef long long ll;

namespace Eddd {
	inline char sc() {
		return getchar();
		static const int LEN = 100000;
		static char Buf[LEN], *OP = Buf, *ED = Buf;
		if (OP == ED) ED = (OP = Buf) + fread(Buf, 1, LEN, stdin);
		return *OP++;
	}
	template<class T> void rd(T &x) {
		static int c, f; x = f = 0;
		while (c = sc(), c < 48) if (c == '-') f = 1;
		do x = (x << 3) + (x << 1) + (c ^ 48);
		while (c = sc(), c > 47); if (f) x = -x;
	}
	template<class T> void pt(T x) {
		if (x < 0) putchar('-'), x = -x;
		else if (!x) putchar('0');
		static int Stk[30], tp = 0;
		for (; x; x /= 10) Stk[tp++] = x % 10;
		while (tp) putchar(Stk[--tp] ^ 48);
	}
	template<class T> void ptk(const T &x) {
		pt(x); putchar(' ');
	}
	template<class T> void ptn(const T &x) {
		pt(x); putchar('\n');
	}
	template<class T> bool chkmi(T &x, const T &y) {
		return x > y ? x = y, true : false;
	}
	template<class T> bool chkmx(T &x, const T &y) {
		return x < y ? x = y, true : false;
	}
}
using namespace Eddd;
const int maxn = 1e6; const ll en = (ll)1<<32;
ll phi[maxn], p[maxn], nump;
int m[maxn],u[maxn];
void eular(ll n)
{
	phi[1] = 1,u[1]=1; 
	for (int i = 2; i <= n; i++) {
		if (!m[i]) {
			p[++nump] = i;
			phi[i] = i - 1;
			u[i] = -1;
		}
		for (int j = 1; j <= nump && p[j] * i <=n; j++)
		{
			m[p[j] * i] = 1;
			if (i%p[j] == 0) {
				phi[i*p[j]] = p[j] * phi[i];
				break;
			}
			else {
				phi[i*p[j]] = phi[i] * phi[p[j]];
			}
			if ((i%p[j]) == 0)
			{
				u[i*p[j]] = 0;
				break;
			}
			u[i*p[j]] = -u[i];
		}
	}
}
int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}
int mob(int x) {
	if (x == 1)return 1;
	int s=1;
	for (int i = 1; p[i] <= x; i++)
	{
		if (x % (p[i] * p[i]) == 0)return 0;
		if (x%(p[i]) == 0)s = -s;
	}
	return s;
}


int main()
{
	int T;
	rd(T);
	while (T--) {
		int n, m;
		rd(n); rd(m);
		eular(n*m);
		ll sum = 0;
		FOR(i, 1, n)
		{
			FOR(j, 1, m) {
				if (u[i*j]) sum += gcd(i,j) * phi[i*j] * u[i*j];
			}sum %= en;
		}
		if (sum < 0)sum += en;
		ptn(sum);
	}
	return 0;
}