#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 3e5 + 7;

int T;
int n;
int a[maxn], b[maxn];

bool is_sorted() {
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void iteration(int t) {
    if (t & 1) {
        for (int i = 1; i <= n - 2; i += 2) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
    } else {
        for (int i = 2; i <= n - 1; i += 2) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        int ans = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (is_sorted()) {
                break;
            }
            ans++;
            iteration(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}


