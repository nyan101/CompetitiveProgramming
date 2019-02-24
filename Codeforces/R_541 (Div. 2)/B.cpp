// http://codeforces.com/contest/1131/problem/B

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

typedef long long llint;

int n;
set<int> S;

int main()
{
	int a, b, pa, pb;
	int ans = 0;

	scanf("%d", &n);

	ans = 0;
	pa = pb = 0;
	S.insert(0);

	for(int i=1;i<=n;i++)
	{
		scanf("%d %d", &a, &b);

		int mini = max(pa, pb) + (pa==pb);
		int maxi = min(a, b) - (a==b);

		ans += max(0, maxi - mini + 1);

		if(a==b)
			S.insert(a);

		pa = a;
		pb = b;
	}
	printf("%d\n", ans + S.size());
    return 0;
}