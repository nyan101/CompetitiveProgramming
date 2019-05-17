#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n;
int cnt[26];
char ss[102];

int main()
{
    llint ans = 0;

    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s", ss);
        cnt[ss[0]-'a']++;
    }

    int cc;
    for(int i=0;i<26;i++)
    {
        cc = cnt[i]/2;
        ans += (cc*(cc-1))/2;

        cc = (cnt[i]+1)/2;
        ans += (cc*(cc-1))/2;
    }

    printf("%lld\n", ans);

    return 0;
}