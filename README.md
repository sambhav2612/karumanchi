# karumanchi

[![Download karumanchi](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/karumanchi/files/latest/download) [![Download karumanchi](https://img.shields.io/sourceforge/dt/karumanchi.svg)](https://sourceforge.net/projects/karumanchi/files/latest/download)

DS Problems from karumanchi. This repository  follows the [C++ Best Practices](https://lefticus.gitbooks.io/cpp-best-practices/content) written by Jason Turner. Some of the code follows the general C++ 11 guidelines such as replacing conventional `NULL` pointers with `nullptr`.

## Changelog

- v0.2.3: Seperate executables from source files.
- v0.2.2: Update Chapter 9.

## Pathway

<details>
<summary>How do I find stuff in this repo?</summary>
    <ul>
        <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/bloom-filter" target="_blank">Bloom Filter</a></li>
        <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/codechef" target="_blank">Codechef</a></li>
        <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/codeforces" target="_blank">Codeforces</a></li>
        <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/external-sorting" target="_blank">External Sorting</a></li>
        <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/js" target="_blank">JavaScript Algorithms</a></li>
        <li>
            <details>
                <summary>Karumanchi</summary>
                <ul>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch1-introduction" target="_blank">Chapter 1 - Introduction</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch2-recursion-and-backtracking" target="_blank">Chapter 2 - Recursion and Backtracking</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch3-linked-lists" target="_blank">Chapter 3 - Linked Lists</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch4-stacks" target="_blank">Chapter 4 - Stacks</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch5-queues" target="_blank">Chapter 5 - Queues</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch6-trees" target="_blank">Chapter 6 - Trees</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch7-priority-queues" target="_blank">Chapter 7 - Priority Queues and Heaps</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch8-disjoint-sets" target="_blank">Chapter 8 - Disjoint Sets ADT</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch9-graph-algorithms" target="_blank">Chapter 9 - Graph ALgorithms</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch10-sorting" target="_blank">Chapter 10 - Sorting</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch12-selection-algorithms" target="_blank">Chapter 12 - Selection Algorithms [Medians]</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch13-symbol-tables" target="_blank">Chapter 13 - Symbol Tables</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch14-hashing" target="_blank">Chapter 14 - Hashing</a></li>
                </ul>
            </details>
        </li>
        <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/spoj" target="_blank">SPOJ</a></li>
        <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/stl" target="_blank">Standard Template Library (C++)</a></li>
    </ul>
</details>

### Guide to run the C++ Algorithms

- Clone this repo
- Install MinGW on Windows and g++ on macOS & Unix-like.
- Compile and run using:

```bash
$ g++ <FILENAME.cpp> -o <OUTPUT-BINARY-NAME>
$ "OUTPUT-BINARY-NAME" # on windows cmd (using "")
$ ./OUTPUT-BINARY-NAME # on macOS and Unix-like
```

**NOTE**: While running any of the C++ code missing their respective headers, please add `using namespace std;` after the pre-included headers. [Reference](https://lefticus.gitbooks.io/cpp-best-practices/content/03-Style.html)

Adding following flags in optional and depends on the users thugh are sugegsted to be used while developing-compiling locally:

- `-g` - turn on debugging (so GDB gives more friendly output)
- `-Wall` or `-Weverything` - turns on most warnings
- `-O or -O2` - turn on optimizations
- `-o <name>` - name of the output file
- `-c` - output an object file (.o)
- `-I<include path>` - specify an include directory
- `-L<library path>` - specify a lib directory
- `-l<library>` - link with library lib<library>.a

**H**owever, it is suggested that you use **_first, second, third and fourth_** (while compiling source files) for best results and local development.

### Guide to run the JS Algorithms

- Install Node.js
- Clone this repo
- Open the `package.json` file to find the appropriate command under **scripts tag**.
- Run in a terminal in following fashion:

```sh
$ npm run <TAG-NAME-INSIDE-SCRIPTS>

# ex: to run stack.js in chapter 4
$ npm run stack

# OR, run directly via node
$ node js/stack.js
```

**NOTE:** Langauge formatting done automatically using VS Code IntelliSense. Better suggestions are welcome!

### Directory Tree

Generated in Windows 10 using `tree /F` command in `cmd //C tree` terminal.

```bash
.
│   .babelrc
│   .editorconfig
│   .eslintignore
│   .eslintrc.json
│   .gitignore
│   .npmignore
│   .travis.yml
│   CMakeLists.txt
│   LICENSE
│   Makefile
│   package-lock.json
│   package.json
│   README.md
│
├───bloom-filter
│   │   readme.md
│   │   requirements.txt
│   │   setup.py
│   │
│   └───bloomf
│           main.py
│           test.py
│           __init__.py
│
├───codechef
│   │   codechef.hpp
│   │   readme.md
│   │
│   └───arrays
│           CHN15A.cpp
│           CNOTE.cpp
│           COPS.cpp
│           FRGTNLNG.cpp
│           LECANDY.cpp
│           RAINBOWA.cpp
│           SALARY.cpp
│
├───codeforces
│       readme.md
│
├───external-sorting
│   │   kway.cpp
│   │   kwaymergesort.hpp
│   │
│   └───gfg
│           0
│           1
│           2
│           3
│           4
│           5
│           6
│           7
│           8
│           9
│           gfg.cpp
│           input.txt
│           output.txt
│
├───js
│       priority-queue.js
│       queue.js
│       readme.md
│       set.js
│       stack.js
│
├───main
│   │   headers.hpp
│   │
│   ├───ch1-introduction
│   │       readme.md
│   │
│   ├───ch2-recursion-and-backtracking
│   │       check-sorting-recursion.cpp
│   │       n-ary-strings.cpp
│   │       readme.md
│   │       tower-of-hanoi.cpp
│   │
│   ├───ch3-linked-lists
│   │       cycle.cpp
│   │       fractional-node.cpp
│   │       merge.cpp
│   │       nth-element-from-end.cpp
│   │       pairwise-reverse.cpp
│   │       palindrome.cpp
│   │       readme.md
│   │       reverse-kth.cpp
│   │       reverse-sll.cpp
│   │       sort.cpp
│   │       split-cll.cpp
│   │
│   ├───ch4-stacks
│   │       adjacentBigger.cpp
│   │       adjacentRepeat.cpp
│   │       growth.cpp
│   │       infix-to-postfix.cpp
│   │       postfix.cpp
│   │       readme.md
│   │       reverse.cpp
│   │       span.cpp
│   │       stack.cpp
│   │       symbol-parser.cpp
│   │
│   ├───ch5-queues
│   │       linked-list-queue.cpp
│   │       readme.md
│   │       simple-queue.cpp
│   │
│   ├───ch6-trees
│   │       array2bst.cpp
│   │       bst2dll.cpp
│   │       check-bst.cpp
│   │       count-tree.cpp
│   │       dll2bst.cpp
│   │       expression-tree.cpp
│   │       find-max.cpp
│   │       inorder-sucessor.cpp
│   │       kth-smallest.cpp
│   │       preorder-sucessor.cpp
│   │       ranger.cpp
│   │       readme.md
│   │       readme.txt
│   │       reverse-lca.cpp
│   │       threaded-tree.cpp
│   │       threaded-tree.txt
│   │
│   ├───ch7-priority-queues
│   │       fimd-max-in-min-heap.cpp
│   │       find-k.cpp
│   │       heap-sort.cpp
│   │       heap.hpp
│   │       median.cpp
│   │       pq.hpp
│   │       readme.md
│   │       stack.cpp
│   │
│   ├───ch8-disjoint-sets
│   │       adt.hpp
│   │       cities.cpp
│   │       readme.md
│   │
│   ├───ch9-graph-algorithms
│   │   │   alist.hpp
│   │   │   amatrix.hpp
│   │   │   bfs.cpp
│   │   │   dfs.cpp
│   │   │   readme.md
│   │   │   tsort.cpp
│   │   │
│   │   └───shortest-path
│   │           bellman-ford.cpp
│   │           unweighted.cpp
│   │
│   ├───ch10-sorting
│   │       bucket.cpp
│   │       check-repeat.cpp
│   │       counting.cpp
│   │       election.cpp
│   │       flagged-bubble.cpp
│   │       insertion.cpp
│   │       max.cpp
│   │       merge.cpp
│   │       mergeAB.cpp
│   │       quick.cpp
│   │       readme.md
│   │       shell.cpp
│   │       sort.hpp
│   │
│   ├───ch12-selection-algorithms
│   │       kth-smallest-2.cpp
│   │       kth-smallest.cpp
│   │       merge.cpp
│   │       readme.md
│   │
│   ├───ch13-symbol-tables
│   │       readme.md
│   │
│   ├───ch14-hashing
│   │       array-matching.cpp
│   │       delete-array.cpp
│   │       find-pairs.cpp
│   │       first-non-repeat.cpp
│   │       first-repeat.cpp
│   │       hash-pairs.cpp
│   │       readme.md
│   │       remove-duplicates.cpp
│   │       seperate-chaining.hpp
│   │       two-arrays.cpp
│   │
│   └───includes
│           cll.hpp
│           dll.hpp
│           queue.hpp
│           sll.hpp
│           stack.hpp
│           tree.hpp
│
├───misc
│       sparse-set.cpp
│       sparse-set.hpp
│
├───spoj
│       readme.md
│
├───src
│       commit.js
│       deploy.js
│       index.js
│       push.js
│
├───stl
│       stl.hpp
│
├───test
│       index.js
│
└───utils
        add-namespace.py
        create-out.py
        delete-exe.py
        pragma-once.py
        readme.md
        requirements.txt
```

### License

© 2018 Sambhav Jain under GPL-v3.0
# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out# Out