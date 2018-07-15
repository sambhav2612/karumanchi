#include "heap.hpp"

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), i, arr[n] = {0};
    for (i = 0; i < n; ++i)
        cin >> arr[i];

    struct heap *h = create_heap(n);
    build_heap(h, arr, n);
    print_k(h, 8, 0);

    return 0;
}
