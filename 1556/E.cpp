#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;
const long long INF = 9223372036854775807;

int n, Q;
long long a[maxn], b[maxn];
long long pre[maxn];

struct node {
    int l, r;
    long long max_val, min_val;
} seg_tree[maxn << 2];

void push_up(int root) {
    seg_tree[root].max_val = max(seg_tree[root << 1].max_val, seg_tree[root << 1 | 1].max_val);
    seg_tree[root].min_val = min(seg_tree[root << 1].min_val, seg_tree[root << 1 | 1].min_val);
}

void build(int root, int l, int r) {
    seg_tree[root].l = l;
    seg_tree[root].r = r;
    if (l == r) {
        seg_tree[root].max_val = pre[l];
        seg_tree[root].min_val = pre[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
    push_up(root);
}

node query(int root, int l, int r) {
    node res{
            .l = l,
            .r = r,
            .max_val = -INF,
            .min_val = INF,
    };

    if (l <= seg_tree[root].l && seg_tree[root].r <= r) {
        res.max_val = seg_tree[root].max_val;
        res.min_val = seg_tree[root].min_val;
        return res;
    }

    int mid = (seg_tree[root].l + seg_tree[root].r) >> 1;

    if (l <= mid) {
        node l_res = query(root << 1, l, r);
        res.max_val = max(res.max_val, l_res.max_val);
        res.min_val = min(res.min_val, l_res.min_val);
    }
    if (r >= mid + 1) {
        node r_res = query(root << 1 | 1, l, r);
        res.max_val = max(res.max_val, r_res.max_val);
        res.min_val = min(res.min_val, r_res.min_val);
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &Q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = b[i] - a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + pre[i];
    }

    build(1, 1, n);
    while (Q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        node res = query(1, l, r);
        if (pre[r] - pre[l-1] != 0 || res.min_val - pre[l - 1] < 0) {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", res.max_val - pre[l - 1] >= 0 ? res.max_val - pre[l - 1] : -1);
    }
    return 0;
}

