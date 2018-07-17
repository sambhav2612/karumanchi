#pragma once

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
    int **weight;
    graph(int t_v, int t_e)
    {
        this->m_v = t_v;
        this->m_e = t_e;
        this->adj = (int *)malloc(sizeof(this->m_v * sizeof(class node)));
        this.weight = (int **)malloc(sizeof(t_v * t_v);
        for (int u = 0; u < this->m_v; ++u)
            this->adj[u] = 0;
    }
    int returnV()
    {
        return this->m_v;
    }
    int returnE()
    {
        return this->m_e;
    }
    graph create_list();
};

void graph::create_list()
{
    int i, x, y, w;
    node *temp;

    for (i = 0; i < returnV(); ++i)
    {
        adj[i] = (class node *)malloc(sizeof(class node));
        adj[i]->m_vertex_num = i;
        adj[i]->m_next = g.adj[i]; //circle back
    }

    for (i = 0; i < returnE(); ++i) // for all edges
    {
        cout << endl
             << "Reading edge [u, v] and edge weights - ";
        cin >> x >> y >> w;
        temp->m_vertex_num = y;
        temp->m_next = g.adj[x];
        adj[x]->m_next = temp;
        weight[x][y] = w;
    }
}
