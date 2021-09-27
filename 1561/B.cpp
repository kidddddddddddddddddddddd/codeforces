#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 3e5 + 7;

int T;
int a, b;
set<int> s;

int high() {
    return (a + b + 1) / 2;
}

int low() {
    return (a + b) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        s.clear();
        scanf("%d%d", &a, &b);
        //a先手
        for (int x = 0; x <= a; x++) {
            int y = high() + x - a;
            if (y >= 0 && y <= b && y <= high()) {
                s.insert(x + y);
            }
        }
        //b先手
        for (int x = 0; x <= a; x++) {
            int y = low() + x - a;
            if (y >= 0 && y <= b && y <= low()) {
                s.insert(x + y);
            }
        }
        printf("%d\n", s.size());
        for (int x: s) {
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}


