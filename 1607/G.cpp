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

const int maxn = 2e3 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;
int n, m;
long long ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		vector<pair<int, int>> dishes;
		long long balance = 0;
		long long max_sum_a = 0, max_sum_b = 0;
		long long total_eat = 1ll * n * m;
		for (int i = 1; i <= n; i++) {
			pair<int, int> dish;
			scanf("%d%d", &dish.first, &dish.second);
			dishes.push_back(dish);
			balance += dish.first - dish.second;
			max_sum_a += min(dish.first, m);
			max_sum_b += min(dish.second, m);
		}
		// eat most a,balance will add A
		long long A = -max_sum_a + (total_eat - max_sum_a);
		// eat most b,balance will add B
		long long B = -(total_eat - max_sum_b) + max_sum_b;

		long long min_a = total_eat - max_sum_b;

		long long eat_a = 0;
		if (balance < 0) { // eat less a
			eat_a = min_a;
			if (balance + B >= 0) {
				eat_a = min(max_sum_a, (total_eat + balance + 1) / 2);
			}
		} else { // eat more a
			eat_a = max_sum_a;
			if (balance + A <= 0) {
				eat_a = min(max_sum_a, (total_eat + balance + 1) / 2);
			}
		}

		ans = abs(balance - eat_a + (total_eat - eat_a));
		printf("%lld\n", ans);

		long long rest_a = eat_a - min_a;
		for (auto dish : dishes) {
			long long cur_a = 0;
			// eat all b
			if (dish.second < m) {
				cur_a += m - dish.second;
			}
			// now it reaches min_a,but we have to add it rest_a
			long long add = min(rest_a, min(m - cur_a, dish.first - cur_a));
			cur_a += add;
			rest_a -= add;
			printf("%lld %lld\n", cur_a, m - cur_a);
		}
	}
	return 0;
}
