#include "ull.h"

ULinkedList::ULinkedList() {
    top_ptr_ = NULL;
}

ULinkedList::~ULinkedList() {}

// Init_node
ull_node* ULinkedList::init_node() {
    ull_node* ret = new(ull_node);
    ret->next = NULL;
    return ret;
}

// Append a new node
void ULinkedList::append(ull_node* new_node) {
    ull_node* cursor = top_ptr_;
    if (cursor == NULL) {
        top_ptr_ = new_node;
        return;
    }
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = new_node;
    
    return;
}

// Assume data is entered in sorted order (sorted by date/time and then by sport). Navigate to the 
// last node in the list. If the node's event array is full, create a new node and add it to the list. 
// Move all events after the threshold amount to the new node. Then add a new event to 
// the array with the event info given in the parameters.
void ULinkedList::insert_data(ull_node* top, string sport, int datetime, string venues) {
    ull_node* cursor = top;
    //navigate to last node
    if (cursor->next != NULL) {
        cursor = cursor->next;
    }
    //if node's array is full, add new node
    if (cursor->num_events = NODE_ORDER) {
        ull_node* new_node = init_node();
        append(new_node);
    }
    int ctr = 0;
    //move items over MIN_THRESHOLD in first node to new node and incr/decr num_events
    for (int i = MIN_THRESHOLD - 1; i < NODE_ORDER; i++) {
        cursor->next->events[ctr] = cursor->events[i];
        cursor->next->num_events++;
        cursor->events[i] = NULL;
        cursor->num_events--;
        ctr++;
    }
    //move cursor to new node
    cursor = cursor->next;

    //create and add new event to array and incr num_events
    event* new_event = new(event);
    new_event->sport = sport;
    new_event->datetime = datetime;
    new_event->venues = venues;
    cursor->events[cursor->num_events - 1] = new_event;
    cursor->num_events++;

    return;
}

// Assume that all events are sorted in ascending order by date/time, and then by sport.
// Find the last event in the first node. If the date/time being searched is greater than the 
// date/time of the last event, skip to the next node. Continue until you find the node that may contain
// the event. Then search that node's array for the event. If item isn't found, return "N/A". If it is,
// return the list of venues. 
string ULinkedList::search_venues(ull_node* top, string sport, int datetime) {
    ull_node* cursor = top;
    //if the top points to null, return N/A
    if (top == NULL) {
        return "N/A";
    }
    //if datetime is greater than the datetime at node's last event in array, go to next node (if not null)
    while (true) {
        if (datetime > cursor->events[cursor->num_events - 1]->datetime) {
            if (cursor->next == NULL) {return "N/A";}
            else {
                cursor = cursor->next;
            }
        }
        else {break;}
    }
    //if node's last event's datetime = the datetime searched for, and sport searched > sport 
    //at node's last event, go to the next node.
    while (true) {
        if (datetime == cursor->events[cursor->num_events - 1]->datetime 
        && sport > cursor->events[cursor->num_events - 1]->sport) {
            if (cursor->next == NULL) {return "N/A";}
            else {
                cursor = cursor->next;
            }
        }
        else {break;}
    }

    //search for element
    for (int i = 0; i < cursor->num_events; i++) {
        if ((datetime == cursor->events[i]->datetime) && sport == cursor->events[i]->sport) {
            return cursor->events[i]->venues;
        }
        else {return "N/A";}
    }
}

//Takes in a top pointer, and uses sport and datetime info to search for and remove event data. If the sport/datetime combination is not found, nothing is changed.
void ULinkedList::remove_data(ull_node* top, string sport, int datetime) {
    ull_node* cursor = top;
    //if the top points to null, return
    if (top == NULL) {
        return;
    }
    //if datetime is greater than the datetime at node's last event in array, go to next node (if not null)
    while (true) {
        if (datetime > cursor->events[cursor->num_events - 1]->datetime) {
            if (cursor->next == NULL) {return;}
            else {
                cursor = cursor->next;
            }
        }
        else {break;}
    }
    //if node's last event's datetime = the datetime searched for, and sport searched > sport 
    //at node's last event, go to the next node.
    while (true) {
        if (datetime == cursor->events[cursor->num_events - 1]->datetime 
        && sport > cursor->events[cursor->num_events - 1]->sport) {
            if (cursor->next == NULL) {return;}
            else {
                cursor = cursor->next;
            }
        }
        else {break;}
    }

    //search for element. If found, shift all array elements past it back one. Set 
    //final event/array value to null. Decrement num_events.
    for (int i = 0; i < cursor->num_events; i++) {
        if ((datetime == cursor->events[i]->datetime) && sport == cursor->events[i]->sport) {
            for (int j = i; j < (cursor->num_events - 1); j++) {
                cursor->events[j] = cursor->events[j + 1];
                cursor->events[cursor->num_events - 1] = NULL;
            }
            cursor->num_events--;
            return;
        }
        else {return;}
    }
}

ull_node* ULinkedList::get_top() { return top_ptr_;}

void ULinkedList::set_top(ull_node* top_ptr) {top_ptr_ = top_ptr;}
