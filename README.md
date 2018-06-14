# karumanchi

DS Problems from karumanchi

## Known Issues

- Tower of Hanoi [Chapter 2]
- SLL Header File [Chapter 3] - **causes entire chapter 3 and some of chapter 4 problems to fail.**

## Latest Update

- Added Tree ADT in C++.

### Guide to run C++ Algos

- Clone this repo
- Install MinGW on Windows and g++ on macOS & Unix-like.
- Compile and run using: 

```sh
$ g++ -std=c11 -Wall <FILENAME.cpp> -o <OUTPUT-BINARY-NAME>
$ "OUTPUT-BINARY-NAME" # on windows cmd
$ ./OUTPUT-BINARY-NAME	# on macOS and Unix-like
```

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

### License

© 2018 Sambhav Jain under GPL-v3.0