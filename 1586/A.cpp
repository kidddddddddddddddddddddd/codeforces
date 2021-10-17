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

const int maxn = 4e5 + 7;
const int maxm = 1e6 + 7;

int T;
int n;
int a[maxn];

bool is_prime(int x)
{
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		int sum = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (!is_prime(sum)) {
			printf("%d\n", n);
			for (int i = 1; i <= n; i++) {
				printf("%d ", i);
			}
			printf("\n");
		} else {
			printf("%d\n", n - 1);
			bool skip = false;
			for (int i = 1; i <= n; i++) {
				if (a[i] % 2 == 1 && (!skip)) {
					skip = true;
					continue;
				}
				printf("%d ", i);
			}
			printf("\n");
		}
	}
	return 0;
}
