#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
long long n, m, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &n, &m, &k);
        long long low = n - 1, high = n * (n - 1) / 2;
        if (n == 1) {
            if (m == 0 && k > 1) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            continue;
        }
        if (m < low || m > high) {
            printf("NO\n");
            continue;
        }
        if (m == high) {
            if (k >= 3) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            continue;
        }
        if (k >= 4) {
            if (m >= low && m <= high) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else if (k == 3) {
            if (m == high) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

