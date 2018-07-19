# How to run?

## C++

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

## JavaScript

- Install Node.js
- Clone this repo
- Open the `package.json` file to find the appropriate command under **scripts tag**.
- Run in a terminal in following fashion:

```sh
$ npm run <TAG-NAME-INSIDE-SCRIPTS>

# ex: to run stack.js
$ npm run stack

# OR, run directly via node
$ node js/stack.js
```

**_Happy Hacking!_**
