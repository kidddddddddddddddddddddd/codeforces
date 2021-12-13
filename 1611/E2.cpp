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
int x[maxn];
vector<int> G[maxn];
int nearest[maxn];

void init()
{
	for (int i = 1; i <= n; i++) {
		G[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		nearest[i] = n;
	}
}

int dfs(int cur, int dist, int pre = -1)
{
	bool children = true;
	int sum = 0;
	for (int v : G[cur]) {
		if (v == pre) {
			continue;
		}
		int cnt = dfs(v, dist + 1, cur);
		if (cnt < 0) {
			children = false;
		}
		nearest[cur] = min(nearest[cur], nearest[v] + 1);
		sum += cnt;
	}
	if (nearest[cur] <= dist) {
		return 1;
	}
	if (sum == 0 || !children) {
		return -1;
	}
	return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		init();
		for (int i = 1; i <= k; i++) {
			scanf("%d", &x[i]);
			nearest[x[i]] = 0;
		}
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		printf("%d\n", dfs(1, 0, -1));
	}
	return 0;
}
