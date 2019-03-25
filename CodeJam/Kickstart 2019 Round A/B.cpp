#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef long long llint;

int R, C;
char ss[305][305];
int visit[305][305];
int up[605], down[605];

int main()
{
    int T;

    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d %d", &R, &C);

        for(int i=1;i<=R;i++)
            scanf("%s", ss[i]+1);

        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=C;j++)
                visit[i][j] = 999;
        }

        for(int i=0;i<=300;i++)
        {
            visit[i][0] = visit[i][C+1] = -1;
            visit[0][i] = visit[R+1][i] = -1;
        }

        for(int i=0;i<=600;i++)
            up[i] = down[i] = 0;

        queue<pair<int,int>> Q;
        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=C;j++)
            {
                up[i+j]++;
                down[i-j+300]++;

                if(ss[i][j]=='1')
                {
                    Q.push({i,j});
                    visit[i][j] = 0;
                }
            }
        }

        int ans = 999;
        int umax, umin, dmax, dmin;
        umax = R+C;
        umin = 0;
        dmax = +R + 300;
        dmin = -C + 300;

        while(!Q.empty())
        {
            int x, y, nx, ny;
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();

            up[x+y]--;
            down[x-y+300]--;

            while(umax >= umin && up[umax]==0) umax--;
            while(umin <= umax && up[umin]==0) umin++;
            while(dmax >= dmin && down[dmax]==0) dmax--;
            while(dmin <= dmax && down[dmin]==0) dmin++;

            int U = umax - umin + 1;
            int D = dmax - dmin + 1;
        
            if(U==D && ((umax + dmax)%2==1 || (umax + dmin)%2==1))
                ans = min(ans, max(visit[x][y], (1+max(U,D))/2));    
            else
                ans = min(ans, max(visit[x][y], max(U,D)/2));


            nx = x+1; ny = y;
            if(visit[nx][ny] > visit[x][y]+1){ visit[nx][ny]=visit[x][y]+1; Q.push({nx,ny}); }

            nx = x-1; ny = y;
            if(visit[nx][ny] > visit[x][y]+1){ visit[nx][ny]=visit[x][y]+1; Q.push({nx,ny}); }

            nx = x; ny = y+1;
            if(visit[nx][ny] > visit[x][y]+1){ visit[nx][ny]=visit[x][y]+1; Q.push({nx,ny}); }

            nx = x; ny = y-1;
            if(visit[nx][ny] > visit[x][y]+1){ visit[nx][ny]=visit[x][y]+1; Q.push({nx,ny}); }
        }
            
        printf("Case #%d: %d\n", test_case, ans);
    }

    return 0;
}