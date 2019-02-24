// http://codeforces.com/contest/1117/problem/C

#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

const llint INF = 2e18+123;

int n;
char ss[100005];
llint x1, x2, y1, y2;
llint dx[100005], dy[100005];

llint xx, yy, res;

int main()
{

    scanf("%lld %lld", &x1, &y1);
    scanf("%lld %lld", &x2, &y2);
    scanf("%d", &n);
    scanf("%s", ss);

    for(int i=0;i<n;i++)
    {
        dx[i+1] = dx[i] - (ss[i]=='R') + (ss[i]=='L');
        dy[i+1] = dy[i] - (ss[i]=='U') + (ss[i]=='D');
    }

    llint l = 0, r = INF;

    while(l < r)
    {
        llint mid = (l+r)/2;

        xx = x2 + dx[n]*(mid/n) + dx[mid%n];   
        yy = y2 + dy[n]*(mid/n) + dy[mid%n];

        res = abs(x1 - xx) + abs(y1 - yy);

        if(res <= mid)
            r = mid;
        else
            l = mid+1;
    }

    if(l==INF)
        printf("-1\n");
    else
        printf("%lld\n", l);

    return 0;
}