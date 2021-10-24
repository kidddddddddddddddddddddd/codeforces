#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;

int T;
int n;
char s[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		int ans = n + 1;
		for (char c = 'a'; c <= 'z'; c++) {
			int l = 1, r = n;
			int cnt = 0;
			while (l <= r) {
				if (s[l] == s[r]) {
					l++;
					r--;
					continue;
				}
				if (s[l] == c) {
					cnt++;
					l++;
					continue;
				}
				if (s[r] == c) {
					cnt++;
					r--;
					continue;
				}
				cnt = n + 1;
				break;
			}
			ans = min(ans, cnt);
		}
		printf("%d\n", ans == n + 1 ? -1 : ans);
	}
	return 0;
}
