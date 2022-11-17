#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include "Graph.hpp"

//loads a filename into a graph
Graph loadGraph(std::string vertices_file, std::string edges_file);

void printEdgesToFile(std::string filename, const Graph& g);
void printVerticesToFile(std::string filename,const Graph& g);
void printEdgesToConsole(std::string filename, const Graph& g);
void printVerticesToConsole(std::string filename, const Graph& g);