#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
char ss[100005];
int cnt[26][100005];

int main()
{
    int T;
    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d %d ", &N, &Q);
        scanf("%s", ss+1);
        for(int i=0;i<26;i++)
            fill(cnt[i], cnt[i]+100002, 0);
        
        for(int i=1;ss[i]!=0;i++)
            cnt[ss[i]-'A'][i] = 1;
        
        for(int i=0;i<26;i++)
        {
            for(int j=1;j<=N;j++)
                cnt[i][j] += cnt[i][j-1];
        }

        int ans = 0;
        int l, r;
        for(int q=1;q<=Q;q++)
        {
            scanf("%d %d", &l, &r);
            int chk1 = (r-l+1)%2;
            int chk2 = 0;
            for(int i=0;i<26;i++)
                chk2 += (cnt[i][r] - cnt[i][l-1])%2;

            if(chk1==chk2)
                ans++;
        }
        printf("Case #%d: %d\n", test_case, ans);
    }

    return 0;
}