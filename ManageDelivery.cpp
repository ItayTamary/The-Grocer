/*************************************
 ** File:    ManageDelivery.cpp
 ** Project: The Grocer
 ** Author:  Itay Tamary
 ** Date:    5/11/2017
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file essentially runs the program. It constructs the vector of 
 ** trucks, deliveries and items. Starts the delivery and manages the trucks
 ** 
 **************************************/

#include "ManageDelivery.h"

const int loadTime = 10;
using namespace std;

// ManageDelivery ()
// Constructs the truck, delivery, and item vector and starts the delivery
ManageDelivery::ManageDelivery(vector<Truck<Item, MAX_CAPACITY> > truck, vector<Delivery> delivery, vector<Item> item) {
  m_truck = truck;
  m_delivery = delivery;
  m_item = item;
  StartDelivery();
}

// StartDelivery ()
// Starts the delievry, assigns deliveries to trucks and then loads items
// onto trucks
void ManageDelivery::StartDelivery() {
  int numTrucks = m_truck.size();
  unsigned int numDelivery = m_delivery.size();
  int numItems = m_item.size();
  cout << "" << endl;
  cout << "Trucks Loaded: " << numTrucks << endl;
  cout << "Deliveries Loaded: " << numDelivery << endl;
  cout << "Items Loaded: " << numItems << endl;
  cout << "Start Time: 0" << endl;
  int totalDelivered = 0;
  unsigned int currentCapacity = 0;
  unsigned int currentDelivery = 0;
  unsigned int truckCapacity, deliverySize;
  bool fullTruck;
  while (currentDelivery < m_delivery.size()) {//while loop of all deliverys
    for (int i = 0; i < numTrucks; i++) {
      truckCapacity = m_truck[i].GetCapacity();
      fullTruck = false;
      while (fullTruck == false) { //loops until current truck is full
		deliverySize = m_delivery[currentDelivery].GetNumItem();
		if ((deliverySize + currentCapacity <= truckCapacity && (numDelivery> currentDelivery))) { //if statements assures no segmentaion fault
		  m_truck[i].AddDelivery(m_delivery[currentDelivery]);
		  for (unsigned int p = 0; p < deliverySize; p++) { 
			m_truck[i].AddItem(m_item[p+totalDelivered]);
		  } //addItem from current point of the item vector
		  totalDelivered = totalDelivered + deliverySize;
		  currentCapacity = currentCapacity + deliverySize;
		  currentDelivery = currentDelivery + 1;
		}
		else {
		  DeliverItem(i);
		  currentCapacity = 0; //when truck switches, new capacity is zero
		  m_truck[i].DeliverItemFromTruck(); 
		  fullTruck = true;
		}
      }
    }
  }
  DisplayItemLeft();
}

// ManageDelivery ()
// Outputs the delivery information of the trucks and items
void ManageDelivery::DeliverItem(int j) {
  cout << "\n*****Loading Truck (" << m_truck[j].GetName() << ")*****" << endl;
  vector<Delivery> truckDelivery = m_truck[j].GetDelivery();
  int deliveryNumItems = 0;
  int numDelivery = truckDelivery.size();
  for (int g = 0; g < numDelivery; g++) { //calculates total number of items
    deliveryNumItems = deliveryNumItems + truckDelivery[g].GetNumItem();
  }
  for (int p = 0; p < deliveryNumItems; p++) {
    m_truck[j].CompleteDelivery(); //retrieves front and then removes front
    cout  << " loaded into " << m_truck[j].GetName() << endl;
  }
  cout << " " << endl;
  cout << "**Truck Name: " << m_truck[j].GetName() << "**" << endl;
  int truckTime = m_truck[j].GetTime();
  m_truck[j].SetTime(truckTime + loadTime); //adds 10 minutes for loading time
  for (int i = 0;  i < numDelivery; i++) {
    truckTime = m_truck[j].GetTime();
    m_truck[j].SetTime(truckTime + truckDelivery[i].GetRTMinute() );
    cout << "***********Delivery " << i + 1 << "***********" << endl;
    cout << "Delivery Time: " << m_truck[j].GetTime() << endl;
    cout << "Delivery for: " << truckDelivery[i].GetName() << endl;
    cout << "Delivered: " << truckDelivery[i].GetNumItem() << endl;
  }
  if (numDelivery == 0) {
    cout << "No deliveries" << endl;
  }
}

// DisplayItemLeft ()
// Displays the items left over in the truck
void ManageDelivery::DisplayItemLeft() {
  cout << "\n*****Items Left After Deliveries*****" << endl;
  unsigned int totalDelivered = 0;
  for (unsigned int i = 0; i < m_delivery.size(); i++) {
    totalDelivered = totalDelivered + m_delivery[i].GetNumItem();
  } //calculates total number of items delivered
  int index = m_item.size() - totalDelivered; //amount of items leftover
  if (totalDelivered != m_item.size()) {
    for (unsigned int p = index; p > 0; p--) {
      cout << "Item " << index - p + 1  << " - Name: " << m_item[m_item.size()-p].GetName() << " - Weight: " << m_item[m_item.size()-p].GetWeight() << endl;
    }
  }
  else {
    cout << "No remaining items" << endl;
  }
}
