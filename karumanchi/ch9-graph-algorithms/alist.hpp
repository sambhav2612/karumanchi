#include "../headers.hpp"
using namespace std;

class node
{
    int m_vertex_num;
    node *m_next;
};

class graph
{
  private:
    int m_v;
    int m_e;

  public:
    int *adj;
    graph(int t_v, int t_e)
    {
        this.m_v = t_v;
        this.m_e = t_e;
        this.adj = malloc(sizeof(this.m_v * sizeof(class node)));
        for (int u = 0; u < this.m_v; ++u)
            this.adj[u] = 0;
    }
    int returnV()
    {
        return this.m_v;
    }
    int returnE()
    {
        return this.m_e;
    }
    graph create_list(int t_v, int t_e);
};

graph graph::create_list(int t_v, int t_e)
{
    int i, x, y;
    graph g = new graph(t_v, t_e);
    node *temp;

    if (!g)
        return nullptr;

    for (i = 0; i < g.returnV(); ++i)
    {
        g.adj[i] = (class node *)malloc(sizeof(class node));
        g.adj[i]->m_vertex_num = i;
        g.adj[i]->m_next = g.adj[i]; //circle back
    }

    for (i = 0; i < g.returnE(); ++i) // for all edges
    {
        cout << endl
             << "Reading edge [u, v]";
        cin >> x >> y;
        temp->m_vertex_num = y;
        temp->m_next = g.adj[x];
        g.adj[x]->m_next = temp;
    }

    return g;
}
