#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string_view>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 3e5 + 7;
const int maxm = 2e6 + 7;

int T;
char keyboard[30];
map<char, int> table;
char s[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%s", keyboard + 1);
		for (int i = 1; i <= 26; i++) {
			table[keyboard[i]] = i;
		}
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			ans += abs(table[s[i]] - table[s[i - 1]]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
