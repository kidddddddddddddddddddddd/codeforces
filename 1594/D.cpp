#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
int n, m;
vector<int> G[maxn];

int tot;
int color[maxn];
int cnt[2];
bool ok;
int ans;

void init() {
    for (int i = 1; i <= n + m; i++) {
        G[i].clear();
        color[i] = -1;
    }
    tot = n;
    ok = true;
    ans = 0;
}

void dfs(int cur) {
    if (cur <= n) {
        cnt[color[cur]]++;
    }
    for (int x: G[cur]) {
        if (color[x] != -1 && color[x] == color[cur]) {
            ok = false;
            return;
        }
        if (color[x] != -1) {
            continue;
        }
        color[x] = color[cur] ^ 1;
        dfs(x);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i <= m; i++) {
            int u, v;
            char s[10];
            scanf("%d %d %s", &u, &v, s);
            if (s[0] == 'i') {
                G[u].push_back(v);
                G[v].push_back(u);
            } else {
                ++tot;
                G[u].push_back(tot);
                G[tot].push_back(u);
                G[v].push_back(tot);
                G[tot].push_back(v);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                memset(cnt, 0, sizeof(cnt));
                color[i] = 0;
                dfs(i);
                ans += max(cnt[0], cnt[1]);
            }
        }
        printf("%d\n", ok ? ans : -1);
        
    }
    return 0;
}
