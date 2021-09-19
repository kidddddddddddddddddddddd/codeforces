#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int T;
int n;
int k;
vector<int> G[maxn];
int dp[maxn];
int inDeg[maxn];
queue<int> Q;
vector<int> seq;

void init() {
    seq.clear();
    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        inDeg[i] = 0;
    }
    while (!Q.empty()) {
        Q.pop();
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
            int k;
            scanf("%d", &k);
            while (k--) {
                int x;
                scanf("%d", &x);
                G[x].push_back(i);
                inDeg[i]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!inDeg[i]) {
                Q.push(i);
                seq.push_back(i);
            }
        }
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (int v: G[cur]) {
                if (--inDeg[v] == 0) {
                    Q.push(v);
                    seq.push_back(v);
                }
                if (v > cur) {
                    dp[v] = max(dp[v], dp[cur]);
                } else {
                    dp[v] = max(dp[v], dp[cur] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp[i]);
        }
        printf("%d\n", seq.size() == n ? ans : -1);
    }
    return 0;
}

