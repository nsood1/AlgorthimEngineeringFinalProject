//
// Created by Nicole Sood on 06/11/2022.
//

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <random>
#include <queue>
#include <algorithm>
using namespace std::chrono;

using namespace std;

void Graph:: setGraph(int V) {
    size = V;
    edges = new Edge *[V];

    for(int i = 0; i < V; i ++){
        edges[i] = nullptr;
        vertices.emplace_back();
        vertices[i].id = i;
    }
}

void Graph::addEdge(const int vert1, const int vert2)
{
    Edge* e = new Edge(vert2, edges[vert1]);
    edges[vert1] = e;
    vertices[vert1].degree++;
}

void Graph::completeGraph() {
    for(int vert = 0; vert < size; vert++){
        for(int edge = 0; edge < size; edge++){
            if (vert == edge) continue;
            addEdge(vert, edge);
        }
    }
}

void Graph::cycleGraph() {
    for(int x = 0; x < size-1; x++) {
        const int temp = x;
        addEdge(temp, x + 1);
        addEdge(temp + 1, x);
    }
    addEdge(size - 1, 0);
    addEdge(0, size - 1);
}

void Graph::evenGraph(const int E) {

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, size-1);

    int maxEdges = (size * (size -1 )) /2;

    if (E > maxEdges){
        cout <<  "Too many edges";
        exit(0);
    }

    for(int i = 0; i < E; i++){
        int v1 = distr(gen);
        int v2 = distr(gen);

        if (v1 == v2 || v1, v2 == size){
            i--;
            continue;
        }

        addEdge(v1, v2);
        addEdge(v2, v1);
    }
}

void Graph::tieredGraph(const int E) {
    //https://stackoverflow.com/questions/7560114/random-number-c-in-some-range

    int maxEdges = (size * (size -1 )) /2;

    if (E > maxEdges){
        cout << "Too many edges";
        exit(0);
    }

    //Evenly distributed across the first 10% of vertices with 1/2 of the choices
    int tempSize = size / 10; //to get roughly 10% of the data

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, tempSize-1);

    for(int i = 0; i < E/2; i++){ //for the first 1/2
        int v1 = distr(gen);
        int v2 = distr(gen);

        if (v1 == v2){
            i--;
            continue;
        }
        addEdge(v1, v2);
        addEdge(v2, v1);
    }

    std::uniform_int_distribution<> distr2(tempSize, size-1);

    for(int j= 0; j < E/2; j++){ //for the 2nd 1/2

        const int vt1 = distr2(gen); // to get a range between the first 10% and last 100%
        const int vt2 = distr2(gen);


        if (vt1 == vt2){ // || vertices[vt1].edges[vt2]){
            j--;
            continue;
        }
        addEdge(vt1, vt2);
        addEdge(vt2, vt1);
    }

}

void Graph::myOwn(const int E) {

    //1/3 of edges to be in the first quarter of vertices
    //2/3 of edges to be in the three quarters of vertices
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, (size/4)-1);

    int maxEdges = (size * (size -1 )) /2;

    if (E > maxEdges){
        cout << "Too many edges";
        exit(0);
    }

    for(int i = 0; i < E/3; i++){
        int v1 = distr(gen);
        int v2 = distr(gen);

        if (v1 == v2){
            i--;
            continue;
        }
        addEdge(v1, v2);
        addEdge(v2, v1);
    }

    std::uniform_int_distribution<> distr2(size/4, size-1);
    for(int i = 0; i < (2*E/3); i++){
        int v1 = distr2(gen);
        int v2 = distr2(gen);

        if (v1 == v2){
            i--;
            continue;
        }
        addEdge(v1, v2);
        addEdge(v2, v1);
    }
}

void Graph::randomOrdering() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, size);

    for (vertex& v : vertices){
        ordering.emplace_back(&v);
    }

    shuffle (ordering.begin(), ordering.end(), std::default_random_engine(distr(gen)));

}

void Graph::smallestLastVertix() {
//NOTE: SOURCE CODE HAS BEEN STRUCTURED AND ADAPTED FROM THE FOLLOWING GITHUB PROJECT(S) AND SOURCES:
//https://github.com/MarkBrub/CS5350-Graph_Coloring/blob/master/Coloring/Graph.cpp
//https://github.com/dhanwin247/Parallel-graph-coloring
//CHANGES HAVE BEEN MADE TO FIT MY UNDERSTANDING OF THE SMALLEST LAST VERTEX ORDERING

    vector<vertex*> degrees(size);
    vector<int> newDegreeSize(size);
    vector<int> deleted(size);

//    cout << "Original ordering: " << endl;
//    for(int i = 0; i < vertices.size(); i++){
//        cout << vertices[i].id << " " << vertices[i].degree << " " << vertices[i].colour << endl;
//    }

    for (int i = 0; i < vertices.size(); i++){
        if(degrees[vertices[i].degree] != nullptr){
            degrees[vertices[i].degree]-> previous = &vertices[i];
            vertices[i].next = degrees[vertices[i].degree];
        }

        degrees[vertices[i].degree] = &vertices[i];
        newDegreeSize[i] = vertices[i].degree;
    }



    for(int i = 0; i < degrees.size(); i++){
        if(!degrees[i]){
            continue;
        }

        vertex* tempHolder = degrees[i];
        ordering.push_back(tempHolder);
        degrees[i] = tempHolder -> next;

        if(tempHolder-> next != nullptr){
            tempHolder->next->previous = nullptr;
        }

        tempHolder-> next = nullptr;
        deleted[tempHolder->id] = -1;

        Edge* currentEdge = edges[tempHolder->id];

        while (currentEdge != nullptr){
            int vert = currentEdge->dest;

            if(deleted[vert] == -1){
                currentEdge = currentEdge -> next;
                continue;
            }

            if (vertices[vert].next != nullptr){
                vertices[vert].next-> previous = vertices[vert].previous;
            }

            if(vertices[vert].previous != nullptr){
                vertices[vert].previous-> next = vertices[vert].next;
            }

            else {
                degrees[newDegreeSize[vert]] = vertices[vert].next;
            }

            int updateDegree = newDegreeSize[vert];
            newDegreeSize[vert] = updateDegree - 1;

            vertices[vert].previous = nullptr;
            vertices[vert].next = degrees[newDegreeSize[vert]];

            if(degrees[newDegreeSize[vert]] != nullptr){
                degrees[newDegreeSize[vert]] = &vertices[vert];
             }

            currentEdge = currentEdge->next;
        }

        if(i == 0) {
            i--;
            continue;
        }

        i -= 2;
    }

    std::reverse(ordering.begin(), ordering.end());

//    cout << endl << "Smallest Last Vertex Ordering: " << endl;
//    for (int i = 0; i < ordering.size(); i++){
//        cout <<  ordering[i] ->id << " " << ordering[i]->degree << " " << ordering[i] ->colour << endl;
//    }
}

void Graph::smallestDegreeFirst() {
    vector<vertex*> degrees(size);

    for (int i = 0; i < vertices.size(); i++){
        if(degrees[vertices[i].degree] != nullptr){
            degrees[vertices[i].degree]-> previous = &vertices[i];
            vertices[i].next = degrees[vertices[i].degree];
        }
        degrees[vertices[i].degree] = &vertices[i];
    }

    for (int i = 0; i < degrees.size(); i++) {
        vertex *current = degrees[i];
        while (current != nullptr) {
            ordering.push_back(current);
            current = current->next;
        }
    }

}

void Graph::largestDegreeFirst() {
    smallestDegreeFirst();
    std::reverse(ordering.begin(), ordering.end());
}

void Graph::largestVertexLast()  {
    smallestLastVertix();
    std::reverse(ordering.begin(), ordering.end());
}

void Graph::myOwnOrderingHelper(vertex *v, vector<bool> found) {
    //THIS CODE IS MADE UP OF THE FOLLOWING SOURCES:
    // https://cppsecrets.com/users/453010411410511610410510710997108105107565464103109971051084699111109/C00-Program-implementing-Topological-Sort.php
    //https://www.geeksforgeeks.org/cpp-program-for-topological-sorting/
    if(found[v->id]){
        return;
    }

    found[v->id] = true;

    ordering.push_back(v);

    while(v-> next != nullptr){
        myOwnOrderingHelper(v->next, found);
    }
}

void Graph::myOwnOrdering() {
    //THIS CODE IS MADE UP OF THE FOLLOWING SOURCES:
    // https://cppsecrets.com/users/453010411410511610410510710997108105107565464103109971051084699111109/C00-Program-implementing-Topological-Sort.php
    //https://www.geeksforgeeks.org/cpp-program-for-topological-sorting/

    std::vector<vertex*> toBeAdded;
    std::vector<bool> found(size,false);

    for(int i = 0; i < vertices.size(); i++){
        toBeAdded.push_back(&vertices[i]);
    }

    for(int i = 0; i < size; i++){
        myOwnOrderingHelper(toBeAdded[i], found);
    }

}

void Graph:: colourGraph(){
    int i = 0;
    for (vertex* v : ordering){
        v-> colour = colour(v);
       //cout << ordering[i]->id << " " << ordering[i]->degree << " " << ordering[i]->colour << endl;
        if (v -> colour > maxColour){
            maxColour = v->colour;
        }
        i++;
    }
}

int Graph::colour(vertex *v) {
    std:: vector<int> colours;
    Edge* current = edges[v->id];

    while (current != nullptr){
        colours.push_back(vertices[current -> dest].colour);
        current = current -> next;
    }

    int num;
    for (int i = 0; i < colours.size(); i++){
        num = colours[i];
        if (0 < num && num <= colours.size() && colours[num - 1] != num){
            std:: swap(colours[i], colours[num -1]);
        }
    }
    return colours.size() + 1;
}


void Graph::print(string filename) {
    ofstream myfile;
    myfile.open(filename + ".txt");
    myfile << size << endl;
    int temp = size + 1;
    for (int v = 0; v < size; v++) {
        myfile << temp << endl;
        temp += vertices[v].degree++;
    }
    for(int i = 0; i < size; i++){
         Edge* current = edges[i];
         while(current != nullptr){
             myfile << current -> dest << std:: endl;
             current = current -> next;
         }
    }
    myfile.close();
}

void Graph::printDist(std::string filename) {
    ofstream file;
    file.open(filename + ".txt");
    for(unsigned int x = 0; x < vertices.size(); x++) {
        file << x << " " << vertices[x].degree << std::endl;
    }
    file.close();
}

