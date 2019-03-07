// http://codeforces.com/contest/1132/problem/F

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long llint;

const int INF = 600;

int n;
char s[505], ss[505];
int dp[502][502];

int f(int st, int ed)
{
	if(st > ed)
		return 0;

	if(st==ed)
		return 1;

	if(dp[st][ed]!=0)
		return dp[st][ed];

	int res = f(st+1, ed) + 1;
	for(int i=st+1;i<=ed;i++)
	{
		if(ss[st]==ss[i])
			res = min(res, f(st+1, i-1) + f(i, ed));
	}

	dp[st][ed] = res;
	return res;
}

int main()
{
	scanf("%d ", &n);
	scanf("%s", s);

	s[n] = -1;

	int n2 = 0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]!=s[i])
			ss[n2++] = s[i-1];
	}
	n = n2;

	printf("%d\n", f(0, n-1));

    return 0;
}