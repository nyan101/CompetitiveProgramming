// http://codeforces.com/contest/1117/problem/A

#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

int n;
int a[100002];
int dp[100002];
int maxi, maxlen;

int main()
{
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);

    maxi = maxlen = -1;

    for(int i=1;i<=n;i++)
        maxi = max(maxi, a[i]);

    int idx = -1;
    for(int i=1;i<=n;i++)
    {
        dp[i] = 0;
        if(a[i]==maxi)
            dp[i] = dp[i-1] + 1;

        maxlen = max(maxlen, dp[i]);
    }

    printf("%d\n", maxlen);

    return 0;
}