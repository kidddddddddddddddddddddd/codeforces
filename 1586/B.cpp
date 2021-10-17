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

int T;
int n, m;
bool vis[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++) {
			vis[i] = false;
		}
		int a, b, c;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			vis[b] = 1;
		}
		int root;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				root = i;
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i == root) {
				continue;
			}
			printf("%d %d\n", i, root);
		}
	}
	return 0;
}
