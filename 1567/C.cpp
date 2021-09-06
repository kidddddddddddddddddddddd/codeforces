#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 3e5 + 7;

int T;
int n;

pair<int, int> part(int x) {
    pair<int, int> res = make_pair(0, 0);
    vector<int> v;
    while (x) {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(),v.end());

    for (int i = 0; i < v.size(); i++) {
        if (i & 1) {
            res.first = res.first * 10 + v[i];
        } else {
            res.second = res.second * 10 + v[i];
        }
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        pair<int, int> parts = part(n);
        //cout<<parts.first<<" "<<parts.second<<endl;
        printf("%lld\n", 1ll * (parts.first + 1) * (parts.second + 1) - 2);
    }
    return 0;
}

