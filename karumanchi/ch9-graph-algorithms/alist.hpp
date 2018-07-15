#include "../headers.hpp"

class node
{
    int vertex_num;
    node *next;
};

class graph
{
  private:
    int v;
    int e;

  public:
    int *adj;
    graph(int v, int e)
    {
        this.v = v;
        this.e = e;
        this.adj = malloc(sizeof(this.v * sizeof(class node)));
        for (int u = 0; u < this.v; ++u)
            this.adj[u] = 0;
    }
    int returnV()
    {
        return this.v;
    }
    int returnE()
    {
        return this.e;
    }
    graph create_list(int v, int e);
};

graph graph::create_list(int v, int e)
{
    int i, x, y;
    graph g = new graph(v, e);
    node *temp;

    if (!g)
        return nullptr;

    for (i = 0; i < g.returnV(); ++i)
    {
        g.adj[i] = (class node *)malloc(sizeof(class node));
        g.adj[i]->vertex_num = i;
        g.adj[i]->next = g.adj[i]; //circle back
    }

    for (i = 0; i < g.returnE(); ++i) // for all edges
    {
        cout << endl
             << "Reading edge [u, v]";
        cin >> x >> y;
        temp->vertex_num = y;
        temp->next = g.adj[x];
        g.adj[x]->next = temp;
    }

    return g;
}
