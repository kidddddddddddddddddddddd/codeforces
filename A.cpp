#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5e2 + 7;

int T;
long long n, s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &s);
        if (n & 1) {
            printf("%lld\n", s / (n - (n / 2)));
        } else {
            printf("%lld\n", s / (n - ((n / 2) - 1)));
        }
    }
    return 0;
}

