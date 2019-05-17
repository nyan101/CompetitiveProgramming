#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n, m;
vector<int> vec[52];

int main()
{
    int cc, x;
    scanf("%d %d", &m, &n);

    for(int i=1;i<=m;i++)
    {
        scanf("%d", &cc);
        for(int j=1;j<=cc;j++)
        {
            scanf("%d", &x);
            vec[i].push_back(x);
        }
        sort(vec[i].begin(), vec[i].end());
    }

    bool flag = true;
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            bool dis = true;
            for(auto x : vec[i])
            {
                if(lower_bound(vec[j].begin(), vec[j].end(), x)
                    != upper_bound(vec[j].begin(), vec[j].end(), x))
                {
                    dis = false;
                    break;
                }
            }
            if(dis)
            {
                flag = false;
                break;
            }
        }
    }
    if(flag)
        printf("possible\n");
    else
        printf("impossible\n");

    return 0;
}