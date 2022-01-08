#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
int w, h;
vector<pair<int, int>> points[4];

void init()
{
	for (int i = 0; i < 4; i++) {
		points[i].clear();
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d%d", &w, &h);

		for (int i = 0; i <= 1; i++) {
			int k, x;
			scanf("%d", &k);
			while (k--) {
				scanf("%d", &x);
				if (i & 1) {
					points[i].push_back(make_pair(x, 0));
				} else {
					points[i].push_back(make_pair(x, h));
				}
			}
		}

		for (int i = 2; i <= 3; i++) {
			int k, x;
			scanf("%d", &k);
			while (k--) {
				scanf("%d", &x);
				if (i & 1) {
					points[i].push_back(make_pair(0, x));
				} else {
					points[i].push_back(make_pair(w, x));
				}
			}
		}

		long long ans = 0;

		ans = max(ans, 1ll * (points[1].back().first - points[1][0].first) * h);
		ans = max(ans, 1ll * (points[0].back().first - points[0][0].first) * h);

		ans = max(ans, 1ll * (points[2].back().second - points[2][0].second) * w);
		ans = max(ans, 1ll * (points[3].back().second - points[3][0].second) * w);

		printf("%lld\n", ans);
	}
	return 0;
}
