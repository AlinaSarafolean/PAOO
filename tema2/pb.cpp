#include <iostream>

// Item 4: Asigurarea inițializării obiectelor înainte de utilizare
class Point {
public:
    // Constructor care inițializează x și y
    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {
        std::cout << "Point created at (" << x << ", " << y << ")" << std::endl;
    }

    void print() const {
        std::cout << "Point (" << x << ", " << y << ")" << std::endl;
    }

private:
    int x, y;
};

// Item 5: Cunoscând funcțiile implicite generate de C++
class Rectangle {
public:
    Rectangle(int w, int h) : width(w), height(h) {
        std::cout << "Rectangle created with width " << width << " and height " << height << std::endl;
    }

    // Constructor de copiere implicit, operator de atribuire și destructor generate automat

    // Putem adăuga explicit constructorul de copiere pentru a vedea efectul
    Rectangle(const Rectangle& other) : width(other.width), height(other.height) {
        std::cout << "Rectangle copied with width " << width << " and height " << height << std::endl;
    }

    // Operator de atribuire
    Rectangle& operator=(const Rectangle& other) {
        if (this != &other) { // verificare auto-atribuire
            width = other.width;
            height = other.height;
            std::cout << "Rectangle assigned with width " << width << " and height " << height << std::endl;
        }
        return *this;
    }

    void print() const {
        std::cout << "Rectangle width: " << width << ", height: " << height << std::endl;
    }

private:
    int width, height;
};

// Item 6: Dezactivarea explicită a funcțiilor generate de compilator
class NonCopyable {
public:
    NonCopyable() = default;               // Constructor implicit
    ~NonCopyable() = default;              // Destructor implicit

    // Dezactivează constructorul de copiere și operatorul de atribuire
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;

    void doSomething() const {
        std::cout << "Doing something in NonCopyable object" << std::endl;
    }
};

int main() {
    // Test Item 4
    Point p(3, 4);
    p.print();

    // Test Item 5
    Rectangle rect1(10, 20);
    Rectangle rect2 = rect1; // Folosește constructorul de copiere
    rect2.print();
    rect1 = rect2;           // Folosește operatorul de atribuire

    // Test Item 6
    NonCopyable nc1;
    nc1.doSomething();
    // NonCopyable nc2 = nc1; // Eroare: constructorul de copiere este dezactivat
    // NonCopyable nc3;
    // nc3 = nc1;             // Eroare: operatorul de atribuire este dezactivat

    return 0;
}

