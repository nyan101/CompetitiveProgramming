// http://codeforces.com/contest/1131/problem/E

#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long llint;

int n;
char ss[100005];
llint cnt[256];
llint cnt2[256];

char lch, rch, ch;
int llen, rlen, len;
int maxi = -1;

int main()
{
	bool allsame;

	scanf("%d", &n);
	scanf("%s", ss);

	len = strlen(ss);
	for(int i=0;i<len;i++)
	{
		int j;
		for(j=i;j<len && ss[i]==ss[j];j++);

		cnt[ss[i]] = max(cnt[ss[i]], (llint)j-i);
		i = j-1;
	}

	for(int q=2;q<=n;q++)
	{
		scanf("%s", ss);

		len = strlen(ss);
		lch = ss[0]; llen = 1;
		for(;llen<len && ss[llen]==lch; llen++);
		rch = ss[len-1]; rlen = 1;
		for(;rlen<len && ss[len-rlen-1]==rch; rlen++);
		allsame = (len==llen);

		for(int ch='a';ch<='z';ch++) cnt2[ch] = 0;
		for(int i=0;i<len;i++)
		{
			int j;
			for(j=i;j<len && ss[i]==ss[j];j++);

			cnt2[ss[i]] = max(cnt2[ss[i]], (llint)j-i);
			i = j-1;
		}

		cnt2[lch] = llen + (cnt[lch]>0);
		cnt2[rch] = rlen + (cnt[rch]>0);

		if(lch==rch && cnt[lch] > 0)
			cnt2[lch] = llen + rlen + 1;

		if(allsame)
			cnt2[ss[0]] = (cnt[ss[0]] + 1) * len + cnt[ss[0]];

		for(int ch='a';ch<='z';ch++)
		{
			if(cnt[ch] > 0)
				cnt2[ch] = max(cnt2[ch], (llint)1);
		}

		for(int ch='a';ch<='z';ch++)
			cnt[ch] = cnt2[ch];
	}

	llint ans = 0;
	for(int i='a';i<='z';i++)
		ans = max(ans, cnt[i]);
	
	printf("%lld\n", ans);
    return 0;
}