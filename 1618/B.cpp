#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 5e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
int n;
string s[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	// scanf("%d", &T);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n - 2; i++) {
			cin >> s[i];
		}
		int cnt = 1;
		string ans = "";
		ans += s[1];
		for (int i = 2; i <= n - 2; i++) {
			if (s[i][0] == ans[ans.size() - 1]) {
				ans += s[i][1];
				continue;
			} else {
				cnt--;
				ans += s[i];
			}
		}
		if (cnt == 1) {
			ans += "a";
		}
		cout << ans << endl;
	}
	return 0;
}
