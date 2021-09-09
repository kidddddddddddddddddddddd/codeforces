#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;

int n, Q;
int a[maxn];

//non-decreasing array len
struct node {
    int l, r;
    long long total_cnt, leftmost_node_val, rightmost_node_val, leftmost_non_dec_len, rightmost_non_dec_len;
} seg_tree[maxn << 2];

void push_up(int root) {
    seg_tree[root].l = seg_tree[root << 1].l;
    seg_tree[root].r = seg_tree[root << 1 | 1].r;
    seg_tree[root].total_cnt = seg_tree[root << 1].total_cnt + seg_tree[root << 1 | 1].total_cnt;
    seg_tree[root].leftmost_node_val = seg_tree[root << 1].leftmost_node_val;
    seg_tree[root].rightmost_node_val = seg_tree[root << 1 | 1].rightmost_node_val;
    seg_tree[root].leftmost_non_dec_len = seg_tree[root << 1].leftmost_non_dec_len;
    seg_tree[root].rightmost_non_dec_len = seg_tree[root << 1 | 1].rightmost_non_dec_len;

    if (seg_tree[root << 1].rightmost_node_val <= seg_tree[root << 1 | 1].leftmost_node_val) {
        seg_tree[root].total_cnt +=
                seg_tree[root << 1].rightmost_non_dec_len * seg_tree[root << 1 | 1].leftmost_non_dec_len;
    }
    if (seg_tree[root << 1].leftmost_non_dec_len == (seg_tree[root << 1].r - seg_tree[root << 1].l + 1) &&
        seg_tree[root << 1].rightmost_node_val <= seg_tree[root << 1 | 1].leftmost_node_val) {
        seg_tree[root].leftmost_non_dec_len =
                seg_tree[root << 1].leftmost_non_dec_len + seg_tree[root << 1 | 1].leftmost_non_dec_len;
    }
    if (seg_tree[root << 1 | 1].rightmost_non_dec_len == (seg_tree[root << 1 | 1].r - seg_tree[root << 1 | 1].l + 1) &&
        seg_tree[root << 1].rightmost_node_val <= seg_tree[root << 1 | 1].leftmost_node_val) {
        seg_tree[root].rightmost_non_dec_len =
                seg_tree[root << 1 | 1].rightmost_non_dec_len + seg_tree[root << 1].rightmost_non_dec_len;
    }
}

node merge(node l_node, node r_node) {
    node res;
    res.l = l_node.l;
    res.r = r_node.r;
    res.total_cnt = l_node.total_cnt + r_node.total_cnt;
    res.leftmost_node_val = l_node.leftmost_node_val;
    res.rightmost_node_val = r_node.rightmost_node_val;
    res.leftmost_non_dec_len = l_node.leftmost_non_dec_len;
    res.rightmost_non_dec_len = r_node.rightmost_non_dec_len;

    if (l_node.rightmost_node_val <= r_node.leftmost_node_val) {
        res.total_cnt +=
                l_node.rightmost_non_dec_len * r_node.leftmost_non_dec_len;
    }
    if (l_node.leftmost_non_dec_len == (l_node.r - l_node.l + 1) &&
        l_node.rightmost_node_val <= r_node.leftmost_node_val) {
        res.leftmost_non_dec_len =
                l_node.leftmost_non_dec_len + r_node.leftmost_non_dec_len;
    }
    if (r_node.rightmost_non_dec_len == (r_node.r - r_node.l + 1) &&
        l_node.rightmost_node_val <= r_node.leftmost_node_val) {
        res.rightmost_non_dec_len =
                r_node.rightmost_non_dec_len + l_node.rightmost_non_dec_len;
    }
    return res;
}

void build(int root, int l, int r) {
    if (l == r) {
        seg_tree[root].l = l;
        seg_tree[root].r = r;
        seg_tree[root].total_cnt = 1;
        seg_tree[root].leftmost_non_dec_len = 1;
        seg_tree[root].rightmost_non_dec_len = 1;
        seg_tree[root].leftmost_node_val = a[l];
        seg_tree[root].rightmost_node_val = a[r];
        return;
    }
    int mid = (l + r) >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
    push_up(root);
}

//a[x]-->y
void modify(int root, int x, int y) {
    if (seg_tree[root].l == x && x == seg_tree[root].r) {
        seg_tree[root].l = x;
        seg_tree[root].r = x;
        seg_tree[root].total_cnt = 1;
        seg_tree[root].leftmost_non_dec_len = 1;
        seg_tree[root].rightmost_non_dec_len = 1;
        seg_tree[root].leftmost_node_val = y;
        seg_tree[root].rightmost_node_val = y;
        return;
    }
    int mid = (seg_tree[root].l + seg_tree[root].r) >> 1;
    if (x <= mid) {
        modify(root << 1, x, y);
    }
    if (x > mid) {
        modify(root << 1 | 1, x, y);
    }
    push_up(root);
}

node query(int root, int l, int r) {
    if (l <= seg_tree[root].l && seg_tree[root].r <= r) {
        return seg_tree[root];
    }
    int mid = (seg_tree[root].l + seg_tree[root].r) >> 1;
    if (l <= mid && r > mid) {
        return merge(query(root << 1, l, r), query(root << 1 | 1, l, r));
    } else if (r <= mid) {
        return query(root << 1, l, r);
    } else if (l > mid) {
        return query(root << 1 | 1, l, r);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &Q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    while (Q--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            modify(1, x, y);
        } else {
            node res = query(1, x, y);
            printf("%lld\n", res.total_cnt);
        }
    }
    return 0;
}

