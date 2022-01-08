#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
int n;
int a[maxn];

int check(int cnt_1, int cnt_2)
{
	int cnt_3 = 0;
	for (int i = 1; i <= n; i++) {
		int min_i = 1e9;
		for (int j = 0; j <= cnt_1; j++) {
			for (int k = 0; k <= cnt_2; k++) {
				if (a[i] >= j + 2 * k && (a[i] - j - 2 * k) % 3 == 0) {
					min_i = min(min_i, (a[i] - j - 2 * k) / 3);
				}
			}
		}
		cnt_3 = max(cnt_3, min_i);
	}
	return cnt_3;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int ans = 1e9;
		for (int i = 0; i <= 3; i++) {
			for (int j = 0; j <= 3; j++) {
				ans = min(ans, check(i, j) + i + j);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
