#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int n, Q;
char s[maxn];
int idx;
char c[5];
int cnt;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d%d", &n, &Q);
	scanf("%s", s);
	for (int i = 0; i + 2 < n; i++) {
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
			cnt++;
		}
	}
	while (Q--) {
		scanf("%d", &idx);
		idx--;
		scanf("%s", c);
		if (s[idx] == 'a') {
			if (idx + 1 < n && idx + 2 < n && s[idx + 1] == 'b' && s[idx + 2] == 'c') {
				cnt--;
			}
		} else if (s[idx] == 'b') {
			if (idx - 1 >= 0 && s[idx - 1] == 'a' && idx + 1 < n && s[idx + 1] == 'c') {
				cnt--;
			}
		} else {
			if (idx - 2 >= 0 && s[idx - 2] == 'a' && idx - 1 >= 0 && s[idx - 1] == 'b') {
				cnt--;
			}
		}

		s[idx] = c[0];
		if (s[idx] == 'a') {
			if (idx + 1 < n && idx + 2 < n && s[idx + 1] == 'b' && s[idx + 2] == 'c') {
				cnt++;
			}
		} else if (s[idx] == 'b') {
			if (idx - 1 >= 0 && s[idx - 1] == 'a' && idx + 1 < n && s[idx + 1] == 'c') {
				cnt++;
			}
		} else {
			if (idx - 2 >= 0 && s[idx - 2] == 'a' && idx - 1 >= 0 && s[idx - 1] == 'b') {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
