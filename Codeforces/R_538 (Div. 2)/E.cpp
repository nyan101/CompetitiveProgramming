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

int n;
llint MOD = 732101;
llint maxi;
vector<llint> vec;

llint gcd(llint a, llint b)
{
    if(a==0) return b;
    if(b==0) return a;
    while(a%b!=0)
    {
        llint t = b;
        b = a%b;
        a = t;
    }
    return b;
}

int main()
{
    int q=0;
    llint res;

    setbuf(stdout, NULL);
    scanf("%d", &n);

    llint l = 0, r = 1e9;


    while(l<r)
    {
        llint mid = (l+r+1)/2;

        q++;
        printf("> %lld\n", mid-1); fflush(stdout);
        scanf("%lld", &res);

        if(res==1)
            l = mid;
        else
            r = mid-1;
    }

    maxi = l;
    llint d = 0;

    if(n==732101)
        MOD = 732097;

    for( ; q<60;q++)
    {
        printf("? %lld\n", 1 + ((q*MOD) % ((llint)n))); fflush(stdout);
        scanf("%lld", &res);
        vec.push_back(res);
    }

    sort(vec.begin(), vec.end());

    for(int i=0;i<vec.size();i++)
    {
        for(int j=i+1;j<vec.size();j++)
            d = gcd(d, vec[j] - vec[i]);
    }

    llint x = maxi - (n-1)*d;

    printf("! %lld %lld\n", x, d); fflush(stdout);



    return 0;
}