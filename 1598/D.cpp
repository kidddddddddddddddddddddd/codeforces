#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 7;

int T;
int n;
int a[maxn], b[maxn];
long long cnt_a[maxn], cnt_b[maxn];

void init()
{
	for (int i = 0; i <= n; i++) {
		cnt_a[i] = 0;
		cnt_b[i] = 0;
	}
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
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i], &b[i]);
			cnt_a[a[i]]++;
			cnt_b[b[i]]++;
		}
		long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
		for (int i = 1; i <= n; i++) {
			ans -= (cnt_a[a[i]] - 1) * (cnt_b[b[i]] - 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
