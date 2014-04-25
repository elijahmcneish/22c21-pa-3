
#include "DAG.h"

DAG::DAG(unsigned int n)
{
    numVertices = n;

    //
    // The following code ensures that vAdjacencyList[0..n-1] are
    // initialized with an empty linked list
    //
    list<unsigned int> l;
    vAdjacencyList.assign(numVertices, l);
}

vector<unsigned int> DAG::getPredecessorCount()
{
    vector<unsigned int> vPredCount;
    // TODO
    return vPredCount;
}

bool DAG::addDirectedEdge(unsigned int i, unsigned int j)
{
    // TODO
    // Check if vertices are valid
	
    // Check if the same edge is already present in the list for vertex i
	
    // Since we ensured no such edge exists, we can now safely add the edge
    return true;
}

vector<unsigned int> DAG::getTopologicalSortedVertices()
{
    vector<unsigned int> vResult;
    // TODO
    return vResult;
}

void DAG::printDAG()
{
    cout << endl << "Adjacency List: " << endl;
    for (unsigned int i = 0; i < vAdjacencyList.size(); ++i)
    {
	cout << endl << "Vertex " << i << ": ";
	//Loop through linked list for each veretx
	for (list<unsigned int>::iterator it = vAdjacencyList[i].begin();
	     it != vAdjacencyList[i].end(); ++it)
	{
	    cout << *it << " ";
	}
    }
    cout << endl;
}
