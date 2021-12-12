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
int b[maxn], p[maxn];
int dis[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			dis[i] = -1;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
		}
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			if (b[p[1]] != p[1]) {
				ok = false;
				break;
			}
			if (i == 1) {
				dis[p[i]] = 0;
			} else {
				if (dis[b[p[i]]] == -1) {
					ok = false;
					break;
				}
				dis[p[i]] = dis[p[i - 1]] + 1;
			}
		}
		if (!ok) {
			printf("-1\n");
		} else {
			for (int i = 1; i <= n; i++) {
				printf("%d ", dis[i] - dis[b[i]]);
			}
			printf("\n");
		}
	}
	return 0;
}
