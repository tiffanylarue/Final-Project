#ifndef ULL_H
#define ULL_H

#include <string>

using namespace std;

#define NODE_ORDER 5
#define MIN_THRESHOLD NODE_ORDER / 2 + 1

struct event {
    string sport;
    int datetime;
    string venues;
};

struct ull_node {
    int num_events;
    event* events[NODE_ORDER];
    ull_node* next;
};

class ULinkedList {
public:
    ULinkedList();

    ~ULinkedList();

    // Creates a new node structure from heap memory. It points to NULL and holds
    // the provided data. The function returns a pointer to that new node.
    ull_node* init_node(); 

    //Append new node to the unrolled linked list
    void append(ull_node* new_node);

    //Add new data to the unrolled linked list
    void insert_data(ull_node* top, string sport, int datetime, string venues);

    //Search sport and date/time to return venues
    string search_venues(ull_node* top, string sport, int datetime);

    //Search for sport/datetime combination and remove if found
    void remove_data(ull_node* top, string sport, int datetime);

    //get top pointer
    ull_node* get_top();

    //set top pointer
    void set_top(ull_node* top_ptr);

private:
    ull_node* top_ptr_;


};


#endif //ULL_H
