#include <iostream>
#include <string>
using namespace std;


void displayMenu() {
	cout << "1. Search for Student by ID or 2. Exit\n\n";
	}

struct studentPool {
	string studentNames = "";
	int studentID = 0;
	double studentGPA = 0.0;
};

int binarySearchByID(const studentPool students[], int size, int targetID) {
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (students[mid].studentID == targetID) {
			return mid;
		}
		else if (students[mid].studentID < targetID) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
};

int main() {
	studentPool* students = new studentPool[3];

	students[0] = { "Grisha", 1, 3.2 };
	students[1] = { "Thomas", 2, 2.9 };
	students[2] = { "Avery", 3, 4.0 };

int size = 3;
	int option;
	int targetID;


	do {
		displayMenu();
		cin >> option;
		if (option == 1) {
			cout << "\nEnter Student ID Number: ";
			cin >> targetID;
			int index = binarySearchByID(students, size, targetID);
			if (index != -1) {
				cout << "\nStudent Name: " << students[index].studentNames 
					<< "\nID Number: " << targetID
					<< "\nGPA: " << students[index].studentGPA << endl;
			} else {
				cout << "\nUnknown Student ID. Exiting now\n";
			}
			delete[] students;
			return 0;
		}

	} while (option != 2);

	delete[] students;
	return 0;
}