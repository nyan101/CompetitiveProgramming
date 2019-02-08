// http://codeforces.com/contest/1110
// 2019.02.07

#include <cstdio>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long llint;

using namespace std;

llint a, b;
int k;

int main()
{

    scanf("%lld %d", &b, &k);

    llint res = 0;
    for(int i=1;i<=k;i++)
    {
        scanf("%lld", &a);
        res = res*b + a;
        res %= 2;
    }

    if(res==0)
        printf("even\n");
    else
        printf("odd\n");

    return 0;
}