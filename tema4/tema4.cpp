#include <iostream>
#include <stdexcept>
#include <cstring>


class ResourceManager {
private:
    char* data; 

public:
    
    // Task 13: Use objects to manage resources
    ResourceManager(const char* initData) {
        data = new char[strlen(initData) + 1];
        strcpy(data, initData);
        std::cout << "Resource allocated: " << data << std::endl;
    }

    ~ResourceManager() {
        delete[] data;
        std::cout << "Resource deallocated" << std::endl;
    }

    // Constructor de copiere - copie profundă
    // Task 14: Think carefully about copying behavior in resource-managing classes
    ResourceManager(const ResourceManager& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        std::cout << "Resource copied: " << data << std::endl;
    }

    // Operator de atribuire - copie profundă
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) { 
            delete[] data; 

            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
            std::cout << "Resource assigned: " << data << std::endl;
        }
        return *this;
    }

    
    const char* getData() const {
        return data;
    }
};

int main() {
    try {
        ResourceManager rm1("Hello, World!");
        ResourceManager rm2 = rm1;
        ResourceManager rm3("Temporary");
        rm3 = rm1;

        std::cout << "rm1 data: " << rm1.getData() << std::endl;
        std::cout << "rm2 data: " << rm2.getData() << std::endl;
        std::cout << "rm3 data: " << rm3.getData() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
