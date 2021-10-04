#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
int n, x;
int a[maxn], b[maxn];
map<int, vector<int> > table;
int fa[maxn];

void init() {
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
    }
    table.clear();
}

int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    fa[find(x)] = find(y);
}

bool check(int x) {
    return x >= 1 && x <= n;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        init();
        for (int i = 1; i <= n; i++) {
            if (check(i + x)) {
                merge(i, i + x);
            }
            if (check(i - x)) {
                merge(i, i - x);
            }
            if (check(i - x) && check(i - 1 - x)) {
                merge(i, i - 1);
            }
            if (check(i + x) && check(i + 1 + x)) {
                merge(i, i + 1);
            }
        }

        for (int i = 1; i <= n; i++) {
            table[find(i)].push_back(i);
        }
        for (const auto &it: table) {
            vector<int> pos = it.second;
            vector<int> values;
            for (int p: pos) {
                values.push_back(a[p]);
            }
            sort(values.begin(), values.end());
            for (int i = 0; i < pos.size(); i++) {
                a[pos[i]] = values[i];
            }
        }

        for (int i = 1; i <= n; i++) {
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            ok &= a[i] == b[i];
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
