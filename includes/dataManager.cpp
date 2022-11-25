#include "dataManager.hpp"

#include <iterator>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

using std::ifstream;
using std::istream;
using std::istream_iterator;
using std::stringstream;

Graph loadGraph(std::string vertices_file, std::string edges_file) {
    ifstream vertice_file(vertices_file);
    ifstream edge_file(edges_file);
    std::string vertice_line;
    std::string edge_line;
    std::vector<std::vector<std::string>> vertice_output; 
    std::vector<std::vector<std::string>> edge_output;
    if (vertice_file.is_open()) {
        while (getline(vertice_file, vertice_line)) {
            /* Used to break the line by whitespace. The CMU Dict does this for
             * separating words from their pronunciations. */
            stringstream line_ss(vertice_line);
            istream_iterator<std::string> line_begin(line_ss);
            istream_iterator<std::string> line_end;
            istream_iterator<std::string> temp_itr = line_begin;
            vertice_output.push_back(std::vector<std::string>(line_begin, line_end));
        }
    }
    if (edge_file.is_open()){
        while(getline(edge_file, edge_line)) {
            stringstream line_ss(edge_line);
            istream_iterator<std::string> line_begin(line_ss);
            istream_iterator<std::string> line_end;
            istream_iterator<std::string> temp_itr = line_begin;
            edge_output.push_back(std::vector<std::string>(line_begin, line_end));

            //Create an edge that in the reverse order since this is an undirected graph
            stringstream line_ss2(edge_line);
            istream_iterator<std::string> line_begin2(line_ss2);
            istream_iterator<std::string> line_end2;
            istream_iterator<std::string> temp_itr2 = line_begin;
            std::vector<std::string> reverse(line_begin2, line_end2);
            std::string temp = reverse.at(1);
            reverse.at(1) = reverse.at(2);
            reverse.at(2) = temp;
            edge_output.push_back(reverse);
        }
    }
    edge_file.close();
    vertice_file.close();
    return Graph(vertice_output, edge_output);
}

void printEdgesToFile(std::string filename, const Graph& g) {
    std::fstream out_file;
    out_file.open(filename, std::ios_base::out);
    int* cols = g.getAdjColsArray();
    double* distances = g.getAdjDataArray();
    int* rowptr = g.getAdjRowPtrArray();
    int row = 0;
    int counter = 0;
    for (int i = 0; i < g.getNumEdges(); i++) {
        out_file<<row<<","<<cols[i]<<","<<distances[i]<<std::endl;
        counter++;
        while (counter >= rowptr[row]) {
            row++;
        }
    }
    out_file.close();
}
void printVerticesToFile(std::string filename, const Graph& g) {
    std::fstream out_file;
    out_file.open(filename,std::ios_base::out);
    int* vertices = g.getVertices();
    for(int i=0;i<g.getNumVertices();i++)
    {
        out_file<<vertices[i]<<std::endl;
    }
    out_file.close();
}