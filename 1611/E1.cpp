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
queue<int> Q, Q_f;
int dis[maxn], dis_f[maxn];

void init()
{
	for (int i = 1; i <= n; i++) {
		G[i].clear();
	}
	while (!Q.empty()) {
		Q.pop();
	}
	while (!Q_f.empty()) {
		Q.pop();
	}
	for (int i = 0; i <= n; i++) {
		dis[i] = -1;
		dis_f[i] = -1;
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
		scanf("%d%d", &n, &k);
		init();
		for (int i = 1; i <= k; i++) {
			scanf("%d", &x[i]);
		}
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 1; i <= k; i++) {
			dis_f[x[i]] = 0;
			Q_f.push(x[i]);
		}
		while (!Q_f.empty()) {
			int x = Q_f.front();
			Q_f.pop();
			for (int y : G[x]) {
				if (dis_f[y] != -1) {
					continue;
				}
				dis_f[y] = dis_f[x] + 1;
				Q_f.push(y);
			}
		}
		dis[1] = 0;
		Q.push(1);
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			for (int y : G[x]) {
				if (dis[y] != -1) {
					continue;
				}
				dis[y] = dis[x] + 1;
				Q.push(y);
			}
		}
		bool ok = false;
		for (int i = 2; i <= n; i++) {
			if (G[i].size() > 1) {
				continue;
			}
			if (dis[i] < dis_f[i]) {
				ok = true;
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}
