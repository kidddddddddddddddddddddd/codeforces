#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 7;
const int maxm = 450 + 7;
const int mod = 1e9 + 7;

int T;
int n, k;
int a[maxn];
int dp[maxn][maxm];
long long pre[maxn];

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
		for (int i = 1; i <= n; i++) {
			pre[i] = pre[i - 1] + a[i];
		}
		for (k = 0; k * (k + 1) / 2 <= n; k++) {
		}
		for (int j = 0; j < k; j++) {
			dp[n + 1][j] = -mod;
		}
		dp[n + 1][0] = mod;
		for (int i = n; i >= 1; i--) {
			for (int j = 0; j < k; j++) {
				dp[i][j] = dp[i + 1][j];
				if (j && i + j - 1 <= n && pre[i + j - 1] - pre[i - 1] < dp[i + j][j - 1]) {
					dp[i][j] = max(dp[i][j], (int)(pre[i + j - 1] - pre[i - 1]));
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < k; i++) {
			if (dp[1][i] > 0) {
				ans = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
