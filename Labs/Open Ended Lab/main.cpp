#include "Polynomial.h"

int main() {
    Polynomial p1, p2;
    std::string file1, file2;
    int choice;
    double x;

    std::cout << "Enter the name of the polynomial file: ";
    std::cin >> file1;
    p1.readFromFile(file1);
    std::cout << "Polynomial 1: ";
    p1.print();

    do {
        std::cout << "\n1. ADD polynomial\n";
        std::cout << "2. MULTIPLY polynomial\n";
        std::cout << "3. EVALUATE polynomial\n";
        std::cout << "4. QUIT\n";
        std::cout << "Enter choice #: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the file containing the polynomial to add: ";
            std::cin >> file2;
            p2.readFromFile(file2);
            p1 = p1.add(p2);
            std::cout << "Sum: ";
            p1.print();
            break;

        case 2:
            std::cout << "Enter the file containing the polynomial to multiply: ";
            std::cin >> file2;
            p2.readFromFile(file2);
            p1 = p1.multiply(p2);
            std::cout << "Product: ";
            p1.print();
            break;

        case 3:
            std::cout << "Enter the value of x to evaluate: ";
            std::cin >> x;
            std::cout << "Result: " << p1.evaluate(x) << "\n";
            break;

        case 4:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
