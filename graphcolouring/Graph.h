//
// Created by Nicole Sood on 06/11/2022.
//

#ifndef GRAPHCOLOURING_GRAPH_H
#define GRAPHCOLOURING_GRAPH_H

#import <vector>

class Graph {
    struct Edge{
        int dest = -1;
        Edge* next = nullptr;
        Edge(int dest, Edge* next) : dest(dest), next(next){};
        ~Edge() {delete next;}
    };

    struct vertex{
        int id =0;
        int degree = 0;
        int colour = 0;

        vertex* next  = nullptr;
        vertex* previous = nullptr;

    };

    Edge** edges = nullptr;
    std:: vector<vertex> vertices;
    std:: vector<vertex*> ordering;

public:
    int size = 0;
    int maxColour = 0;

    Graph() = default;

    void setGraph(int V);
    void addEdge(int v, int w);
    void print(std::string filename);
    void printDist(std:: string filename);

    void completeGraph();
    void cycleGraph();
    void evenGraph(const int);
    void tieredGraph(const int);
    void myOwn(const int);

    void randomOrdering();
    void smallestLastVertix();
    void smallestDegreeFirst();
    void largestDegreeFirst();
    void largestVertexLast();

    void myOwnOrdering();
    void myOwnOrderingHelper(vertex* v, std::vector<bool> found);

    void colourGraph();
    int colour(vertex *v);


};


#endif //GRAPHCOLOURING_GRAPH_H
