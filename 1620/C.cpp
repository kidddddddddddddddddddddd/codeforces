#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
long long n, k, x;
string s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	cin >> T;
	while (T--) {
		cin >> n >> k >> x;
		x--;
		cin >> s;
		reverse(s.begin(), s.end());
		string ans = "";
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				long long cur = cnt * k + 1;
				ans += string(x % cur, 'b') + 'a';
				x /= cur;
				cnt = 0;
			} else {
				cnt++;
			}
		}

		ans += string(x % (cnt * k + 1), 'b');
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	return 0;
}
