#include "ull.h"

ULinkedList::ULinkedList() {
    top_ptr_ = NULL;
}

ULinkedList::~ULinkedList() {}

ull_node* ULinkedList::init_node() {
    ull_node* ret = new(ull_node);
    ret->next = NULL;
    return ret;
}

//append node to end of linked list
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

//Assume entered in sorted order by date and then sport.
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

//Can use assumption of sorted order to search node for item. Search by date/time first.
string ULinkedList::search_venues(string sport, int datetime) {
    

    return "venues";
}

ull_node* ULinkedList::get_top() { return top_ptr_;}

void ULinkedList::set_top(ull_node* top_ptr) {top_ptr_ = top_ptr;}
