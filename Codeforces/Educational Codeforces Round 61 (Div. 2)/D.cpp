// http://codeforces.com/contest/1132/problem/D

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long llint;

int n, k;
llint a[200002], b[200002], c[200002];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
		scanf("%lld", &a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld", &b[i]);

	llint l = 0, r=1e13;
	while(l<r)
	{
		llint mid = (l+r)/2;

		priority_queue<pair<llint,int>> PQ;
		for(int i=1;i<=n;i++)
		{
			c[i] = a[i];
			PQ.push({-1*(c[i]/b[i]), i});
		}

		bool flag = true;
		for(int t=0;t<=k-1;t++)
		{
			auto p = PQ.top(); PQ.pop();
			if(-1*p.first < t)
			{
				flag = false;
				break;
			}
			c[p.second] = min(c[p.second]+mid, k*b[p.second]);
			PQ.push({-1*(c[p.second]/b[p.second]), p.second});
		}

		if(flag)
			r = mid;
		else 
			l = mid+1;
	}

	printf("%lld\n", (l==1e13)? -1 : l);

    return 0;
}