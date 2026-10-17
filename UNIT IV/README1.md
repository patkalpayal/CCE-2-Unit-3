1. Project Title

Company Hierarchy Management System Using Binary Tree and Queue

Subject: Data Structures and Algorithms (DSA)
Unit: IV
Programming Language: C++
Data Structures Used: Binary Tree and Queue

2. Problem Statement

Develop a Company Hierarchy Management Application using a Binary Tree in C++. The application should represent the organizational structure of a company, where each employee is represented as a node in the binary tree.

The system should allow users to create a company hierarchy by adding employees under their respective managers. It should display the hierarchy level by level using a Queue and perform level-order traversal to show employees according to their organizational levels.

3. Objectives

1. To understand and implement a Binary Tree in C++.
2. To represent a company's organizational structure using a Binary Tree.
3. To implement a Queue for level-order traversal.
4. To display employees level by level, starting from the CEO.
5. To understand the practical applications of trees and queues.
6. To develop a menu-driven application for managing and displaying a company hierarchy.

4. Theory / Introduction

A. Binary Tree

A Binary Tree is a non-linear data structure in which each node can have at most two children: a left child and a right child.

In this project, each node represents an employee in the company.

For example:
- The CEO is the root node.
- The left child may represent one department head.
- The right child may represent another department head.
- Further children may represent employees working under those managers.

Example:

                 CEO
                /   \
          HR Manager  IT Manager
             /           \
       HR Executive   Software Engineer

Here, the CEO is the root node, and the other employees are connected through parent-child relationships.

A binary tree allows each employee node to have at most two direct reports in this representation. Real company structures can have more than two direct reports, so this project uses a simplified organizational hierarchy.

B. Queue

A Queue is a linear data structure that follows the FIFO (First In, First Out) principle. This means the element inserted first is removed first.

The main queue operations are:

Enqueue: Adds an element to the rear of the queue.
Dequeue: Removes an element from the front of the queue.
Front: Returns the first element.
Empty: Checks whether the queue is empty.

C. Level-Order Traversal

Level-order traversal visits the nodes of a binary tree level by level, from left to right. It uses a queue to determine which employee should be processed next.

Example:

                 CEO
                /   \
          HR Manager  IT Manager
           /   \        /   \
        HR Exec HR Lead IT Exec Developer

The level-order output is:

Level 0: CEO
Level 1: HR Manager, IT Manager
Level 2: HR Executive, HR Lead, IT Executive, Developer

This is the main operation of the project.

5. Algorithm

Algorithm: Company Hierarchy Management

Step 1: Start the program.

Step 2: Create a structure named Node containing employee information and pointers to the left and right children.

Step 3: Initialize the root of the binary tree as NULL.

Step 4: Display the menu:
- Add CEO
- Add Employee
- Display Company Hierarchy
- Exit

Step 5: If the user selects Add CEO, create the root node if it does not already exist.

Step 6: If the user selects Add Employee:
- Search for the manager by name.
- If the manager is found, check whether the left or right child position is available.
- Add the new employee in the selected available position.
- If both positions are occupied, display a suitable message.

Step 7: If the user selects Display Company Hierarchy:
- Create an empty queue.
- Insert the root node into the queue.
- Remove the front node and display the employee.
- Insert its left child into the queue if it exists.
- Insert its right child into the queue if it exists.
- Repeat until the queue becomes empty.

Step 8: If the user selects Exit, terminate the program.

Step 9: Stop.

6. Conclusion

This project demonstrates how a binary tree can represent a company's organizational hierarchy and how a queue can be used for level-order traversal. It helps explain how employees can be arranged under managers and displayed level by level. The project also provides practical understanding of binary trees, queues, and traversal techniques in C++.

