# Where to Watch the Olympics: Unrolled Linked List
## Project Background
My project's goal is to store information about which local venues will show each Olympic event. The user can search for an event's location by entering the sport they want to watch and the date/time of the event. For example, "women’s gymnastics" and "202408021200" (date/times are integers of the format YYYYMMDDHHMM, using a 24 hour clock). They will then get a string returned with the venues where the event is showing. There are 2,400 events that need to be stored, with associated date/time, sport category, and venues data.

## Why Unrolled Linked List

<img src="https://github.com/user-attachments/assets/625804d7-1793-47c6-96aa-66be5b174a25" alt="ull" width="650"/>

The events data is stored in an unrolled linked list. I chose this data structure because the 2,400 events that need to be stored and managed is a small data set, so a simple list data structure is sufficient to store and manage it. Additionally, since searching is the most important operation for users, the unrolled linked list has time and space complexity advantages over a standard linked list.

The unrolled linked list is similar to a linked list, except multiple data elements can be stored in each node, using an array. The advantage of this is that 

benefits - common for storing list of items. benefit over LL.

## Implementation
arrays in nodes are size 5. would do 10+ for real application
Threshold is size/2 + 1. Fill to capacity, then create new node and move over extra from first node and add new item


## Operations
### End User Functions
insert_data - assumes pre-sorted data. uses date/time to search if last item in node has time greater than item. if no, move to next item. saves searching ea elem

search_venues - assumes pre-sorted data. uses date/time to search if last item in node has time greater than item. if no, move to next item. saves searching ea elem

remove_data - similar to serach, but remove item and push later array items to left. update num_events


### Helper Functions
init_node
append

## ull_node struct

## event struct
(image)

## To Operate..

