// http://codeforces.com/contest/1114
// 2019.02.10

#include <cstdio>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long llint;

using namespace std;

const int INF = 0x7fffffff;
int n, n2;
int c[5005], c2[5005];
int memo[5005][5005];

int f(int l, int r)
{
    if(l>=r)
        return 0;

    if(memo[l][r] >= 0)
        return memo[l][r];

    int res = -1;
    if(c[l]==c[r])
        res = f(l+1, r-1) + 1;
    else
        res = min(f(l, r-1), f(l+1, r)) + 1;

    return (memo[l][r] = res);
}

int main()
{
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
        scanf("%d", &c2[i]);

    int idx = 1;
    for(int i=1;i<=n;i++)
    {
        if(c2[i]!=c2[i-1])
            c[idx++] = c2[i];
    }
    n = idx-1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            memo[i][j] = -1;
    }

    printf("%d\n", f(1, n));

    return 0;
}