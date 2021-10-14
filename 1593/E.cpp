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

const int maxn = 4e5 + 7;
const int maxm = 1e6 + 7;

int T;
int n, k;
set<int> G[maxn];

void init()
{
	for (int i = 0; i <= n; i++) {
		G[i].clear();
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
		scanf("%d%d", &n, &k);
		init();
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].insert(v);
			G[v].insert(u);
		}
		set<int> leaves;
		for (int i = 1; i <= n; i++) {
			if (G[i].size() == 1) {
				leaves.insert(i);
			}
		}
		int remain = n;
		while (remain >= 1 && k > 0) {
			if (remain <= 2) {
				k--;
				remain = 0;
				break;
			}
			k--;
			set<int> nxt;
			while (!leaves.empty()) {
				int leaf = *leaves.begin();
				leaves.erase(leaves.begin());
				// delete leaf
				for (int v : G[leaf]) {
					G[v].erase(leaf);
					if (G[v].size() == 1) {
						nxt.insert(v);
					}
				}
				G[leaf].clear();
				remain--;
			}
			leaves = nxt;
		}
		printf("%d\n", remain);
	}
	return 0;
}
