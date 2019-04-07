#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

int n, m;
int a[505][505];
int b[505][505];

int main()
{
    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            scanf("%d", &a[i][j]);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            scanf("%d", &b[i][j]);
    }

    for(int i=1;i<=n;i++)
    {
        a[i][0] = b[i][0] = 0;
        for(int j=1;j<=m;j++)
        {
            a[i][0] ^= a[i][j];
            b[i][0] ^= b[i][j];
        }
    }
    for(int j=1;j<=m;j++)
    {
        a[0][j] = b[0][j] = 0;
        for(int i=1;i<=n;i++)
        {
            a[0][j] ^= a[i][j];
            b[0][j] ^= b[i][j];
        }
    }

    bool flag = true;
    for(int i=1;i<=n;i++)
        flag = flag && (a[i][0] == b[i][0]);
    for(int j=1;j<=m;j++)
        flag = flag && (a[0][j] == b[0][j]);

    if(flag)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}