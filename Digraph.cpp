// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include "Digraph.hpp"
#include <climits>
#include <vector>


unsigned int Digraph::noVertices()
{
    return 0;
}

unsigned int Digraph::noEdges()
{
    return 0;
}

void Digraph::resetEdges()
{
    for(int i = 0; i<distMatrix.size(); i++) {
        for(int j = 0; j<distMatrix.size(); j++) {
            distMatrix[i][j] = INT_MAX;
        }
    }
    
    for(int i = 0; i<distMatrix.size(); i++) {
        distMatrix[i][i] = 0;
    }
}

void Digraph::addEdge(int source, int dest, int wt)
{
    distMatrix[source][dest] = wt;
    distMatrix[source][dest] = wt;
    
    numberOfEdges++;
}

void Digraph::delEdge(int source, int dest)
{
    distMatrix[source][dest] = INT_MAX;
    distMatrix[dest][source] = INT_MAX;
    
    --numberOfEdges;
}

int Digraph::isEdge(int source, int dest)
{
    int edge = distMatrix[source][dest];
    if(edge != INT_MAX) {
        return edge;
    }
    
    else
        return INT_MAX;
}

int Digraph::dijkstra(int source, int dest)
{
    int num = vertex.size();
    int D[num];
    
    for(int i=0; i<vertex.size(); i++) {
        D[i] = INT_MAX;
    }
    
    D[source] = 0;

    for (int i = 0; i < vertex.size(); i++) {
    
        int v = minVertex(D);
    
        vertex[v]->setStatus(VISITED);
    
            for (int j = 0; j < vertex.size(); j++) {
                if(D[j] > D[v] + distMatrix[v][j] && D[v] != INT_MAX && distMatrix[v][j] != INT_MAX)
                    D[j] = D[v] + distMatrix[v][j];
            }
        }
    
    for(int i; i<vertex.size(); i++) {
        vertex[i]->setStatus(NOT_VISITED);
    }
    return D[dest];
}

int Digraph::minVertex(int D[]) {
    
    int v = 0; // Initialize to unvisited vertex
    
    
    for (int i=0; i<vertex.size(); i++)
        if (vertex[i]->getStatus() == NOT_VISITED) { v = i; break; }
    for (int i=0; i<vertex.size(); i++)
        // Now find smallest value
        if ((vertex[i]->getStatus() == NOT_VISITED) && (D[i] < D[v]))
            v = i;
    return v;
}
