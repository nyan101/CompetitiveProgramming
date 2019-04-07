#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

int n;
llint a[300005];
llint ans = 0;
llint rem = 0;
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);

        llint t = min(rem, a[i]/2);
        ans += t;
        rem -= t;
        a[i] -= 2*t;

        ans += a[i]/3;
        rem += a[i]%3;
    }

    printf("%lld\n", ans);

    return 0;
}