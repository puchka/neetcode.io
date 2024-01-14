#include <vector>

using namespace std;

class Node {
private:
  Node* m_next = NULL;
  int m_val;
public:
  Node(Node* next, int val) {
    m_next = next;
    m_val = val;
  }

  Node* getNext() {
    return m_next;
  }

  void setNext(Node* next) {
    m_next = next;
  }
  int getVal() {
    return m_val;
  }
  void setVal(int val) {
    m_val = val;
  }
};

class LinkedList {
private:
  Node* root = NULL;
  
public:
  LinkedList() {
    root = new Node(NULL, -1);
  }

  int get(int index) {
    Node* current = root;
    int i = 0;
    while (i++ < index && current != NULL)
      current = current->getNext();
    
    if (current != NULL && i == index + 1)
      return current->getVal();
    return -1;
  }
    
  void insertHead(int val) {
    if (root->getVal() == -1 && root->getNext() == NULL) {
      root->setVal(val);
      return;
    }
    Node* tmp = root;
    root = new Node(tmp, val);
  }

  void insertTail(int val) {
    Node* current = root;
    if (root->getVal() == -1 && root->getNext() == NULL) {
      root->setVal(val);
      return;
    }
    while (current->getNext() != NULL)
      current = current->getNext();
    current->setNext(new Node(NULL, val));
  }

  bool remove(int index) {
    Node* current = root;
    int i = 0;
    while (current->getNext() != NULL && ++i < index)
      current = current->getNext();

    if (index == 0 && current->getVal() != -1 && current->getNext() == NULL) {
      root = new Node(NULL, -1);
      return true;
    }
    if (index == 0 && current->getNext() != NULL) {
      Node* tmp = root->getNext();
      root = tmp;
      return true;
    }
    if (i == index && current->getNext() != NULL) {
      current->setNext(current->getNext()->getNext());
      return true;
    } 
    return false;
  }

  vector<int> getValues() {
    vector<int> values;
    Node* current = root;
    while (current->getNext() != NULL) {
      values.push_back(current->getVal());
      current = current->getNext();
    }
    if (current->getVal() != -1)
      values.push_back(current->getVal());
    return values;
  }
};
