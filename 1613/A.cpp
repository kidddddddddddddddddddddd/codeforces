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

int T;
int x1, p1, x2, p2;

int len(int x)
{
	int res = 0;
	while (x) {
		res++;
		x /= 10;
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &x1, &p1);
		scanf("%d%d", &x2, &p2);
		while (len(x1) < len(x2) && p1 > 0) {
			p1--;
			x1 *= 10;
		}
		while (len(x1) > len(x2) && p2 > 0) {
			p2--;
			x2 *= 10;
		}
		if (len(x1) == len(x2)) {

			if (x1 == x2) {
				if (p1 == p2) {
					printf("=\n");
				}
				if (p1 > p2) {
					printf(">\n");
				}
				if (p1 < p2) {
					printf("<\n");
				}
			}

			if (x1 > x2) {
				if (p1 >= p2) {
					printf(">\n");
				} else {
					printf("<\n");
				}
			}

			if (x1 < x2) {
				if (p1 <= p2) {
					printf("<\n");
				} else {
					printf(">\n");
				}
			}

		} else if (len(x1) > len(x2)) {
			printf(">\n");
		} else {
			printf("<\n");
		}
	}
	return 0;
}
