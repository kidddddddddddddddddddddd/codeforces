#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int n, m;
int block;
int x[maxn], y[maxn];
int pre[maxn];
int add_date[maxn];
int sum;

int cnt[500][500];

void block_modify(int date, int k, int v) {
    int len = x[k] + y[k];
    for (int i = 0; i < len; i++) {
        if ((i - (date % len) + len) % len >= x[k]) {
            cnt[len][i] += v;
        }
    }
}

int block_query(int date) {
    int res = 0;
    for (int i = 2; i <= block; i++) {
        res += cnt[i][date % i];
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    block = sqrt(m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= m; i++) {
        int opt, k;
        scanf("%d%d", &opt, &k);
        if (opt == 1) {
            if (block < x[k] + y[k]) {
                for (int j = i + x[k]; j <= m; j += x[k] + y[k]) {
                    pre[j]++;
                    if (j + y[k] <= m) {
                        pre[j + y[k]]--;
                    }
                }
            } else {
                block_modify(i, k, 1);
            }
            add_date[k] = i;
        } else {
            if (block < x[k] + y[k]) {
                for (int j = add_date[k] + x[k]; j <= m; j += x[k] + y[k]) {
                    pre[j]--;
                    if (j + y[k] <= m) {
                        pre[j + y[k]]++;
                    }
                    if (j < i && j + y[k] >= i) {
                        sum--;
                    }
                }
            } else {
                block_modify(add_date[k], k, -1);
            }
        }
        sum += pre[i];
        printf("%d\n", sum + block_query(i));
    }
    return 0;
}
