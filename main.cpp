#include "DAG.h"

void test0()
{
    //
    //Instantiate dag with 6 vertices
    //
    DAG dag(6);
    //
    //Add a directed edge (u,v): u->v
    //
    dag.addDirectedEdge(0,1);
    dag.addDirectedEdge(0,2);
    dag.addDirectedEdge(0,3);
    dag.addDirectedEdge(1,4);
    dag.addDirectedEdge(2,4);
    dag.addDirectedEdge(3,4);
    dag.addDirectedEdge(2,5);
    dag.addDirectedEdge(3,5);

    //Print each vertex and its adjacent verices
    dag.printDAG();

    try
    {
	vector<unsigned int> vSorted = dag.getTopologicalSortedVertices();
 	cout << endl << "Sorted vertices: ";
	for (unsigned int j = 0; j < vSorted.size(); j++)
	    cout << vSorted[j] << " ";
	cout << endl;
    }
    catch (const char* error_msg)
    { cout << error_msg << endl; }
    
}
int main()
{
    test0();
}
