// #define DEBUG 1
#include "DAG.h"

DAG::DAG(unsigned int n)
{
    numVertices = n;

    // Initialize vAdjacencyList[0...n-1] with an empty linked list.
    list<unsigned int> l;
    vAdjacencyList.assign(numVertices, l);

    // Initialize indegree counts.
    vIndegreeCount.assign(numVertices, 0);
    
}

vector<unsigned int> DAG::getPredecessorCount()
{
    vector<unsigned int> vPredCount;
    vPredCount.assign(vAdjacencyList.size(), 0);
    
    for (unsigned int i = 0; i < vAdjacencyList.size(); ++i)
    {
    	//Loop through linked list for each veretx
    	for (list<unsigned int>::iterator it = vAdjacencyList[i].begin();
    	     it != vAdjacencyList[i].end(); ++it)
    	{ ++vPredCount[*it]; }
    }
    
    return vPredCount;
}

bool DAG::addDirectedEdge(unsigned int i, unsigned int j)
{
    // TODO
    // Check if vertices are valid
    
    // Check if the same edge is already present in the list for vertex i
    for (list<unsigned int>::iterator it = vAdjacencyList[i].begin();
	 it != vAdjacencyList[i].end(); ++it)
    {
	if (*it == j)
	{ return false; }
    }
	
    // Since we ensured no such edge exists, we can now safely add the edge
    vAdjacencyList[i].push_back(j);

    // Update indegree count.
    vIndegreeCount[j]++;
        
    return true;
}

vector<unsigned int> DAG::getAdjacentVertices(unsigned int i)
{
    vector<unsigned int> vertices;
    for (list<unsigned int>::iterator it = vAdjacencyList[i].begin(); it != vAdjacencyList[i].end(); ++it)
    {
    	vertices.push_back(*it);
    }

    return vertices;
}

vector<unsigned int> DAG::getTopologicalSortedVertices()
{
    vector<unsigned int> vResult;

    // Make a copy of the graph's indegree counts so we don't modify the original.
    vector<unsigned int> indegrees = vIndegreeCount;
    
    // Initialize a queue of vertices with indegree 0.
    queue<unsigned int> indeg_zero;
    unsigned int i = 0;
    for (vector<unsigned int>::iterator it = indegrees.begin(); it != indegrees.end(); ++it)
    {
	if (*it == 0)
	{
	    indeg_zero.push(i);
	}
	++i;
    }

    // While there are vertices remaining...
    while (!indeg_zero.empty())
    {
	// Dequeue and output a vertex.
	unsigned int vertex = indeg_zero.front();
	vResult.push_back(vertex);
	indeg_zero.pop();

	
	// Decrement the indgree count for all vertices adjacent to the vertex we just popped.
	    for (list<unsigned int>::iterator it = vAdjacencyList[vertex].begin();
		 it != vAdjacencyList[vertex].end(); ++it)
	    {
		if (indegrees[*it] > 0)
		{
		    --indegrees[*it];
		    // Check if the indegree count for that vertex is now 0.
		    if (indegrees[*it] == 0)
		    { indeg_zero.push(*it); }
		}
	    }


#ifdef DEBUG
	    cout<< endl<<"new indgree count"<<endl;
	    for (vector<unsigned int>::iterator it = indegrees.begin(); it != indegrees.end(); ++it)
	    {
		cout << *it << " ";
	    }
	    cout << endl;
	    
	    queue<unsigned int> new_queue = indeg_zero;
	    cout << endl << "new queue: ";
	    while (!new_queue.empty())
	    {
		
		cout << new_queue.front() << " ";
		new_queue.pop();
		
	    }
#endif // DEBUG
    }

    if (vResult.size() != numVertices)
    { throw "ERROR: Cycle detected. No valid topological sort."; }
        
    return vResult;
}

void DAG::printDAG()
{
    cout << endl << "Adjacency List: " << endl;
    for (unsigned int i = 0; i < vAdjacencyList.size(); ++i)
    {
	cout << endl << "Vertex: " << i << " | Adjacent to: ";
	//Loop through linked list for each veretx
	for (list<unsigned int>::iterator it = vAdjacencyList[i].begin();
	     it != vAdjacencyList[i].end(); ++it)
	{
	    cout << *it << " ";
	}
	cout << "| # Indegrees: " << vIndegreeCount[i];
    }
    cout << endl;
}
