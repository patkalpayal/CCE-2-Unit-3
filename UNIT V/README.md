# **Represent university courses and their prerequisite relationships using a directed graph, and apply DFS to explore courses reachable from a selected course.** 

## **1.Problem Statement** 

In a university, some courses need basic knowledge of other courses before students can study them. For example, students should learn Programming before studying Data Structures. In this project, we represent courses and their relationships using a directed graph. We use DFS to find which courses can be reached from a selected course. 

## **2.Objective** 

The main objective of this project is to understand how graphs are used to represent university courses. It also helps us learn how DFS works and how it can be used to find courses connected to a particular course. 

## **3.Introduction** 

A university has many courses, and some courses are related to each other. These relationships can be represented using a graph. 

In this project, each course is treated as a vertex, and the relationship between two courses is shown using a directed edge. For example, Programming can be connected to Data Structures because Programming is required before learning Data Structures. 

DFS is used to explore the connected courses one by one. This project is developed using C++. 

## **4.Concepts Used** 

- C++: Used to write and execute the program. 

- Directed Graph: Used to represent courses and their prerequisite relationships. 

- Adjacency List: Used to store the connections between courses. 

- Depth First Search (DFS): Used to explore courses connected to a selected course. 

- Recursion: Used to visit connected courses step by step. 

- Visited Array: Used to avoid visiting the same course repeatedly. 

## 5. **Algorithm** 

1. Start the program. 

2. Enter the number of courses and their names. 

3. Create a graph to store the course relationships. 

4. Enter the prerequisite relationships between courses. 

5. Connect each prerequisite course to the course that depends on it. 

6. Enter the name of the starting course. 

7. Check whether the course exists in the graph. 

8. Mark all courses as unvisited. 

9. Apply DFS to explore the courses connected to the selected course. 

10. Mark each visited course and continue exploring its connected courses. 

11. Display the reachable courses. 

12. Stop the program. 

## **6.Working of the Program** 

First, the program accepts the names of university courses from the user. It then takes the prerequisite relationships and stores them in a directed graph. 

After that, the user enters the name of a course from which the search should begin. The program checks the connections of that course and uses DFS to explore the courses that can be reached from it. 

A visited array keeps track of the courses already explored. This prevents the program from visiting the same course again. 

For example, if Programming is connected to DataStructures, and DataStructures is connected to Algorithms, then starting from Programming allows the program to reach both DataStructures and Algorithms. 

The program displays the reachable courses in DFS traversal order. 

## 7. **Applications** 

8. It helps in planning university courses. 

9. It shows which courses are connected to a selected course. 

10. It helps understand relationships between different subjects. 

11. It can be used for course dependency analysis. 

12. It helps students understand graph traversal in a practical way. 

## 8. **Conclusion** 

In this project, we represented university courses and their prerequisite relationships using a directed graph. We used DFS to explore the courses reachable from a selected course. Through this program, we learned how graphs, adjacency lists, recursion and DFS can be used to solve a real-world problem using C++. 

