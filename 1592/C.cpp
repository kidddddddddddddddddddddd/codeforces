#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
int n, k;
int a[maxn];
int xor_sum[maxn]; //以i为子树的异或和
int dep[maxn];
int pre_node[maxn]; //父节点 定向
bool deleted[maxn]; //删除节点
vector<int> G[maxn];

void init_graph() {
    for (int i = 0; i <= n; i++) {
        G[i].clear();
        pre_node[i] = 0;
        deleted[i] = false;
        dep[i] = 0;
    }
}

void init_prefix() {
    for (int i = 0; i <= n; i++) {
        xor_sum[i] = 0;
    }
}

void get_fa(int cur, int fa) {
    pre_node[cur] = fa;
    dep[cur] = dep[fa] + 1;
    for (int nxt: G[cur]) {
        if (nxt == fa) {
            continue;
        }
        get_fa(nxt, cur);
    }
}

void delete_sub_tree(int cur) {
    deleted[cur] = true;
    for (int nxt: G[cur]) {
        if (nxt == pre_node[cur]) {
            continue;
        }
        delete_sub_tree(nxt);
    }
}

void dfs_sum(int cur) {
    xor_sum[cur] = a[cur];
    for (int nxt: G[cur]) {
        if (nxt == pre_node[cur] || deleted[nxt]) {
            continue;
        }
        dfs_sum(nxt);
        xor_sum[cur] ^= xor_sum[nxt];
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        init_graph();
        init_prefix();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1, u, v; i < n; i++) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        get_fa(1, 0);

        dfs_sum(1);

        if (xor_sum[1] == 0) {
            printf("YES\n");
            continue;
        }
        if (k == 2) {
            printf("NO\n");
            continue;
        }
        int sum = xor_sum[1];

        int first_node = 0;
        for (int i = 2; i <= n; i++) {
            if (xor_sum[i] == sum && dep[i] >= dep[first_node]) {
                first_node = i;
            }
        }
        delete_sub_tree(first_node);
        init_prefix();
        dfs_sum(1);
        int second_node = 0;
        for (int i = 2; i <= n; i++) {
            if (deleted[i]) {
                continue;
            }
            if (xor_sum[i] == sum) {
                second_node = i;
                break;
            }
        }
        printf("%s\n", ((first_node == 0) || (second_node == 0)) ? "NO" : "YES");
    }
    return 0;
}
