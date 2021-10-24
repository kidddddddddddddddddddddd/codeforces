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

const int maxn = 1e3 + 7;
const int maxm = 2e6 + 7;

int T;
long long a, b, c;
long long sum;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld", &a, &b, &c);
		sum = a + 2 * b + 3 * c;
		printf("%lld\n", sum % 2);
	}
	return 0;
}
