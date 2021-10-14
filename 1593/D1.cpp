#include <algorithm>
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

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int T;
int n;
set<int> s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		s.clear();
		for (int i = 1, x; i <= n; i++) {
			scanf("%d", &x);
			s.insert(x);
		}
		if (s.size() == 1) {
			printf("-1\n");
			continue;
		}
		vector<int> diffs;
		int min_val = *s.begin();
		for (int x : s) {
			if (x == min_val) {
				continue;
			}
			diffs.push_back(x - min_val);
		}
		int ans = 0;
		for (int i = 0; i < diffs.size(); i++) {
			ans = gcd(ans, diffs[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
