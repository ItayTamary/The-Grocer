/*************************************
 ** File:    Delivery.cpp
 ** Project: The Grocer
 ** Author:  Itay Tamary
 ** Date:    5/11/2017
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file contains the code to construct and return a delivery object
 ** passed through a text file.
 ** 
 **
 **************************************/

#include "Delivery.h"
using namespace std;

// Delivery ()
// Empty Delivery Constructor
Delivery::Delivery() {}

// Delivery (name, numItem, rtMinute)
// Constructs a delivery with the customer's last name, how many items
// the customer ordered, and the time it takes to deliver the items
Delivery:: Delivery(string name, int numItem, int rtMinute) {
  m_name = name;
  m_numItem = numItem;
  m_rtMinute = rtMinute;
}

// GetName ()
// Returns the customer's last name
string Delivery::GetName() const {
  return m_name;
}


// GetNumItem ()
// Returns the number of items the customer ordered
int Delivery::GetNumItem() const {
	return m_numItem;
}


// GetRTMinute ()
// Returns the amount of time (in minutes) it takes to deliver the order
int Delivery::GetRTMinute() const {
	return m_rtMinute;
}
