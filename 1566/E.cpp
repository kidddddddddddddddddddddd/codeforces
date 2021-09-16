#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int T;
int n;
vector<int> G[maxn];
int type[maxn];

void init() {
    for (int i = 0; i <= n; i++) {
        G[i].clear();
    }
    for (int i = 0; i <= n; i++) {
        type[i] = -1;
    }
}

void dfs(int cur, int fa) {
    bool leaves = false;
    for (int v: G[cur]) {
        if (v == fa) {
            continue;
        }
        dfs(v, cur);
        leaves |= (type[v] == 1);
    }
    if (fa != 0) {
        if (!leaves) {
            type[cur] = 1;
        } else {
            type[cur] = 2;
        }
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
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        type[1] = 0;
        dfs(1, 0);
        bool root_leaf = false;
        for (int v: G[1]) {
            root_leaf |= (type[v] == 1);
        }
        int k = 0;
        for (int i = 1; i <= n; i++) {
            k += (type[i] == 2);
        }
        printf("%d\n", n - 2 * k - root_leaf);
    }
    return 0;
}

