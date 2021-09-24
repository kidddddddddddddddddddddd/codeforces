#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 3e5 + 7;

int T;
int n, Q;
char s[maxn];
int pre[maxn];
map<int, set<int> > table;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &Q);
        scanf("%s", s + 1);
        table.clear();
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (((i & 1) == (s[i] == '+')) ? 1 : -1);
            table[pre[i - 1] + pre[i]].insert(i);
        }

        while (Q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            if (pre[r] - pre[l - 1]) {
                if ((r - l) & 1) {
                    printf("2\n");
                    printf("%d ", r);
                    r--;
                } else {
                    printf("1\n");
                }
                printf("%d\n", *table[pre[r] + pre[l - 1]].lower_bound(l));
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}


