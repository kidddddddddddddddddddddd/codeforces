#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;

int T;
int n;
int a[maxn];
std::priority_queue<pair<int, int> > Q;

vector<pair<int, int> > ans;

void init() {
    while (!Q.empty()) {
        Q.pop();
    }
    ans.clear();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (!a[i]) {
                continue;
            }
            Q.push(make_pair(a[i], i));
        }
        while (Q.size() >= 2) {
            pair<int, int> x = Q.top();
            Q.pop();
            pair<int, int> y = Q.top();
            Q.pop();
            ans.push_back(make_pair(x.second, y.second));
            x.first--;
            if (x.first > 0) {
                Q.push(x);
            }
            y.first--;
            if (y.first > 0) {
                Q.push(y);
            }
        }
        printf("%d\n", ans.size());
        for (auto it: ans) {
            printf("%d %d\n", it.first, it.second);
        }
    }
    return 0;
}


