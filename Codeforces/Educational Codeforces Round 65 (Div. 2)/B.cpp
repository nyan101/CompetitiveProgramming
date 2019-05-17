#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

llint a[6];
llint x[6];

int main()
{
    setbuf(stdout, NULL);
    printf("? 1 2\n"); scanf("%lld", &a[1]);
    printf("? 2 3\n"); scanf("%lld", &a[2]);
    printf("? 3 4\n"); scanf("%lld", &a[3]);
    printf("? 4 5\n"); scanf("%lld", &a[4]);

    if(a[1]%7==0 && a[2]%7!=0) x[1] = 42;
    if(a[1]%7==0 && a[2]%7==0) x[2] = 42;
    if(a[2]%7==0 && a[3]%7==0) x[3] = 42;
    if(a[3]%7==0 && a[4]%7==0) x[4] = 42;
    if(a[3]%7!=0 && a[4]%7==0) x[5] = 42;

    if(a[1]%5==0 && a[2]%5!=0) x[1] = 15;
    if(a[1]%5==0 && a[2]%5==0) x[2] = 15;
    if(a[2]%5==0 && a[3]%5==0) x[3] = 15;
    if(a[3]%5==0 && a[4]%5==0) x[4] = 15;
    if(a[3]%5!=0 && a[4]%5==0) x[5] = 15;
    
    if(a[1]%23==0 && a[2]%23!=0) x[1] = 23;
    if(a[1]%23==0 && a[2]%23==0) x[2] = 23;
    if(a[2]%23==0 && a[3]%23==0) x[3] = 23;
    if(a[3]%23==0 && a[4]%23==0) x[4] = 23;
    if(a[3]%23!=0 && a[4]%23==0) x[5] = 23;

    for(int c=0;c<10;c++)
    {
        for(int i=1;i<=4;i++)
        {
            if(x[i]==0) continue;

            x[i+1] = a[i] / x[i];
        }

        for(int i=2;i<=4;i++)
        {
            if(x[i]==0) continue;

            x[i-1] = a[i-1] / x[i];
        }
    }

    x[6] =  4 + 8 + 15 + 16 + 23 + 42 - x[1] - x[2] - x[3] - x[4] - x[5];

    printf("! ");
    for(int i=1;i<=6;i++)
        printf("%lld ", x[i]);
    printf("\n");

    return 0;
}