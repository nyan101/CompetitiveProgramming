// http://codeforces.com/contest/1114
// 2019.02.10

#include <cstdio>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long llint;

using namespace std;

int main()
{
    int x, y, z, a, b, c;
    int eat;

    bool flag = true;

    scanf("%d %d %d", &x, &y, &z);
    scanf("%d %d %d", &a, &b, &c);

    if(a < x)
        flag = false;

    eat = min(a, x);

    a -= eat;

    if(a+b < y)
        flag = false;

    eat = min(a, y);
    a -= eat;
    y -= eat;

    eat = min(b, y);
    b -= eat;
    y -= eat;

    if(a+b+c < z)
        flag = false;

    if(flag)
        printf("YES\n");
    else
        printf("NO\n");



    return 0;
}