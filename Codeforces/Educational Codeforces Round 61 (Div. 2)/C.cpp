// http://codeforces.com/contest/1132/problem/C

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long llint;

int n, q;
int l[5002], r[5002];
int a[5005], b[5005];

int f1(int st, int ed)
{
	return a[ed] - a[st-1];
}

int f2(int st, int ed)
{
	return b[ed] - b[st-1];
}

int main()
{
	scanf("%d %d", &n, &q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d", &l[i], &r[i]);
		a[l[i]]++;
		a[r[i]+1]--;
	}

	for(int i=1;i<=n;i++)
		a[i] += a[i-1];

	int Area = 0;
	for(int i=1;i<=n;i++)
	{
		Area += (a[i]>0);
		b[i] = (a[i]==2);
		a[i] = (a[i]==1);
	}
	for(int i=1;i<=n;i++)
	{
		a[i] += a[i-1];
		b[i] += b[i-1];
	}

	int ans = 0;
	for(int i=1;i<=q;i++)
	{
		for(int j=i+1;j<=q;j++)
		{
			int l1, l2, r1, r2;
			l1 = l[i]; r1 = r[i];
			l2 = l[j]; r2 = r[j];

			if(l1 > l2)
			{
				swap(l1, l2);
				swap(r1, r2);
			}

			int loss = 0;
			if(r1 < l2)
				loss = f1(l1, r1) + f1(l2, r2);
			else if(r2 <= r1)
				loss = f1(l1, r1) + f2(l2, r2);
			else
				loss = f1(l1, r1) + f1(l2, r2) - f1(l2, r1) + f2(l2, r1);

			ans = max(ans, Area - loss);
		}
	}
	printf("%d\n", ans);


    return 0;
}