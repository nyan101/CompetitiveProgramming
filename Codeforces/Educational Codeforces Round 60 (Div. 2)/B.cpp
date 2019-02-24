// http://codeforces.com/contest/1117/problem/B

#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

int n;
llint m, k;
vector<llint> vec;

int main()
{
    llint x;

    scanf("%d %lld %lld", &n, &m, &k);

    for(int i=1;i<=n;i++)
    {
        scanf("%lld", &x);
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    llint res = 0;

    res = (k*vec[0] + vec[1]) * (m/(k+1));
    res += vec[0]*(m%(k+1));

    printf("%lld\n", res);

    return 0;
}