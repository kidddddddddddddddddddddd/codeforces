#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;

int T;
char s[maxn];
int cnt[3];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            cnt[s[i] - 'A']++;
        }
        printf("%s\n", cnt[1] == cnt[0] + cnt[2] ? "YES" : "NO");
    }
    return 0;
}


