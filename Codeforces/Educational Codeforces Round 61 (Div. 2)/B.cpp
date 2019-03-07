// http://codeforces.com/contest/1132/problem/B

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long llint;

int n, m, q;
llint a[300002], su=0;

int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld", &a[i]);
		su += a[i];
	}
	sort(a, a+n);
	reverse(a, a+n);

	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		scanf("%d", &q);
		printf("%lld\n", su - a[q-1]);
	}

    return 0;
}