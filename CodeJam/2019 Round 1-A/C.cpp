#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char ss[52];

int num;
int tri[50005][26], cc[50005];

void initNode(int v)
{
    cc[v] = 0;
    for(int i=0;i<26;i++)
        tri[v][i] = -1;
}

int dfs(int v)
{
    if(v==-1) return 0;

    int res = 0;
    for(int i=0;i<26;i++)
        res += dfs(tri[v][i]);
    if(cc[v] - res>=2)
        res += 2;

    return res;
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d", &n);
        num = 1;
        initNode(0);
        for(int i=1;i<=n;i++)
        {
            scanf("%s", ss);
            reverse(ss, ss+strlen(ss));
            
            int v = 0;
            for(int j=0;ss[j]!=0;j++)
            {
                if(tri[v][ss[j]-'A']==-1)
                {
                    initNode(num);
                    tri[v][ss[j]-'A'] = num;
                    num++;
                }
                v = tri[v][ss[j]-'A'];
                cc[v]++;
            }
        }
        
        int ans = dfs(0);
        printf("Case #%d: %d\n", test_case, ans);
    }

    return 0;
}