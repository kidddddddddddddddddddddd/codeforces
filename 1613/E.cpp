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

const int maxn = 5e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
int n, m;
vector<vector<char>> pic;
vector<vector<bool>> vis;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int cnt(int x, int y)
{
	int res = 0;
	for (int i = 0; i < 4; i++) {
		res += (pic[x + dx[i]][y + dy[i]] == '.');
	}
	return res;
}

void bfs(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(x, y));
	vis[x][y] = 1;
	while (!Q.empty()) {
		auto it = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nxt_x = it.first + dx[i], nxt_y = it.second + dy[i];
			if (!vis[nxt_x][nxt_y] && pic[nxt_x][nxt_y] != '#' && cnt(nxt_x, nxt_y) < 2) {
				vis[nxt_x][nxt_y] = 1;
				pic[nxt_x][nxt_y] = '+';
				Q.push(make_pair(nxt_x, nxt_y));
			}
		}
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
		cin >> n >> m;
		pic.clear();
		vis.clear();
		pic.resize(n + 2);
		vis.resize(n + 2);
		for (int i = 0; i < n + 2; i++) {
			pic[i].resize(m + 2);
			vis[i].resize(m + 2);
		}
		for (int j = 0; j < m + 2; j++) {
			pic[0][j] = '#';
			vis[0][j] = true;
			pic[n + 1][j] = '#';
			vis[n + 1][j] = true;
		}
		for (int i = 1; i <= n; i++) {
			pic[i][0] = '#';
			vis[i][0] = true;
			pic[i][m + 1] = '#';
			vis[i][m + 1] = true;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> pic[i][j];
			}
		}
		int sx, sy;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (pic[i][j] == 'L') {
					sx = i;
					sy = j;
				}
			}
		}
		bfs(sx, sy);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << pic[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
