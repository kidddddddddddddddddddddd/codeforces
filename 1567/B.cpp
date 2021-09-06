#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 3e5 + 7;

int T;
int a, b;
int pre_xor[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    for (int i = 1; i <= 300000; i++) {
        pre_xor[i] = i ^ pre_xor[i - 1];
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &a, &b);
        if (pre_xor[a - 1] == b) {
            printf("%d\n", a);
            continue;
        }
        int x = b ^ pre_xor[a - 1];
        if (x == a) {
            printf("%d\n", a + 2);
            continue;
        }
        printf("%d\n", a + 1);
    }
    return 0;
}

