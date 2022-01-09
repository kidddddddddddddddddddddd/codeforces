#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

#define int long long
int T;
int n;
int a[maxn];

int ans[maxn];
int cnt[maxn];
long long pre[maxn];
long long sum[maxn];
long long val[maxn];

void init()
{
	for (int i = 0; i <= n; i++) {
		ans[i] = -1;
		cnt[i] = 0;
		pre[i] = 0;
	}
	val[0] = 0;
	for (int i = 1; i <= n; i++) {
		val[i] = val[i - 1] + i;
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &n);
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			cnt[a[i]]++;
		}
		pre[0] = cnt[0];
		for (int i = 1; i <= n; i++) {
			pre[i] = pre[i - 1] + cnt[i];
			sum[i] = sum[i - 1] + 1ll * cnt[i] * i;
		}

		vector<int> res;
		int cur = 0;

		if (cnt[0]) {
			ans[0] = cnt[0];
			for (int i = 1; i < cnt[0]; i++) {
				res.push_back(0);
			}
		} else {
			ans[0] = 0;
		}

		for (int i = 1; i <= n; i++) {
			if (pre[i - 1] < i) {
				break;
			}
			ans[i] = cur + cnt[i];

			if (cnt[i] == 0 && res.size()) {
				cur += i - res.back();
				res.pop_back();
			}

			for (int j = 1; j < cnt[i]; j++) {
				res.push_back(i);
			}
		}
		for (int i = 0; i <= n; i++) {
			printf("%lld ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
