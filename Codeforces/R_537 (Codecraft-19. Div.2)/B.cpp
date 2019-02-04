// http://codeforces.com/contest/1111
// 2019.02.04

#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n, k, m;
vector<int> vec;

int main()
{
	int x;
	scanf("%d %d %d", &n, &k, &m);

	for(int i=1;i<=n;i++)
	{
		scanf("%d", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	llint su=0;
	double ans = 0;

	for(int i=1;i<=n;i++)
	{
		su += vec[i-1];

		if(m - (n-i) < 0)
			continue;

		llint add = m - (n-i);

		add = min(add, ((llint)k)*i);

		ans = max(ans, (1.0*(su + add))/i);
	}

	printf("%.9lf\n", ans);

    return 0;
}