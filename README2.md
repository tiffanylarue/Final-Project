# Where to Watch the Olympics: Unrolled Linked List
## Project Background
My project's goal is to store information about which local venues will show each Olympic event. The user can search for an event's location(s) by entering the sport they want to watch and the date/time of the event. For example, "gymnastics" and "202408021200" (date/times are integers of the format YYYYMMDDHHMM, using a 24 hour clock). They will then get a string returned with the venues where the event is showing. For 2024, there are 40 Olympic sport categories, and a total of 2,400 events that need to be stored, with associated date/time, sport category, and venues data. For the implementation, I used some dummy data about which events are showing at which venues in the Seattle Eastside.

## Why Unrolled Linked List
<img src="https://github.com/user-attachments/assets/625804d7-1793-47c6-96aa-66be5b174a25" alt="ull" width="650"/>

The diagram above shows the unrolled linked list data structure I chose to store the events data. I chose this data structure because the 2,400 events that need to be stored and managed is a small data set, so a simple list data structure is sufficient to store and manage it. Additionally, since searching is the most important operation for users, the unrolled linked list has time and space complexity advantages over a standard linked list.

# About the Unrolled Linked List and Invariants
The unrolled linked list is similar to a linked list, except multiple data elements can be stored in each node, using an array. In this way, the node is similar to a B-tree node as compared with a BST node. The array is only filled to a threshold of half to 3/4 full, so that new elements can be added without creating a whole new node. When the array in a node is full, adding a new element will create a new node, and elements from original node over the threshold are moved to the new node; then the new element is added. Removing elements is the opposite of adding - when all elements in a node are removed, the node will be removed, and nodes on either side will be joined. The number of nodes shoud should always be sqrt(total number of elements in the arrays).

## Advantages and Disadvantages
 The search time for a normal linked list is O(n), however an unrolled linked list achieves O(sqrt(n)). Cache behavior is another advantage of the unrolled linked list, because all elements in a node will get cached, rather than just a single element, improving linear search. Saving multiple items per node also requires less storage space for pointer/references compared to the standard linked list. Finally, operations like insertion, deletion, and traversal are more quick. The disadvantage of the unrolled linked list is that there is high overhead per node in that an array is required and unused memory is stored in each node.

## Implementation
For my implementation, I created two structs - one for the node, "ull_node", and one to hold event data "event". Instead of holding single data elements in the array, I needed to store multiple pieces of data for each event, so the array in ull_node holds pointers to event elements. There are 2,400 data elements, so there should be sqrt(2,400) = 49 nodes, and 49 elements in each array. However to make things simpler, I used an array of 5 slots, with a threshold of NODE_ORDER/2 + 1, or 5/2 + 1 = 3 elements. I created a class ULinkedList, similar to the one we used for LinkedList, and I borrowed some of the functions from the Linked List homework: init_node, append, get_top, and set_top. The functions I created are: insert_data, search_venues, and remove_data. For these to work, data being inserted must be pre-sorted by data/time and then alphabetically by sport.

## Operations
### End User Functions
void insert_data(ull_node* top, string sport, int datetime, string venues):  - assumes pre-sorted data. uses date/time to search if last item in node has time greater than item. if no, move to next item. saves searching ea elem

string search_venues(ull_node* top, string sport, int datetime): - assumes pre-sorted data. uses date/time to search if last item in node has time greater than item. if no, move to next item. saves searching ea elem

void remove_data(ull_node* top, string sport, int datetime): - similar to serach, but remove item and push later array items to left. update num_events


### Helper Functions
ull_node* init_node(): 
void append(ull_node* new_node): 
ull_node* get_top(): 
void set_top(ull_node* top_ptr):

## ull_node struct

## event struct
(image)

## To Operate..
