#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>

class Resource {
  private:
    int* data;

  
  public:
    // Constructor implicit
    Resource(int value = 0);

    
    // Copy constructor
    Resource(const Resource& other);

     // Move constructor
    Resource(Resource&& other) noexcept;

    // Destructor
    ~Resource();

    // Metodă de afișare a valorii
    void display() const;

    // Setare valoare
    void setValue(int value);

};

#endif