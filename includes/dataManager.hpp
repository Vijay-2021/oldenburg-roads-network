#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include "Graph.hpp"

/**
* @param vertices_file
* @param edges_file
*/
Graph loadGraph(std::string vertices_file, std::string edges_file);

/**
 * Writes all the given edges into a file.
 * @param filename The CSR file to write edges into.
 * @param g The graph of which data is coming from.
 */
void printEdgesToFile(std::string filename, const Graph& g);

/**
 * Writes all the given vertices into a file.
 * @param filename The CSR file to write vertices into.
 * @param g The graph of which data is coming from.
 */
void printVerticesToFile(std::string filename,const Graph& g);
