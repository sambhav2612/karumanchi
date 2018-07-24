# Chapter 3 - Linked Lists

Linked Lists are a sequential way to storage. No, unlike arrays where each element would have an adjacent neighbour from its domain, linked lists can have their nodes (elements) scattered in the memort anywhere. The access is provided by an extra pointer (taking extra space) to store the address of the next element in the structure. This sort of provides an analogous approach to implementing ordinary arrays.

Linked Lists can be of multiple types:

- Singly (only next pointers hence only frontal movement)
- Doubly (both next and prev pointers hence can move to front and back nodes in the list)
- Circular (last element in the list has next pointer pointing back to the start of the list, called **head** node)

Each such linked list would have some basic operations defined within their ADT, such as:

- Insert
- Delete
- Traverse (Print all)
- Find
- Delete list
- and so on, it really never ends.

Linked Lists can also be used to implement other sequential structures like Stack, Queues, etc by slighly changing the basic ADT to adapt with the properties of those data structures.

## Must Dos

- ADTs
- Cycle Detection
- Exercise Questions

**NOTE**: Sequential here refers to linear.