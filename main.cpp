#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    string dueDate;
    bool completed;
};

bool compareDueDates(const Task& task1, const Task& task2) {
    return task1.dueDate < task2.dueDate;
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    cout << "Enter due date (DD-MM-YYYY): ";
    cin >> newTask.dueDate;
    newTask.completed = false;

    tasks.push_back(newTask);
    sort(tasks.begin(), tasks.end(), compareDueDates);
    cout << "Task added successfully!\n";
}

void markTaskCompleted(vector<Task>& tasks) {
    int taskNumber;

    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n----- Tasks -----\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        cout << "Description: " << tasks[i].description << " | ";
        cout << "Due Date: " << tasks[i].dueDate << " | ";
        cout << "Status: " << (tasks[i].completed ? "Completed" : "Incomplete") << "\n";
    }
    cout << "---------------------\n";
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "Enter task number to remove: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;

    int choice;
    do {
        cout << "\n----- To-Do List Manager -----\n";
        cout << "1. Add New Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. View Tasks\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "-----------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                markTaskCompleted(tasks);
                break;
            case 3:
                viewTasks(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }

    } while (choice != 5);

    return 0;
}