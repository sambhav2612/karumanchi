# karumanchi

[![Build Status](https://travis-ci.org/sambhav2612/karumanchi.svg?branch=master)](https://travis-ci.org/sambhav2612/karumanchi) [![npm version](https://badge.fury.io/js/karumanchi.svg)](https://badge.fury.io/js/karumanchi) [![Download karumanchi](https://img.shields.io/sourceforge/dt/karumanchi.svg)](https://sourceforge.net/projects/karumanchi/files/latest/download)

Almost all problems and codes from **_Data Structures Made Easy by Narasimha Karumanchi_**. Mostly written in C++, this repository follows the [C++ Best Practices](https://lefticus.gitbooks.io/cpp-best-practices/content) written by Jason Turner. Some of the code follows the general C++ 11 guidelines such as replacing conventional `NULL` pointers with `nullptr`.

Some extra implementations have been added as side-projects, mostly written in Python with an additional utility to constantly manage [and seperate] the CPP executables from their source files.

Each sub-directory has been enclosed with a readme to help you in understamding the workflow of the source code in that directory. Please find the same as you are contributing.

## Changelog

- **0.3.1**: :pencil: files.
- **0.3.0**: Start electron application development and remove local packages.
- **0.2.10**: Add [DCO](https://github.com/sambhav2612/karumanchi/blob/master/DCO).
- **0.2.9**: Add Chapter 15.
- **0.2.8**: Update readme.
- **0.2.7**: Update and complete Chapter 11.
- **0.2.6**: Update travis configuration for package deloyment.
- **0.2.5**: Add Chapter 11.
- **0.2.4**: Update python utility.
- **0.2.3**: Add python utility to seperate executables from source code.
- **0.2.2**: Update and complete Chapter 9.

## Pathway

<details>
<summary>How do I find stuff in this repo?</summary>
    <ul>
        <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/bloom-filter" target="_blank">Bloom Filter <a href="https://badge.fury.io/py/bloomf"><img src="https://badge.fury.io/py/bloomf.svg" alt="PyPI version" height="18"></a></a></li>
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
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch11-searching" target="_blank">Chapter 11 - Searching</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch12-selection-algorithms" target="_blank">Chapter 12 - Selection Algorithms [Medians]</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch13-symbol-tables" target="_blank">Chapter 13 - Symbol Tables</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch14-hashing" target="_blank">Chapter 14 - Hashing</a></li>
                    <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/karumanchi/ch15-string-algorithms" target="_blank">Chapter 15 - String Algorithms</a></li>
                </ul>
            </details>
        </li>
        <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/spoj" target="_blank">SPOJ</a></li>
        <li><a href="https://github.com/sambhav2612/karumanchi/tree/master/stl" target="_blank">Standard Template Library (C++)</a></li>
    </ul>
</details>

## Contributing

Please checkout the contribution guideline [here](https://github.com/sambhav2612/karumanchi/blob/master/CONTRIBUTING.md).

### How to run the algorithms?

Please find the the how to run guide [here](https://github.com/sambhav2612/karumanchi/blob/master/HOW_TO_RUN.md).

### Craving for more?

You can find [this](https://yuchengkai.cn/docs/cs/dataStruct.html) resource particularly cool to put in use while you're here.

### Directory Tree

Generated in Windows 10 using `tree /F` command in terminal. Inside the main book directory, each chapter has a folder named `out`, which contains all the preprocessed headers and execuatables seperated from source files by the python utility I wrote a while back.

```sh
.
│   .editorconfig
│   .gitignore
│   .npmignore
│   .travis.yml
│   binding.gyp
│   CODE_OF_CONDUCT.md
│   CONTRIBUTING.md
│   DCO
│   HOW_TO_RUN.md
│   LICENSE
│   Makefile
│   native.cc
│   package-lock.json
│   package.json
│   README.md
│
├───app
│   │   .babelrc
│   │   .editorconfig
│   │   .gitignore
│   │   LICENSE
│   │   package-lock.json
│   │   package.json
│   │   README.md
│   │
│   ├───app
│   │       app.html
│   │
│   ├───config
│   │       env_development.json
│   │       env_production.json
│   │       env_test.json
│   │
│   ├───e2e
│   │       hello_world.e2e.js
│   │       utils.js
│   │
│   ├───resources
│   │   │   icon.icns
│   │   │   icon.ico
│   │   │
│   │   └───icons
│   │           512x512.png
│   │
│   └───src
│       │   app.js
│       │   background.js
│       │
│       ├───hello_world
│       │       hello_world.js
│       │       hello_world.spec.js
│       │
│       ├───helpers
│       │       context_menu.js
│       │       external_links.js
│       │       window.js
│       │
│       ├───menu
│       │       dev_menu_template.js
│       │       edit_menu_template.js
│       │
│       └───stylesheets
│               main.css
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
│   │   │   check-sorting-recursion.cpp
│   │   │   n-ary-strings.cpp
│   │   │   readme.md
│   │   │   tower-of-hanoi.cpp
│   │   │
│   │   └───out
│   │
│   ├───ch3-linked-lists
│   │   │   cycle.cpp
│   │   │   fractional-node.cpp
│   │   │   merge.cpp
│   │   │   nth-element-from-end.cpp
│   │   │   pairwise-reverse.cpp
│   │   │   palindrome.cpp
│   │   │   readme.md
│   │   │   reverse-kth.cpp
│   │   │   reverse-sll.cpp
│   │   │   sort.cpp
│   │   │   split-cll.cpp
│   │   │
│   │   └───out
│   │
│   ├───ch4-stacks
│   │   │   adjacentBigger.cpp
│   │   │   adjacentRepeat.cpp
│   │   │   growth.cpp
│   │   │   infix-to-postfix.cpp
│   │   │   postfix.cpp
│   │   │   readme.md
│   │   │   reverse.cpp
│   │   │   span.cpp
│   │   │   stack.cpp
│   │   │   symbol-parser.cpp
│   │   │
│   │   └───out
│   │
│   ├───ch5-queues
│   │   │   linked-list-queue.cpp
│   │   │   readme.md
│   │   │   simple-queue.cpp
│   │   │
│   │   └───out
│   │
│   ├───ch6-trees
│   │   │   array2bst.cpp
│   │   │   bst2dll.cpp
│   │   │   check-bst.cpp
│   │   │   count-tree.cpp
│   │   │   dll2bst.cpp
│   │   │   expression-tree.cpp
│   │   │   find-max.cpp
│   │   │   inorder-sucessor.cpp
│   │   │   kth-smallest.cpp
│   │   │   preorder-sucessor.cpp
│   │   │   ranger.cpp
│   │   │   readme.md
│   │   │   reverse-lca.cpp
│   │   │   threaded-tree.cpp
│   │   │   threaded-tree.txt
│   │   │
│   │   └───out
│   │
│   ├───ch7-priority-queues
│   │   │   fimd-max-in-min-heap.cpp
│   │   │   find-k.cpp
│   │   │   heap-sort.cpp
│   │   │   heap.hpp
│   │   │   median.cpp
│   │   │   pq.hpp
│   │   │   readme.md
│   │   │   stack.cpp
│   │   │
│   │   └───out
│   │
│   ├───ch8-disjoint-sets
│   │   │   adt.hpp
│   │   │   cities.cpp
│   │   │   readme.md
│   │   │
│   │   └───out
│   │
│   ├───ch9-graph-algorithms
│   │   │   alist.hpp
│   │   │   amatrix.hpp
│   │   │   bfs.cpp
│   │   │   dfs.cpp
│   │   │   path.cpp
│   │   │   readme.md
│   │   │   tsort.cpp
│   │   │
│   │   ├───out
│   │   │
│   │   └───shortest-path
│   │           bellman-ford.cpp
│   │           unweighted.cpp
│   │
│   ├───ch10-sorting
│   │   │   bucket.cpp
│   │   │   check-repeat.cpp
│   │   │   counting.cpp
│   │   │   election.cpp
│   │   │   flagged-bubble.cpp
│   │   │   insertion.cpp
│   │   │   max.cpp
│   │   │   merge.cpp
│   │   │   mergeAB.cpp
│   │   │   quick.cpp
│   │   │   readme.md
│   │   │   shell.cpp
│   │   │   sort.hpp
│   │   │
│   │   └───out
│   │
│   ├───ch11-searching
│   │   │   bin-search-first.cpp
│   │   │   bin-search-last.cpp
│   │   │   bin-search-rotated.cpp
│   │   │   bin-search.cpp
│   │   │   closest2zero.cpp
│   │   │   counter.cpp
│   │   │   duplicates.cpp
│   │   │   findk.cpp
│   │   │   first-repeat.cpp
│   │   │   intercept.cpp
│   │   │   missing.cpp
│   │   │   readme.md
│   │   │   rgb.cpp
│   │   │   trailing0.cpp
│   │   │
│   │   └───out
│   │
│   ├───ch12-selection-algorithms
│   │   │   kth-smallest-2.cpp
│   │   │   kth-smallest.cpp
│   │   │   merge.cpp
│   │   │   readme.md
│   │   │
│   │   └───out
│   │
│   ├───ch13-symbol-tables
│   │       readme.md
│   │
│   ├───ch14-hashing
│   │   │   array-matching.cpp
│   │   │   delete-array.cpp
│   │   │   find-pairs.cpp
│   │   │   first-non-repeat.cpp
│   │   │   first-repeat.cpp
│   │   │   hash-pairs.cpp
│   │   │   readme.md
│   │   │   remove-duplicates.cpp
│   │   │   seperate-chaining.hpp
│   │   │   two-arrays.cpp
│   │   │
│   │   └───out
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
├───stl
│       stl.hpp
│
├───test
│       index.js
│
└───utils
        pragma.py
        readme.md
```

### License

Copyright © 2018 Sambhav Jain under GPL-3.0

**_Happy Hacking!_**