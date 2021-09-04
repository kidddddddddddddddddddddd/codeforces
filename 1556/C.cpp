#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e3 + 7;

int n;
long long a[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    long long ans = 0;
    for (int l = 1; l <= n; l += 2) { //最左边的第一对
        if (a[l + 1] > a[l]) { //无法延续
            ans += a[l];
            continue;
        }
        ans += a[l+1];
        long long l_left = a[l] - a[l + 1];
        long long mid_left = 0;
        for (int nxt_l = l + 2; nxt_l <= n; nxt_l += 2) {
            if (a[nxt_l] > a[nxt_l + 1]) {
                mid_left += a[nxt_l] - a[nxt_l + 1];
                continue;
            }
            long long cur_right = a[nxt_l + 1] - a[nxt_l];
            if (cur_right < mid_left) {
                mid_left -= cur_right;
                continue;
            }
            cur_right -= mid_left;
            mid_left = 0;
            if(l_left>=cur_right){
                ans += cur_right +1;
                l_left -= cur_right;
            }else{
                ans += l_left +1;
                break;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}


