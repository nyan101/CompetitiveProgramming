// http://codeforces.com/contest/1106/my
// 2019.01.31

#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n, m, k;

int dd[100005];
llint ww[100005];

int dvec[100005];
llint wvec[100005];

bool chk[100005];
llint dp[201][100005];

priority_queue<pair<pair<llint, int>, int>> PQ;
vector<pair<int, pair<int,int>>> events;

int main()
{
	int s, t, d;
	llint w;

	scanf("%d %d %d", &n, &m, &k);

	for(int i=1;i<=k;i++)
	{
		scanf("%d %d %d %lld", &s, &t, &d, &w);

		events.push_back({s, {i, 1}});
		events.push_back({t+1, {i, -1}});
		dvec[i] = d;
		wvec[i] = w;
	}

	sort(events.begin(), events.end());

	auto it = events.begin();

	for(int i=1;i<=n;i++)
	{
		while(it != events.end() && (*it).first==i)
		{
			auto p = (*it).second;

			if(p.second==1)
			{
				PQ.push({{wvec[p.first], dvec[p.first]}, p.first});
				chk[p.first] = true;
			}
			else
				chk[p.first] = false;
			++it;
		}

		ww[i] = 0;
		dd[i] = i;

		while(!PQ.empty() && chk[PQ.top().second]==false)
			PQ.pop();

		if(!PQ.empty())
		{
			ww[i] = PQ.top().first.first;
			dd[i] = PQ.top().first.second;
		}
	}

	dp[0][n+1] = 0;
	for(int i=n;i>=1;i--)
		dp[0][i] = ww[i] + dp[0][dd[i]+1];
	
	for(int i=1;i<=m;i++)
	{
		dp[i][n+1] = 0;
		for(int j=n;j>=1;j--)
			dp[i][j] = min(dp[i-1][j+1], ww[j] + dp[i][dd[j]+1]);
	}

	printf("%lld\n", dp[m][1]);
    return 0;
}