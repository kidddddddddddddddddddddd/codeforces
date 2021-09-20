#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int T;
int n;
int a[maxn];
int pre[maxn], suf[maxn];

//(r-l+1)&1
vector<int> solve(int l, int r) {
    vector<int> res;
    for (int i = l; i <= r - 2; i += 2) {
        res.push_back(i);
    }
    for (int i = r - 4; i >= l; i -= 2) {
        res.push_back(i);
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        pre[0] = 0;
        suf[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = a[i] ^ pre[i - 1];
        }
        for (int i = n; i >= 1; i--) {
            suf[i] = a[i] ^ suf[i + 1];
        }
        if (pre[n] != 0) {
            printf("NO\n");
            continue;
        }
        vector<int> ans;
        if (n & 1) {
            ans = solve(1, n);
        } else {
            int mid = 0;
            for (int i = 1; i <= n - 1; i++) {
                if (pre[i] == 0 && suf[i + 1] == 0 && i % 2 == 1) {
                    mid = i;
                    break;
                }
            }
            if (mid == 0) {
                printf("NO\n");
                continue;
            }
            vector<int> ans_l = solve(1, mid);
            vector<int> ans_r = solve(mid + 1, n);
            ans.insert(ans.end(), ans_l.begin(), ans_l.end());
            ans.insert(ans.end(), ans_r.begin(), ans_r.end());
        }
        printf("YES\n");
        printf("%d\n", ans.size());
        for (int x: ans) {
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}

