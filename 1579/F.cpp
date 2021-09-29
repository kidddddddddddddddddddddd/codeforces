#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e6 + 7;

int T;
int n, d;
int a[maxn];
int cnt[maxn];

int dfs(int cur) {
    if (a[cur] == 0) {
        return 0;
    }
    if (cnt[cur] != -1) {
        return cnt[cur];
    }
    cnt[cur] = dfs((cur + d) % n) + 1;
    return cnt[cur];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &d);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            cnt[i] = -1;
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                continue;
            }
            cnt[i] = 0;
            ans = max(ans, dfs((i + d) % n));
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == -1) {
                ok = false;
            }
        }
        printf("%d\n", ok ? ans : -1);
    }
    return 0;
}


