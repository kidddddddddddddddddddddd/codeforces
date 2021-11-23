#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;
int x, y;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &x, &y);
		if ((x + y) & 1) {
			printf("-1 -1\n");
			continue;
		}
		int d = (x + y) >> 1;
		int a = -1, b = -1;
		for (a = 0; a <= 100; a++) {
			for (b = 0; b <= 100; b++) {
				if ((a + b == d) && (abs(x - a) + abs(y - b) == d)) {
					goto out;
				}
			}
		}
	out:
		printf("%d %d\n", a, b);
	}
	return 0;
}
