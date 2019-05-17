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
char ss[] = "aeiou";

int main()
{
    scanf("%d", &n);

    int cc = 1;
    for(int i=5;i<=n/5;i++)
    {
        if(n%i==0)
        {
            cc = i;
            break;
        }
    }

    if(cc==1)
        printf("-1\n");
    else
    {
        for(int i=0;i<n/cc;i++)
        {
            for(int j=0;j<cc;j++)
                printf("%c", ss[(i+j)%5]);
        }
        printf("\n");
    }

    return 0;
}