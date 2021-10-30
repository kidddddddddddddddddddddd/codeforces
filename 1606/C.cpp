#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 7;
const int maxm = 1e6 + 7;
const int mod = 1e9 + 7;

int T;
int n, k;
long long a[20];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			a[i] = pow(10, a[i]);
		}
		long long ans = 0;
		k++;
		for (int i = 1; i < n; i++) {
			long long cnt = min(1ll * k, a[i + 1] / a[i] - 1);
			k -= cnt;
			ans += a[i] * cnt;
		}
		ans += k * a[n];
		printf("%lld\n", ans);
	}
	return 0;
}
