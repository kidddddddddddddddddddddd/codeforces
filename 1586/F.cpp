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

const int maxn = 1e3 + 7;
const int maxm = 2e6 + 7;

int n, k;
int col[maxn][maxn];
int ans;

int calc(int x, int y)
{
	int res = 0, cur = 1;
	while (x != 0 || y != 0) {
		if (x % k != y % k) {
			res = cur;
		}
		cur++;
		x /= k;
		y /= k;
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int color = calc(i - 1, j - 1);
			ans = max(ans, color);
			col[i][j] = color;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			printf("%d ", col[i][j]);
		}
	}
	printf("\n");
	return 0;
}
