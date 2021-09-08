#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 3e5 + 7;

int T;
int s, n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &s, &n);
        while (n--) {
            if (!n) {
                printf("%d\n", s);
            } else {
                int p = pow(10, (int) log10(s - n));
                printf("%d ", p);
                s -= p;
            }
        }
    }
    return 0;
}

