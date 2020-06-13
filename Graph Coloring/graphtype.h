#ifndef GRAPHTYPE H INCLUDED
#define GRAPHTYPE H INCLUDED
template<class VertexType>
class GraphType{
public:
    GraphType();
    GraphType(int maxV);
    ~GraphType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void AddVertex(VertexType);
    void AddEdge(VertexType, VertexType, int); int Weightis(VertexType, VertexType); void MarkVertex(VertexType);
    bool IsMarked(VertexType);
    bool GraphColor(int m, int i);
    bool ColorNotMatched();
    void printColors();

private:
    int numVertices;
    int maxVertices; VertexType* vertices; int **edges;
    bool* marks;
    int *color;
};
#endif // GRAPHTYPE #define GRAPHTYPE H INCLUDED

