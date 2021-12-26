#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

long long poww(long long a, long long b)
{
	long long res = 1, base = a;
	while (b) {
		if (b & 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		b >>= 1;
	}
	return res;
}

int n;
char a[maxn][4];
long long fac[maxn], invfac[maxn];

void init()
{
	invfac[0] = fac[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fac[i] = fac[i - 1] * i % mod;
		invfac[i] = poww(fac[i], mod - 2);
	}
}

long long C(int n, int m)
{
	return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	init();
	scanf("%d", &n);
	int W = 0, B = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i]);
		W += (a[i][0] == 'W') + (a[i][1] == 'W');
		B += (a[i][0] == 'B') + (a[i][1] == 'B');
	}
	if (W > n || B > n) {
		printf("0\n");
		return 0;
	}
	long long ans = C(2 * n - W - B, n - W);
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		// WW or BB exists
		if (a[i][0] == a[i][1] && a[i][0] != '?') {
			flag = true;
			break;
		}
	}

	if (!flag) {
		long long sub = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i][0] == '?' && a[i][1] == '?') {
				sub = (sub << 1) % mod;
			}
		}
		ans = (ans - sub + mod) % mod;

		int flagwb = 1, flagbw = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i][0] == 'B' || a[i][1] == 'W') {
				flagwb = 0;
			}
			if (a[i][0] == 'W' || a[i][1] == 'B') {
				flagbw = 0;
			}
		}
		ans = (ans + flagbw + flagwb) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
