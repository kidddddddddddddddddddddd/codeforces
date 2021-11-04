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

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;
int n;
int a[maxn], b[maxn], m[maxn];
int res_a[maxn];

map<int, set<pair<pair<int, int>, int>>> table;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		table.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i], &b[i], &m[i]);
			table[a[i] + b[i] - m[i]].insert(
					make_pair(make_pair(max(a[i] - m[i], 0), a[i]), i));
		}
		int res = 0;
		for (auto it : table) {
			int cur = 1e9;
			for (auto rit = it.second.rbegin(); rit != it.second.rend(); rit++) {
				if (cur > (*rit).first.second) {
					cur = (*rit).first.first;
					res++;
				}
				res_a[(*rit).second] = cur;
			}
		}
		printf("%d\n", res);
		for (int i = 1; i <= n; i++) {
			printf("%d %d\n", a[i] - res_a[i], m[i] - (a[i] - res_a[i]));
		}
	}
	return 0;
}
