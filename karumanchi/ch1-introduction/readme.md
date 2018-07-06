# Introduction

The chapter introduces to various paradigms followed in algorithm anaylysis and programming in general. It starts from defining `variables` as an unit to store data of a particular type.

A `data type` could be a set of variables defined on it. It can be either predefined or user-defined. Predefined means that those data types were already present and packaged within the language system (compiler/interpreter know about them alreary) *ex:* integer, floating-point numbers, boolean, characters, etc. User-defined data types are those that are defined by the user of the language themselves and are composed of the predefined/primitive data types told above. Examples could be `structures in C` and `classes in Java`.

Now, what good does a data type serve unless some operations could not be defined to use it. Hence, we create `Abstract Data Types` which are just user-defined data types along with operations on the enclosed variables. These operations are in form of functions.

`Data Structures` are just an organised way to store and collect data. There can two types of primtive data structures in terms of storage pattern:

- Sequential (Linear) access: Linked Lists, Stack, Queues, etc. [Sequential saving not compulsory like Arrays]
- Non-equential access and non-sequential save: Graphs, Trees, etc.

## Algorithm Analysis

An algorithm is a step-by-step procedure to solve a particular computation problem carrying some logical weight. Now, this logical weight could mean it's relevance to code. **Analysis of algorithms is generally carried out via there particular running times as there can be any number of algorithms possible to solve the same problems, each taking a different approach to do so and hence different running times.** The running time of any algorithm is variable to the input provided to it. Hence a good meaure to find the optimal algorithm should be by mapping how the algotihm behaves for different input sizes in terms of running time, regardless the machine architecture, programming lanaguage or execution times.

This simply means that running time is function of input size provided to the algorithm.

Now, running times could be divided in worst, best and average cases; where the worst-case analysis is most important. To determine these cases, we tend to bound our function `f(n)` on another function `g(n)` for larger values of n. The upper bound can be determined for all larger values of n for which values of some function `cg(n)` is always greater than that of `f(n)` i.e., `0 <= f(n) <= cg(n)`. **This gives us a tight upperbound (Big-O) on f(n)**. The tight lowerbound (Omega) is analogous to this i.e., `0 <= cg(n) <= f(n)`.

We can find the average bound (Theta) using both the upper and lowerbounds.

**A** major factor in algorithm analysis is complexity of the alogithm i.e., mapping the algorithm is terms of real-world factors like time, space, etc.

## Must Dos

- Divide and Conquer Master Theoram
- Substract and Conquer Master Theoram
- Exercise Questions