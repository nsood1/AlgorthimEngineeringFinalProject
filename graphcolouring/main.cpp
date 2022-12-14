#include <iostream>
#include "Graph.h"
using namespace std::chrono;

int main() {

    Graph temp;
    temp.setGraph(10000);

    auto start = high_resolution_clock::now();
    //temp.completeGraph();
    //temp.cycleGraph();
    //temp.evenGraph(64000);
    //temp.tieredGraph(64000);
    temp.myOwn(64000);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    //temp.print("SLVDemoGraph");

    auto start2 = high_resolution_clock::now();
    //temp.randomOrdering();
    //temp.smallestLastVertix();
    //temp.smallestDegreeFirst();
    //temp.largestDegreeFirst();
    //temp.largestVertexLast();
    temp.myOwnOrdering();


    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

   //std::cout << "Graph creation: " << duration.count() << " microseconds" << std::endl;
   std::cout << "Graph Ordering: " << duration2.count() << " microseconds" << std::endl;

    auto start3 = high_resolution_clock::now();
    temp.colourGraph();
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    std::cout << "Colouring: " << duration3.count() << " microseconds" << std::endl;

    std:: cout << "Colours: " << temp.maxColour << std::endl;
   // temp.printDist("MyDistribution2");


    return 0;
}
