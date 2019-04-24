#include "pch.h"
#include "DFSgph.h"


DFSgph::DFSgph()
{
}

void DFSgph::addEdge(int src, int dest)
{
	adjLists[src].push_front(dest);
}

void DFSgph::DFS(int vertex)
{
	visited[vertex] = true;
    list<int> adjList = adjLists[vertex];
    
    cout << vertex << " ";
 
    list::iterator i;
    for(i = adjList.begin(); i != adjList.end(); ++i)
        {//push *i
        if(!visited[*i])
            //*i==dest;
            //ret=1
            DFS(*i);//flag=DFS(*i);
            /*if (flag==1){
                return;
            }
            else{
                pop stack;
            }*/
}

DFSgph::~DFSgph()
{
}
