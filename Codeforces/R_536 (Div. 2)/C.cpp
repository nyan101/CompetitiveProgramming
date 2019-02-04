// http://codeforces.com/contest/1106/my
// 2019.01.31

#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n;
vector<llint> vec;

int main()
{
	llint x;
	scanf("%d", &n);

	for(int i=1;i<=n;i++)
	{
		scanf("%lld", &x);
		vec.push_back(x);
	}

	sort(vec.begin(), vec.end());

	llint ans = 0;
	for(int i=0;i<n/2;i++)
		ans += (vec[i] + vec[vec.size()-i-1])*(vec[i] + vec[vec.size()-i-1]);
	
	printf("%lld\n", ans);

    return 0;
}