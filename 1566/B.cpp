#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;

int T;
char s[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        s[0] = '2';
        int len = strlen(s + 1);
        int cnt[2];
        vector<char> v;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= len; i++) {
            cnt[s[i] - '0']++;
            if (s[i] != s[i - 1]) {
                v.push_back(s[i]);
            }
        }
        if (v.size() == 1) {
            if (cnt[0] == len) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else {
            int cnt_0 = 0;
            for (char c: v) {
                cnt_0 += (c == '0');
            }
            if (cnt_0 > 1) {
                printf("2\n");
            } else {
                printf("1\n");
            }
        }
    }
    return 0;
}

