#include <limits.h>

class DynamicArray {
private:
  int* m_data;
  int m_capacity = 0;
  int m_size = 0;
public:

  DynamicArray(int capacity) {
    m_capacity = capacity;
    m_data = new int[capacity]();
  }
  
  int get(int i) {
    return m_data[i];
  }

  void set(int i, int n) {
    if (i < m_size)
      m_data[i] = n;
  }
  
  void pushback(int n) {
    if (m_size == m_capacity)
      resize();
    m_data[m_size++] = n;
  }

  int popback() {
    if (m_size > 0 )
      return m_data[--m_size];
    return INT_MIN;
  }

  void resize() {
    int* tmp = m_data;
    m_capacity = 2 * m_capacity;
    m_data = new int[m_capacity]();
    m_data = tmp;
  }

  int getSize() {
    return m_size;
  }

  int getCapacity() {
    return m_capacity;
  }
};
