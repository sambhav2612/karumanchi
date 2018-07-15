#include "../headers.hpp"

// for dense graphs
class graph
{
  private:
    int v;
    int e;

  public:
    int **adj;
    graph(int v, int e)
    {
        this.v = v;
        this.e = e;
        this.adj = malloc(sizeof(v * v));
        for (int u = 0; u < this.v; ++u)
            for (int v = 0; v < this.v; ++v)
                this.adj[u][v] = 0;
    }
    int returnE()
    {
        return this.e;
    }
    graph create_matrix();
};

graph graph::create_matrix(int v, int e)
{
    int i, u, v;
    graph g = new graph(v, e);

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
