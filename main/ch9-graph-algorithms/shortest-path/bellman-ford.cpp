#include "../alist.cpp"
using namespace std;

void shortest_path(class graph g, int s)
{
    queue<int> q;
    int v, w, distance[v] = {0}, path[v] = {0};
    q.push(v);
    distance[s] = 0;

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (w = 0; w < g.returnV(); ++w)
            if (g.adj[v]->m_next == g.adj[w])
            {
                int d = distance[v] + g.weight[v][w];
                if (distance[v] > d)
                {
                    distance[v] += g.weight[v][w];
                    path[w] = v;
                }
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
