#include <iostream>
#include "LinkedList.cpp"

void print(LinkedList* list) {
 vector<int> v;
  v = list->getValues();
  cout << "--------------" << endl;
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << endl;
}

int main() {
  LinkedList* list = new LinkedList();
  list->insertTail(0);
  list->insertTail(1);
  list->insertTail(2);
  cout << list->get(1) << endl;
  //cout << list->remove(0) << endl;
  list->remove(0);
  //list->remove(0);
  print(list);
}
