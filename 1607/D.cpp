#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string_view>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 3e5 + 7;
const int maxm = 2e6 + 7;

int T;
int n;
int a[maxn];
char s[maxn];
vector<pair<int, int>> v;
bool vis[maxn];

void init()
{
	for (int i = 0; i <= n; i++) {
		vis[i] = false;
	}
	v.clear();
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
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'B') {
				if (1 <= a[i]) {
					v.push_back(make_pair(1, min(n, a[i])));
				}
			} else {
				if (a[i] <= n) {
					v.push_back(make_pair(max(1, a[i]), n));
				}
			}
		}
		sort(v.begin(), v.end());
		int cur = 1;
		for (pair<int, int> node : v) {
			if (node.first <= cur && cur <= node.second) {
				vis[cur++] = 1;
			}
		}
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			ok &= vis[i];
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}
