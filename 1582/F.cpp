#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 7;
const int maxm = 1e6 + 7;
const int mod = 1e9 + 7;

int n;
int a[maxm];

vector<int> g[maxn];
int vis[maxn], r[maxn];
vector<int> ans;

void init()
{
	for (int i = 0; i <= (1 << 13); i++) {
		g[i].clear();
		g[i].push_back(0);
		vis[i] = 0;
		r[i] = 1 << 13;
	}
	ans.clear();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init();
	vis[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int v : g[a[i]]) {
			int nxt = v ^ a[i];
			vis[nxt] = 1;
			while (r[nxt] > a[i]) {
				if (r[nxt] != a[i]) {
					g[r[nxt]].push_back(nxt);
				}
				r[nxt]--;
			}
		}
		g[a[i]].clear();
	}
	for (int i = 0; i < (1 << 13); i++) {
		if (vis[i]) {
			ans.push_back(i);
		}
	}
	printf("%d\n", ans.size());
	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}
