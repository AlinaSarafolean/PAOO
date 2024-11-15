#include "Resource.h"

// Constructor
Resource::Resource(int value) : data(new int(value)) {
    std::cout << "Constructor apelat. Valoare: " << *data << std::endl;
}

// Copy constructor 
Resource::Resource(const Resource& other) : data(new int(*other.data)) {
    std::cout << "Copy constructor apelat. Valoare copiată: " << *data << std::endl;
}

// Move constructor 
Resource::Resource(Resource&& other) noexcept : data(other.data) {
    other.data = nullptr;
    std::cout << "Move constructor apelat. Resursa mutată." << std::endl;
}

// Destructor 
Resource::~Resource() {
    if (data != nullptr) {
        std::cout << "Destructor apelat. Eliberare valoare: " << *data << std::endl;
        delete data;
    } else {
        std::cout << "Destructor apelat. Nicio resursă de eliberat." << std::endl;
    }
}

// Metodă de afișare
void Resource::display() const {
    if (data != nullptr) {
        std::cout << "Valoare resursă: " << *data << std::endl;
    } else {
        std::cout << "Resursa nu are valoare." << std::endl;
    }
}

// Setare valoare
void Resource::setValue(int value) {
    if (data != nullptr) {
        *data = value;
    }
}