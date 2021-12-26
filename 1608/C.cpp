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
const int mod = 998244353;

int T;
int n;
pair<int, int> a[maxn], b[maxn];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i].first);
			a[i].second = i;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i].first);
			b[i].second = i;
		}
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		reverse(a + 1, a + 1 + n);
		reverse(b + 1, b + 1 + n);

		set<int> s;
		for (int i = 1; i <= n; i++) {
			s.insert(a[i].second);
			s.insert(b[i].second);
			if (s.size() == i) {
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (s.find(i) != s.end()) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}
