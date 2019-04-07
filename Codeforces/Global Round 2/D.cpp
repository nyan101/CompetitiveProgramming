#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

int N, Q;
llint s[100005];
llint qq[100005];
vector<llint> qvec;
priority_queue<pair<llint,int>> PQ;

int parL[100005], parR[100005];

map<llint, llint> mp;

int Lfind(int x){ return parL[x]<0? x : parL[x]=Lfind(parL[x]); }
int Rfind(int x){ return parR[x]<0? x : parR[x]=Rfind(parR[x]); }

int main()
{
    scanf("%d", &N);

    for(int i=1;i<=N;i++)
        scanf("%lld", &s[i]);

    sort(s+1, s+N+1);
    for(int i=1;i<=N-1;i++)
        PQ.push({s[i]-s[i+1], i});

    fill(parL, parL+N+1, -1);
    fill(parR, parR+N+1, -1);

    llint l, r;
    scanf("%d", &Q);
    for(int i=1;i<=Q;i++)
    {
        scanf("%lld %lld", &l, &r);
        qq[i] = r-l;
        qvec.push_back(qq[i]);
    }
    sort(qvec.begin(), qvec.end());


    llint ans = N;
    int num = N;
    for(llint q : qvec)
    {
        while(!PQ.empty() && -1*PQ.top().first <= q)
        {
            auto p = PQ.top(); PQ.pop();

            int xl = Lfind(p.second);
            int xr = Rfind(p.second);
            int yl = Lfind(p.second+1);
            int yr = Rfind(p.second+1);

            parR[xl] = yr; parR[xr] = yr;
            parL[yl] = xl; parL[yr] = xl;

            ans -= (s[xr] - s[xl] + 1);
            ans -= (s[yr] - s[yl] + 1);
            ans += (s[yr] - s[xl] + 1);
            num --;
        }

        mp[q] = ans + num * q;
    }

    for(int i=1;i<=Q;i++)
        printf("%lld ", mp[qq[i]]);
    printf("\n");

    return 0;
}