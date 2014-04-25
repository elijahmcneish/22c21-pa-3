#ifndef DAG_H_
#define DAG_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class DAG
{
private:
    unsigned int numVertices;
    //
    // Stores the adjacency list of the graph
    // The i-th entry i.e. vAdjacencyList[i] stores the list of
    // neighboring vertex indices.
    //
    vector<list<unsigned int> > vAdjacencyList;

protected:
    //
    // Returns the number of predecessors(indegree) of each vertex in the graph, in order of their
    // indices i.e. the i-th entry in the vector returned will have the number of predecessors
    // of vertex i
    //
    vector<unsigned int> getPredecessorCount();

public:
    //
    // Constructs an empty DAG of 'n' vertices, indexed from 0
    // to n - 1
    //
    DAG(unsigned int n);

    //
    // Adds a directed edge from vertex i to vertex j. Returns
    // true if such an edge was not previously present, and
    // both i and j are indices less than number of vertices of DAG
    //
    bool addDirectedEdge(unsigned int i, unsigned int j);

    // Prints the DAG's adjacency list
    void printDAG();

    // Returns the vertices sorted according topologically
    vector<unsigned int> getTopologicalSortedVertices();
};

#endif /* DAG_H_ */
