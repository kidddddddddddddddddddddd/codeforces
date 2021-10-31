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

int T;
int n;
vector<int> v[2];
int dp[2][maxn];
int a[maxn];

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
			scanf("%d", &a[i]);
		}
		long long ans = 0;
		for (int i = n; i >= 1; i--) {
			int idx = i & 1;
			v[idx].push_back(a[i]);
			dp[idx][a[i]] = 1;
			int lst = a[i];
			for (int x : v[idx ^ 1]) {
				int y = dp[idx ^ 1][x];
				int split = (a[i] + x - 1) / x;
				int st = a[i] / split;
				ans = (ans + 1ll * (split - 1) * y * i) % mod;
				dp[idx][st] += y;
				if (lst != st) {
					v[idx].push_back(st);
					lst = st;
				}
			}
			for (int x : v[idx ^ 1]) {
				dp[idx ^ 1][x] = 0;
			}
			v[idx ^ 1].clear();
		}
		printf("%lld\n", ans);

		for (int x : v[0]) {
			dp[0][x] = 0;
			dp[1][x] = 0;
		}
		for (int x : v[1]) {
			dp[0][x] = 0;
			dp[1][x] = 0;
		}

		// memset(dp, 0, sizeof(dp));
		v[0].clear();
		v[1].clear();
	}
	return 0;
}
