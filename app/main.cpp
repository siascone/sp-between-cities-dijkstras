#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "../code/Graph.h"
#include "../code/Node.h"
#include "../code/Edge.h"
#include "../code/Pqueue.h"
#include "../code/Graph.cpp"
#include "../code/Node.cpp"
#include "../code/Edge.cpp"
#include "../code/Pqueue.cpp"
#include "../tests/graph_builders.cpp"
#include "greeting.cpp"
#include "city_selection_options.cpp"

using namespace std;

int main(){
    
    vector<string> cities = {
            "Boulder",
            "Gunbarrel",
            "Niwot",
            "Lyons",
            "Hygiene",
            "Longmont",
            "Erie",
            "Lafayette",
            "Louisville",
            "Superior",
            "Eldorado Springs",
            "Broomfield"
         };
        
    bool processing = true;
    string input_1;
    string input_2;
    int start_city;
    int dest_city;
    
    Graph* lgGraph = mkLargeLocalGraph();
    
    greeting();
    
    city_selection_options();
    
    while (processing) {
        // clear inputs for loops after first round
        cin.clear(); 
        input_1 = "";
        input_2 = "";
        start_city = -1;
        dest_city = -1;
        
        // Get start city from user
        cout << "Pease select a starting city by number (e.g. 3): ";
        cin >> input_1;
        
        try {
            start_city = stoi(input_1);
        } catch (...) { // catch attempts to convert letters to number
            cout << endl;
            cout << "\033[1mInvalid input. Input mist be an integer 0-12.\033[0m" << endl <<endl;
            continue;
        }
        
        // check start_city is within selection range 0 - 12
        if (start_city < 0 || start_city > 12) 
        {
            cout << endl;
            cout << "\033[1mInvalid input. Input must be an integer 0-12.\033[0m";
            cout << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } 
        
        if (start_city == 0) {
            processing = false;
            break;
        }
        
        // if (dest_city == 0) {
        //     processing = false;
        //     break;
        // }
        
        cout << "You selected " 
             << "\033[1m" << cities[start_city - 1] 
             << "\033[0m" << " as your starting city." 
             << endl;

        // Get destination city from user
        cin.clear();
        cout << endl << "Please select a destination city by number (e.g. 3): ";
        cin >> input_2;
        
        try {
            dest_city = stoi(input_2);
        } catch (...) { // catch attempts to convert letters to number
            cout << endl;
            cout << "\033[1mInvalid input. Input mist be an integer 0-12.\033[0m" << endl <<endl;
            continue;
        }
        
        // check dest_city is within selection range 0 - 12
        if (dest_city < 0 || dest_city > 12) 
        {
            cout << endl;
            cout << "\033[1mInvalid input. Input must be an integer 0-12.\033[0m";
            cout << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } 
        
        if (dest_city == 0) {
            processing = false;
            break;
        }
        
        cout << "You selected " 
             << "\033[1m" << cities[dest_city - 1] 
             << "\033[0m" << " as your destination city." 
             << endl;
        
        // delay for UI effect
        cout << endl << "Calculating best route. One moment please..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1500)); // 1.5 second delay
        
        // calculate sp
        Node* start = lgGraph->findNode(cities[start_city - 1]);
        Node* end = lgGraph->findNode(cities[dest_city - 1]);
        
        if (start == nullptr || end == nullptr) {
            cout << endl << "Something went wrong on our end. Please try again." << endl << endl;
            continue;
        }
        
        vector<Node*> sp = lgGraph->computeShortestPath(start, end);
        
        // output sp information
        double total_dist = sp[sp.size() - 1]->getDist();
        cout << endl;
        cout << "The shortest path from " 
             << cities[start_city - 1] 
             << " to " << cities[dest_city - 1] 
             << " follows: " << endl;
        
        for (int i = 0; i < static_cast<int>(sp.size()); i++) {
            cout << "  " << i+1 << ". " << sp[i]->getName() << "." << endl; 
        }
        
        cout << "for a total distance of " 
             << "\033[1m" << total_dist 
             << "\033[0m" << " miles." 
             << endl << endl;
        
        
        cout << "--------------------------------------------------------------------------------" << endl << endl; 
        
        cout << "If you would like to calculate a different route" << endl;
    }
    
    // add delay for UI effect upon exit. 
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << endl << "Thank you for using the Boulder Aare SP Finder. Safe travels!" << endl << endl;
    

    return 0;
}