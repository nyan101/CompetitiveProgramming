// http://codeforces.com/contest/1117/problem/E

#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

typedef long long llint;

int n;
char ss[10005], rs[10005];
char s1[10005], s2[10005], s3[10005];
int a[17580];
set<int> S[17580];


int main()
{
    scanf("%s", ss);
    n = strlen(ss);

    printf("? ");
    for(int i=0;i<n;i++)
        printf("%c", 'a'+(i%26));
    printf("\n");
    fflush(stdout);

    scanf("%s", s1);

    for(int i=0;i<n;i++)
    {
        int st = (s1[i]-'a')%26;

        for(int nv=st;nv<n;nv+=26)
            S[i].insert(nv);
    }


    printf("? ");
    for(int i=0;i<n;i++)
        printf("%c", 'a'+((i/26)%26));
    printf("\n");
    fflush(stdout);

    scanf("%s", s2);

    for(int i=0;i<n;i++)
    {
        vector<int> toErase;
        for(int idx : S[i])
        {
            char ch = 'a'+((idx/26)%26);
            if(s2[i]!=ch)
                toErase.push_back(idx);
        }
        for(int idx : toErase)
            S[i].erase(idx);
    }

    printf("? ");
    for(int i=0;i<n;i++)
        printf("%c", 'a'+((i/676)%26));
    printf("\n");
    fflush(stdout);

    scanf("%s", s3);

    for(int i=0;i<n;i++)
    {
        vector<int> toErase;
        for(int idx : S[i])
        {
            char ch = 'a'+((idx/676)%26);
            if(s3[i]!=ch)
                toErase.push_back(idx);
        }
        for(int idx : toErase)
            S[i].erase(idx);
    }

    for(int i=0;i<n;i++)
    {
        for(int idx : S[i])
            rs[idx] = ss[i];
    }

    printf("! %s\n", rs);
    fflush(stdout);

    return 0;
}
