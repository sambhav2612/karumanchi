#include "amatrix.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    int v = atoi(argv[1]), e = atoi(argv[2]);
    graph obj, g = obj.create_matrix(v, e);
    g.dfs(u);
    g.dfs_traversal();
    return 0;
}
