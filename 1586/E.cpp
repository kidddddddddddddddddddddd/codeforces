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
const int maxm = 2e6 + 7;

int n, m;
int Q;
int X[maxn], Y[maxn];
int cnt[maxn];

int fa[maxn];
vector<int> G[maxn];

void init()
{
	for (int i = 0; i < maxn; i++) {
		fa[i] = i;
	}
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }

vector<int> tmp_ans;
vector<int> ans;

void dfs(int from, int pre, int to)
{
	tmp_ans.push_back(from);
	if (from == to) {
		ans = tmp_ans;
		return;
	}
	for (int v : G[from]) {
		if (v == pre) {
			continue;
		}
		dfs(v, from, to);
	}
	tmp_ans.pop_back();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	init();
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y);
		if (find(x) != find(y)) {
			G[x].push_back(y);
			G[y].push_back(x);
			merge(x, y);
		}
	}

	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%d%d", &X[i], &Y[i]);
		cnt[X[i]]++;
		cnt[Y[i]]++;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += cnt[i] & 1;
	}
	if (sum) {
		printf("NO\n");
		printf("%d\n", sum / 2);
		return 0;
	}
	printf("YES\n");
	for (int i = 1; i <= Q; i++) {
		tmp_ans.clear();
		ans.clear();
		dfs(X[i], 0, Y[i]);
		printf("%d\n", ans.size());
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}
