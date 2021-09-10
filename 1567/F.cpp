#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5e2 + 7;
//l u r d
const int dx[] = {0, 0, -1, 0, 1}, dy[] = {0, -1, 0, 1, 0};
int n, m;
char pic[maxn][maxn];

int idx(int x, int y) {
    return (x - 1) * m + y;
}

bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && pic[x][y] == '.';
}

vector<int> G[maxn * maxn];
int color[maxn * maxn];

int fail_now;

void dfs(int x, int val) {
    color[x] = val;
    for (int v: G[x]) {
        if (!color[v]) {
            dfs(v, 5 - val);
        }
        if (color[v] == color[x]) {
            fail_now = 1;
        }
        if (fail_now) {
            return;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", pic[i] + 1);
    }
    //build graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pic[i][j] == 'X') {
                vector<int> nodes;
                for (int k = 1; k <= 4; k++) {
                    if (check(i + dx[k], j + dy[k])) {
                        nodes.push_back(idx(i + dx[k], j + dy[k]));
                    }
                }
                if (nodes.size() & 1) {
                    printf("NO\n");
                    return 0;
                }
                if (nodes.size() == 2) {
                    G[nodes[0]].push_back(nodes[1]);
                    G[nodes[1]].push_back(nodes[0]);
                }
                if (nodes.size() == 4) {
                    G[nodes[0]].push_back(nodes[1]);
                    G[nodes[1]].push_back(nodes[0]);

                    G[nodes[0]].push_back(nodes[3]);
                    G[nodes[3]].push_back(nodes[0]);

                    G[nodes[2]].push_back(nodes[1]);
                    G[nodes[1]].push_back(nodes[2]);

                    G[nodes[2]].push_back(nodes[3]);
                    G[nodes[3]].push_back(nodes[2]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pic[i][j] == '.' && !color[idx(i, j)]) {
                dfs(idx(i, j), 1);
            }
        }
    }

    if (fail_now) {
        printf("NO\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pic[i][j] == 'X') {
                for (int k = 1; k <= 4; k++) {
                    if (pic[i + dx[k]][j + dy[k]] == '.') {
                        color[idx(i, j)] += color[idx(i + dx[k], j + dy[k])];
                    }
                }
            }
        }
    }

    printf("YES\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",color[idx(i,j)]);
        }
        printf("\n");
    }
    return 0;
}

