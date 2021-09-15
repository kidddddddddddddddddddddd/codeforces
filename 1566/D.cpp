#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int T;
int n, m;
struct node {
    int val, idx;
} a[maxn];

bool cmp1(node x, node y) {
    if (x.val == y.val) {
        return x.idx < y.idx;
    }
    return x.val < y.val;
}

bool cmp2(node x, node y) {
    if (x.val == y.val) {
        return x.idx > y.idx;
    }
    return x.val < y.val;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n * m; i++) {
            scanf("%d", &a[i].val);
            a[i].idx = i;
        }
        sort(a + 1, a + 1 + n * m, cmp1);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int l = (i - 1) * m + 1, r = i * m;
            sort(a + l, a + r + 1, cmp2);
            for (int j = l; j <= r; j++) {
                for (int k = l; k < j; k++) {
                    if (a[k].idx < a[j].idx) {
                        ans++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

