#include <iostream>
#include "graphtype.cpp"
#include "graphtype.h"
using namespace std;

int main()
{

    GraphType<int> grph(6);
    grph.AddVertex(1);
    grph.AddVertex(2);
    grph.AddVertex(3);
    grph.AddVertex(4);
    grph.AddVertex(5);
    grph.AddVertex(6);


    grph.AddEdge(1,1,1);
    grph.AddEdge(1,2,1);
    grph.AddEdge(1,3,1);

    grph.AddEdge(2,2,1);
    grph.AddEdge(2,1,1);
    grph.AddEdge(2,4,1);

    grph.AddEdge(3,3,1);
    grph.AddEdge(3,1,1);
    grph.AddEdge(3,4,1);
    grph.AddEdge(3,5,1);

    grph.AddEdge(4,4,1);
    grph.AddEdge(4,2,1);
    grph.AddEdge(4,3,1);
    grph.AddEdge(4,5,1);
    grph.AddEdge(4,6,1);

    grph.AddEdge(5,5,1);
    grph.AddEdge(5,3,1);
    grph.AddEdge(5,4,1);

    grph.AddEdge(6,6,1);
    grph.AddEdge(6,4,1);

        int m=3; // number of colors

        if(!grph.GraphColor(m,0))
            cout<<"Solution doesn't exist";

        return 0;
    }

