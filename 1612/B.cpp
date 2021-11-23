#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;
int n, a, b;
bool vis[107];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &a, &b);
		memset(vis, 0, sizeof(vis));
		vector<int> left, right;
		left.push_back(a);
		vis[a] = true;
		right.push_back(b);
		vis[b] = true;
		for (int i = 1; i <= n; i++) {
			if (i == a || i == b) {
				continue;
			}
			if (i > b) { // must left
				left.push_back(i);
				vis[i] = 1;
				continue;
			}
			if (i < a) { // must right
				right.push_back(i);
				vis[i] = 1;
				continue;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i]) {
				continue;
			}
			if (left.size() < n / 2) {
				left.push_back(i);
				vis[i] = 1;
				continue;
			}
			if (right.size() < n / 2) {
				right.push_back(i);
				vis[i] = 1;
				continue;
			}
		}
		sort(left.begin(), left.end());
		sort(right.begin(), right.end());
		if (left.size() == n / 2 && right.size() == n / 2 && left[0] == a && right[n / 2 - 1] == b) {
			for (int x : left) {
				printf("%d ", x);
			}
			for (int x : right) {
				printf("%d ", x);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
