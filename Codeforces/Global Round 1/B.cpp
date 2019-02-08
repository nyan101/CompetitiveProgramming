// http://codeforces.com/contest/1110
// 2019.02.07

#include <cstdio>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long llint;

using namespace std;

int n, m, k;
vector<int> vec;
priority_queue<int> PQ;

int main()
{
    int x;
    int ans = 0;

    scanf("%d %d %d", &n, &m, &k);

    for(int i=1;i<=n;i++)
    {
        scanf("%d", &x);
        vec.push_back(x);
    }

    for(int i=1;i<n;i++)
        PQ.push(vec[i]-vec[i-1]-1);

    ans = vec[n-1] - vec[0]+1;

    for(int i=0;i<k-1;i++)
    {
        ans -= PQ.top();
        PQ.pop();
    }

    printf("%d\n", ans);


    return 0;
}