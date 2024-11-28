#pragma once

#include<iostream>

class Stack {
	int size;
	int counter;
	char* data;
public:
	Stack(int size = 80) {
		this->size = size;
		counter = -1;
		data = new char[size];
	}
	~Stack() {
		delete[]data;
	}
	void insert(char c) {
		counter++;
		this->data[counter] = c;
	}

	char remove() {
		char c = this->data[counter];
		counter--;
		return c;
	}

	bool isEmpty() {
		return counter == -1;
	}

	bool checkPalindrome(char data[], int size) {
		for (int i = 0; i < size; i++) {
			insert(data[i]);
		}
		Stack stack2(size);
		Stack stack3(size);
		stack3.data = this->data;
		stack3.counter = this->counter;
		while (!stack3.isEmpty()) {
			stack2.insert(stack3.remove());
		}

		for (int i = 0; i < size; i++) {
			if (this->data[i] != stack2.data[i]) {
				return false;
			}
		}
		
		return true;
	}

};
