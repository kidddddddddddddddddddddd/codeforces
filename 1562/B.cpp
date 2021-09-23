#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;

int T;
int k;
char s[57];

set<int> table, pos[10];

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int cur_num, int cur_pos) {
    if (cur_pos > 4) {
        return;
    }
    if (!is_prime(cur_num)) {
        table.insert(cur_num);
    }
    dfs(cur_num * 10 + 2, cur_pos + 1);
    dfs(cur_num * 10 + 3, cur_pos + 1);
    dfs(cur_num * 10 + 5, cur_pos + 1);
    dfs(cur_num * 10 + 7, cur_pos + 1);
}

void init() {
    table.insert(1);
    for (int i = 1; i < 10; i++) {
        if (!is_prime(i)) {
            table.insert(i);
        }
    }
    dfs(0, 1);
}

void clear_pos() {
    for (auto &po: pos) {
        po.clear();
    }
}

vector<int> split(int x) {
    vector<int> res;
    while (x) {
        res.push_back(x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool judge(int x) {
    vector<int> digits = split(x);
    int pre_pos = 0;
    for (int x: digits) {
        auto it = pos[x].upper_bound(pre_pos);
        if (it == pos[x].end()) {
            return false;
        }
        pre_pos = *it;
    }
}

void print(int x) {
    vector<int> digits = split(x);
    printf("%d\n%d\n", digits.size(), x);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    init();
    scanf("%d", &T);
    while (T--) {
        clear_pos();
        scanf("%d", &k);
        scanf("%s", s + 1);
        for (int i = 1; i <= k; i++) {
            pos[s[i] - '0'].insert(i);
        }
        for (int x: table) {
            if (judge(x)) {
                print(x);
                break;
            }
        }
    }
    return 0;
}

