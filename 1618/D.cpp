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

int T;
int n, k;
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n - 2 * k; i++) {
			ans += a[i];
		}
		for (int i = n - k + 1; i <= n; i++) {
			ans += a[i - k] / a[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
