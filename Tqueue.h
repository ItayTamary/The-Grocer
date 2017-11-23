/*************************************
 ** File:    Tqueue.h
 ** Project: The Grocer
 ** Author:  Itay Tamary
 ** Date:    5/11/2017
 ** E-mail: itay.tamary@gmail.com
 **
 ** This header file constructs the dynamically allocated array Queue
 ** and manages the Queue
 ** 
 **
 **************************************/


#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor - Not used but required for project 5
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue
  void enqueue(T data); //Adds item to queue (to back)
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  void dequeue(T &); //Removes item from queue (from front)
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve front (does not remove it)
  void queueFront(T &);    // Retrieve front (does not remove it)
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0
  //Name: isFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int isFull(); //Returns 1 if queue is full else 0
  //Name: Overloaded assignment operator - Not used but required for project 5
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Add class definition below ****

// Tqueue ()
// Constructor of storage Queue
template <class T, int N>
Tqueue<T, N>::Tqueue() {
  m_data = new T[N]();
  m_front = 0;
  m_back = 0;
}

// Tqueue (x)
// Copy constructor of Tqueue
template <class T, int N>
  Tqueue<T, N>::Tqueue(const Tqueue<T,N>& x) {
  m_data = new T[N];
  for (int i = 0; i < m_back; i++) {
    m_data[i] = x.m_data[i];
  }
  m_front =  x.m_front;
  m_back =  x.m_back;
  
}

// ~Tqueue ()
// Destructs the queue and the dynamically allocated memory (array)
template <class T, int N> 
  Tqueue<T, N>::~Tqueue() {
      delete [] m_data;
}

// enqueue ()
// Adds an item to the end of the queue
template <class T, int N> 
  void Tqueue<T, N>::enqueue(T data) {
  m_data[m_back] = data;
  m_back = m_back + 1;
}

// dequeue ()
// Removes an item from the font of the queue
template <class T, int N>
  void Tqueue<T, N>::dequeue(T & front) {
  front = m_data[m_front];
  for (int i = 0; i < m_back; i++) {
    m_data[i] = m_data[i+1];
  }
  m_back = m_back - 1; //pushes everything back one
}

// queueFront ()
// Passes through object and retrieves front
template <class T, int N>
  void Tqueue<T, N>::queueFront(T & front) {
  front = m_data[m_front];
}

// isEmpty()
// Returns whether queue is empty or not
template <class T, int N>
  int Tqueue<T, N>::isEmpty() {
  int empty = 0;
  if (m_back == m_front) {
    empty = 1;
  }
  return empty;
}

// isFull ()
// Returns whether queue is full or not
template <class T, int N>
  int Tqueue<T, N>::isFull() {
  int full = 0;
  if (m_back == N) {
    full = 1;
  }
  return full;
}

// operator= ()
// Overload operator that allows to make to compare to queues
template <class T, int N>
  Tqueue<T,N>& Tqueue<T, N>::operator=( Tqueue<T,N> y) {
  for (int i = 0; i < y.m_back; i++) {
    m_data[i] = y.m_data[i];
  }
  m_front =  y.m_front;
  m_back =  y.m_back;
  return *this;
}
  
  
#endif
