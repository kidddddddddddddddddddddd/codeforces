#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;

int T;
int n;
int a[maxn];
vector<int> ans;


void solve(int len) {
    if (len == 1) {
        return;
    }
    for (int i = 1; i <= len; i++) {
        if (a[i] == len) {
            ans.push_back(i);
            reverse(a + 1, a + i + 1);
            break;
        }
    }
    for (int i = 1; i <= len; i++) {
        if (a[i] == len - 1) {
            ans.push_back(i - 1);
            reverse(a + 1, a + i);
            break;
        }
    }
    for (int i = 1; i <= len; i++) {
        if (a[i] == len - 1) {
            ans.push_back(i + 1);
            reverse(a + 1, a + i + 1 + 1);
            break;
        }
    }
    for (int i = 1; i <= len; i++) {
        if (a[i] == len) {
            ans.push_back(i);
            reverse(a + 1, a + i + 1);
            break;
        }
    }
    ans.push_back(len);
    reverse(a + 1, a + len + 1);

    solve(len - 2);
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
        ans.clear();
        bool can_not = false;
        for (int i = 1; i <= n; i++) {
            can_not |= (a[i] & 1) ^ (i & 1);
        }
        if (can_not) {
            printf("-1\n");
            continue;
        }
        solve(n);

        printf("%d\n", ans.size());
        for (int x: ans) {
            printf("%d ", x);
        }
        printf("\n");

    }
    return 0;
}


