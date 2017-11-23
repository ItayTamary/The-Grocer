/*************************************
 ** File:    ReadyDelivery.cpp
 ** Project: The Grocer
 ** Author:  Itay Tamary
 ** Date:    5/11/2017
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file reads in the text files and builds the vector of trucks
 ** items and deliveries.
 **
 **
 **************************************/

#include "ReadyDelivery.h"
#include <fstream>
using namespace std;

// ReadyDelivery ()
// Empty Constructor
ReadyDelivery::ReadyDelivery() {
  m_truck;
  m_delivery.resize(0);
  m_item.resize(0);
}

// ReadyDelivery (truckFile, deliveryFile, itemFile)
// Constructs and calls the reading in of text files
ReadyDelivery::ReadyDelivery(string truckFile, string deliveryFile, string itemFile) {
  m_delivery.resize(0);
  m_item.resize(0);
  m_truckFile = truckFile;
  m_deliveryFile = deliveryFile;
  m_itemFile = itemFile;
  LoadTruck();
  LoadDelivery();
  LoadItem();
}

// LoadTruck()
// Loads in truck textfile and adds to truck vector
void ReadyDelivery::LoadTruck() {
  string name;
  int capacity;
  ifstream inReader(m_truckFile.c_str());
  while (inReader >> name >> capacity) {
    m_truck.push_back(Truck<Item, MAX_CAPACITY>(name, capacity));
  }
  inReader.close();
}

// LoadDelivery ()
// Loads in delivery textfile and adds to delivery vector
void ReadyDelivery::LoadDelivery() {
  string name;
  int numItem, rtMinute;
  ifstream inReader(m_deliveryFile.c_str());
  while (inReader >> name >> numItem >> rtMinute) {
    m_delivery.push_back(Delivery(name, numItem, rtMinute));
  }
  inReader.close();
}

// LoadItem ()
// Loads in item text files and adds item to item vector
void ReadyDelivery::LoadItem() {
  string name;
  float weight;
  ifstream inReader(m_itemFile.c_str());
  while (inReader >>name >> weight) {
    m_item.push_back(Item(name, weight));
  }
  inReader.close();
}

// GetTruck ()
// Returns truck vector
vector<Truck<Item, MAX_CAPACITY> >& ReadyDelivery::GetTruck() {
  return m_truck;
}

// GetDelivery ()
// Returns delivery vector
vector<Delivery> ReadyDelivery::GetDelivery() {
  return m_delivery;
}

// GetItem ()
// Returns item vector
vector<Item> ReadyDelivery::GetItem() {
  return m_item;
}


