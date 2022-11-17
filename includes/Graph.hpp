#pragma once
#include <vector>
#include <string>
#include "Edge.h"
class Graph{
    public:
        Graph();
        Graph(std::vector<std::vector<std::string>> vertice_input, std::vector<std::vector<std::string>> edge_input);
        Graph(std::vector<int> vertice_input, std::vector<Edge> edge_input);
        Graph(const Graph& rhs);
        ~Graph();    
        Graph& operator=(const Graph& rhs);

        //getters and setters 
        int getNumEdges() const;
        int getNumVertices() const;
        bool areAdjacent(int vertex1, int vertex2) const;
        double edgeValue(int idx) const;
        int indexOfAdjacentEdge(int vertex1, int vertex2) const;
        
        std::vector<int> adjacent(int vertex) const;
        int* getAdjColsArray() const;
        double* getAdjDataArray() const;
        int* getAdjRowPtrArray() const;
        int* getVertices() const;

    private:
        void copyGraph(const Graph& rhs);
        void deleteGraph();
        bool areAdjacentHelper(int vertex1, int vertex2) const;
        int num_edges_; // this is the size of cols and data 
        int num_vertices_;
        int row_ptr_size_;
        int* vertice_array_;
        int* adjacency_matrix_cols_;
        double* adjacency_matrix_data_;
        int* adjacency_matrix_rowptr_;
        

};