#include <algorithm>
#include <cmath>
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

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;
int n;
long long ans_i, ans_j, ans_k;

long long ask(long long l, long long r)
{
	long long res;
	printf("? %lld %lld\n", l, r);
	fflush(stdout);
	scanf("%lld", &res);
	return res;
}

long long c_n_2_n(long long x)
{
	long long res = 0;
	x <<= 1;
	long long tmp = sqrt(x);
	for (long long i = max(tmp - 10, 1ll); i <= tmp + 10; i++) {
		if (i * (i - 1) == x) {
			return i;
		}
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		long long A = ask(1, n);
		long long i = n + 1;
		long long l = 1, r = n;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			if (ask(mid, n) < A) {
				r = mid - 1;
			} else {
				l = mid + 1;
				i = mid;
			}
		}
		long long B = ask(i + 1, n);
		long long j = A - B + i + 1;
		long long c_j_i = (j - i) * (j - i - 1) / 2;
		long long c_k_j_1 = A - c_j_i;
		long long k_j_1 = c_n_2_n(c_k_j_1);
		long long k = k_j_1 + j - 1;
		printf("! %lld %lld %lld\n", i, j, k);
		fflush(stdout);
	}
	return 0;
}
