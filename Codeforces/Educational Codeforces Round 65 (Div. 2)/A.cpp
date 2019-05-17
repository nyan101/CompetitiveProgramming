#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;


int n;
char s[102];

int main()
{
    int T;
    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d", &n);
        scanf("%s", s);

        int st = n;
        for(int i=0;s[i]!=0;i++)
        {
            if(s[i]=='8')
            {
                st = i;
                break;
            }
        }

        if(n - st >= 11)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}