#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 4e5 + 7;
const int maxm = 1e6 + 7;

int T;
int n;
int a[maxn];

int cnt[1 << 21], vis[1 << 21];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	int tm = 0;
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			a[i] += 1000000;
		}
		int k;
		for (k = 1 << 21; k > 0; k--) {
			int max_val = 0;
			tm++;
			for (int i = 1; i <= n; i++) {
				int x = a[i] % k;
				if (vis[x] < tm) {
					vis[x] = tm;
					cnt[x] = 0;
				}
				if (max_val < ++cnt[x]) {
					max_val = cnt[x];
				}
			}
			if (max_val >= n / 2) {
				break;
			}
		}
		printf("%d\n", k == 1 << 21 ? -1 : k);
	}
	return 0;
}
