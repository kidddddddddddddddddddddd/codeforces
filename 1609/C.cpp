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

int T;
int n, e;
int a[maxn];
int pre[maxn], suf[maxn];

bool vis[maxm], prime[maxm];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	for (int i = 2; i < maxm; i++) {
		if (vis[i]) {
			continue;
		}
		prime[i] = true;
		for (int j = i; j < maxm; j += i) {
			vis[j] = true;
		}
	}

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &e);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			pre[i] = 0;
			if (i > e && a[i - e] == 1) {
				pre[i] = pre[i - e] + 1;
			}
		}
		for (int i = n; i >= 1; i--) {
			suf[i] = 0;
			if (i + e <= n && a[i + e] == 1) {
				suf[i] = suf[i + e] + 1;
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			if (prime[a[i]]) {
				ans += 1ll * (pre[i] + 1) * (suf[i] + 1) - 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
