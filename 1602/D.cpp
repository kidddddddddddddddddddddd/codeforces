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

const int maxn = 3e5 + 7;
const int maxm = 1e6 + 7;

int n;
int a[maxn], b[maxn];
int dis[maxn], pre[maxn];
queue<int> Q;

void print(int x)
{
	if (x >= n) {
		return;
	}
	print(pre[x]);
	printf("%d ", x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	int min_h = n;
	Q.push(n);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if (cur == 0) {
			printf("%d\n", dis[cur]);
			print(0);
			printf("\n");
			return 0;
		}
		int dist = cur + b[cur];
		for (int i = min(dist - 1, min_h - 1); i >= dist - a[dist]; i--) {
			dis[i] = dis[cur] + 1;
			pre[i] = cur;
			Q.push(i);
		}
		min_h = min(min_h, dist - a[dist]);
	}
	printf("-1\n");
	return 0;
}
