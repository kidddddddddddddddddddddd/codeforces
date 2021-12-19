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
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int n, Q;
char s[maxn];

struct node {
	int l, r;
	int a, b, c;
	int ab, bc;
	int abc;
} seg_tree[maxn << 2];

void push_up(int root)
{
	seg_tree[root].a = seg_tree[root << 1].a + seg_tree[root << 1 | 1].a;
	seg_tree[root].b = seg_tree[root << 1].b + seg_tree[root << 1 | 1].b;
	seg_tree[root].c = seg_tree[root << 1].c + seg_tree[root << 1 | 1].c;
	seg_tree[root].ab = min(seg_tree[root << 1].a + seg_tree[root << 1 | 1].ab,
			seg_tree[root << 1].ab + seg_tree[root << 1 | 1].b);
	seg_tree[root].bc = min(seg_tree[root << 1].b + seg_tree[root << 1 | 1].bc,
			seg_tree[root << 1].bc + seg_tree[root << 1 | 1].c);
	seg_tree[root].abc = min(seg_tree[root << 1].ab + seg_tree[root << 1 | 1].bc,
			min(seg_tree[root << 1].abc + seg_tree[root << 1 | 1].c,
					seg_tree[root << 1].a + seg_tree[root << 1 | 1].abc));
}

void build(int root, int l, int r)
{
	seg_tree[root].l = l;
	seg_tree[root].r = r;
	int mid = (l + r) >> 1;
	if (l == r) {
		seg_tree[root].a = s[mid] == 'a';
		seg_tree[root].b = s[mid] == 'b';
		seg_tree[root].c = s[mid] == 'c';
		return;
	}
	build(root << 1, l, mid);
	build(root << 1 | 1, mid + 1, r);
	push_up(root);
}

void update(int root, int idx, char c)
{
	int mid = (seg_tree[root].l + seg_tree[root].r) >> 1;
	if (seg_tree[root].l == seg_tree[root].r) {
		s[mid] = c;
		seg_tree[root].a = s[mid] == 'a';
		seg_tree[root].b = s[mid] == 'b';
		seg_tree[root].c = s[mid] == 'c';
		return;
	}
	if (idx <= mid) {
		update(root << 1, idx, c);
	}
	if (idx > mid) {
		update(root << 1 | 1, idx, c);
	}
	push_up(root);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d%d", &n, &Q);
	scanf("%s", s + 1);
	build(1, 1, n);
	int idx;
	char c[5];
	while (Q--) {
		scanf("%d", &idx);
		scanf("%s", c);
		update(1, idx, c[0]);
		printf("%d\n", seg_tree[1].abc);
	}
	return 0;
}
