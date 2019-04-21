// Only passed small dataset
// get MCMF code from https://github.com/stjepang/snippets/blob/master/mcmf_dijkstra.cpp

#include <cstdio>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long llint;

namespace MCMF {
  const int MAXV = 1000100;
  const int MAXE = 1000100;
  const llint oo = 1e18;

  int V, E;
  int last[MAXV], how[MAXV]; llint dist[MAXV], pi[MAXV];
  int next[MAXE], from[MAXE], adj[MAXE];
  llint cap[MAXE], cost[MAXE];

  struct cmpf {
    bool operator () (int a, int b) {
      if (dist[a] != dist[b]) return dist[a] < dist[b];
      return a < b;
    }
  };
  set<int, cmpf> S;

  void init(int n) {
    V = n;
    E = 0;
    for(int i=0;i<V;i++)
        last[i] = -1;
  }

  void edge(int x, int y, llint c, llint w) {
    from[E] = x; adj[E] = y; cap[E] = c; cost[E] = +w; next[E] = last[x]; last[x] = E++;
    from[E] = y; adj[E] = x; cap[E] = 0; cost[E] = -w; next[E] = last[y]; last[y] = E++;
  }

  pair<llint, llint> run(int src, int sink) {
    llint total = 0;
    llint flow = 0;

    for(int i=0;i<V;i++) pi[i] = oo;
    pi[src] = 0;

    for (;;) {
      bool done = true;
      for(int x=0;x<V;x++)
        {
        for (int e = last[x]; e != -1; e = next[e])
        if (cap[e] && pi[adj[e]] > pi[x] + cost[e])
          pi[adj[e]] = pi[x] + cost[e], done = false;
        }
      if (done) break;
    }

    for (;;) {
        for(int i=0;i<V;i++)
            dist[i] = oo;
      S.clear();

      dist[src] = 0;
      S.insert(src);

      while (!S.empty()) {
        int x = *S.begin();
        S.erase(S.begin());
        if (x == sink) break;

        for (int e = last[x]; e != -1; e = next[e]) {
          if (cap[e] == 0) continue;

          int y = adj[e];
          llint val = dist[x] + pi[x] + cost[e] - pi[y];

          if (val < dist[y]) {
            S.erase(y);
            dist[y] = val;
            how[y] = e;
            S.insert(y);
          }
        }
      }
      if (dist[sink] >= oo / 2) break;

      llint aug = cap[how[sink]];
      for (int i = sink; i != src; i = from[how[i]])
        aug = min(aug, cap[how[i]]);

      for (int i = sink; i != src; i = from[how[i]]) {
        cap[how[i]] -= aug;
        cap[how[i]^1] += aug;
        total += cost[how[i]] * aug;
      }
      flow += aug;

      for(int i=0;i<V;i++)
        pi[i] = min(pi[i] + dist[i], oo);
    }

    return {total, flow};
  }
}

int N;
int S[100005];
int E[100005];
int L[100005];

int main()
{
    int T;
    scanf("%d", &T);

    setbuf(stdout, NULL);
    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d", &N);
        for(int i=1;i<=N;i++)
            scanf("%d %d %d", &S[i], &E[i], &L[i]);

        MCMF::init(300);
        for(int i=1;i<=N;i++)
        {
            MCMF::edge(0, i, 1, 0);
            MCMF::edge(i+100, 201, 1, 0);

            for(int j=1;j<=N;j++)
                MCMF::edge(i, j+100, 1, 100000 - max(E[i] - L[i]*S[1]*(j-1), 0));
        }
        auto p = MCMF::run(0, 201);

        printf("Case #%d: %d\n", test_case, 100000*N - p.first);
    }
    
    return 0;
}
