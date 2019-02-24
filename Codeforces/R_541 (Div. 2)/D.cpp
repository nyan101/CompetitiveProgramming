// http://codeforces.com/contest/1131/problem/D

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long llint;

int n, m;
int a[1002][1002];
int p1[1002], p2[1002];
int ans1[1002], ans2[1002];
char ss[1005];

bool cmp1(int x1, int x2)
{
	return p1[x1] < p1[x2];
}

bool cmp2(int y1, int y2)
{
	return p2[y1] < p2[y2];
}

int main()
{
	scanf("%d %d", &n, &m);

	for(int i=1;i<=n;i++)
	{
		scanf("%s", ss);
		for(int j=1;j<=m;j++)
		{
			a[i][j] = 1;
			if(ss[j-1]=='<') // -1
				a[i][j] = 0;
			else if(ss[j-1]=='>') // +1
				a[i][j] = 2;
		}
	}

	vector<int> vec1, vec2;
	for(int i=1;i<=n;i++)
	{
		vec1.push_back(i);
		p1[i] = 0;
		for(int j=1;j<=m;j++)
			p1[i] += a[i][j];
	}
	for(int j=1;j<=m;j++)
	{
		vec2.push_back(j);
		p2[j] = 0;
		for(int i=1;i<=n;i++)
			p2[j] += 2 - a[i][j];
	}
	sort(vec1.begin(), vec1.end(), cmp1);
	sort(vec2.begin(), vec2.end(), cmp2);

	for(int i=1;i<=n;i++)
		a[i][0] = 0;
	for(int j=1;j<=m;j++)
		a[0][j] = 2;
	a[0][0] = 1;

	int idx1, idx2;
	idx1 = idx2 = 0;

	int p = 1;
	while(idx1 < vec1.size() && idx2 < vec2.size())
	{
		int x = vec1[idx1];
		int y = vec2[idx2];

		if(a[x][y] == 0)
		{
			while(idx1 < vec1.size() && p1[vec1[idx1]]==p1[x])
			{
				ans1[vec1[idx1]] = p;
				idx1++;
			}
			p++;
		}
		else if(a[x][y]==2)
		{
			while(idx2 < vec2.size() && p2[vec2[idx2]]==p2[y])
			{
				ans2[vec2[idx2]] = p;
				idx2++;
			}
			p++;
		}
		else // 0
		{
			while(idx1 < vec1.size() && p1[vec1[idx1]]==p1[x])
			{
				ans1[vec1[idx1]] = p;
				idx1++;
			}
			while(idx2 < vec2.size() && p2[vec2[idx2]]==p2[y])
			{
				ans2[vec2[idx2]] = p;
				idx2++;
			}
			p++;
		}
	}

	while(idx1 < vec1.size())
	{
		int x = vec1[idx1];
		while(idx1 < vec1.size() && p1[vec1[idx1]]==p1[x])
		{
			ans1[vec1[idx1]] = p;
			idx1++;
		}
		p++;
	}

	while(idx2 < vec2.size())
	{
		int x = vec2[idx2];
		while(idx2 < vec2.size() && p2[vec2[idx2]]==p2[x])
		{
			ans2[vec2[idx2]] = p;
			idx2++;
		}
		p++;
	}

	bool flag = true;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==0 && !(ans1[i] < ans2[j]))
				flag = false;
			if(a[i][j]==1 && !(ans1[i]==ans2[j]))
				flag = false;
			if(a[i][j]==2 && !(ans1[i] > ans2[j]))
				flag = false;
		}
	}

	if(flag==false)
		printf("No\n");
	else
	{
		printf("Yes\n");
		for(int i=1;i<=n;i++)
			printf("%d ", ans1[i]);
		printf("\n");
		for(int j=1;j<=m;j++)
			printf("%d ", ans2[j]);
		printf("\n");
	}

	

    return 0;
}