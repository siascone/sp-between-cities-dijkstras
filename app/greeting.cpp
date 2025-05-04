#include <iostream>

using namespace std;

void greeting() {
    cout << endl << "Welcome to the Boulder Aare SP Finder - Your Fast Route Planner for Boulder, CO!" << endl << endl;
    cout << "Discover the most efficient baths between Boulder and its 11 neighboring cities" << endl;
    cout << "using this interactive map-based tool!" << endl << endl;
    
    cout << "Each city is a node on a bidrectional, weighted graph with 56 connecting roads" << endl;
    cout << "mapped as edges with distances as weights." << endl << endl;
    
    cout << "Powered by Dijkstra's Algorithm and a custom built Priority Queue, the Boulder" << endl;
    cout << "Area SP Finder quickly calculates the shortest path based on relative travel" << endl;
    cout << "distances - all designed to help you find the best route with certainty." << endl << endl;
    
    cout << "Ready to explore? Select your starting city and destination to get started!" << endl<< endl;
}