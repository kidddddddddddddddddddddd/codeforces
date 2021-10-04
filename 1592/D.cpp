#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int n;
vector<int> G[maxn];
int fa[maxn];
int max_val;
vector<int> euler_order;
int ans_node;

void dfs(int cur, int pre_node) {
    euler_order.push_back(cur);
    fa[cur] = pre_node;
    for (int nxt: G[cur]) {
        if (nxt == pre_node) {
            continue;
        }
        dfs(nxt, cur);
        euler_order.push_back(cur);
    }
}

int query(int pos) {
    set<int> s;
    for (int i = 0; i <= pos; i++) {
        s.insert(euler_order[i]);
    }
    printf("? %d", s.size());
    for (int x: s) {
        printf(" %d", x);
    }
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    max_val = query(euler_order.size() - 1);
    int l = 0, r = euler_order.size() - 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        int x = query(mid);
        if (x == max_val) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("! %d %d\n", euler_order[l], euler_order[r]);
    fflush(stdout);
    return 0;
}
