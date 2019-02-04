// http://codeforces.com/contest/1111
// 2019.02.04

#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long llint;

using namespace std;

int n;
char s1[1002], s2[1002];

bool isVowel(char ch)
{
    return (ch=='a') || (ch=='e') || (ch=='i') || (ch=='o') || (ch=='u');
}

int main()
{
    scanf("%s", s1);
    scanf("%s", s2);

    if(strlen(s1)!=strlen(s2))
        printf("No\n");
    else
    {
        bool flag = true;
        for(int i=0;s1[i]!=0;i++)
        {
            if(isVowel(s1[i])!=isVowel(s2[i]))
                flag = false;
        }

        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}