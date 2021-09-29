#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;

int T;
int n;
int a[maxn], b[maxn];

struct node {
    int l, r, d;
};

void move(int l, int r, int d) {
    deque<int> Q;
    for (int i = l; i <= r; i++) {
        Q.push_back(a[i]);
    }
    for (int i = 1; i <= d; i++) {
        int x = Q.front();
        Q.pop_front();
        Q.push_back(x);
    }
    for (int i = l; i <= r; i++) {
        a[i] = Q.front();
        Q.pop_front();
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
        vector<node> ans;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[j] == b[i]) {
                    ans.push_back(node{i, j, j - i});
                    move(i, j, j - i);
                    break;
                }
            }
        }
        printf("%d\n", ans.size());
        for (node nd: ans) {
            printf("%d %d %d\n", nd.l, nd.r, nd.d);
        }
    }
    return 0;
}


