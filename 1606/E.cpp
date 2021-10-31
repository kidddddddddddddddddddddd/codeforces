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
const int maxm = 1e6 + 7;
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

long long fac[maxn];
long long inv[maxn];

long long C(int n, int m)
{
	if (n < m) {
		return 0;
	}
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void init()
{
	fac[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	for (int i = 0; i <= 200000; i++) {
		inv[i] = poww(fac[i], mod - 2);
	}
}

long long dp[507][507];

int main()
{
#ifndef ONLINE_JUDGE
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	init();
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= x; i++) {
		dp[1][i] = i;
		dp[2][i] = i * (i - 1);
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			if (j < i) {
				dp[i][j] = 0;
				continue;
			}
			// die k
			for (int k = 0; k < i; k++) {
				dp[i][j] = (dp[i][j] + dp[i - k][j - i + 1] * poww(i - 1, k) % mod * C(i, k) % mod) % mod;
			}
		}
	}
	printf("%lld\n", (poww(x, n) - dp[n][x] + mod) % mod);
	return 0;
}
