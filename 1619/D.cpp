#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
int m, n;
int a[maxn];

int pos(int x, int y)
{
	return (x - 1) * n + y;
}

bool check(int mid)
{
	for (int j = 1; j <= n; j++) {
		int flag = 1;
		for (int i = 1; i <= m; i++) {
			if (a[pos(i, j)] >= mid) {
				flag = 0;
			}
		}
		if (flag) {
			return 0;
		}
	}

	for (int i = 1; i <= m; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (a[pos(i, j)] >= mid) {
				cnt++;
			}
		}
		if (cnt >= 2) {
			return 1;
		}
	}

	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &m, &n);
		int l = 1, r = 1000000000;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[pos(i, j)]);
			}
		}
		int ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				ans = max(ans, mid);
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
