#include "amatrix.hpp"

int main(int argc, char const *argv[])
{
    int v = atoi(argv[1]), e = atoi(argv[2]);
    graph obj, g = obj.create_matrix(v, e);
    g.bfs(u);
    g.bfs_traversal();
    return 0;
}
