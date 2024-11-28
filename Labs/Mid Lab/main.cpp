#include <iostream>
#include <vector>
#include "list.h"
using namespace std;

vector<Nodeptr> userInput() {
	vector<Nodeptr> cars;
	cout << "How many Car do you want to register?\n=> ";
	int carNum;
	cin >> carNum;
	for (int i = 0; i < carNum; i++) {
		Nodeptr newNode = new Node;
		int ccInput;
		cout << "Car " << i + 1 << ": \n";
		cout << "Enter Car Engine Capacity (cc): ";
		cin >> ccInput;
		newNode->cc = ccInput;
		int regInput;
		cout << "Enter Car Reg Num (4 - Digit): ";
		cin >> regInput;
		newNode->registrationNum = regInput;
		cars.push_back(newNode);
		cout << endl;
	}
	return cars;
}

int main() {
	List list;
	cout << "Welcome to Car List :)" << endl;
	list.filter(userInput());
	int input;
	do {
		cout << "1. Remove Low CC Car ?\n";
		cout << "2. Display Car List\n";
		cout << "3. Exit\n=> ";
		cin >> input;
		switch (input) {
		case 1:
			list.remove();
			break;
		case 2:
			list.display();
			break;
		case 3:
			cout << "Exiting....";
			break;
		default:
			cout << "Enter Correct Input";
			cin.clear();
			break;
		}
	} while (input != 3);
	return 0;
}


// #include <iostream>
// #include <string>
// #include "stack.h";
// using namespace std;

// int checkLength(char data[]) {
// 	for (int i = 0; i < 80; i++) {
// 		if (data[i] == NULL) {
// 			return i;
// 		}
// 	}
// }

// int main() {
// 	cout << "Welcome to Palindrome Checker :)\n";
// 	cout << "Enter your String: ";
// 	char test[80];
// 	cin >> test;
// 	int size = checkLength(test);
// 	Stack stack(size);
// 	if (stack.checkPalindrome(test, size)) {
// 		cout << "This String is a Palindrome.";
// 	}
// 	else {
// 		cout << "This String is not a Palindrome.";
// 	}
// 	return 0;
// }