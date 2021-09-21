#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int T;
int val[3];
int m;


int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 3; i++) {
            scanf("%d", &val[i]);
        }
        sort(val, val + 3);
        scanf("%d", &m);
        int low = max(val[2] - val[1] - val[0] - 1, 0), high = val[0] + val[1] + val[2] - 3;
        //cout<<low<<" "<<high<<" "<<m<<endl;
        printf("%s\n", (m >= low && m <= high) ? "YES" : "NO");
    }
    return 0;
}

