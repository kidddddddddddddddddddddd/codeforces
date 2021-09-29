#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;

int T;
int n, m, k;

char pic[17][27];
bool is_ticked[17][27];

bool tick(int i, int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m && pic[i][j] == '*';
}

void paint(int i, int j, int d) {
    is_ticked[i][j] = true;
    for (int l = 1; l <= d; l++) {
        is_ticked[i - l][j - l] = true;
        is_ticked[i - l][j + l] = true;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        memset(is_ticked, 0, sizeof(is_ticked));
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%s", pic[i] + 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pic[i][j] == '*') {
                    int l_len = 0, r_len = 0;
                    //top_left
                    for (int d = 1; d <= min(n, m); d++) {
                        if (tick(i - d, j - d)) {
                            l_len = d;
                        } else {
                            break;
                        }
                    }
                    //top_right
                    for (int d = 1; d <= min(n, m); d++) {
                        if (tick(i - d, j + d)) {
                            r_len = d;
                        } else {
                            break;
                        }
                    }
                    int d = min(l_len, r_len);
                    if (d < k) {
                        continue;
                    }
                    paint(i, j, d);
                }
            }
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pic[i][j] == '*' && (!is_ticked[i][j])) {
                    ok = false;
                }
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}


