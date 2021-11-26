#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;
int n;
int a[maxn];

bool judge(int x)
{
	vector<int> tmp_a;
	vector<int> tmp_reverse_a;
	for (int i = 1; i <= n; i++) {
		if (a[i] != x) {
			tmp_a.push_back(a[i]);
			tmp_reverse_a.push_back(a[i]);
		}
	}
	reverse(tmp_reverse_a.begin(), tmp_reverse_a.end());
	return tmp_a == tmp_reverse_a;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		bool ok = true;
		vector<int> x;
		int l = 1, r = n;
		while (l <= r) {
			if (a[l] == a[r]) {
				l++;
				r--;
			} else {
				x.push_back(a[l]);
				x.push_back(a[r]);
				break;
			}
		}
		if (x.empty()) {
			printf("%s\n", "YES");
			continue;
		}
		if (judge(x[0]) || judge(x[1])) {
			printf("%s\n", "YES");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}
