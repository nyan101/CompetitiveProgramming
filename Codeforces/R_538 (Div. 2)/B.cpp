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

int n, m, k;
int a[200002];
vector<int> vec;
llint ans = 0;

priority_queue<pair<int,int>> PQ;

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);

        PQ.push({a[i], i});
    }


    for(int i=0;i<m*k;i++)
    {
        ans += PQ.top().first;
        vec.push_back(PQ.top().second);
        PQ.pop();
    }

    sort(vec.begin(), vec.end());

    printf("%lld\n", ans);
    for(int i=1;i<=k-1;i++)
        printf("%d ", vec[i*m-1]);
    printf("\n");




    return 0;
}