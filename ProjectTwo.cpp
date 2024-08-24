// ====================================================================================================
// Name: ProjectTwo.cpp
// Author: Shari Storlie
// Version: 1.0
// Description: CS-300, Lab 7-1, Project Two 
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Define the Course struct
struct Course {
    string courseNumber;
    string title;
    vector<string> prerequisites;
};

// Define the Node struct for the binary search tree
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node(Course c) : course(c), left(nullptr), right(nullptr) {}
};


// Function Prototypes
Course parseLine(const string& line);
Node* insertCourse(Node* root, Course course);
Node* loadCourseDataToTree(const string& filePath);
void validatePrerequisitesInTree(Node* root);
bool isPrerequisiteValid(const string& prereq, Node* root);
void printCourseList(Node* root);
string getPrerequisitesAsString(const vector<string>& prerequisites);
void printCourseInfoFromTree(Node* root, const string& courseNumber);
void printCourseInfoFromTree(Node* root, const string& courseNumber);
void displayMenu();


// Function to load course data from a file into a binary search tree
Node* loadCourseDataToTree(const string& filePath) {
    Node* root = nullptr;
    ifstream file(filePath);

    if (!file.is_open()) {
        cout << "Error: Unable to open file" << endl;
        return root;
    }   else {
            cout << "File opened successfully: " << filePath << endl;
    }

    string line;
    while (getline(file, line)) {
        Course course = parseLine(line);
        root = insertCourse(root, course);
    }

    file.close();
    validatePrerequisitesInTree(root);
    return root;
}

// Function to parse a line into a Course object
Course parseLine(const string& line) {
    Course course;
    stringstream ss(line);
    string token;

    getline(ss, course.courseNumber, ',');
    getline(ss, course.title, ',');

    while (getline(ss, token, ',')) {
        course.prerequisites.push_back(token);
    }

    return course;
}

// Function to insert a course into the binary search tree
Node* insertCourse(Node* root, Course course) {
    if (root == nullptr) {
        return new Node(course);
    }

    if (course.courseNumber < root->course.courseNumber) {
        root->left = insertCourse(root->left, course);
    }
    else {
        root->right = insertCourse(root->right, course);
    }

    return root;
}

// Function to print courses in alphanumeric order (in-order traversal)
void printCourseList(Node* root) {
    if (root == nullptr) return;

    printCourseList(root->left);
    cout << root->course.courseNumber << ", " << root->course.title << endl;
    printCourseList(root->right);
}

// Function to validate prerequisites in the tree
void validatePrerequisitesInTree(Node* root) {
    if (root == nullptr) return;
    for (const auto& prereq : root->course.prerequisites) {
        if (!isPrerequisiteValid(prereq, root)) {
            cout << "Error: Prerequisite " << prereq << " for course " << root->course.courseNumber << " does not exist in file" << endl;
        }
    }
    
    validatePrerequisitesInTree(root->left);
    validatePrerequisitesInTree(root->right);
}

// Function to check if a prerequisite exists in the binary search tree
bool isPrerequisiteValid(const string& prereq, Node* root) {
    if (root == nullptr) return false;

    if (root->course.courseNumber == prereq) {
        return true;
    }
    else if (prereq < root->course.courseNumber) {
        return isPrerequisiteValid(prereq, root->left);
    }
    else {
        return isPrerequisiteValid(prereq, root->right);
    }
}

// Function to print course information
void printCourseInfoFromTree(Node* root, const string& courseNumber) {
    if (root == nullptr) {
        cout << "Error: Course " << courseNumber << " not found" << endl;
        return;
    }

    if (root->course.courseNumber == courseNumber) {
        cout << "Course Number: " << root->course.courseNumber << endl;
        cout << "Title: " << root->course.title << endl;
        cout << "Prerequisites: " << getPrerequisitesAsString(root->course.prerequisites) << endl;
    }
    else if (courseNumber < root->course.courseNumber) {
        printCourseInfoFromTree(root->left, courseNumber);
    }
    else {
        printCourseInfoFromTree(root->right, courseNumber);
    }
}

// Function to get prerequisites as a string
string getPrerequisitesAsString(const vector<string>& prerequisites) {
    if (prerequisites.empty()) return "None";
    string result;
    for (const auto& prereq : prerequisites) {
        result += prereq + " ";
    }
    return result;
}

// Main Program
void displayMenu() {
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit." << endl;
}

// Execute the main function
int main() {
    Node* root = nullptr;
    string filePath = "CS 300 ABCU_Advising_Program_Input.csv";
    int choice;

    while (true) {
        displayMenu();
        cout << endl;
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the file name: ";
            cin >> filePath;
            root = loadCourseDataToTree(filePath);
            break;
        case 2:
            if (root == nullptr) {
                cout << "Load the data structure first." << endl;
            }
            else {
                printCourseList(root);
            }
            break;
        case 3:
            if (root == nullptr) {
                cout << "Load the data structure first." << endl;
            }
            else {
                string courseNumber;
                cout << "What course do you want to know about? ";
                cin >> courseNumber;
                printCourseInfoFromTree(root, courseNumber);
            }
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            return 0;
        default:
            cout << choice << " is not a valid option." << endl << endl;
            break;
        }
    }

    return 0;
}



