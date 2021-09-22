#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;

int T;
long long l, r;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &l, &r);
        long long a = r, b = max(a / 2 + 1, l);
        //cout << a << " " << b << endl;
        printf("%lld\n", a % b);
    }
    return 0;
}

