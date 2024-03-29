#include "Graph.hpp"
#include <algorithm>
#include <iostream> 
#include <cmath> 


Graph::Graph(): num_edges_(0), num_vertices_(0), row_ptr_size_(0), vertice_array_(nullptr), adjacency_matrix_cols_(nullptr), adjacency_matrix_data_(nullptr), adjacency_matrix_rowptr_(nullptr) {

}

Graph::Graph(std::vector<int> vertice_input, std::vector<double> x_locs, std::vector<double> y_locs , std::vector<Edge> edge_input) {
    // Allocate memory for arrays
    num_vertices_ = vertice_input.size();
    row_ptr_size_ = num_vertices_ + 1;
    vertice_array_ = new int[num_vertices_];
    x_locs_ = new double[num_vertices_];
    y_locs_ = new double[num_vertices_];

    // Assign into private variable arrays for A*
    for (unsigned i = 0; i < vertice_input.size(); i++) { 
        x_locs_[i] = x_locs[i];
        y_locs_[i] = y_locs[i];
        vertice_array_[i] = vertice_input[i]; // assume the 0th index contains the vertex value
    }
    num_edges_ = edge_input.size();
    std::sort(edge_input.begin(), edge_input.end(),
          [](const Edge& one, const Edge& two) {
            return one.v1 < two.v1;
    });

    // Allocate adjacency matrix arrays
    adjacency_matrix_cols_ = new int[num_edges_];
    adjacency_matrix_data_ = new double[num_edges_];
    adjacency_matrix_rowptr_ = new int[row_ptr_size_];
    int curr_vertex = 0; // we start "behind" in CSR
    int total = 0;

    // Populate indices in arrays with appropriate data values, column / rowptr number
    for (unsigned i = 0; i < edge_input.size(); i++ ) {
        int first_vertice = edge_input[i].v1;
        int second_vertice = edge_input[i].v2;
        double value = edge_input[i].distance;
        adjacency_matrix_cols_[i] = second_vertice;
        adjacency_matrix_data_[i] = value;
        if (first_vertice != curr_vertex) {
            while (curr_vertex < first_vertice) {
                 adjacency_matrix_rowptr_[curr_vertex] = total;
                 curr_vertex ++;
            }
        } 
        total++;
    }
    adjacency_matrix_rowptr_[curr_vertex + 1] = num_edges_;
}

Graph::Graph(std::vector<std::vector<std::string>> vertice_input, std::vector<std::vector<std::string>> edge_input) {
    // Allocate memory for arrays
    num_vertices_ = vertice_input.size();
    row_ptr_size_ = num_vertices_ + 1;
    vertice_array_ = new int[num_vertices_];
    x_locs_ = new double[num_vertices_];
    y_locs_ = new double[num_vertices_];

    // Assign vals to arrays for A*
    for (unsigned i = 0; i < vertice_input.size(); i++) {
        vertice_array_[i] = std::stoi(vertice_input[i][0]);
        if (vertice_input[i].size() < 3) {
            x_locs_[i] = 0;
            y_locs_[i] = 0;
        } else {
            x_locs_[i] = std::stod(vertice_input[i][1]);
            y_locs_[i] = std::stod(vertice_input[i][2]);
        }
    }
    num_edges_ = edge_input.size();
    std::sort(edge_input.begin(), edge_input.end(),
          [](const std::vector<std::string>& one, const std::vector<std::string>& two) {
            return std::stoi(one[1]) < std::stoi(two[1]);
    });

    // Allocate adjacency matrix arrays
    adjacency_matrix_cols_ = new int[num_edges_];
    adjacency_matrix_data_ = new double[num_edges_];
    adjacency_matrix_rowptr_ = new int[row_ptr_size_];
    int curr_vertex = 0;
    int total = 0;

    // Populate indices in arrays with appropriate data values, column / rowptr number
    for (unsigned i = 0; i < edge_input.size(); i++ ) {
        int first_vertice = std::stoi(edge_input[i][1]);
        int second_vertice = std::stoi(edge_input[i][2]);
        double value = std::stod(edge_input[i][3]);
        adjacency_matrix_cols_[i] = second_vertice;
        adjacency_matrix_data_[i] = value;
        if (first_vertice != curr_vertex) {
            while (curr_vertex < first_vertice) {
                adjacency_matrix_rowptr_[curr_vertex] = total;
                curr_vertex ++;
            }
        } 
        total++;
    }
    while (curr_vertex <= num_vertices_) {
        adjacency_matrix_rowptr_[curr_vertex] = num_edges_;
        curr_vertex++;
    }

}

// Rule of three functions: 

Graph::Graph(const Graph& rhs) {
    copyGraph(rhs);
}
Graph::~Graph() {
    deleteGraph();
}

Graph& Graph::operator=(const Graph& rhs) {
    if (&rhs == this) return *this;
    deleteGraph();
    copyGraph(rhs);
    return *this;
}

// Perform a deep copy of another graph
void Graph::copyGraph(const Graph& rhs) {
    num_edges_ = rhs.num_edges_;
    num_vertices_ = rhs.num_vertices_;
    row_ptr_size_ = rhs.row_ptr_size_;
    adjacency_matrix_cols_ = new int[num_edges_];
    adjacency_matrix_data_ = new double[num_edges_];
    adjacency_matrix_rowptr_ = new int[row_ptr_size_];
    vertice_array_ = new int[num_vertices_];
    x_locs_ = new double[num_vertices_];
    y_locs_ = new double[num_vertices_];

    for (int i = 0; i < num_vertices_; i++) {
        vertice_array_[i] = rhs.vertice_array_[i];
        x_locs_[i] = rhs.x_locs_[i];
        y_locs_[i] = rhs.y_locs_[i];
    }
    for (int i = 0; i < num_edges_; i++) {
        adjacency_matrix_cols_[i] = rhs.adjacency_matrix_cols_[i];
        adjacency_matrix_data_[i] = rhs.adjacency_matrix_data_[i];
    }
    for (int i = 0; i < row_ptr_size_; i++) {
        adjacency_matrix_rowptr_[i] = rhs.adjacency_matrix_rowptr_[i];
    }
}

void Graph::deleteGraph() {
    if (num_edges_ > 0) {
        delete[] adjacency_matrix_cols_;
        delete[] adjacency_matrix_data_;
    }
    if (num_vertices_ > 0) {
        delete[] adjacency_matrix_rowptr_;
        delete[] vertice_array_;
        delete[] x_locs_;
        delete[] y_locs_;
    }
    adjacency_matrix_rowptr_ = nullptr;
    adjacency_matrix_data_ = nullptr;
    adjacency_matrix_cols_ = nullptr;
    vertice_array_ = nullptr;
}

double Graph::getEuclideanDist(int first, int second) const {
    
    double x_dist = x_locs_[first] - x_locs_[second];
    double y_dist = y_locs_[first] - y_locs_[second];
    return std::sqrt(std::pow(x_dist, 2) + std::pow(y_dist, 2));
}

double Graph::getX(int vertex) const {
    return x_locs_[vertex];
}
double Graph::getY(int vertex) const {
    return y_locs_[vertex];
}

int Graph::getNumEdges() const {
    return num_edges_;
}
int Graph::getNumVertices() const {
    return num_vertices_;
}

int* Graph::getVertices() const { 
    return vertice_array_;
}
int* Graph::getAdjColsArray() const {
    return adjacency_matrix_cols_;
}
double* Graph::getAdjDataArray() const {
    return adjacency_matrix_data_;
}
int* Graph::getAdjRowPtrArray() const {
    return adjacency_matrix_rowptr_;
}
bool Graph::areAdjacent(int vertex1, int vertex2) const {
    return (areAdjacentHelper(vertex1, vertex2) || areAdjacentHelper(vertex2, vertex1));
}

bool Graph::areAdjacentHelper(int vertex1, int vertex2) const {
    int start_idx = 0;
    if (vertex1 > 0) {
        start_idx = adjacency_matrix_rowptr_[vertex1 - 1];
    }
    int end_idx = adjacency_matrix_rowptr_[vertex1];
    for (int i = start_idx; i < end_idx; i++) {
        if (adjacency_matrix_cols_[i] == vertex2) {
            return true;
        }
    }
    return false;
}

int Graph::indexOfAdjacentEdge(int vertex1, int vertex2) const{
    int start_idx = 0;
    if (vertex1 > 0) {
        start_idx = adjacency_matrix_rowptr_[vertex1 - 1];
    }
    int end_idx = adjacency_matrix_rowptr_[vertex1];
    for (int i = start_idx; i < end_idx; i++) {
        if (adjacency_matrix_cols_[i] == vertex2) {
            return i;
        }
    }
    return -1; // error case
}

double Graph::edgeValue(int idx) const {
    return adjacency_matrix_data_[idx];
}

std::vector<int> Graph::adjacent(int vertex) const {
    std::vector<int> adjacentVertices;
    int start_idx = 0;
    if (vertex > 0) {
        start_idx = adjacency_matrix_rowptr_[vertex - 1];
    }
    int end_idx = adjacency_matrix_rowptr_[vertex];

    for (int i = start_idx; i < end_idx; i++) {
        adjacentVertices.push_back(adjacency_matrix_cols_[i]);
    }
    return adjacentVertices;
}