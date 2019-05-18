#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int day;

int pre = 50;
int rem = 10;
int discard = 20 - rem;

int cc[22];
vector<int> vec[22];

priority_queue<pair<int,int>> PQ;

int main()
{
    int n, x;
    int T;

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        while(!PQ.empty()) PQ.pop();
        for(int i=1;i<=20;i++)
            cc[i] = 0;

        for(int d=1;d<=pre;d++)
        {
            scanf("%d", &day);
            printf("%d %d\n", 20-(d%discard),100);
        }
        
        for(int d=pre+1;d<=pre+rem;d++)
        {
            scanf("%d", &day);
            printf("%d %d\n", d-pre, 0);

            scanf("%d", &n);
            for(int i=1;i<=n;i++)
                scanf("%d", &x);
            cc[d-pre] = n;
            PQ.push({-n, d-pre});
        }

        int idx = PQ.top().second; PQ.pop();

        for(int d=pre+rem+1;d<=99;d++)
        {
            scanf("%d", &day);
            auto p = PQ.top(); PQ.pop();
            printf("%d %d\n", p.second, 100);
            PQ.push({p.first-1, p.second});
        }

        scanf("%d", &day);
        printf("%d %d\n", idx, 100);
    }

    return 0;
}
