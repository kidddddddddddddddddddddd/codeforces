#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;


const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

long long poww(long long a, long long b, long long mod) {
    long long res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        b >>= 1;
    }
    return res;
}

int k, n;
long long dp[600000 + 7][6];
vector<int> color[6];
map<long long, int> label;
long long c[600000 + 7];
vector<vector<int>> adj;

long long solve(int i, int j) {
    if (c[i] != -1 && c[i] != j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    long long ans = 0;
    long long sum[2] = {0};
    for (auto x: color[j]) {
        for (int it = 0; it < adj[i].size(); it++) {
            sum[it] = (sum[it] + solve(adj[i][it], x)) % mod;
        }
    }
    if (adj[i].empty()) {
        sum[0] = sum[1] = 1;
    }
    if (adj[i].size() == 1) {
        sum[1] = 1;
    }
    ans = (sum[0] * sum[1]) % mod;
    return dp[i][j] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    color[0] = {1, 2, 4, 5};
    color[1] = {0, 2, 3, 5};
    color[2] = {0, 1, 3, 4};
    color[3] = {1, 2, 4, 5};
    color[4] = {0, 2, 3, 5};
    color[5] = {0, 1, 3, 4};

    map<string, int> mp;
    mp["white"] = 0;
    mp["blue"] = 1;
    mp["red"] = 2;
    mp["yellow"] = 3;
    mp["green"] = 4;
    mp["orange"] = 5;

    memset(dp, -1, sizeof(dp));
    memset(c, -1, sizeof(c));

    cin >> k >> n;
    long long total = (1ll << k) - 1;

    int lab = 0;
    map<long long, int> ar;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        string s;
        cin >> s;
        ar[x] = mp[s];
        long long cur = x;
        while (cur >= 1 && !label.count(cur)) {
            label[cur] = lab;
            lab++;
            total--;
            cur >>= 1;
        }
    }
    adj.assign(lab + 5, vector<int>());
    for (auto x: label) {
        if (ar.count(x.first)) {
            c[x.second] = ar[x.first];
        }
        if (label.count(x.first << 1)) {
            adj[x.second].push_back(label[x.first << 1]);
        }
        if (label.count(x.first << 1 | 1)) {
            adj[x.second].push_back(label[x.first << 1 | 1]);
        }
    }
    long long ans = poww(4, total, mod);
    long long sum = 0;
    for (int i = 0; i < 6; i++) {
        sum = (sum + solve(label[1], i)) % mod;
    }
    ans = (ans * sum) % mod;
    cout << ans << endl;
    return 0;
}
