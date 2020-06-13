#include "graphtype.h"
#include<iostream>
using namespace std;
const int NULL_EDGE = 0;

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
	numVertices = 0;
	maxVertices = maxV;

	vertices = new VertexType[maxV];
	edges = new int*[maxV];

	for(int i=0;i<maxV;i++)
		edges[i] = new int [maxV];
	marks = new bool[maxV];

	for(int x = 0; x < numVertices; x++){
		for(int y = 0; y < numVertices; y++){
			edges[x][y] = 0;
		}
	}
   color = new int[6];
}



template<class VertexType>
GraphType<VertexType>::~GraphType()
{
	delete [] vertices;
	delete [] marks;

	for(int i=0;i<maxVertices;i++)
		delete [] edges[i];
	delete [] edges;
}


template<class VertexType>
void GraphType<VertexType>::MakeEmpty()
{
	numVertices = 0;
}


template<class VertexType>
bool GraphType<VertexType>::IsEmpty()
{
	return (numVertices == 0);
}


template<class VertexType>
bool GraphType<VertexType>::IsFull()
{
	return (numVertices == maxVertices);
}


template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
{
	vertices[numVertices] = vertex;

	for (int index=0; index<numVertices; index++)
	{
		edges[numVertices][index] = NULL_EDGE;
		edges[index][numVertices] = NULL_EDGE;
	}

	numVertices++;
}



template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex)
{
	int index = 0;
	while (!(vertex == vertices[index]))
		index++;
	return index;
}

template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex)
{
	int index = IndexIs(vertices, vertex);
	marks[index] = true;
}


template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType
vertex)
{
	int index = IndexIs(vertices, vertex);
	return marks[index];
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
{
	int row = IndexIs(vertices, fromVertex);
	int col= IndexIs(vertices, toVertex);
	edges[row][col] = weight;
}

template <class VertexType>
bool GraphType<VertexType>::GraphColor(int m, int i)
{
    if(i==numVertices)
    {
        if(ColorNotMatched())
        {
            printColors();
            return true;
        }
        return false;
    }

    for(int j=1;j<=m;j++)
    {
        color[i]=j;
        if(GraphColor(m,i+1))
            return true;
        color[i]=0;
    }
    return false;
}

template<class VertexType>
bool GraphType<VertexType>::ColorNotMatched()
{
    for(int i=0;i<numVertices;i++)
    {
        for(int j=i+1;j<numVertices;j++)
        {
            if(edges[i][j]==1 && color[j]==color[i])
                return false;
        }
    }
    return true;
}

template<class VertexType>
void GraphType<VertexType>::printColors()
{
    int i=0;
    string clr;
    for(int i=0;i<numVertices;i++)
    {
        if(color[i]==1)
            clr="Red";
        else if(color[i]==2)
            clr="Green";
        else if(color[i]==3)
            clr="Blue";

        cout<<" Vertex "<<i+1<<"---> Color "<<color[i]<<" = "<<clr<<endl;
    }

}
