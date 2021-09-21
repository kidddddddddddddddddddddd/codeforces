#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int T;
int n;


int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("(");
            }
            for (int j = 1; j <= i; j++) {
                printf(")");
            }
            for (int j = 1; j <= n - i; j++) {
                printf("(");
            }
            for (int j = 1; j <= n - i; j++) {
                printf(")");
            }
            printf("\n");
        }
    }
    return 0;
}

