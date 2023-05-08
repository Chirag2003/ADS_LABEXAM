#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int n, m; // number of vertices and edges
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], cost[MAXN << 1], cnt;
int dis[MAXN], vis[MAXN];
struct Edge
{
  int u, v, w;
  bool operator<(const Edge &rhs) const
  {
    return w < rhs.w;
  }
} edges[MAXN << 1];

void addEdge(int u, int v, int w)
{
  to[++cnt] = v;
  cost[cnt] = w;
  nxt[cnt] = head[u];
  head[u] = cnt;
}

void init()
{
  memset(head, -1, sizeof(head));
  memset(vis, 0, sizeof(vis));
  memset(dis, INF, sizeof(dis));
  cnt = -1;
}

void prim(int s)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, s));
  dis[s] = 0;
  while (!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (int i = head[u]; i != -1; i = nxt[i])
    {
      int v = to[i], w = cost[i];
      if (!vis[v] && dis[v] > w)
      {
        dis[v] = w;
        pq.push(make_pair(dis[v], v));
      }
    }
  }
}

int find(int x, int *p)
{
  if (x != p[x])
  {
    p[x] = find(p[x], p);
  }
  return p[x];
}

void kruskal()
{
  sort(edges, edges + m);
  int p[MAXN];
  for (int i = 1; i <= n; i++)
  {
    p[i] = i;
  }
  int ans = 0, cnt = 0;
  for (int i = 0; i < m; i++)
  {
    int u = edges[i].u, v = edges[i].v, w = edges[i].w;
    int pu = find(u, p), pv = find(v, p);
    if (pu != pv)
    {
      p[pu] = pv;
      ans += w;
      cnt++;
      if (cnt == n - 1)
        break;
    }
  }
  cout << ans << endl;
}

int main()
{
  init();
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    addEdge(u, v, w);
    addEdge(v, u, w);
    edges[i] = (Edge){u, v, w};
  }
  prim(1);
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += dis[i];
  }
  cout << ans << endl;
  kruskal();
  return 0;
}