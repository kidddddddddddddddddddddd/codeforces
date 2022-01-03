#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
int n;
int a[maxn];
bool vis[maxn];
multiset<int> s;

void init()
{
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
	}
	s.clear();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] <= n && (!vis[a[i]])) {
				vis[a[i]] = true;
				continue;
			}
			s.insert(a[i]);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) {
				continue;
			}
			int x = *s.begin();
			s.erase(s.begin());
			int up = (x - 1) / 2;
			if (up >= i) {
				cnt++;
				vis[i] = true;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				cnt = -1;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
