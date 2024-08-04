#include <iostream>
#include "../code/ull.h"
#include "../code/ull.cpp"

using namespace std;

ull_node* build_helper_node() {
    ull_node* top = new(ull_node);
    top->next = NULL;
    event* event1 = new(event);
    top->events[0] = event1;
    event1->sport = "men's basketball";
    event1->datetime = 202408051530;
    event1->venues = "Racha Thai, Ivar's, Sam's Tavern";
    top->num_events++;
    event* event2 = new(event);
    top->events[1] = event2;
    event1->sport = "women's gymnastics";
    event1->datetime = 202408021200;
    event1->venues = "Central Tavern, Celtics, Hole in One";
    top->num_events++;
    event* event3 = new(event);
    top->events[2] = event3;
    event1->sport = "equestrian";
    event1->datetime = 202408011400;
    event1->venues = "Pho Palace, Celtics";
    top->num_events++;
}


int main() {
    ULinkedList my_list;
    ull_node* list_top = build_helper_node();
    my_list.set_top(list_top);
    my_list.insert_data(list_top, "volleyball", 202408050530, "Taylor's, Oyster Bar, Beach House");

    ull_node* cursor = list_top;
    while (cursor != NULL) {
        for (int i = 0; i < cursor->num_events; i++) {
        cout << "sport: " << cursor->events[i]->sport << ", date/time: " << cursor->events[i]->datetime << ", venue: " 
        << cursor->events[i]->venues;
        }
        cursor = cursor->next;
    } 

    return 0;
}