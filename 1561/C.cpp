#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 3e5 + 7;

int T;
int n;
vector<int> caves[maxn];

void init() {
    for (int i = 1; i <= n; i++) {
        caves[i].clear();
    }
}

bool check(int mid) {
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 0; j < caves[i].size(); j++) {
            int val = caves[i][j] - j;
            tmp = max(tmp, val + 1);
        }
        //打cave[i]的时候能力必须有tmp
        v.emplace_back(tmp, caves[i].size());
    }
    sort(v.begin(), v.end());
    int cur = mid;
    for (auto &i: v) {
        if (cur < i.first) {
            return false;
        }
        cur += i.second;
    }
    return true;
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
        for (int i = 1, k, x; i <= n; i++) {
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &x);
                caves[i].push_back(x);
            }
        }

        int ans = 1e9 + 7;
        int l = 1, r = 1e9 + 7;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid - 1;
                ans = min(ans, mid);
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}


