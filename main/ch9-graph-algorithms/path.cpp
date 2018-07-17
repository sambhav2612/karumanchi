#include "amatrix.hpp"
using namespace std;

int count_paths(class graph g, int source, int destination)
{
    int t, count = 0;
    visited[source] = 1;
    if (source == destination)
    {
        count++;
        visited[source] = 0;
        return 1; // path found -> cycle
    }
    for (t = 0; t < g.returnV(); ++t)
        if (g.adj[source][t] && !visited[t])
        {
            g.dfs(t);
            visited[t] = 0;
        }
    return count;
}

int hash_path(class graph g, int source, int destination)
{
    int t;
    visited[source] = 1;
    if (source == destination)
        return 1; // path found -> cycle
    for (t = 0; t < g.returnV(); ++t)
        if (g.adj[source][t] && !visited[t])
            if (g.dfs(t))
                return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    int v = atoi(argv[1]), e = atoi(argv[2]), s = atoi(argv[3]), d = atoi(argv[4]);
    graph g = new graph(v, e);
    g.create_matrix();

    cout << endl
         << hash_path(g, s, d)
         << endl
         << count_paths(g, s, d);

    return 0;
}
