/*************************************
 ** File:    Item.cpp
 ** Project: The Grocer
 ** Author:  Itay Tamary
 ** Date:    5/11/2017
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file constructs each Item object the customer ordered with the 
 ** item's name and weight passed through a text file.
 **
 **************************************/

#include "Item.h"
using namespace std;

// Item ()
// Empty Item Constructor
Item::Item() {}

// Item (iName, iWeight) 
// Constructs an Item with its name and weight
Item::Item(string iName, float iWeight) {
  m_name = iName;
  m_weight = iWeight;
}

// GetName ()
// Returns the name of the item
string Item::GetName() const {
  return m_name;
}

// GetWeight ()
// Returns the weight of the item
float Item::GetWeight() const {
  return m_weight;
}
