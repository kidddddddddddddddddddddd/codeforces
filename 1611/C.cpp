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
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		deque<int> Q;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			Q.push_back(a[i]);
		}
		deque<int> ans;
		if (Q.front() == n) {
			ans.push_back(Q.front());
			Q.pop_front();
			while (!Q.empty()) {
				if (Q.front() < Q.back()) {
					ans.push_front(Q.front());
					Q.pop_front();
				} else {
					ans.push_back(Q.back());
					Q.pop_back();
				}
			}
		} else if (Q.back() == n) {
			ans.push_back(Q.back());
			Q.pop_back();
			while (!Q.empty()) {
				if (Q.front() < Q.back()) {
					ans.push_front(Q.front());
					Q.pop_front();
				} else {
					ans.push_back(Q.back());
					Q.pop_back();
				}
			}
		} else {
			printf("-1\n");
			continue;
		}
		while (!ans.empty()) {
			printf("%d ", ans.front());
			ans.pop_front();
		}
		printf("\n");
	}
	return 0;
}
