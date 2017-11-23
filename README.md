# The-Grocer
Truck Delivery Grocery Simulation 

May 2017

Grade: A+ 100% (80/80)

First run "make" in command line to compile.

Inorder to run each project use command line input: "make run1", "make run2", "make run3"

Rules:

•	Each project run requires three files. The first file represents each truck.  The second file represents each of the deliveries. The third file represents each item in the deliveries.

•	There are no menus – the entire run of the program will be based on the three files loaded as command line arguments.

•	The three input files must use command line arguments to import them.

Deliveries Input Files:

•	The proj5_delivery files can contain any number of deliveries. T1 has 2 deliveries with a total of 8 items (7 left over). T2 has 4 deliveries with a total of 100 items. T3 has 100 deliveries with a total of 3000 items.

•	The trucks listed in the proj5_truck file is represented by the truck name, (usually truck1, truck2 etc) and its capacity.

•	The deliveries listed in the proj5_delivery file is represented by Name, number of items, and roundtrip time for each delivery (roundtrip from store to customer). 

•	The items listed in the proj5_item file is represented by name (the names are not unique) and their weight (in tenths of pounds)

•	Below is a diagram showing the relationship between the deliveries and the item list. Each delivery is for a specific number of items. As in the first delivery for the Smith family, there are 3 items in the delivery. The second delivery, to the Jones family has 5 items in it. These would represent the first 8 items in the items list of 15. There will be 7 items remaining on the truck after the deliveries.

Delivery Rules:

•	Loading a truck (regardless of the number of deliveries or number of items) takes 10 minutes. Therefore, every time a truck returns to the store, it takes 10 minutes to load.

•	Deliveries are loaded from the ManageDelivery class into a specific truck. The truck completes those deliveries and returns to the store for additional deliveries.

•	If there are 2 or more trucks, you do not need to take into considerations which one returns to the store first. You can assume that they aren’t necessarily at the same time but rather deliveries across an entire day. The time is tracking the number of minutes on the actual road and to load them.

•	Trucks will take turns until all of the deliveries are complete.

•	There will always be enough items to fill a delivery but there may be too many items in the truck (leftover items).

•	Trucks will use the Tqueue data structure to hold the items. Everything else uses a vector.
