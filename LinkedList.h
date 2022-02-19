#pragma once
#include <vector>
using namespace std;
template <typename T>
class LinkedList {
   public:
   class Node;
   //Behaviors
   void PrintForward() const;
   void PrintReverse() const;
   void PrintForwardRecursive(const Node* node) const;
   void PrintReverseRecursive(const Node* node) const;
   //Accessors
   unsigned int NodeCount() const;
   Node* Head();
   Node* Tail();
   Node* GetNode(unsigned int index);
   Node* Find(const T& data);
   void FindAll(vector<Node*>& outData, const T& value) const;
   const Node* Head() const;
   const Node* Tail() const;
   const Node* GetNode(unsigned int index) const;
   const Node* Find(const T& data) const;
   //Insertion
   void AddHead(const T& data);
   void AddTail(const T& data);
   void AddNodesHead(const T* data, unsigned int count);
   void AddNodesTail(const T* data, unsigned int count);
   void InsertAfter(Node* node, const T& data);
   void InsertBefore(Node* node, const T& data);
   void InsertAt(const T& data, unsigned int index);
   //Removal
   bool RemoveHead();
   bool RemoveTail();
   unsigned int Remove(const T& data);
   bool RemoveAt(unsigned int index);
   void Clear();
   //Operators
   T& operator[](unsigned int index);
   const T& operator[](unsigned int index) const;
   LinkedList<T>& operator=(const LinkedList& rhs);
   bool operator==(const LinkedList<T>& rhs) const;
   //Construction/Destruction
   LinkedList();
   ~LinkedList();
   LinkedList(const LinkedList<T>& list);
   class Node {
      public:
      T data;
      Node* next;
      Node* prev;
   };
   private:
   unsigned int count;
   T* data;
   Node* tempNode;
   Node* currentHead;
   Node* currentTail;
};
//Behaviors
   template <typename T>
   void LinkedList<T>::PrintForward() const {
   Node* currentNode = currentHead;
   while (currentNode != nullptr) {
      cout<<currentNode->data<<endl;
      currentNode = currentNode->next;
   }
   }
   template <typename T>
   void LinkedList<T>::PrintReverse() const {
   Node* currentNode = currentTail;
   while (currentNode != nullptr) {
      cout<<currentNode->data<<endl;
      currentNode = currentNode->prev;
   }
   }
   template <typename T>
   void LinkedList<T>::PrintForwardRecursive(const Node* node) const{
      const Node* storage = node;
      cout<< storage-> data<<endl;
      if (storage != currentTail) {
         PrintForwardRecursive(storage->next);
      }
   }
   template <typename T>
   void LinkedList<T>::PrintReverseRecursive(const Node* node) const{
      const Node* storage = node;
      cout<< storage-> data<<endl;
      if (storage != currentHead) {
         PrintReverseRecursive(storage->prev);
      }
   }
   //Accessors
   template <typename T>
   unsigned int LinkedList<T>::NodeCount() const {
   return count;
   }
   template <typename T>
   typename LinkedList<T>::Node* LinkedList<T>::Head(){
      return currentHead;
      }
   template <typename T>
   typename LinkedList<T>::Node* LinkedList<T>::Tail(){
      return currentTail;
      }
   template <typename T>
   typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index){
      Node* currentNode = currentHead;
       if (index >= count) {
            throw out_of_range("Index out of range");
         }
      for (unsigned int i = 0; i < index; i++) {
      currentNode = currentNode->next;
      }
      return currentNode;
      }
   template <typename T>
   typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data){
      Node* currentNode = currentHead;
      while (currentNode != nullptr) {
         if (currentNode->data == data) {
         return currentNode;
      }
      currentNode = currentNode->next;
   }
      return nullptr;
      }
      template <typename T>
   void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const{
      Node* tempNode = currentHead;
      for (unsigned int i = 0; i < count; i++) {
         if (tempNode->data == value) {
            outData.push_back(tempNode);
         }
         tempNode = tempNode->next;
      }
      delete tempNode;
      }
   template <typename T>
   const typename LinkedList<T>::Node* LinkedList<T>::Head() const{
      return currentHead;
      }
   template <typename T>
   const typename LinkedList<T>::Node* LinkedList<T>::Tail() const{
      return currentTail;
      }
   template <typename T>
   const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const{
      Node* currentNode = currentHead;
      if (index >= count) {
            throw out_of_range("Index out of range");
         }
      for (unsigned int i = 0; i < index; i++) {
      currentNode = currentNode->next;
      }
      return currentNode;
   }
   template <typename T>
   const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const{
      Node* currentNode = currentHead;
      while (currentNode != nullptr) {
         if (currentNode->data == data) {
         return currentNode;
      }
      currentNode = currentNode->next;
   }
      return nullptr;
      }
   //Insertion
   template <typename T>
   void LinkedList<T>::AddHead(const T& data) {
   tempNode = new Node();
   tempNode->data = data;
   if (currentHead == nullptr) {
      currentTail = tempNode;
   } else {
      currentHead->prev = tempNode;
      tempNode-> next = currentHead;
   }
   currentHead = tempNode;
   tempNode = nullptr;
   count++;
   }
   template <typename T>
   void LinkedList<T>::AddTail(const T& data) {
   tempNode = new Node();
   tempNode->data = data;
   if (currentTail == nullptr) {
      currentHead = tempNode;
   } else {
      currentTail->next = tempNode;
      tempNode-> prev = currentTail;
   }
   currentTail = tempNode;
   tempNode = nullptr;
   count++;
   }
   template <typename T>
   void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
   unsigned int tempCount = count - 1;
   while (tempCount >= 0) {
    AddHead(data[tempCount]);
    if (tempCount == 0) {
     break;
    }
    tempCount--;
   }
   }
   template <typename T>
   void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
   unsigned int tempCount = 0;
   while (tempCount < count) {
    AddTail(data[tempCount]);
    tempCount++;
   }
   }
   template <typename T>
   void LinkedList<T>::InsertAfter(Node* node, const T& data) {
      Node* newNode = new Node();
      Node* nextNode = node->next;
      nextNode->prev = newNode;
      newNode-> prev = node;
      newNode-> next = nextNode;
      node-> next = newNode;
      newNode->data = data;
   }
   template <typename T>
   void LinkedList<T>::InsertBefore(Node* node, const T& data) {
      Node* newNode = new Node();
      Node* previousNode = node->prev;
      previousNode->next = newNode;
      newNode-> next = node;
      newNode-> prev = previousNode;
      node-> prev = newNode;
      newNode->data = data;
   }
   template <typename T>
   void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
    if (index > count) {
        throw out_of_range("Index out of range");
    }
    Node* newNode = new Node();
    tempNode = Head();
    if (index == count) {
        AddTail(data);
        delete newNode;
    } else if (index != 0) {
        tempNode = GetNode(index);
        Node *previousNode = tempNode->prev;
        newNode->prev = previousNode;
        previousNode->next = newNode;
        newNode-> next = tempNode;
        tempNode-> prev = newNode;
        newNode->data = data;
        count++;
    }else {
        currentHead = newNode;
        newNode-> next = tempNode;
        tempNode-> prev = newNode;
        newNode->data = data;
        count++;
    }
   }
   //Removal
   template <typename T>
   bool LinkedList<T>::RemoveHead(){
      if (currentHead != nullptr) {
         tempNode = currentHead;
           if (tempNode->next != nullptr) {
            Node* storage = currentHead->next;
         storage->prev = nullptr;
         currentHead = storage;
         if (count <= 2) {
           currentTail = storage; 
         }
         } else if (tempNode == currentTail) {
         delete tempNode;
         count--;
         currentTail = nullptr;
         currentHead = nullptr;
         return true;
         } else {
          return false;  
         } 
         delete tempNode;
         count--;
         return true;
      }
      return false;
   }
   template <typename T>
   bool LinkedList<T>::RemoveTail(){
      if (currentTail != nullptr) {
         tempNode = currentTail;
         if (tempNode->prev != nullptr) {
            Node* storage = currentTail->prev;
         storage->next = nullptr;
         currentTail = storage;
         if (count <= 2) {
           currentHead = storage; 
         }
         } else if (tempNode == currentHead) {
         delete tempNode;
         count--;
         currentTail = nullptr;
         currentHead = nullptr;
         return true;
         } else {
          return false;  
         }
         delete tempNode;
         count--;
         return true;
      }
      return false;
   }
   template <typename T>
   unsigned int LinkedList<T>::Remove(const T& data){
      unsigned int deletedCount = 0;
      for (unsigned int i = 0; i < this->count; i++) {
         if (this->GetNode(i)->data == data) {
            this->RemoveAt(i);
            deletedCount++;
         }
      }
      return deletedCount;
   }
   template <typename T>
   bool LinkedList<T>::RemoveAt(unsigned int index){
      if (index > count) {
         return false;
      }
      tempNode = GetNode(index);
      Node* previousNode = tempNode->prev;
      Node* nextNode = tempNode->next;
      delete tempNode;
      previousNode->next = nextNode;
      nextNode->prev = previousNode;
      count--;
      return true;
   }
   template <typename T>
   void LinkedList<T>::Clear(){
      Node* tempDeleter = currentHead;
   Node* deleter;
   while (tempDeleter != nullptr) {
      deleter = tempDeleter->next;
      delete tempDeleter;
      tempDeleter = deleter;
   }
   currentTail = nullptr;
   currentHead = nullptr;
   tempNode = nullptr;
   count = 0;
   }
   //Operators
   template <typename T>
   T& LinkedList<T>::operator[](unsigned int index){
      if (index > count) {
       throw out_of_range("Index out of range");
      }
      Node* currentNode = currentHead;
      for (unsigned int i = 0; i < index; i++) {
         currentNode = currentNode->next;
      }
      return currentNode -> data;
      }
   template <typename T>
   LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs){
      Node* tempDeleter = this->currentHead;
   Node* deleter;
   while (tempDeleter != nullptr) {
      deleter = tempDeleter->next;
      delete tempDeleter;
      tempDeleter = deleter;
   }
   this->currentTail = nullptr;
   this->currentHead = nullptr;
   this->tempNode = nullptr;
   this->count = 0;
      for (unsigned int i = 0; i < rhs.count; i++) {
         AddTail(rhs[i]);
      }
      return *this;
      }
      template <typename T>
   const T& LinkedList<T>::operator[](unsigned int index) const {
      Node* currentNode = currentHead;
      if (index > count) {
            throw out_of_range("Index out of range");
         }
      for (unsigned int i = 0; i < index; i++) {
         currentNode = currentNode->next;
      }
      return currentNode -> data;
      }
      template <typename T>
   bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const{
      bool isEqual = true;
      for (unsigned int i = 0; i < rhs.count; i++) {
         if (this->GetNode(i)->data != rhs.GetNode(i)->data) {
            isEqual = false;
            break;
         }
      }
      return isEqual;
      }
   //Construction/Destruction
   template <typename T>
   LinkedList<T>::LinkedList() {
   count = 0;
   currentHead = nullptr;
   currentTail = nullptr;
   }
   template <typename T>
   LinkedList<T>::~LinkedList() {
   Clear();
   }
   template <typename T>
   LinkedList<T>::LinkedList(const LinkedList<T>& list) {
      this->count = 0;
      this->currentHead = nullptr;
      this->currentTail = nullptr;
      for (unsigned int i = 0; i < list.count; i++) {
         AddTail(list[i]);
      }
   }