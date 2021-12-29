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

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int T;
int n;
long long a[maxn];

bool check(long long x)
{
	int flag[2];
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; i += 2) {
		if (a[i] % x != 0) {
			flag[1] = 1;
		}
	}
	for (int i = 2; i <= n; i += 2) {
		if (a[i] % x == 0) {
			flag[0] = 1;
		}
	}
	if (flag[0] + flag[1] == 0) {
		return true;
	}

	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; i += 2) {
		if (a[i] % x == 0) {
			flag[1] = 1;
		}
	}
	for (int i = 2; i <= n; i += 2) {
		if (a[i] % x != 0) {
			flag[0] = 1;
		}
	}
	if (flag[0] + flag[1] == 0) {
		return true;
	}

	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		vector<long long> v[2];
		for (int i = 1; i <= n; i++) {
			v[i & 1].push_back(a[i]);
		}
		long long g[2];
		g[0] = g[1] = 0;
		for (long long x : v[0]) {
			g[0] = gcd(g[0], x);
		}
		for (long long x : v[1]) {
			g[1] = gcd(g[1], x);
		}
		if (check(g[0])) {
			printf("%lld\n", g[0]);
		} else if (check(g[1])) {
			printf("%lld\n", g[1]);
		} else {
			printf("0\n");
		}
	}
	return 0;
}
