// http://codeforces.com/contest/1131/problem/A

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long llint;


int main()
{
    int w1, w2, h1, h2;

    scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
    printf("%d\n", 2*w1+2*(h1+h2) + 4);
    return 0;
}