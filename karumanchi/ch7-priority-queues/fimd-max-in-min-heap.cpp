#include "heap.hpp"

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]), i, old, arr[n] = {0};
    for (i = 0; i < n; ++i)
        cin >> arr[i];

    struct heap *h = create_heap(n);
    build_min_heap(h, arr, n);

    int max = -1;
    for (i = (h->count + 1) / 2; i < h->count; i++)
        if (h->array[i] > max)
            max = h->array[i];

    cout << endl
         << "Max Element: " << max;
    return 0;
}
