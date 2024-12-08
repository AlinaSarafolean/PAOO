#include <iostream>
#include <cstring> 

class MyClass {
private:
    char* data; 
    size_t size; 

public:
    // Constructor default
    MyClass() : data(nullptr), size(0) {
        std::cout << "Default constructor called\n";
    }

    // Constructor parametrizat
    MyClass(const char* input) : size(std::strlen(input)) {
        data = new char[size + 1];
        std::strcpy(data, input);
        std::cout << "Parameterized constructor called\n";
    }

    // Constructor de copiere
    MyClass(const MyClass& other) : size(other.size) {
        data = new char[size + 1];
        std::strcpy(data, other.data);
        std::cout << "Copy constructor called\n";
    }

    // Destructor
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor called\n";
    }

    // Operator de atribuire
    MyClass& operator=(const MyClass& other) {
        // Item 11: Gestionăm auto-atribuirea
        if (this == &other) {
            std::cout << "Self-assignment detected\n";
            return *this;
        }

        // Item 12: Copiem toate părțile obiectului
        // Eliberăm resursa veche
        delete[] data;

        // Alocăm și copiem resursa nouă
        size = other.size;
        data = new char[size + 1];
        std::strcpy(data, other.data);

        std::cout << "Assignment operator called\n";

        // Item 10: Returnăm *this pentru a permite operațiuni în lanț
        return *this;
    }

    
    void display() const {
        if (data) {
            std::cout << "Data: " << data << "\n";
        } else {
            std::cout << "Data is null\n";
        }
    }
};

int main() {
    MyClass obj1("Hello");    // Constructor parametrizat
    MyClass obj2 = obj1;      // Constructor de copiere

    obj2.display();

    MyClass obj3;             // Constructor default
    obj3 = obj1;              // Operator de atribuire
    obj3.display();

    obj1 = obj1;              // Auto-atribuire
    obj1.display();

    return 0;
}
