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
		__int128 sum1 = 0, sum2 = 0;
		for (int i = 1; i <= n; i++) {
			sum1 += a[i];
		}
		if ((sum1 * (n - 2)) % n) {
			printf("0\n");
			continue;
		}
		sum2 = sum1 - (sum1 * (n - 2)) / n;
		map<long long, long long> cnt;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += cnt[sum2 - a[i]];
			cnt[a[i]]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
