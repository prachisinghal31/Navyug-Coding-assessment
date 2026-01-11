# Add Two Numbers Represented by Linked Lists

## Problem Statement
You are given the head of two singly linked lists head1 and head2 representing two non-negative integers. You have to return the head of the linked list representing the sum of these two numbers.


Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

---

## Approach
1. Remove leading zeros from both linked lists.
2. Reverse both linked lists to make addition easier.
3. Add corresponding digits one by one while maintaining carry.
4. Create a new linked list to store the result.
5. Reverse the result list to restore forward order.

---

## Example
**Input:**
123
999

---

**Output:**
1 -> 1 -> 2 -> 2

---

## Implementation
- Language: **C++**
- Data Structure Used: **Singly Linked List**

---

## Time & Space Complexity
- **Time Complexity:** O(n + m)  
  where n and m are the lengths of the two linked lists.
- **Space Complexity:** O(1) auxiliary space (excluding output list).

---

## File
- `C++_coding.cpp` – Contains the complete C++ implementation.

---

## Author
Prachi Singhal

