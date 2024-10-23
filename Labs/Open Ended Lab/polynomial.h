#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>

class Polynomial {
private:
    struct Term {
        double coefficient;
        int degree;
        Term* next;
        Term(double c, int d) : coefficient(c), degree(d), next(nullptr) {}
    };

    Term* head;

    void insertTerm(double coefficient, int degree) {
        if (coefficient == 0) return; 
        Term* newTerm = new Term(coefficient, degree);
        if (!head || head->degree > degree) {
            newTerm->next = head;
            head = newTerm;
        } else {
            Term* current = head;
            while (current->next && current->next->degree < degree) {
                current = current->next;
            }
            if (current->degree == degree) {
                current->coefficient += coefficient;
                if (current->coefficient == 0) removeTerm(degree); 
            } else {
                newTerm->next = current->next;
                current->next = newTerm;
            }
        }
    }

    void removeTerm(int degree) {
        if (!head) return;
        if (head->degree == degree) {
            Term* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Term* current = head;
        while (current->next && current->next->degree != degree) {
            current = current->next;
        }
        if (current->next && current->next->degree == degree) {
            Term* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

public:
    Polynomial() : head(nullptr) {}

    ~Polynomial() {
        while (head) {
            Term* temp = head;
            head = head->next;
            delete temp;
        }
    }

void readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file\n";
        return;
    }

    std::string line;
    if (std::getline(file, line)) {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());

        size_t pos = 0;
        while (pos < line.length()) {
            int sign = 1;
            
            if (line[pos] == '-') {
                sign = -1;
                pos++;
            } else if (line[pos] == '+') {
                pos++;
            }

            double coefficient = sign;
            size_t xPos = line.find('x', pos);
            if (xPos == std::string::npos) {
                coefficient *= std::stod(line.substr(pos));
                insertTerm(coefficient, 0);
                break;
            }

            if (xPos > pos) {
                coefficient *= std::stod(line.substr(pos, xPos - pos));
            } else {
                coefficient *= 1.0;
            }
            pos = xPos + 1; // Move past the 'x'

            int degree = 1; // Default degree is 1
            if (pos < line.length() && line[pos] == '^') {
                pos++; // Move past '^'
                size_t degreeEnd = line.find_first_of("+-", pos);
                degree = std::stoi(line.substr(pos, degreeEnd - pos));
                pos = degreeEnd; // Move past the degree
            }

            insertTerm(coefficient, degree);
        }
    }
    file.close();
}


    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        Term* t1 = head;
        Term* t2 = other.head;

        while (t1 || t2) {
            if (!t2 || (t1 && t1->degree < t2->degree)) {
                result.insertTerm(t1->coefficient, t1->degree);
                t1 = t1->next;
            } else if (!t1 || (t2 && t2->degree < t1->degree)) {
                result.insertTerm(t2->coefficient, t2->degree);
                t2 = t2->next;
            } else {
                result.insertTerm(t1->coefficient + t2->coefficient, t1->degree);
                t1 = t1->next;
                t2 = t2->next;
            }
        }

        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        Polynomial result;
        for (Term* t1 = head; t1; t1 = t1->next) {
            for (Term* t2 = other.head; t2; t2 = t2->next) {
                result.insertTerm(t1->coefficient * t2->coefficient, t1->degree + t2->degree);
            }
        }
        return result;
    }

    double evaluate(double x) const {
        double result = 0;
        for (Term* current = head; current; current = current->next) {
            result += current->coefficient * std::pow(x, current->degree);
        }
        return result;
    }

    void print() const {
        if (!head) {
            std::cout << "0";
            return;
        }
        Term* current = head;
        while (current) {
            std::cout << current->coefficient << "x^" << current->degree;
            if (current->next) std::cout << " + ";
            current = current->next;
        }
        std::cout << "\n";
    }
};
