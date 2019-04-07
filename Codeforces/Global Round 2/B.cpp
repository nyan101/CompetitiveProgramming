#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

int n;
llint h;
llint a[1002];
llint b[1002];

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d %lld", &n, &h);

    for(int i=1;i<=n;i++)
        scanf("%lld", &a[i]);

    int l, r;
    l = 1; r = n;
    while(l<r)
    {
        int mid = (l+r+1)/2;
        for(int i=1;i<=mid;i++)
            b[i] = a[i];
        sort(b+1, b+mid+1);

        llint th = 0;
        for(int i=mid;i>=1;i-=2)
            th += b[i];

        if(th <= h)
            l = mid;
        else
            r = mid-1;
    }

    printf("%d\n", l);

    return 0;
}