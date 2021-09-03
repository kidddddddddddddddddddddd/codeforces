#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;
int T;
int n;
int a[maxn];
int seq[maxn][2];

long long calc(int type) {
    int cnt_seq[2], cnt_a[2];
    memset(cnt_seq, 0, sizeof(cnt_seq));
    memset(cnt_a, 0, sizeof(cnt_a));
    for (int i = 1; i <= n; i++) {
        cnt_seq[seq[i][type]]++;
        cnt_a[a[i]]++;
    }
    if (cnt_seq[0] != cnt_a[0] || cnt_seq[1] != cnt_a[1]) {
        return 1e18;
    }
    vector<int> seq_ones, a_ones;
    for (int i = 1; i <= n; i++) {
        if (seq[i][type] == 1) {
            seq_ones.push_back(i);
        }
        if (a[i] == 1) {
            a_ones.push_back(i);
        }
    }
    long long ans = 0;
    for (int i = 0; i < seq_ones.size(); i++) {
        ans += abs(seq_ones[i] - a_ones[i]);
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    for (int i = 1; i <= 100000; i++) {
        if (i & 1) {
            seq[i][1] = 1;
            seq[i][0] = 0;
        } else {
            seq[i][1] = 0;
            seq[i][0] = 1;
        }
    }

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i] = a[i] & 1;
        }
        long long ans_0 = calc(0), ans_1 = calc(1);
        printf("%lld\n", min(ans_0, ans_1) == 1e18 ? -1 : min(ans_0, ans_1));
    }
    return 0;
}

