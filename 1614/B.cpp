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
int n;
int a[maxn];
int ans[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector<pair<int, int>> v;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			v.push_back(make_pair(a[i], i));
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		vector<int> factor;
		for (int i = 1; i <= n; i++) {
			factor.push_back(-i);
			factor.push_back(i);
		}
		for (int i = 0; i < n; i++) {
			ans[v[i].second] = factor[i];
		}
		long long cost = 0;
		for (int i = 0; i < n; i++) {
			int id = v[i].second;
			cost += 1ll * a[id] * 2 * abs(ans[id]);
		}
		printf("%lld\n", cost);
		for (int i = 0; i <= n; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
