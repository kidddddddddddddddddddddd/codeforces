#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 1e3 + 7;

int n, m, Q;
long long ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &Q);
	vector<vector<int>> a(n, vector<int>(m, 1));
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (x == 0) {
				for (int k = 1; k <= n + m; k++) {
					int nx = x + k / 2;
					int ny = y + (k + 1) / 2;
					if (nx == n || ny == m) {
						break;
					}
					ans += k;
				}
			}
			if (y == 0) {
				for (int k = 1; k <= n + m; k++) {
					int nx = x + (k + 1) / 2;
					int ny = y + k / 2;
					if (nx == n || ny == m) {
						break;
					}
					ans += k;
				}
			}
		}
	}
	ans += n * m;
	while (Q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		for (int c = 0; c < 2; c++) {
			int l = 1, r = 1;
			while (true) {
				int nx = x + (l + c) / 2;
				int ny = y + (l + !c) / 2;
				if (nx == n || ny == m || a[nx][ny] == 0) {
					break;
				}
				++l;
			}
			while (true) {
				int nx = x - (r + !c) / 2;
				int ny = y - (r + c) / 2;
				if (nx < 0 || ny < 0 || a[nx][ny] == 0) {
					break;
				}
				++r;
			}
			if (a[x][y] == 0) {
				ans += l * r;
			} else {
				ans -= l * r;
			}
		}
		ans += a[x][y];
		a[x][y] ^= 1;
		ans -= a[x][y];
		printf("%lld\n", ans);
	}
	return 0;
}
