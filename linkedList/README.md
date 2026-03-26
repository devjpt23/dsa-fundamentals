This folder contains a lightweight, interview-oriented linked list implementation I built as part of a college course project. The goal was to re-implement a singly linked list from scratch (separate from the course-provided header), and capture the core patterns needed to comfortably solve a dozen or more of the most common linked list interview questions.

## ListChain (LinkedListLite) Overview

`LinkedListLite.h` defines a small, self-contained singly linked list template, `ListChain<T>`, with its own internal `ListNode` type. It is designed as an alternative to the course-provided `LinkedList` in `linkedlist.h`, with different structure and naming, but covering the same core operations:

- **Basic operations**: `is_empty`, `length`, `prepend`, `append`, `remove_front`, `remove_back`, `at_position`
- **Search and deletion patterns**: `locate`, `erase_last_match`, `insert_before_index`, `drop_every_other`
- **Utility**: `as_string`, `purge`, and a low-level `raw_head` accessor for algorithm-style functions

These operations capture the most common singly linked list manipulation patterns you see in technical interviews (iterating, inserting/removing at head/tail/middle, scanning for matches, and skipping nodes).

## LeetCode-style applicability

As of 2026, LeetCode lists **79 linked list problems** in its official "Linked List" collection. The patterns implemented in `ListChain<T>` (iterative traversal, insertion and removal by index/value, skipping nodes, and working from a head pointer) are directly useful for **the majority of these 79 problems**, including classics like:

- Reversing a list, merging lists, removing nodes from the front/back or by position
- Finding or removing specific values or duplicates
- Jumping/skipping nodes (e.g., every other node, n-th from end, cycle detection helpers)

In practice, if you are comfortable with the patterns in `LinkedListLite.h`, you will be well-prepared for essentially all standard singly linked list questions on LeetCode and similar interview platforms.

## Representative LeetCode problems that match these patterns

You can use the building blocks in `LinkedListLite.h` to directly implement solutions for many of the classic LeetCode linked list problems. A non-exhaustive, but representative, subset includes:

- **206. Reverse Linked List** – iterative pointer rewiring over `ListNode*`
- **21. Merge Two Sorted Lists** – iterative merge using `next` pointers
- **83. Remove Duplicates from Sorted List** – skip duplicate nodes while walking the list
- **203. Remove Linked List Elements** – delete nodes whose value matches a target
- **19. Remove Nth Node From End of List** – two-pointer pattern plus node deletion
- **141. Linked List Cycle** / **142. Linked List Cycle II** – Floyd’s cycle-finding with `next` traversal
- **160. Intersection of Two Linked Lists** – pointer walk with length normalization
- **234. Palindrome Linked List** – traversal, middle-finding, and sublist operations
- **876. Middle of the Linked List** – fast/slow pointer traversal
- **24. Swap Nodes in Pairs** – local pointer rewiring and skipping nodes
- **92. Reverse Linked List II** – reverse a sub-range using head/tail and `next`
- **61. Rotate List** – connect tail to head and re-break at the right position

All of these problems rely on the same fundamental operations exposed by `ListChain<T>` (traversal, insert/remove around a node, and skipping nodes), so practice with this header maps very closely onto solving these LeetCode questions.

