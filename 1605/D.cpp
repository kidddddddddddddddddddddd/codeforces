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
vector<int> G[maxn];
vector<int> nodes[2];
vector<int> nums[20];
int ans[maxn];
int Msb[maxn];

void init()
{
	for (int i = 0; i <= n; i++) {
		G[i].clear();
	}
	for (int i = 0; i < 2; i++) {
		nodes[i].clear();
	}
	for (int i = 0; i < 20; i++) {
		nums[i].clear();
	}
}

int msb(int x)
{
	for (int i = 19; i >= 0; i--) {
		if ((x >> i) & 1) {
			return i;
		}
	}
	return 0;
}

void pre_calc()
{
	for (int i = 1; i <= 200000; i++) {
		Msb[i] = msb(i);
	}
}

void dfs(int cur, int pre, int color)
{
	nodes[color].push_back(cur);
	for (int v : G[cur]) {
		if (v == pre) {
			continue;
		}
		dfs(v, cur, color ^ 1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	pre_calc();
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		init();
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0, 0);
		for (int i = 1; i <= n; i++) {
			nums[Msb[i]].push_back(i);
		}
		for (int i = 19; i >= 0; i--) {
			int cur = 0;
			if (nodes[cur ^ 1].size() > nodes[cur].size()) {
				cur ^= 1;
			}
			for (int it : nums[i]) {
				if (it > n) {
					continue;
				}
				ans[nodes[cur].back()] = it;
				nodes[cur].pop_back();
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
