#ifndef DAG_H_
#define DAG_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::queue;

class DAG
{
private:
    unsigned int numVertices;
    /* Stores the adjacency list of the graph.
     * The i-th entry i.e. vAdjacencyList[i] stores the list of
     * neighboring vertex indices.
     */
    vector<list<unsigned int> > vAdjacencyList;

    // Stores the indegrees of all vertices.
    vector<unsigned int> vIndegreeCount;
    
protected:
    // Returns the adjacent vertices of the ith vertex in the graph.
    vector<unsigned int> getAdjacentVertices(unsigned int i);
    
public:
    // Constructs an empty DAG of 'n' vertices, indexed from 0 to n - 1.
    DAG(unsigned int n);

    /* Adds a directed edge from vertex i to vertex j. Returns
     * true if such an edge was not previously present, and
     * both i and j are indices less than number of vertices of DAG
     */
    bool addDirectedEdge(unsigned int i, unsigned int j);

    // Prints the DAG's adjacency list.
    void printDAG();

    // Returns the vertices sorted topologically.
    vector<unsigned int> getTopologicalSortedVertices();
};

#endif /* DAG_H_ */
