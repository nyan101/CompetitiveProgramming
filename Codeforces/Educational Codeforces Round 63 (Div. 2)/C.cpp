#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

int n, m;
llint x[300005];
llint p[300005];

llint gcd(llint a, llint b)
{
    while(a%b!=0)
    {
        llint t = a%b;
        a = b;
        b = t;
    }
    return b;
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++)
        scanf("%lld", &x[i]);

    for(int i=1;i<=m;i++)
        scanf("%lld", &p[i]);

    llint g = x[2] - x[1];
    for(int i=1;i<=n-1;i++)
        g = gcd(g, x[i+1] - x[i]);

    bool flag = false;
    for(int i=1;i<=m;i++)
    {
        if(g % p[i] ==0)
        {
            flag = true;
            printf("YES\n");
            printf("%lld %lld\n", x[1], i);
            break;
        }
    }
    if(!flag)
        printf("NO\n");


    return 0;
}