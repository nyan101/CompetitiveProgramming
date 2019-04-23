#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

int n;
llint a[300005], x;
llint dpL[300005], dpR[300005];
llint psum[300005];
llint ans;

priority_queue<llint> PQ;

int main()
{
    scanf("%d %lld", &n, &x);

    for(int i=1;i<=n;i++)
        scanf("%lld", &a[i]);

    ans = 0;
    for(int i=1;i<=n;i++)
    {
        dpL[i] = max(a[i], a[i]+dpL[i-1]);
        ans = max(ans, dpL[i]);
        psum[i] = psum[i-1] + a[i];
    }
    for(int i=n;i>=1;i--)
        dpR[i] = max(a[i], a[i]+dpR[i+1]);

    for(int i=n;i>=1;i--)
    {
        PQ.push(dpR[i]-a[i] + psum[i]*x);

        llint tmp = PQ.top() - x*psum[i-1] + dpL[i] - a[i];
        ans = max(ans, tmp);
    }

    printf("%lld\n", ans);

    return 0;
}