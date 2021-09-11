#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;
const long long INF = 9223372036854775807;

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
        int ans_l = -1, ans_r = -1;
        for (int l = 1; l <= n; l++) {
            for (int r = l + 1; r <= n; r++) {
                int len = r - l + 1;
                int cnt_a = 0, cnt_b = 0;
                for (int k = l; k <= r; k++) {
                    cnt_a += s[k] == 'a';
                    cnt_b += s[k] == 'b';
                }
                if (cnt_a == len / 2 && cnt_b == len / 2) {
                    ans_l = l;
                    ans_r = r;
                }
            }
        }
        printf("%d %d\n", ans_l, ans_r);
    }
    return 0;
}

