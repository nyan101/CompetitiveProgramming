#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
int a[100005];
int cnt[100005];
vector<int> vec[100005];

int seg[400005];
int lazy[400005];
int ans = 0;

void pushdown(int v)
{
    seg[2*v]  += lazy[v];
    lazy[2*v] += lazy[v];
    
    seg[2*v+1]  += lazy[v];
    lazy[2*v+1] += lazy[v];

    lazy[v] = 0;
}

int getMax(int v, int l, int r, int st, int ed)
{
    if(st <= l && r <= ed)
        return seg[v];

    int mid = (l+r)/2;
    int res = 0;

    pushdown(v);
    if(st<=mid)
        res = max(res, getMax(v*2, l, mid, st, ed));
    if(mid+1<=ed)
        res = max(res, getMax(v*2+1, mid+1, r, st, ed));

    return res;
}

void add(int v, int l, int r, int st, int ed, int val)
{
    if(st <= l && r <= ed)
    {
        seg[v] += val;
        lazy[v] += val;
        return;
    }

    int mid = (l+r)/2;

    pushdown(v);
    if(st<=mid)
        add(v*2, l, mid, st, ed, val);
    if(mid+1<=ed)
        add(v*2+1, mid+1, r, st, ed, val);

    seg[v] = max(seg[v*2], seg[v*2+1]);
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d %d", &N, &S);

        for(int i=1;i<=100000;i++)
            vec[i].clear();

        fill(seg, seg+400001, 0);
        fill(lazy, lazy+400001, 0);

        for(int i=1;i<=N;i++)
        {
            scanf("%d", &a[i]);
            vec[a[i]].push_back(i);
        }
        for(int i=1;i<=100000;i++)
            vec[i].push_back(N+1);

        int cc = 0;
        fill(cnt, cnt+100001, 0);
        for(int i=1;i<=N;i++)
        {
            cnt[a[i]]++;
            if(cnt[a[i]]<=S)   cc += 1;
            if(cnt[a[i]]==S+1) cc -= S;

            add(1, 1, N, i, i, cc);
        }
        ans = getMax(1, 1, N, 1, N);

        for(int i=1;i<=N-1;i++)
        {
            auto &v = vec[a[i]];
            int idx = lower_bound(v.begin(), v.end(), i) - v.begin();
            
            int ed = (idx+S) < v.size() ? v[idx+S]-1 : N;
            add(1, 1, N, i+1, ed, -1);

            int ed2 = (idx+S+1) < v.size() ? v[idx+S+1]-1 : N;
            if(ed!=N)
                add(1, 1, N, ed+1, ed2, S);

            ans = max(ans, getMax(1, 1, N, i+1, N));
        }
        printf("Case #%d: %d\n", test_case, ans);
    }

    return 0;
}