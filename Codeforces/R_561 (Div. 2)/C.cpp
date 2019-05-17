#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n;
vector<int> vec;

int count(int l, int r)
{
    return upper_bound(vec.begin(), vec.end(), r) - lower_bound(vec.begin(), vec.end(), l);
}

int main()
{
    int x;
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d", &x);
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());

    llint ans = 0;
    for(int i=0;i<n;i++)
    {
        if(vec[i] < 0)
        {
            ans += count(2*vec[i], vec[i]-1);
            ans += count(-vec[i], -2*vec[i]);
        }
        else if(vec[i] > 0)
        {
            ans += count(-2*vec[i], -vec[i]-1);
            ans += count(vec[i]+1, 2*vec[i]);
        }
    }
    printf("%lld\n", ans);

    return 0;
}