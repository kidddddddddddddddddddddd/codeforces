#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <ios>
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
const int mod = 1e9 + 7;

int T;
int n, m;
char s[maxm];
int max_up[maxm], max_down[maxm], max_left[maxm], max_right[maxm];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		int x = 0, y = 0;
		for (int i = 1; i <= len; i++) {
			max_up[i] = max_up[i - 1];
			max_down[i] = max_down[i - 1];
			max_left[i] = max_left[i - 1];
			max_right[i] = max_right[i - 1];
			if (s[i] == 'U') {
				x--;
				if (x <= 0) {
					max_up[i] = max(max_up[i], abs(x));
				}
			}
			if (s[i] == 'D') {
				x++;
				if (x >= 0) {
					max_down[i] = max(max_down[i], abs(x));
				}
			}
			if (s[i] == 'L') {
				y--;
				if (y <= 0) {
					max_left[i] = max(max_left[i], abs(y));
				}
			}
			if (s[i] == 'R') {
				y++;
				if (y >= 0) {
					max_right[i] = max(max_right[i], abs(y));
				}
			}
		}
		x = 1, y = 1;
		for (int i = 1; i <= len; i++) {
			int tmp_x = n - max_down[i];
			int tmp_y = max_left[i] + 1;
			if (tmp_x - max_up[i] >= 1 && tmp_y + max_right[i] <= m) {
				x = tmp_x;
				y = tmp_y;
			} else {
				break;
			}
		}
		printf("%d %d\n", x, y);
	}
	return 0;
}
