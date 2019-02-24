// http://codeforces.com/contest/1131/problem/F

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

typedef long long llint;

int n;

vector<int> G[150002];
int par[150002];
int sz[150002];
vector<int> ans;

int ufind(int v) { return par[v] < 0? v : ufind(par[v]); }

void dfs(int v)
{
	ans.push_back(v);

	for(int nv : G[v])
		dfs(nv);
}

int main()
{
	int x, y;

	scanf("%d", &n);

	for(int i=0;i<=n;i++)
	{
		par[i] = -1;
		sz[i] = 1;
	}

	for(int i=1;i<=n-1;i++)
	{
		scanf("%d %d", &x, &y);

		int rx = ufind(x);
		int ry = ufind(y);

		if(rx==ry) continue;

		if(sz[rx] < sz[ry])
			swap(rx, ry);

		sz[rx] += sz[ry];
		par[ry] = rx;
		G[rx].push_back(ry);
	}

	dfs(ufind(1));

	for(int i=0;i<n;i++)
		printf("%d ", ans[i]);
	printf("\n");


    return 0;
}