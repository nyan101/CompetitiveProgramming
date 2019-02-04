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
vector<vector<int>> G;
priority_queue<int> PQ;
bool visit[100005], chk[100005];
vector<int> ans;

int main()
{
	int a, b;

	scanf("%d %d", &n, &m);

	G.resize(n+5);

	for(int i=1;i<=m;i++)
	{
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for(int i=1;i<=n;i++)
		visit[i] = chk[i] = false;
	
	PQ.push(-1);
	chk[1] = true;

	while(!PQ.empty())
	{
		int v = -1*PQ.top(); PQ.pop();

		if(visit[v])
			continue;

		ans.push_back(v);
		visit[v] = true;

		for(int nv : G[v])
		{
			if(chk[nv])
				continue;

			chk[nv] = true;
			PQ.push(-1*nv);
		}
	}

	for(int v : ans)
		printf("%d ", v);
	printf("\n");


    return 0;
}