#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 3e5 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
int n;
char c;
char s[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d %c", &n, &c);
        scanf("%s", s + 1);
        vector<int> left[2], right[2];
        for (int i = 1; i <= n; i++) {
            if (i <= n / 2) {
                if (s[i] == c) {
                    left[1].push_back(i);
                } else {
                    left[0].push_back(i);
                }
            } else {
                if (s[i] == c) {
                    right[1].push_back(i);
                } else {
                    right[0].push_back(i);
                }
            }
        }
        if (left[0].size() + right[0].size() == 0) {
            printf("0\n");
            continue;
        }
        if (right[1].size()) {
            printf("1\n");
            printf("%d\n", right[1][0]);
            continue;
        }
        printf("2\n");
        printf("%d %d\n", right[0][0], right[0][0] + 1);
    }
    return 0;
}
