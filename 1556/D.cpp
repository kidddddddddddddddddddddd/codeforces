#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e4 + 7;

int n, k;
int a[maxn];

int get_or(int i, int j) {
    int ans = -1;
    printf("or %d %d\n", i, j);
    fflush(stdout);
    scanf("%d", &ans);
    return ans;
}

int get_and(int i, int j) {
    int ans = -1;
    printf("and %d %d\n", i, j);
    fflush(stdout);
    scanf("%d", &ans);
    return ans;
}

int calc(int j) {
    int sum_and = get_and(1, j);
    int sum_or = get_or(1, j);
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        if ((a[1] >> i) & 1) {
            if ((sum_and >> i) & 1) {
                ans |= (1 << i);
            }
        } else {
            if ((sum_or >> i) & 1) {
                ans |= (1 << i);
            }
        }
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);

    int a12 = get_and(1, 2) + get_or(1, 2);
    int a23 = get_and(2, 3) + get_or(2, 3);
    int a13 = get_and(1, 3) + get_or(1, 3);

    a[2] = (a12 + a23 - a13) / 2;
    a[1] = a12 - a[2];
    a[3] = a13 - a[1];

    for (int i = 4; i <= n; i++) {
        a[i] = calc(i);
    }
    sort(a + 1, a + 1 + n);
    printf("finish %d\n", a[k]);
    fflush(stdout);
    return 0;
}

/*
 To solve this problem, we can use the fact that 𝑎+𝑏=(𝑎 or 𝑏)+(𝑎 and 𝑏).
 Then we can determine the first 3 numbers in 6 operations using the sums
 𝑎01=𝑎0+𝑎1, 𝑎12=𝑎1+𝑎2 and 𝑎02=𝑎0+𝑎2.
 Using the formula 𝑎1=𝑎01+𝑎12−𝑎02/2, 𝑎0=𝑎01−𝑎1 and 𝑎2=𝑎12−𝑎1.
 */
