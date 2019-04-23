#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char ss[300005];

int main()
{
    bool flag = false;
    int idx = -1;

    scanf("%d", &n);
    scanf("%s", ss);

    for(int i=0;i<n-1;i++)
    {
        if(ss[i]>ss[i+1])
        {
            flag = true;
            idx = i;
            break;
        }
    }

    if(!flag)
        printf("NO\n");
    else
    {
        printf("YES\n");
        printf("%d %d\n", idx+1, idx+2);
    }


    return 0;
}