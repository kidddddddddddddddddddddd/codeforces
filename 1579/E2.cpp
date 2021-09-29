#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;

int T;
int n;
int a[maxn], b[maxn];

int bit_tree[maxn];

int lowbit(int x) {
    return x & (-x);
}

void modify(int x, int val) {
    while (x <= n) {
        bit_tree[x] += val;
        x += lowbit(x);
    }
}

int query(int x) {
    int sum = 0;
    while (x) {
        sum += bit_tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

void init() {
    for (int i = 0; i <= n; i++) {
        bit_tree[i] = 0;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            // min(push_front,push_back)
            ans += min(query(1, a[i] - 1), query(a[i] + 1, n));
            modify(a[i], 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}


