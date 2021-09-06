#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 7;

int T;
int n;
char s[107];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='U'){
                s[i]='D';
            }else if(s[i]=='D'){
                s[i]='U';
            }
        }
        printf("%s\n",s+1);
    }
    return 0;
}

