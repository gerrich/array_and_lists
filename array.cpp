#include <iostream>
#include <stdint.h>

template <typename T>
void swap(T &lhs, T &rhs) {
  T tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

typedef int data_t;
struct array_t {
  data_t *data;
  size_t capacity;
  size_t size;

  array_t() 
    :data(NULL)
    ,capacity(0)
    ,size(0)
  {}

  array_t(size_t _size) 
    :data(new data_t[_size])
    ,capacity(_size)
    ,size(_size)
  {}

  bool increase() {
    // here one need some more memoty
    if (size >= capacity) {
      size_t new_capacity = 8;
      if ( capacity > 4) {
        new_capacity = capacity * 2;
      }

      data_t *tmp = new data_t[new_capacity];
      for (size_t i = 0; i < size; ++i) {
        tmp[i] = data[i];
      }

      swap(tmp, data);
      delete [] tmp;
      capacity = new_capacity;

      return true;
    }
    return false;
  }

  void push_back(const data_t& value) {
    increase();
       
    data[size] = value;
    ++size;
  }

  void pop_back() {
    // decrease();
    --size;
  }

  const data_t& back() const {
    return data[size - 1];
  }

  ~array_t() {
    delete [] data;
  }

  void append(const array_t& rhs) {
    //resize(size + rhs.size);
    //
  }
};

void array_append(array_t &lhs, const array_t &rhs) {
  //...
}

void init_array(array_t &array) {
  array.data = NULL;
  array.size = 0;
}

int main() {
  int count;
  std::cin >> count;
  
  array_t array;

  for (int i = 0; i < count; ++i) {
    data_t value;
    std::cin >> value;
    
    array.push_back(value); 
  }
 
  for (size_t i = 0; i < count; ++i) {
    std::cout << array.back() << "\n";
    array.pop_back();
  }
  return 0;
}












