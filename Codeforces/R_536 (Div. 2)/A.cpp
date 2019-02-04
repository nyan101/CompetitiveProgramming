// http://codeforces.com/contest/1106/my
// 2019.01.31

#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n;
char ss[510][510];

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%s", ss[i]+1);
    

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ss[i][j]=='X' && ss[i-1][j-1]=='X' && ss[i+1][j+1]=='X' && ss[i-1][j+1]=='X' && ss[i+1][j-1]=='X')
                ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}