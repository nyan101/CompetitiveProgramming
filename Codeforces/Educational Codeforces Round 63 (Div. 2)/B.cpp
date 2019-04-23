#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char ss[100005];

int main()
{
    scanf("%d", &n);
    scanf("%s", ss);

    int cnt = 0;
    for(int i=0;i<=n-11;i++)
    {
        if(ss[i]=='8')
            cnt--;
        else
            cnt++;
    }

    if(cnt<0)
        printf("YES\n");
    else
        printf("NO\n");


    return 0;
}