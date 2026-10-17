#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
using namespace std;

struct Node
{
    string name;
    vector<Node*> children;

    Node(string n)
    {
        name = n;
    }
};

string trim(string s)
{
    size_t start = s.find_first_not_of(" \t");

    if (start == string::npos)
        return "";

    size_t end = s.find_last_not_of(" \t");

    return s.substr(start, end - start + 1);
}

string normalize(string s)
{
    s = trim(s);

    for (int i = 0; i < (int)s.length(); i++)
    {
        s[i] = tolower((unsigned char)s[i]);
    }

    return s;
}

Node* searchEmployee(Node* root, string name)
{
    if (root == NULL)
        return NULL;

    if (normalize(root->name) == normalize(name))
        return root;

    for (int i = 0; i < (int)root->children.size(); i++)
    {
        Node* found = searchEmployee(root->children[i], name);

        if (found != NULL)
            return found;
    }

    return NULL;
}

void displayEmployees(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    cout << "\nAvailable Employees:\n";

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        cout << "- " << current->name << endl;

        for (int i = 0; i < (int)current->children.size(); i++)
        {
            q.push(current->children[i]);
        }
    }
}

void addEmployee(Node* root)
{
    if (root == NULL)
    {
        cout << "Please add the CEO first!\n";
        return;
    }

    string managerName, employeeName;

    cout << "Enter manager name: ";
    getline(cin, managerName);

    Node* manager = searchEmployee(root, managerName);

    if (manager == NULL)
    {
        cout << "Manager not found!\n";
        displayEmployees(root);
        return;
    }

    cout << "Enter employee name: ";
    getline(cin, employeeName);

    employeeName = trim(employeeName);

    if (employeeName.empty())
    {
        cout << "Employee name cannot be empty!\n";
        return;
    }

    if (searchEmployee(root, employeeName) != NULL)
    {
        cout << "Employee already exists!\n";
        return;
    }

    Node* newEmployee = new Node(employeeName);

    manager->children.push_back(newEmployee);

    cout << "Employee added successfully!\n";
}

void displayHierarchy(Node* root)
{
    if (root == NULL)
    {
        cout << "Company hierarchy is empty!\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    int level = 0;

    cout << "\nCompany Hierarchy\n";

    while (!q.empty())
    {
        int size = (int)q.size();

        cout << "Level " << level << ": ";

        for (int i = 0; i < size; i++)
        {
            Node* current = q.front();
            q.pop();

            cout << current->name;

            if (i < size - 1)
                cout << ", ";

            for (int j = 0;
                 j < (int)current->children.size(); j++)
            {
                q.push(current->children[j]);
            }
        }

        cout << endl;
        level++;
    }
}

void deleteTree(Node* root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < (int)root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }

    delete root;
}

int main()
{
    Node* root = NULL;
    int choice;

    do
    {
        cout << "\nCompany Hierarchy Management System\n";
        cout << "1. Add CEO\n";
        cout << "2. Add Employee\n";
        cout << "3. Display Company Hierarchy\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );
            continue;
        }

        cin.ignore(
            numeric_limits<streamsize>::max(), '\n'
        );

        switch (choice)
        {
            case 1:
            {
                if (root != NULL)
                {
                    cout << "CEO already exists!\n";
                    break;
                }

                string ceoName;

                cout << "Enter CEO name: ";
                getline(cin, ceoName);

                ceoName = trim(ceoName);

                if (ceoName.empty())
                {
                    cout << "CEO name cannot be empty!\n";
                    break;
                }

                root = new Node(ceoName);

                cout << "CEO added successfully!\n";
                break;
            }

            case 2:
                addEmployee(root);
                break;

            case 3:
                displayHierarchy(root);
                break;

            case 4:
                cout << "Exiting application...\n";
                break;

            default:
                cout << "Invalid choice! Select 1 to 4.\n";
        }

    } while (choice != 4);

    deleteTree(root);

    return 0;
}
