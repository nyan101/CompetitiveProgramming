// http://codeforces.com/contest/1132/problem/A

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long llint;


int main()
{
	llint a, b, c, d;

	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

	if(a!=d)
		printf("0\n");
	else if(c>0 && a==0)
		printf("0\n");
	else
		printf("1\n");

    return 0;
}