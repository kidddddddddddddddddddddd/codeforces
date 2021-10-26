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

int T;
int n, m;
int a[maxm], b[maxm], c[maxm], tmp[maxm];
int pos[maxm];

void solve(int l_a, int r_a, int l_b, int r_b)
{
	if (l_b > r_b) {
		return;
	}
	int mid = (l_b + r_b) >> 1;
	int cnt = 0;
	int min_val, idx;
	for (int i = l_a; i <= r_a; i++) {
		if (a[i] < b[mid]) {
			cnt++;
		}
	}
	min_val = cnt, idx = l_a;
	for (int i = l_a + 1; i <= r_a; i++) {
		if (a[i - 1] < b[mid]) {
			cnt--;
		}
		if (a[i - 1] > b[mid]) {
			cnt++;
		}
		if (cnt < min_val) {
			min_val = cnt;
			idx = i;
		}
	}
	pos[mid] = idx;
	solve(l_a, idx, l_b, mid - 1);
	solve(idx, r_a, mid + 1, r_b);
}

int bit_tree[maxm];

int lowbit(int x) { return x & (-x); }

void modify(int pos, int val)
{
	while (pos < maxm) {
		bit_tree[pos] += val;
		pos += lowbit(pos);
	}
}

int query(int pos)
{
	int res = 0;
	while (pos) {
		res += bit_tree[pos];
		pos -= lowbit(pos);
	}
	return res;
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
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d", &b[i]);
		}
		sort(b + 1, b + 1 + m);
		solve(1, n + 1, 1, m);
		int pos_b = 1;
		int tot = 0;
		for (int i = 1; i <= n + 1; i++) {
			while (pos_b <= m && pos[pos_b] == i) {
				c[++tot] = b[pos_b++];
			}
			if (i != n + 1) {
				c[++tot] = a[i];
			}
		}
		for (int i = 1; i <= tot; i++) {
			tmp[i] = c[i];
		}
		sort(tmp + 1, tmp + 1 + tot);
		for (int i = 1; i <= tot; i++) {
			c[i] = lower_bound(tmp + 1, tmp + 1 + tot, c[i]) - tmp;
		}
		// calc
		long long ans = 0;
		for (int i = 1; i <= tot; i++) {
			ans += query(2000000) - query(c[i]);
			modify(c[i], 1);
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= tot; i++) {
			modify(c[i], -1);
		}
	}
	return 0;
}
