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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		vector<int> pos_x, neg_x;
		for (int i = 1, x; i <= n; i++) {
			scanf("%d", &x);
			if (x >= 0) {
				pos_x.push_back(x);
			} else {
				neg_x.push_back(x);
			}
		}
		sort(pos_x.begin(), pos_x.end());
		sort(neg_x.begin(), neg_x.end());
		long long ans = 0;
		for (int i = pos_x.size() - 1; i >= 0; i -= k) {
			ans += pos_x[i];
		}
		for (int i = 0; i < neg_x.size(); i += k) {
			ans += abs(neg_x[i]);
		}
		int del = 0;
		if (!pos_x.empty()) {
			del = max(del, pos_x.back());
		}
		if (!neg_x.empty()) {
			del = max(del, abs(neg_x[0]));
		}
		printf("%lld\n", ans * 2 - del);
	}
	return 0;
}
