#include "Resource.h"
#include <iostream>

int main() {
    std::cout << "Creare resursă r1 cu valoarea 10:" << std::endl;
    Resource r1(10);
    r1.display();

    std::cout << "\nCreare resursă r2 prin copierea lui r1:" << std::endl;
    Resource r2 = r1; // Copy constructor
    r2.display();

    std::cout << "\nCreare resursă r3 prin mutarea lui r1:" << std::endl;
    Resource r3 = std::move(r1); // Move constructor
    r3.display();
    r1.display(); // r1 nu ar trebui să mai aibă resurse

    std::cout << "\nSetare valoare pentru r2:" << std::endl;
    r2.setValue(20);
    r2.display(); 

    std::cout << "\nFinalul programului. Destructorii vor fi apelați automat." << std::endl;

    return 0;
}