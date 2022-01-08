#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int Q;
int n;
set<int> s[maxn];
int ans[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &Q);
	int opt, x, y;
	while (Q--) {
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d", &x);
			s[x].insert(++n);
		} else {
			scanf("%d%d", &x, &y);
			if (s[x].empty() || x == y) {
				continue;
			}
			if (s[x].size() < s[y].size()) {
				for (int val : s[x]) {
					s[y].insert(val);
				}
				s[x].clear();
			} else {
				for (int val : s[y]) {
					s[x].insert(val);
				}
				s[y].clear();
				swap(s[x], s[y]);
			}
		}
	}
	for (int i = 1; i <= 500000; i++) {
		for (int idx : s[i]) {
			ans[idx] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
