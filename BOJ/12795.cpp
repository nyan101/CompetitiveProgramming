#include <cstdio>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long llint;

const llint INF = 2e18;
const llint XMAX =  1e12;
const llint XMIN = -1e12;

int Q;
int idx;
vector<pair<int,int>> tree;
vector<llint> a, b;

llint query(int v, llint l, llint r, llint x)
{
	if(v==-1)
		return -INF;

	llint res = a[v]*x + b[v];
	llint mid = (l+r)>>1;

	if(l==r)
		return res;

	if(x<=mid)
		return max(res, query(tree[v].first, l, mid, x));
	else
		return max(res, query(tree[v].second, mid+1, r, x));
}

void add(int v, llint l, llint r, llint aa, llint bb)
{
	llint mid = (l+r)>>1;

	bool l_chk = (a[v]*l + b[v] < aa*l + bb);
	bool m_chk = (a[v]*mid + b[v] < aa*mid + bb);
	
	if(m_chk)
	{
		swap(a[v], aa);
		swap(b[v], bb);
	}

	if(l==r) return;

	if(l_chk != m_chk)
	{
		if(tree[v].first==-1)
		{
			tree[v].first = tree.size();
			tree.push_back({-1, -1});
			a.push_back(0);
			b.push_back(-INF);
		}
		add(tree[v].first, l, mid, aa, bb);
	}
	else
	{
		if(tree[v].second==-1)
		{
			tree[v].second = tree.size();
			tree.push_back({-1, -1});
			a.push_back(0);
			b.push_back(-INF);
		}
		add(tree[v].second, mid+1, r, aa, bb);
	}
}

int main()
{
	llint aa, bb, x;
	int op;

	tree.push_back({-1,-1});
	a.push_back(0);
	b.push_back(-INF);

	scanf("%d", &Q);

	for(int q=1;q<=Q;q++)
	{
		scanf("%d", &op);
		
		if(op==1)
		{
			scanf("%lld %lld", &aa, &bb);
			add(0, XMIN, XMAX, aa, bb);
		}
		else
		{
			scanf("%lld", &x);
			printf("%lld\n", query(0, XMIN, XMAX, x));
		}
	}

	return 0;
}