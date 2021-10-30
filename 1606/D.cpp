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
const int maxm = 1e6 + 7;
const int mod = 1e9 + 7;

int T;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(),
				[&a](int x, int y) { return a[x][0] > a[y][0]; });
		vector<vector<int>> mxl(n, vector<int>(m, -mod));
		vector<vector<int>> mnr(n, vector<int>(m, mod));
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				mxl[i][j] = a[order[i]][j];
				if (i < n - 1) {
					mxl[i][j] = max(mxl[i][j], mxl[i + 1][j]);
				}
				if (j > 0) {
					mxl[i][j] = max(mxl[i][j], mxl[i][j - 1]);
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				mnr[i][j] = a[order[i]][j];
				if (i < n - 1) {
					mnr[i][j] = min(mnr[i][j], mnr[i + 1][j]);
				}
				if (j < m - 1) {
					mnr[i][j] = min(mnr[i][j], mnr[i][j + 1]);
				}
			}
		}
		vector<int> mnl(m, mod), mxr(m, -mod);
		pair<int, int> ans(-1, -1);
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				mnl[j] = min(mnl[j], a[order[i]][j]);
				if (j > 0) {
					mnl[j] = min(mnl[j], mnl[j - 1]);
				}
			}
			for (int j = m - 1; j >= 0; j--) {
				mxr[j] = max(mxr[j], a[order[i]][j]);
				if (j < m - 1) {
					mxr[j] = max(mxr[j], mxr[j + 1]);
				}
			}
			for (int j = 0; j < m - 1; j++) {
				if (mnl[j] > mxl[i + 1][j] && mxr[j + 1] < mnr[i + 1][j + 1]) {
					ans = { i, j };
				}
			}
		}
		if (ans.first == -1) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		string res(n, 'R');
		for (int i = 0; i < n; i++) {
			res[order[i]] = i <= ans.first ? 'R' : 'B';
		}
		printf("%s %d\n", res.c_str(), ans.second + 1);
	}
	return 0;
}
