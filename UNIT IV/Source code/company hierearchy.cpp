#include <iostream>
#include <queue>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

struct Node
{
    string name;
    Node* left;
    Node* right;

    Node(string n)
    {
        name = n;
        left = NULL;
        right = NULL;
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
        s[i] = (char)tolower((unsigned char)s[i]);

    return s;
}

Node* searchEmployee(Node* root, string name)
{
    if (root == NULL)
        return NULL;

    if (normalize(root->name) == normalize(name))
        return root;

    Node* found = searchEmployee(root->left, name);

    if (found != NULL)
        return found;

    return searchEmployee(root->right, name);
}

void displayEmployees(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    cout << "\nAvailable Employees and Managers:\n";

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        cout << "- " << current->name << endl;

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

void addEmployee(Node* root)
{
    if (root == NULL)
    {
        cout << "Please add the CEO first!\n";
        return;
    }

    string managerName, employeeName, position;

    cout << "Enter manager/parent name: ";
    getline(cin, managerName);

    Node* manager = searchEmployee(root, managerName);

    if (manager == NULL)
    {
        cout << "Manager/parent not found!\n";
        displayEmployees(root);
        return;
    }

    cout << "Enter new employee name: ";
    getline(cin, employeeName);

    employeeName = trim(employeeName);

    if (employeeName.empty())
    {
        cout << "Employee name cannot be empty!\n";
        return;
    }

    if (searchEmployee(root, employeeName) != NULL)
    {
        cout << "This name already exists in the hierarchy!\n";
        return;
    }

    cout << "Enter position (L for left, R for right): ";
    getline(cin, position);

    position = normalize(position);

    if (position != "l" && position != "r")
    {
        cout << "Invalid position! Enter L or R.\n";
        return;
    }

    if (position == "l")
    {
        if (manager->left != NULL)
        {
            cout << "Left position is already occupied!\n";
            return;
        }

        manager->left = new Node(employeeName);
    }
    else
    {
        if (manager->right != NULL)
        {
            cout << "Right position is already occupied!\n";
            return;
        }

        manager->right = new Node(employeeName);
    }

    cout << "Employee/manager added successfully!\n";
}

void displayHierarchy(Node* root)
{
    if (root == NULL)
    {
        cout << "Company hierarchy is empty! "
             << "Please add the CEO first.\n";
        return;
    }

    queue<Node*> q;
    queue<int> levels;

    q.push(root);
    levels.push(0);

    cout << "\n====================================\n";
    cout << "       COMPANY HIERARCHY\n";
    cout << "====================================\n";

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        int level = levels.front();
        levels.pop();

        cout << "Level " << level << ": "
             << current->name << endl;

        if (current->left != NULL)
        {
            q.push(current->left);
            levels.push(level + 1);
        }

        if (current->right != NULL)
        {
            q.push(current->right);
            levels.push(level + 1);
        }
    }

    cout << "====================================\n";
}

void deleteTree(Node* root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

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
        cout << "2. Add Manager/Employee\n";
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
