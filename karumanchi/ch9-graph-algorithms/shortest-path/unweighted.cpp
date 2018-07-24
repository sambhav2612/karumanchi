#include "../alist.hpp"
#include <queue>
using namespace std;

void shortest_path(class graph g, int s)
{
    queue<int> q;
    int v, w, distance[v] = {0}, path[v] = {0};
    q.push(s);
    for (int i = 0; i < g.returnV(); ++i)
        distance[i] = -1;
    distance[s] = 0;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (w = 0; w < g.returnV(); ++w)
            if (g.adj[v]->m_next == g.adj[w] && distance[w] == -1) // vertex w adjacent to v
            {
                distance[w] = distance[v] + 1;
                path[w] = v;
                q.push(w);
            }
    }
}

int main(int argc, char const *argv[])
{
    int v = atoi(argv[1]), e = atoi(argv[2]), start_vertex = atoi(argv[3]);
    graph g = new graph(v, e);
    g.create_list();

    shortest_path(g, start_vertex);
    return 0;
}
