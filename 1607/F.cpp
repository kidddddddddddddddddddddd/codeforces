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

const int maxn = 2e3 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;
int n, m;
int ans, r, c;
int loop, id;
int vis[maxn][maxn], dist[maxn][maxn];

char pic[maxn][maxn];

int dfs(int x, int y, int id, int depth)
{
	if (x < 1 || x > n || y < 1 || y > m) {
		return 1;
	}
	if (vis[x][y] && vis[x][y] != id) {
		return 1 + dist[x][y];
	}
	if (vis[x][y] == id) {
		return loop = depth - dist[x][y];
	}
	vis[x][y] = id;
	int nex_x = x, nex_y = y;
	if (pic[x][y] == 'L') {
		nex_y--;
	} else if (pic[x][y] == 'R') {
		nex_y++;
	} else if (pic[x][y] == 'U') {
		nex_x--;
	} else {
		nex_x++;
	}
	dist[x][y] = depth;
	dist[x][y] = dfs(nex_x, nex_y, id, depth + 1);
	loop--;
	if (loop <= 0) {
		return 1 + dist[x][y];
	}
	return dist[x][y];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", pic[i] + 1);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				vis[i][j] = 0;
			}
		}
		ans = 0, id = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (vis[i][j]) {
					continue;
				}
				id++;
				loop = 0;
				dfs(i, j, id, 0);
				if (dist[i][j] > ans) {
					ans = dist[i][j];
					r = i;
					c = j;
				}
			}
		}
		printf("%d %d %d\n", r, c, ans);
	}
	return 0;
}
