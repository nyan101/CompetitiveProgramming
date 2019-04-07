#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[300002];
int ans = 0;

int main()
{
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);

    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[n])
        {
            ans = n-i;
            break;
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(a[1] != a[i])
        {
            ans = max(ans, i-1);
            break;
        }
    }
    printf("%d\n", ans);

    return 0;
}