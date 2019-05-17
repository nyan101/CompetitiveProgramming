#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int Q;
llint a, b, m;
vector<llint> vec, ans;

int main()
{
    scanf("%d", &Q);

    for(int q=1;q<=Q;q++)
    {
        scanf("%lld %lld %lld", &a, &b, &m);

        if(a==b)
        {
            printf("1 %lld\n", a);
            continue;
        }

        int k;
        llint two = 1;
        bool flag = false;
        for(k=0;k<=52;k++)
        {
            if(two*a + two > b) break;
            if(two*a + two <= b && b <= two*a + two*m)
            {
                flag = true;
                break;
            }
            two *= 2;
        }
        if(!flag)
            printf("-1\n");
        else
        {
            int k2 = k;   
            vec.clear();
            llint c = b - two*a;
            k--;
            llint maxi = 0;
            while(k>=0)
            {
                llint rem = c - (1LL<<k);
                llint add = min(m, rem/(1LL<<k));
                vec.push_back(add);
                c -= add * (1LL<<k);
                k--;
            }
            vec.push_back(c);

            ans.clear();
            ans.push_back(a);
            for(llint add : vec)
            {
                ans.push_back(a+add);
                a += a + add;
            }

            if(ans[ans.size()-1]!=b)
            {
                printf("-1\n");
                continue;
            }

            printf("%d ", k2+2);
            for(llint x : ans)
                printf("%lld ", x);
            printf("\n");
        }
    }

    return 0;
}