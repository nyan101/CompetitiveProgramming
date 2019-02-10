// http://codeforces.com/contest/1114
// 2019.02.10

#include <cstdio>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long llint;

using namespace std;

llint n, b;
llint ans = 0;
map<llint,llint> mp;
vector<llint> pvec;
vector<llint> need;
vector<llint> have;

int main()
{
    scanf("%lld %lld", &n, &b);

    for(llint i=2;i*i<=b;i++)
    {
        while(b%i==0)
        {
            if(mp.find(i)==mp.end())
                mp[i] = 1;
            else
                mp[i] += 1;
            b /= i;
        }
    }

    if(b > 1)
    {
        if(mp.find(b)==mp.end())
            mp[b] = 1;
        else
            mp[b] += 1;
    }

    for(auto p : mp)
    {
        pvec.push_back(p.first);
        need.push_back(p.second);
    }

    for(llint p : pvec)
    {
        llint n2 = n;
        llint cc = 0;
        while(n2>0)
        {
            cc += n2/p;
            n2 /= p;
        }
        have.push_back(cc);
    }

    llint ans = 0x7fffffffffffffffLL;

    for(int i=0;i<need.size();i++)
        ans = min(ans, have[i] / need[i]);

    printf("%lld\n", ans);

    return 0;
}