#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
string s, t;
int cnt[30];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	cin >> T;
	while (T--) {
		cin >> s >> t;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < s.size(); i++) {
			cnt[s[i] - 'a']++;
		}
		string ans = "";

		if (t == "abc" && cnt[0] && cnt[1] && cnt[2]) {
			for (int i = 1; i <= cnt[0]; i++) {
				ans += "a";
			}
			for (int i = 1; i <= cnt[2]; i++) {
				ans += "c";
			}
			for (int i = 1; i <= cnt[1]; i++) {
				ans += "b";
			}
			for (int i = 3; i <= 25; i++) {
				for (int j = 0; j < cnt[i]; j++) {
					ans += 'a' + i;
				}
			}
		} else {
			for (int i = 0; i <= 25; i++) {
				for (int j = 0; j < cnt[i]; j++) {
					ans += 'a' + i;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}
