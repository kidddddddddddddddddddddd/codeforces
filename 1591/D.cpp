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
int n;
int a[maxn];
bool vis[maxn];
int bit_tree[maxn];

void init()
{
	for (int i = 0; i <= n; i++) {
		bit_tree[i] = 0;
		vis[i] = 0;
	}
}

int lowbit(int x) { return x & (-x); }
void modify(int x)
{
	while (x <= n) {
		bit_tree[x]++;
		x += lowbit(x);
	}
}

int query(int x)
{
	int res = 0;
	while (x) {
		res += bit_tree[x];
		x -= lowbit(x);
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		init();
		bool has_same = false;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (vis[a[i]]) {
				has_same = true;
			}
			vis[a[i]] = 1;
		}
		if (has_same) {
			printf("YES\n");
			continue;
		}
		long long cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += query(n) - query(a[i]);
			modify(a[i]);
		}
		printf("%s\n", cnt & 1 ? "NO" : "YES");
	}
	return 0;
}
