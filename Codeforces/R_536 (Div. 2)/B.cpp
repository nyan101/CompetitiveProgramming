// http://codeforces.com/contest/1106/my
// 2019.01.31

#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n, m;
int a[100005];
llint c[100005];
int t, d;
vector<int> vec;
queue<int> Q;

int main()
{
	scanf("%d %d", &n, &m);

	for(int i=1;i<=n;i++)
	{
		scanf("%d", &a[i]);
		vec.push_back(i);
	}
	for(int i=1;i<=n;i++)
		scanf("%lld", &c[i]);

	sort(vec.begin(), vec.end(), [&](int i, int j){ return (c[i]!=c[j])? (c[i]<c[j]) : (i<j); });
	for(int idx : vec)
		Q.push(idx);

	for(int i=1;i<=m;i++)
	{
		scanf("%d %d", &t, &d);

		int cnt = min(a[t], d);
		llint cost = 0;

		cost += c[t]*cnt;
		d -= cnt;
		a[t] -= cnt;

		while(d > 0)
		{
			while(!Q.empty() && a[Q.front()]==0)
				Q.pop();

			if(Q.empty())
				break;

			t = Q.front();
			cnt = min(a[t], d);
			cost += c[t] * cnt;
			d -= cnt;
			a[t] -= cnt;
		}

		if(d>0)
			cost = 0;

		printf("%lld\n", cost);
	}
    return 0;
}