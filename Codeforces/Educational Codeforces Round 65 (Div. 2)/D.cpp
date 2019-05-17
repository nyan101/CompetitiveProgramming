#include <cstdio>
#include <map>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;


int n;
char ss[200005];
char c[200005];

char tok = '0';
stack<int> stk;

int main()
{
    scanf("%d", &n);
    scanf("%s", ss);

    for(int i=0;ss[i]!=0;i++)
    {
        if(ss[i]=='(')
        {
            stk.push(i);
            continue;
        }

        c[stk.top()] = '0' + (stk.size() % 2);
        c[i] = '0' + (stk.size() % 2);
        stk.pop();
    }
    c[n] = 0;

    printf("%s\n", c);

    return 0;
}