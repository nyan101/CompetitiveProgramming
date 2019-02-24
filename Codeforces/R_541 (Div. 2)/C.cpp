// http://codeforces.com/contest/1131/problem/C

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long llint;

int n;
vector<int> vec;
int a[102];

int main()
{
	int x;

	scanf("%d", &n);

	for(int i=0;i<n;i++)
	{
		scanf("%d", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());

	for(int i=0;2*i<n;i++)
	{
		a[i] = vec[2*i];
		if(2*i+1 < n)
			a[n-i-1] = vec[2*i+1];
	}

	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");

    return 0;
}