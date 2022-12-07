#pragma once
#include <vector>
#include <string>
#include "Edge.h"
class Graph{
    public:

        /**
        * Default constructor
        */
        Graph();

        /**
        * @param vertice_input 2d vector of strings containing vertice data stored in following format: index, x-loc, y-loc
        * @param edge_input 2d vector of strings containing edge data stored in the following format: first, second, weight
        * Constructs a graph with vertices at the given x and y locations and edges with the given weights and vertices
        */
        Graph(std::vector<std::vector<std::string>> vertice_input, std::vector<std::vector<std::string>> edge_input);

        /**
        * @param vertice_input vector of vertice ids
        * @param x_locs vector of corresponding x locations
        * @param y_locs vector of corresponding y locations
        * @param edge_input vector of corresponding edges
        * Constructs a graph with vertices at the given x and y locations and edges with the given weights and vertices
        */
        Graph(std::vector<int> vertice_input, std::vector<double> x_locs, std::vector<double> y_locs , std::vector<Edge> edge_input);
       
        /**
        * @param rhs the graph to copy
        * Copy constructor: takes in the rhs graph and constructs a deep copy of it
        */
        Graph(const Graph& rhs);

        /**
        * Destructor, deletes dynamically allocated arrays / frees dynamic memory
        */
        ~Graph();    

        /**
        * @param rhs the graph to copy
        * Copy assignment operator, constructs a deep copy
        */
        Graph& operator=(const Graph& rhs);

        //getters and setters 
        int getNumEdges() const;
        int getNumVertices() const;
        bool areAdjacent(int vertex1, int vertex2) const;
        double edgeValue(int idx) const;
        int indexOfAdjacentEdge(int vertex1, int vertex2) const;
        double getX(int vertex) const;
        double getY(int vertex) const;

        /**
        * @param vertex the vertex to get the adjacent edges of 
        * Returns the adjacent edges of a given vertex, this is similar to an adjacency list, especially because we are using CSR format
        * For very sparse graphs, like ours, the run time is virtually constant 
        */
        std::vector<int> adjacent(int vertex) const; 

        // more getters and setters(returns values of local variables)
        int* getAdjColsArray() const;
        double* getAdjDataArray() const;
        int* getAdjRowPtrArray() const;
        int* getVertices() const;

        /**
        * @param first the first vertex for Euclidean distance calculation
        * @param second the second vertex for Euclidean distance calculation
        * Returns the Euclidean distance between the first and second vertex using the X and Y coordinates provided and the Euclidean distance formula sqrt((x1 - x2)^2 + (y1 - y2)^2)
        */
        double getEuclideanDist(int first, int second) const;

    private:
        
        /**
        * @param rhs The graph to copy
        * Helper function to avoid redundancy in copying the graph for the copy constructor and the copy assignment operator. This         * performs a deep copy of the passed graph, with the assumption that all dynamically allocated arrays are empty or NULL.
        */
        void copyGraph(const Graph& rhs);

        /**
        * Helper function to avoid redundancy for the destructor and the copy assignment operator. This deallocates all dynamically        * allocated memory and sets all pointers to NULL
        */
        void deleteGraph();

        /**
        * @param vertex1 the first vertex to check are adjacent for
        * @param vertex2 the second vertex to check are adjacent for
        * This checks if there is an edge going from the first vertex to the second vertex. Since we are storing in CSR format we are actually storing the data as a directed graph with an edge going from vertex1 to vertex2 for vertex1's component of the CSR matrix and an edge going from vertex2 to vertex1 in vertex2's component of the CSR matrix. Thus when we check for are adjacent we need code to check in both parts of the adjacency matrix. 
        */
        bool areAdjacentHelper(int vertex1, int vertex2) const;
        int num_edges_; // this is the size of cols and data 
        int num_vertices_;
        int row_ptr_size_;
        int* vertice_array_;
        double* x_locs_;
        double* y_locs_;
        int* adjacency_matrix_cols_;
        double* adjacency_matrix_data_;
        int* adjacency_matrix_rowptr_;
        

};