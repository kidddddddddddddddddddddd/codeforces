#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int n;
int a[maxn];
int len;
int val[maxn], pre_xor[maxn];

void solve(int k) {
    //init
    unordered_map<int, int> mp[2];
    mp[0][pre_xor[0]] = 0;
    int min_l = 1;
    for (int r = 1; r <= n; r++) {
        bool flag = (a[r] >> k) & 1;
        if (!flag) {
            min_l = r + 1;
        }

        if (mp[r & 1].count(pre_xor[r])) {
            if (mp[r & 1][pre_xor[r]] < min_l - 1) {
                mp[r & 1][pre_xor[r]] = r;
            }
        } else {
            mp[r & 1][pre_xor[r]] = r;
        }

        if (r & 1) { //(l-1)&1
            if (!mp[1].count(pre_xor[r])) {
                continue;
            }
            int it = mp[1][pre_xor[r]];
            if (it >= min_l - 1) {
                len = max(len, r - it);
            }
        } else {
            if (!mp[0].count(pre_xor[r])) {
                continue;
            }
            int it = mp[0][pre_xor[r]];
            if (it >= min_l - 1) {
                len = max(len, r - it);
            }
        }

    }
    //post processor
    for (int i = 1; i <= n; i++) {
        val[i] |= (1 << k) & a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre_xor[i] = pre_xor[i - 1] ^ val[i];
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int k = 20; k >= 0; k--) {
        solve(k);
    }
    printf("%d\n", len);
    return 0;
}
