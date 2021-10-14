#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 20;
const int maxm = 1 << maxn;

int T;

char s[maxn];

int calc(int l, int r, int len)
{
	int ans = 0;
	for (int i = r + 1; i < len; i++) {
		ans++;
	}
	for (int i = l + 1; i < r; i++) {
		ans++;
	}
	return ans;
}

// 25 50 75 00
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int len = strlen(s);
		int l = len, r = len;
		int ans = len;
		for (int i = len - 1; i >= 0; i--) {
			if (s[i] == '0') {
				for (int j = i - 1; j >= 0; j--) {
					if (s[j] == '0' || s[j] == '5') {
						l = j;
						r = i;
						ans = min(ans, calc(l, r, len));
						break;
					}
				}
			} else if (s[i] == '5') {
				for (int j = i - 1; j >= 0; j--) {
					if (s[j] == '2' || s[j] == '7') {
						l = j;
						r = i;
						ans = min(ans, calc(l, r, len));
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
