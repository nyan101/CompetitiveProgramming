// http://codeforces.com/contest/1110
// 2019.02.07

#include <cstdio>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long llint;

using namespace std;

int n;
int a[100002];
int b[100002];

int main()
{
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d", &b[i]);

    bool flag = true;

    if(a[1]!=b[1])
        flag = false;

    for(int i=1;i<=n-1;i++)
    {
        a[i] = a[i] - a[i+1];
        b[i] = b[i] - b[i+1];
    }
    sort(a+1, a+n);
    sort(b+1, b+n);

    for(int i=1;i<=n-1;i++)
    {
        if(a[i]!=b[i])
            flag = false;
    }

    if(flag)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}