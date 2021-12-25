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
int n;
long long h;
long long a[maxn];

bool check(long long k)
{
	long long damage = 0;
	for (int i = 1; i < n; i++) {
		damage += min(k, a[i + 1] - a[i]);
	}
	damage += k;
	return damage >= h;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &h);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		long long l = 1, r = 1e18;
		long long ans = r + 1;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			if (check(mid)) {
				ans = min(ans, mid);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
