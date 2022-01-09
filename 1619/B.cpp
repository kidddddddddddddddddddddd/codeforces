#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		set<long long> s;
		for (long long i = 1; i * i <= n; i++) {
			if (i * i <= n) {
				s.insert(i * i);
			}
			if (i * i * i <= n) {
				s.insert(i * i * i);
			}
		}
		printf("%d\n", s.size());
	}
	return 0;
}
