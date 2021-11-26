#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;
int n;
int a[maxn], b[maxn];

bool check(int mid)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (mid - 1 - a[i] <= cnt && cnt <= b[i]) {
			cnt++;
		}
	}
	return cnt >= mid;
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
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i], &b[i]);
		}
		int ans = 0;
		int l = 1, r = n;
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
