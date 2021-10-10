/*
 * We have an array 𝑎 of length 𝑛 where every element of it is a positive integer and the sum of the whole array is 𝑠.
 * If no matter how we construct the array 𝑎, we can find a non-zero length subarray which has sum equal to 𝑘
 * print "YES" else print "NO".
 *
 * 1,1,1,1,...𝑘+1,1,1,1,...𝑘+1,1,1,1
 */
#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;


const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
long long s, n, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &s, &n, &k);
        if (n < k) {
            if (s == k) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            continue;
        }
        long long sum = n / k * 2 * k + n % k;
        printf("%s\n", s < sum ? "YES" : "NO");
    }
    return 0;
}
