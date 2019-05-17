#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;


int N, M;
int par[500002];

int ufind(int v){ return par[v]<0? v : par[v]=ufind(par[v]); }

int main()
{
    int cc, x, y;

    scanf("%d %d", &N, &M);

    for(int i=1;i<=N;i++)
        par[i] = -1;

    for(int g=1;g<=M;g++)
    {
        scanf("%d", &cc);
        if(cc==0) continue;

        scanf("%d", &x);
        for(int i=2;i<=cc;i++)
        {
            scanf("%d", &y);

            x = ufind(x);
            y = ufind(y);

            if(x==y) continue;

            if(par[x] < par[y]) swap(x,y);

            par[y] += par[x];
            par[x] = y;

            x = y;
        }
    }

    for(int i=1;i<=N;i++)
    {
        x = ufind(i);
        printf("%d ", -par[x]);
    }

    return 0;
}