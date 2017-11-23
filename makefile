CXX = g++
CXXFLAGS = -Wall -g

grocer: driver.cpp Tqueue.h Item.o Truck.h ReadyDelivery.o Delivery.o ManageDelivery.o
	$(CXX) $(CXXFLAGS) Tqueue.h driver.cpp Item.o Truck.h ReadyDelivery.o ManageDelivery.o Delivery.o -o grocer

ManageDelivery.o: ManageDelivery.h ManageDelivery.cpp Item.o Delivery.o Tqueue.h Truck.h ReadyDelivery.o
	$(CXX) $(CXXFLAGS) -c ManageDelivery.cpp

ReadyDelivery.o: ReadyDelivery.h ReadyDelivery.cpp Item.o Delivery.o Tqueue.h Truck.h
	$(CXX) $(CXXFLAGS) -c ReadyDelivery.cpp

Item.o: Item.cpp Item.h
	$(CXX) $(CXXFLAGS) -c Item.cpp

Delivery.o: Delivery.cpp Delivery.h
	$(CXX) $(CXXFLAGS) -c Delivery.cpp


clean:
	rm *.o*
	rm *~ 

#Rules to test each situation
run:
	./grocer

run1:
	./grocer grocer_truck_t1.txt grocer_delivery_t1.txt grocer_item_t1.txt

run2:
	./grocer grocer_truck_t2.txt grocer_delivery_t2.txt grocer_item_t2.txt

run3:
	./grocer grocer_truck_t3.txt grocer_delivery_t3.txt grocer_item_t3.txt

#rules to test using valgrind to check for memory leaks
valgrind1:
	valgrind ./grocer grocer_truck_t1.txt grocer_delivery_t1.txt grocer_item_t1.txt

valgrind2:
	valgrind ./grocer grocer_truck_t2.txt grocer_delivery_t2.txt grocer_item_t2.txt 

valgrind3:
	valgrind ./grocer grocer_truck_t3.txt grocer_delivery_t3.txt grocer_item_t3.txt