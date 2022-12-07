#pragma once

#include <vector>

using namespace std;
class DisjointSets {
public:
    /**
    * Adds num elements of value -1 to the elements_ vector
    * @param num
    */
    void addelements(int num);

    /**
    * Returns the parent index of elem while compressing paths 
    * @param elem
    * @return index of the parent of the disjoint set
    */
    int find(int elem);

    /**
    * Unions two elements within the elements_ vector
    * @param a
    * @param b
    */
    void setunion(int a, int b);

    /**
    * Unions two elements within the elements_ vector
    * @param elem
    * @return size of the disjoint set
    */
    int size(int elem); 

private:
    // vector of elements storing the DisjointSets
    vector<int> elements_;
};