#include <iostream>
#include <vector>
#include <string>
using namespace std;

void DFS(int course, vector<vector<int> > &graph,
         vector<bool> &visited, vector<string> &courses) {
    visited[course] = true;
    cout << courses[course] << endl;

    for (int i = 0; i < graph[course].size(); i++) {
        int next = graph[course][i];

        if (!visited[next]) {
            DFS(next, graph, visited, courses);
        }
    }
}

int main() {
    int n, m;

    cout << "Enter number of courses: ";
    cin >> n;

    vector<string> courses(n);

    cout << "Enter course names (without spaces):" << endl;

    for (int i = 0; i < n; i++) {
        cin >> courses[i];
    }

    vector<vector<int> > graph(n);

    cout << "Enter number of prerequisite relationships: ";
    cin >> m;

    cout << "Enter prerequisite course and dependent course:"
         << endl;

    for (int i = 0; i < m; i++) {
        string prerequisite, dependent;
        cin >> prerequisite >> dependent;

        int u = -1, v = -1;

        for (int j = 0; j < n; j++) {
            if (courses[j] == prerequisite)
                u = j;

            if (courses[j] == dependent)
                v = j;
        }

        if (u != -1 && v != -1) {
            graph[u].push_back(v);
        } else {
            cout << "Invalid course name. Relationship skipped."
                 << endl;
        }
    }

    string selected;

    cout << "Enter the starting course: ";
    cin >> selected;

    int start = -1;

    for (int i = 0; i < n; i++) {
        if (courses[i] == selected) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        cout << "Course not found." << endl;
        return 0;
    }

    vector<bool> visited(n, false);

    cout << "\nCourses reachable from " << selected
         << " using DFS:" << endl;

    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];

        if (!visited[next]) {
            DFS(next, graph, visited, courses);
        }
    }

    cout << "\nDFS traversal completed." << endl;

    return 0;
}
