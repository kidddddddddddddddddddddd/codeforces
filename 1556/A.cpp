#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int T;
long long c, d;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d",&T);
    while (T--) {
        scanf("%lld%lld", &c, &d);
        if (abs(c - d) & 1) {
            printf("-1\n");
            continue;
        }
        if (c == d) {
            printf("%d\n", c == 0 ? 0 : 1);
            continue;
        }
        printf("2\n");
    }
    return 0;
}

