#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 7;
const int maxm = 1e6 + 7;

int T;
int n;
int a[maxn];
int Q;
vector<pair<int, int>> Queries;
vector<int> pos[maxn];
map<pair<int, int>, int> ans;

void init()
{
	Queries.clear();
	for (int i = 0; i <= n + 10; i++) {
		pos[i].clear();
	}
	ans.clear();
}

void trans()
{
	map<int, int> cnt;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = cnt[a[i]];
	}
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
		scanf("%d", &Q);
		while (Q--) {
			int k, x;
			scanf("%d%d", &x, &k);
			k = min(k, n + 10);
			Queries.push_back(make_pair(x, k));
			pos[k].push_back(x);
		}

		for (int i = 0; i <= n + 10; i++) {
			for (int x : pos[i]) {
				ans[make_pair(x, i)] = a[x];
			}
			trans();
		}
		for (pair<int, int> query : Queries) {
			printf("%d\n", ans[query]);
		}
	}
	return 0;
}
