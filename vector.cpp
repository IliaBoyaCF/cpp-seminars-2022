#include <iostream>

class vector {
  int *data;
  int size;
  int capacity;

  // resizes vector to given capacity
  void resize(int new_capacity)
  // using method is allocating new array with new_capacity and coping previos values to it
  {
    int *extendedArray = new int[new_capacity];
    for (int i = 0; i < this->size; ++i)
    {
      extendedArray[i] = this->data[i];
    }
    this->data = extendedArray;
  }

  public:

  vector(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->data = new int[capacity]();
  }

  ~vector() { delete[] data; }

  // adds element to the last avaialable position,
  // resizes vector if current capacity is reached
  void push_back(int num)
  {
    if (this->size == this->capacity) 
    {
      // new capacity should be doubled previous for the sake of fast access
      int newCapacity = this->capacity * 2;
      this->resize(newCapacity); // should be an exception if resize fails
    }
    this->data[size] = num;
    this->size += 1;
  }

  int getSize() { return this->size; }

  void set(int num, int idx);
  int at(int idx);
  void print()
  {
    for (int i = 0; i < this->size; ++i)
    {
      std::cout << this->data[i] << ", ";
    }
    std::cout << std::endl;
  }
};

int main(int argc, char **argv) {
  // // size(&v)
  // vector v1;
  // v1.size();
}