#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;


int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector<vector<int>> a(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        for (int j = 0; j < c[i]; j++) {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }
    int m;
    scanf("%d", &m);
    vector<vector<int>> banned(m, vector<int>(0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            --x;
            banned[i].push_back(x);
        }
    }

    sort(banned.begin(), banned.end());
    set<pair<int, vector<int> > > s;
    {
        int sum = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            sum += a[i].back();
            v[i] = c[i] - 1;
        }
        s.emplace(sum, v);
    }
    while (true) {
        if (s.empty()) {
            cout << "set empty!!!!!!!!" << endl;
            return 0;
        }
        auto it = prev(s.end());
        int sum = it->first;
        vector<int> v = it->second;
        s.erase(it);
        auto iter = lower_bound(banned.begin(), banned.end(), v);
        if (iter == banned.end() || *iter != v) {
            for (int i = 0; i < n; i++) {
                printf("%d ", v[i] + 1);
            }
            printf("\n");
            break;
        }
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) {
                int new_sum = sum - a[i][v[i]] + a[i][v[i] - 1];
                v[i] -= 1;
                s.emplace(new_sum, v);
                v[i] += 1;
            }
            if (v[i] < c[i] - 1) {
                break;
            }
        }
    }

    return 0;
}

