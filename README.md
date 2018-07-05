# karumanchi

DS Problems from karumanchi

## Latest Update

Start creating npm global module.

### Guide to run C++ Algos

- Clone this repo
- Install MinGW on Windows and g++ on macOS & Unix-like.
- Compile and run using:

```bash
$ g++ <FILENAME.cpp> -o <OUTPUT-BINARY-NAME>
$ "OUTPUT-BINARY-NAME" # on windows cmd (using "")
$ ./OUTPUT-BINARY-NAME # on macOS and Unix-like
```

Adding following flags in optional and depends on the users thugh are sugegsted to be used while developing-compiling locally:

- `-g` - turn on debugging (so GDB gives more friendly output)
- `-Wall` - turns on most warnings
- `-O or -O2` - turn on optimizations
- `-o <name>` - name of the output file
- `-c` - output an object file (.o)
- `-I<include path>` - specify an include directory
- `-L<library path>` - specify a lib directory
- `-l<library>` - link with library lib<library>.a

**H**owever, it is suggested that you use **_first, second and fourth_** (while compiling source files) for best results and local development.

### Guide to run JS Algos

- Install Node
- Clone this repo
- Open the `package.json` file to find the appropriate command under **scripts tag**.
- Run in a terminal in following fashion:

```sh
$ npm run <TAG-NAME-INSIDE-SCRIPTS>

# ex: to run stack.js in chapter 4
$ npm run stack

# OR, run directly via node
$ node ch4-stacks/stack.js
```

**NOTE:** Langauge formatting done automatically using VS Code IntelliSense. Better suggestions are welcome!

### Directory Tree

Generated in Windows 10 using `tree /F` command in `cmd //C tree` terminal.

```bash
.
│   .babelrc
│   .editorconfig
│   .eslintrc.json
│   .gitignore
│   .travis.yml
│   CMakeLists.txt
│   headers.h
│   headers.h.gch
│   LICENSE
│   Makefile
│   package-lock.json
│   package.json
│   README.md
│
├───.vscode
│       compile_commands.json
│       c_cpp_properties.json
│       settings.json
│
├───ch1-introduction
│       readme.md
│
├───ch10-sorting
│       bucket.cpp
│       check-repeat.cpp
│       counting.cpp
│       flagged-bubble.cpp
│       insertion.cpp
│       merge.cpp
│       quick.cpp
│       readme.md
│       shell.cpp
│       sort.h
│
├───ch2-recursion-and-backtracking
│       check-sorting-recursion.cpp
│       n-ary-strings.cpp
│       readme.md
│       tower-of-hanoi.cpp
│
├───ch3-linked-lists
│       cycle.cpp
│       fractional-node.cpp
│       merge.cpp
│       nth-element-from-end.cpp
│       pairwise-reverse.cpp
│       palindrome.cpp
│       readme.md
│       reverse-kth.cpp
│       reverse-sll.cpp
│       sort.cpp
│       split-cll.cpp
│
├───ch4-stacks
│       adjacentBigger.cpp
│       adjacentRepeat.cpp
│       growth.cpp
│       infix-to-postfix.cpp
│       postfix.cpp
│       readme.md
│       reverse.cpp
│       span.cpp
│       stack.cpp
│       symbol-parser.cpp
│
├───ch5-queues
│       linked-list-queue.cpp
│       readme.md
│       simple-queue.cpp
│
├───ch6-trees
│       array2bst.cpp
│       bst2dll.cpp
│       check-bst.cpp
│       count-tree.cpp
│       dll2bst.cpp
│       expression-tree.cpp
│       find-max.cpp
│       inorder-sucessor.cpp
│       kth-smallest.cpp
│       preorder-sucessor.cpp
│       ranger.cpp
│       readme.md
│       readme.txt
│       reverse-lca.cpp
│       threaded-tree.cpp
│       threaded-tree.txt
│
├───codechef
│   │   codechef.h
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
│   │   kwaymergesort.h
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
├───includes
│       cll.h
│       dll.h
│       queue.h
│       sll.h
│       stack.h
│       tree.h
│
├───js
│       priority-queue.js
│       queue.js
│       readme.md
│       set.js
│       stack.js
│
├───misc
│       sparse-set.cpp
│       sparse-set.h
│
├───lib
│       index.js
│
├───spoj
│       readme.md
│
├───src
│       index.js
│
├───stl
│        stl.h
│
└───test
        index.js
```

### License

© 2018 Sambhav Jain under GPL-v3.0