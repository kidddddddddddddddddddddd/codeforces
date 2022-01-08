#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
int n;
char s[maxn];
int fa[maxn];
void init()
{
	for (int i = 0; i <= n; i++) {
		fa[i] = i;
	}
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); };
void merge(int x, int y) { fa[find(x)] = find(y); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		init();
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			int nxt = i + 1 > n ? 1 : i + 1;
			if (s[i] == 'E') {
				merge(i, nxt);
			}
		}
		for (int i = 1; i <= n; i++) {
			int nxt = i + 1 > n ? 1 : i + 1;
			if (s[i] == 'N' && find(i) == find(nxt)) {
				flag = false;
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}
