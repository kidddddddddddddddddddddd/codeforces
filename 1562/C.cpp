#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;

int T;
int n;
char s[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        bool ok = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                if (i <= n / 2) {
                    ok = 1;
                    printf("%d %d %d %d\n", i, n, i + 1, n);
                } else {
                    ok = 1;
                    printf("%d %d %d %d\n", 1, i, 1, i - 1);
                }
                break;
            }
        }
        if (!ok) { //all 1
            int l1 = 1, r1 = n / 2;
            printf("%d %d %d %d\n", l1, r1, (n % 2) == 1 ? r1 + 2 : r1 + 1, n);
        }
    }
    return 0;
}

