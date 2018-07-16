#include "../headers.hpp"
#include <queue>
using namespace std;

int *visited;

// for dense graphs
class graph
{
  private:
    int m_v;
    int m_e;

  public:
    int **adj;
    graph()
    {
        this.m_v = this.m_e = 0;
    }
    graph(int t_v, int t_e)
    {
        this.m_v = t_v;
        this.m_e = t_e;
        this.adj = malloc(sizeof(t_v * t_v));
        visited = malloc(sizeof(t_v));
        for (int u = 0; u < this.m_v; ++u)
            for (int v = 0; v < this.m_v; ++v)
                this.adj[u][v] = 0;
    }
    int returnV()
    {
        return this.m_v;
    }
    int returnE()
    {
        return this.m_e;
    }
    graph create_matrix(int t_v, int t_e);
    void dfs(int t_u)
    {
        visited[t_u] = 1;
        for (int v = 0; v < returnV(); ++v)
            if (!visited[v] && adj[t_u][v])
                dfs(g, v);
    }
    void bfs(int t_u)
    {
        queue<int> q;
        q.push(t_u);
        while (!q.empty())
        {
            t_u = q.front();
            q.pop();
            visited[t_u] = 1; // vertex u has been visited
            for (int v = 0; v < returnV(); ++v)
                if (!visited[v] && adj[t_u][v])
                    q.push(v);
        }
    }
    void dfs_traversal()
    {
        for (int i = 0; i < returnV(); ++i)
            visited[i] = 0;
        for (int i = 0; i < returnV(); ++i)
            if (!visited[i])
                dfs(i);
    }
    void bfs_traversal()
    {
        for (int i = 0; i < returnV(); ++i)
            visited[i] = 0;
        for (int i = 0; i < returnV(); ++i)
            if (!visited[i])
                bfs(i);
    }
};

graph graph::create_matrix(int t_v, int t_e)
{
    int i, u, v;
    graph g = new graph(t_v, t_e);

    if (!g)
        return nullptr;

    for (i = 0; i < g.returnE(); ++i) // for all edges
    {
        cout << endl
             << "Reading edge [u, v]";
        cin >> u >> v;
        g.adj[u][v] = 1;
        g.adj[v][u] = 1;
    }

    return g;
}
