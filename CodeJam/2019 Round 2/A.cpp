#include <cstdio>
#include <set>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n;
llint C[302], J[302];
set<pair<llint,llint>> S;

llint gcd(llint a, llint b)
{
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
    int T;
    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
            scanf("%lld %lld", &C[i], &J[i]);

        S.clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(C[i] < C[j] && J[i] > J[j])
                {
                    llint CC = C[j] - C[i];
                    llint JJ = J[i] - J[j];
                    llint g = gcd(CC, JJ);
                    CC /= g; JJ /= g;

                    S.insert({CC, JJ});
                }
            }
        }

        printf("Case #%d: %d\n", test_case, S.size()+1);
    }

    return 0;
}
