#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;
const long long INF = 9223372036854775807;

int T;
int n;
char s[57];
char ans[57][57];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans[i][j] = '.';
            }
        }
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                for (int j = 1; j <= n; j++) {
                    ans[i][j] = '=';
                    ans[j][i] = '=';
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            ans[i][i] = 'X';
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '2') {
                int cnt = 0;
                for (int j = 1; j <= n; j++) {
                    if (ans[i][j] == '.') {
                        cnt++;
                        ans[i][j] = '+';
                        ans[j][i] = '-';
                        break;
                    }
                }
                if (cnt == 0) {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) {
            printf("NO\n");
        } else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (ans[i][j] == '.') {
                        ans[i][j] = '=';
                    }
                }
            }
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    printf("%c", ans[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

