// Passed Small Only

#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n;
llint C[102], J[102];

llint minA, minB, maxA, maxB; // A/B
int main()
{
    int T;
    
    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
            scanf("%lld %lld", &C[i], &J[i]);

        maxA = 1; maxB = 1e9;
        minA = 1e9; minB = 1;
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(C[i] >= C[j] && J[i] >= J[j])
                    flag = false;

                if(C[i] <= C[j] && J[i] <= J[j])
                    continue;

                if(C[i] - C[j] > 0)
                {
                    if(minA * (C[i] - C[j]) > minB *(J[j] - J[i]) )
                    {
                        minA = (J[j] - J[i]);
                        minB = (C[i] - C[j]);
                    }
                }
                else
                {
                    if(maxA * (C[j] - C[i]) < maxB * (J[i] - J[j]))
                    {
                        maxA = (J[i] - J[j]);
                        maxB = (C[j] - C[i]);
                    }
                }
            }
        }

        if(minA * maxB <= maxA * minB)
            flag = false;

        if(!flag)
        {
            printf("Case #%d: IMPOSSIBLE\n", test_case);
            continue;
        }

        llint minBx = minA;
        llint maxBx = 0;
        llint y;

        for(llint x = 1;x<=2e9+10;x++)
        {
            maxBx += maxB;
            minBx += minB;

            y = (minBx)/minA;

            if(y * maxA < maxBx)
            {
                printf("Case #%d: %lld %lld\n", test_case, x, y);
                break;
            }
        }
    }

    return 0;
}
