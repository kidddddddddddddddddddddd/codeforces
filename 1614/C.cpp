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
const int mod = 1e9 + 7;

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

int T;
int n, m;
int l, r, x;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		long long X = 0;
		scanf("%d%d", &n, &m);
		while (m--) {
			scanf("%d%d%d", &l, &r, &x);
			X |= x;
		}
		printf("%lld\n", X * poww(2, n - 1) % mod);
	}
	return 0;
}
