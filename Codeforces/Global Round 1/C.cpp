// http://codeforces.com/contest/1110
// 2019.02.07

#include <cstdio>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long llint;

using namespace std;

int Q, a;

int arr[] = {-1, -1, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int main()
{
    int res;

    scanf("%d", &Q);

    for(int q=1;q<=Q;q++)
    {
        scanf("%d", &a);

        if((a & (a+1)) != 0)
        {
            res = 1;
            while(res <= a)
                res *= 2;
            res--;
            printf("%d\n", res);
        }
        else
        {
            int idx = (int)(log2(a+1) + 0.5);

            printf("%d\n", arr[idx]);
        }
    }

    return 0;
}