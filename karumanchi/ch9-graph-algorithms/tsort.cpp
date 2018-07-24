#include "amatrix.hpp"
using namespace std;

int *tsort(class graph g)
{
    queue<int> q;
    int counter = 0, v, w;
    int *indegree = g.return_indegree(), *torder = 0;
    for (v = 0; v < g.returnV(); ++v)
        if (indegree[v] == 0)
            q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        torder[v] = ++counter;
        for (w = 0; w < g.returnV(); ++w)
            if (g.adj[w][v] && --indegree[v] == 0)
                q.push(v);
    }
    if (counter != g.returnV())
    {
        cout << endl
             << "Cycle Found!";
        return nullptr;
    }

    return torder;
}

int main(int argc, char **argv)
{
    int v = atoi(argv[1]), e = atoi(argv[2]);
    graph g = new graph(v, e);
    g.create_matrix();

    int *torder = tsort(g), len = sizeof(torder) / sizeof(torder[0]);

    cout << endl
         << "Topological Order is - ";
    for (int i = 0; i < len; ++i)
        cout << torder[i] << " ";
    return 0;
}
