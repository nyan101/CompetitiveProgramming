// Only for small case

#include <cstdio>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;

int R, C;
bool chk[24][24];
stack<pair<int,int>> stk;

bool dfs(int r, int c)
{
    chk[r][c] = true;
    stk.push({r,c});

    if(stk.size()==R*C)
        return true;

    for(int i=1;i<=R;i++)
    {
        if(r==i) continue;
        for(int j=1;j<=C;j++)
        {
            if(chk[i][j] || c==j || r+c==i+j || r-c==i-j)
                continue;
            bool res = dfs(i,j);
            if(res)
                return true;
        }
    }
    chk[r][c] = false;
    stk.pop();

    return false;
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d %d", &R, &C);

        for(int i=0;i<=R;i++)
        {
            for(int j=0;j<=C;j++)
                chk[i][j] = false;
        }
        while(!stk.empty()) stk.pop();

        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=2;j++)
            {
                if(dfs(i,j))
                    break;
            }
        }

        if(stk.size()==R*C)
        {
            printf("Case #%d: POSSIBLE\n", test_case);
            while(!stk.empty())
            {
                printf("%d %d\n", stk.top().first, stk.top().second);
                stk.pop();
            }
        }
        else
            printf("Case #%d: IMPOSSIBLE\n", test_case);
    }

    return 0;
}