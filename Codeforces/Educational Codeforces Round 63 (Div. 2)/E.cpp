#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

const llint MOD = 1000003;

int n;
llint m[12][12];

llint mpow(llint a, llint e)
{
    llint res = 1;
    while(e>0)
    {
        if(e%2==1)
            res = (res*a)%MOD;

        a = (a*a)%MOD;
        e /= 2;
    }
    return res;
}

int main()
{
    setbuf(stdout, NULL);
    for(int x=0;x<=10;x++)
    {
        m[x][0] = 1;
        for(int i=1;i<=10;i++)
            m[x][i] = (m[x][i-1]*x)%MOD;
    }
    for(int x=0;x<=10;x++)
    {
        printf("? %d\n", x);
        scanf("%lld", &m[x][11]);
    }

    for(int x=0;x<=10;x++)
    {
        llint inv = mpow(m[x][x], MOD-2);

        for(int i=0;i<=11;i++)
            m[x][i] = (m[x][i]*inv)%MOD;

        for(int y=0;y<=10;y++)
        {
            if(x==y) continue;

            llint coef = m[y][x];
            for(int i=0;i<=11;i++)
            {
                m[y][i] -= (coef*m[x][i])%MOD;
                m[y][i] = (m[y][i]+MOD)%MOD;
            }
        }
    }

    llint ans = -1;
    for(llint a=0;a<MOD;a++)
    {
        llint res = 0;
        for(int i=10;i>=0;i--)
            res = (res*a + m[i][11])%MOD;

        if(res==0)
        {
            ans = a;
            break;
        }
    }

    printf("! %lld\n", ans);

    return 0;
}