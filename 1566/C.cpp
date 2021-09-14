#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;

int T;
int n;
char a[maxn], b[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", a + 1);
        scanf("%s", b + 1);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                ans += 2;
                continue;
            }
            if (i + 1 <= n && a[i + 1] == b[i + 1] && a[i] != a[i + 1]) {
                ans += 2;
                i++;
                continue;
            }
            if (a[i] == '0') {
                ans += 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

