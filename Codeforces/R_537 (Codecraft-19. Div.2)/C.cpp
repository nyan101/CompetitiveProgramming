// http://codeforces.com/contest/1111
// 2019.02.04

#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n, k;
vector<int> vec;
llint A, B;

int cnt(int st, int ed)
{
	int idx1 = lower_bound(vec.begin(), vec.end(), st) - vec.begin();
	int idx2 = upper_bound(vec.begin(), vec.end(), ed) - vec.begin();

	return idx2 - idx1;
}

llint f(int st, int ed)
{
	llint res = 0;
	int cc = cnt(st, ed);
	if(cc == 0)
		return A;
	res = (B*cc)*(ed-st+1);
	if(st!=ed)
	{
		int mid = (st+ed)/2;
		res = min(res, f(st, mid)+f(mid+1, ed));
	}
	return res;
}

int main()
{
	int x;

	scanf("%d %d %lld %lld", &n, &k, &A, &B);

	for(int i=0;i<k;i++)
	{
		scanf("%d", &x);
		vec.push_back(x);
	}

	sort(vec.begin(), vec.end());

	printf("%lld\n", f(1, 1<<n));

    return 0;
}