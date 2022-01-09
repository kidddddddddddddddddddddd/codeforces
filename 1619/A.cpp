#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
string s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	cin >> T;
	while (T--) {
		cin >> s;
		int len = s.size();
		bool flag = false;
		for (int i = len / 2; i <= len / 2; i++) {
			string s1 = s.substr(0, i), s2 = s.substr(i);
			if (s1 + s2 == s && s1 == s2) {
				flag = true;
			}
		}
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}
