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
const int maxm = 2e7 + 7;
const int mod = 1e9 + 7;

int n;
long long ans;
long long cnt[maxm+3];
long long dp[maxm+3];
bool vis[maxm+3];
vector<long long> primes;

int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif

	for (int i = 2; i < maxm; i++) {
		if (!vis[i]) {
			primes.push_back(i);
		}
		for (long long p : primes) {
			if (p * i > maxm) {
				break;
			}
			vis[p * i] = 1;
			if (i % p == 0) {
				break;
			}
		}
	}
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		cnt[x]++;
	}
	for (long long p : primes) {
		for (long long j = maxm / p; j >= 1; j--) {
			cnt[j] += cnt[j * p];
		}
	}
	for (long long i = maxm - 1; i >= 1; i--) {
		dp[i] = cnt[i] * i;
		for (long long p : primes) {
			long long j = p * i;
			if (j > maxm) {
				break;
			}
			dp[i] = max(dp[i], dp[j] + i * (cnt[i] - cnt[j]));
		}
		if (cnt[i] == n) {
			ans = max(ans, dp[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

