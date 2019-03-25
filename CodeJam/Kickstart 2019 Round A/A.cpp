#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef long long llint;

int N, P;
int cnt[10005];
llint psum[10005];

int main()
{
    int T;
    int x;

    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        for(int i=0;i<=10000;i++)
            cnt[i] = psum[i] = 0;

        scanf("%d %d", &N, &P);

        for(int i=1;i<=N;i++)
        {
            scanf("%d", &x);
            cnt[x]++;
        }

        for(int i=1;i<=10000;i++)
            psum[i] = cnt[i]*(10000LL-i);

        for(int i=1;i<=10000;i++)
            psum[i] += psum[i-1];
            
        int st = 10001;
        int cc = 0;
        llint ans = 2e18;
        llint tmp;

        for(int i=10000;i>=1;i--)
        {
            while(st>=1 && cc < P)
            {
                st--;
                cc += cnt[st];
            }

            if(cc<P) break;

            tmp = psum[i] - psum[st-1];
            tmp -= (10000LL - st) * (cc - P);
            tmp -= P * (10000LL - i);
            

            ans = min(ans, tmp);

            cc -= cnt[i];
        }

        printf("Case #%d: %lld\n", test_case, ans);
    }

    return 0;
}