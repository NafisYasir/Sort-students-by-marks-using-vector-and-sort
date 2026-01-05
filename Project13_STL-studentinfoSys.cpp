 #include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <limits> 

using namespace std;

class Studentinfo {
    private:
    map<int, pair<string, int>> studentRegistry; // ID -> (Name, Marks)
    set<int> uniqueIDs;

    public:
    void addStudent(int id, const string& name, int marks) {
        studentRegistry[id] = make_pair(name, marks);
        uniqueIDs.insert(id);
    }
    void displayAllStudents() const {
        cout << "\n--- All Students ---" << endl;
        for (const auto& [id, info] : studentRegistry) {
            cout << "ID: " << id << " | Name: " << info.first << " | Marks: " << info.second << endl;
        }
    }
    void displayStudentsSortedByMarks() const {
        vector<pair<int, pair<string, int>>> studentsVec(studentRegistry.begin(), studentRegistry.end());
        sort(studentsVec.begin(), studentsVec.end(), [](const auto& a, const auto   & b) {
            return a.second.second > b.second.second; // Sort by marks descending
        });
        cout << "\n--- Students Sorted by Marks ---" << endl;
        for (const auto& [id, info] : studentsVec) {
            cout << "ID: " << id << " | Name: " << info.first << " | Marks: " << info.second << endl;
        }
    }
    void findStudentByID(int id) const {
        auto it = studentRegistry.find(id);
        if (it != studentRegistry.end()) {
            cout << "Found Student - ID: " << id << " | Name: " << it->second.first << " | Marks: " << it->second.second << endl;
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }
    int getUniqueIDCount() const {
        return uniqueIDs.size();
    }
};

void DisplayManue(){
    cout << "1. Add Student" << std::endl;
    cout << "2. Display All Students" << std::endl;
    cout << "3. Display Students Sorted by Marks" << std::endl;
    cout << "4. Find student by ID" << std::endl;
    cout << "5. Exit" << std::endl;

    cout << "Enter your choice: ";
}

int main() {
    Studentinfo studentInfo;
    int choice;

    do {
        DisplayManue();

        // Fix for Menu Choice: Handles non-numeric input
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number (1-5)." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue; 
        }

        switch (choice) {
            case 1: {
                int id, marks;
                string name;

                cout << "Enter Student ID: ";
                // Fix for ID: Asks again if input is not a number
                while (!(cin >> id)) {
                    cout << "Invalid ID! Please enter a numeric ID: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Enter Student Name: ";
                cin >> name;

                cout << "Enter Student Marks: ";
                // Fix for Marks: Asks again if input is not a number
                while (!(cin >> marks)) {
                    cout << "Invalid Marks! Please enter numeric marks: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                studentInfo.addStudent(id, name, marks);
                break;
            }
            case 2:
                studentInfo.displayAllStudents();
                break;
            case 3:
                studentInfo.displayStudentsSortedByMarks();
                break;
            case 4: {
                int id;
                cout << "Enter Student ID to search: ";
                // Fix for Search ID: Handles non-numeric search input
                while (!(cin >> id)) {
                    cout << "Invalid ID! Please enter a numeric ID: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                studentInfo.findStudentByID(id);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}