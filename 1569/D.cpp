#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int T;
int n, m, k;
int x[maxn], y[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &y[i]);
        }
        map<int, int> px, py;
        map<pair<int, int>, int> pxy, pyx;
        long long ans = 0;
        while (k--) {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            int pos_x = lower_bound(x + 1, x + n + 1, xx) - x;
            int pos_y = lower_bound(y + 1, y + m + 1, yy) - y;
            if (x[pos_x] == xx && y[pos_y] == yy) {
                continue;
            } else if (x[pos_x] == xx) {
                ans += py[pos_y] - pxy[make_pair(pos_x, pos_y)];
                ++py[pos_y];
                ++pxy[make_pair(pos_x, pos_y)];
            } else if (y[pos_y] == yy) {
                ans += px[pos_x] - pyx[make_pair(pos_y, pos_x)];
                ++px[pos_x];
                ++pyx[make_pair(pos_y, pos_x)];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

