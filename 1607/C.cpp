#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string_view>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 3e5 + 7;
const int maxm = 2e6 + 7;

int T;
int n;
long long a[maxn];

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
		sort(a + 1, a + 1 + n);
		long long val = -1e18;
		long long ans = 0;
		int idx = n;
		for (int i = 1; i <= n; i++) {
			val = max(val, a[i] - ans);
			ans += a[i] - ans;
		}
		printf("%lld\n", val);
	}
	return 0;
}
