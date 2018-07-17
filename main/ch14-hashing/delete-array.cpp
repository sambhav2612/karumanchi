#include "../headers.hpp"

char *symmetric(char *arr, char *to_del, int len)
{
    int del_len = strlen(to_del), hash_table[256] = {0}, i, j;

    for (i = 0; i < len; ++i)
        hash_table[arr[i]]++;

    for (i = 0; i < len; ++i)
        for (j = 0; j < del_len; ++j)
            if (hash_table[arr[i]] == to_del[j] && hash_table[arr[i]] % to_del[j] == 0)
                hash_table[arr[i]]--;

    arr[0] = '\0';

    for (i = 0; i < 256; ++i)
        //if (hash_table[i])
        //arr[i] = hash_table[i];
        cout << i << " -> " << hash_table[i] << endl;

    return arr;
}

int main(int argc, char **argv)
{
    char *arr = argv[1], *to_del = argv[2];
    int len = strlen(arr);

    cout << endl
         << "String before deletion - " << arr << endl
         << endl
         << "String after deletion - " << symmetric(arr, to_del, len);

    return 0;
}
