#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;

int T;
int n;
int p[maxn];
deque<int> Q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++){
            if(Q.empty()||Q.front()>p[i]){
                Q.push_front(p[i]);
            }else{
                Q.push_back(p[i]);
            }
        }
        while (!Q.empty()){
            printf("%d ",Q.front());
            Q.pop_front();
        }
        printf("\n");
    }
    return 0;
}


