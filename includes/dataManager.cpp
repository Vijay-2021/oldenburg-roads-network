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
        }
    }
    edge_file.close();
    vertice_file.close();
    return Graph(vertice_output, edge_output);
}