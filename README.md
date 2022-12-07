# CS225 Fall 2022 Final Project | oldenburg-roads-network
# Group Info
- Group Name: 225finalProjGroup
- Members:
  - Vijay Shah (vijays2)
  - Ben Guan (bg16)
  - Edwin Ing (edwinji2)
  - Justin Leong (jyleong2)
  
# Overview

We are trying to understand the underlying structure of the city of Oldenburg. 

Our final project uses the City of Oldenburg Road Network Dataset from https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm. The format of the edges dataset for the Oldenburg Road Network is a file containing four space-separated values which represent the Edge ID, Start Node ID, End Node ID, L2 Distance, respectively. The format of the vertices dataset for the Oldenburg Road Network is a file containing three space-separate values which represent Node ID, Normalized X Coordinate, Normalized Y Coordinate, respectively.


# Github Organization

## Presentation Video
You can find our presentation video here: (todo)

## Code
Our code follows a very similar structure to the CS225 MPs.
### data folder
Inside the data folder, you can find the dataset we used for our project as well as the datasets we used to test our algorithms. Our custom datasets test specific edge cases in our algorithm implementations.

### entry folder
Here you can find the `main.cpp` file that used to create the main executable for our program. 

### includes folder
Here you can find the custom data structures we used in our algorithms. For example, it contains the disjoint sets and priority queue we use A* Search Algorithm and Kruskal's MST. This folder also contains our CSR format graph implementation and a data manager class that is used to load data from the input files into our graph implementation.

### lib folder
The `lib` folder holds our implementation for all three algorithms we chose for our project in the `team-proposal.md`. 

`BFS.hpp/BFS.cpp`: A BFS class that has a function to perform a BFS traversal (and returns a map of distances from the first node to all the other nodes) and a function that counts the number of components on an input graph using BFS. To use the functions, create a BFS object and call the functions with a graph object.

`AStar.hpp/AStar.cpp`: An AStar class that takes in a graph object in the constructor. Creating the AStar object will run A* on the graph passed in. The class has a function that retrieves the shortest path once the algorithm runs on the graph.

`Kruskals.hpp/Kruskals.cpp`: A Kruskals class that has a function to get the minimal spanning tree as well as getter functions for the weight and edges of the minimum spanning tree. To make the MST, create a Kruskals object and call the function with a graph object.

`Node.h`: Holds a Node struct that is used in A*

### tests folder
All the test files can be found under this folder. Each test file tests our algorithms against the original dataset (or a subset of it) and our own custom datasets that can also be found in the `data` folder. 

### Other Files
Our README.md, results.md, team-contract.md, and team-proposal.md can be found in the base directory of the repo. They contain our documentation and deliverables for our project. 

# Usage
The files in this repository can be ran in the CS225 Docker environment. 

1. To build and run the main executable, first clone the repository. 
    ```console
    $ git clone https://github.com/Vijay-2021/oldenburg-roads-network.git
    ```
2. Navigate into the `oldenburg-roads-network` folder that was created.
    ```console
    $ cd oldenburg-roads-network
    ```
3. Running commands to setup the build folder and CMake.
    ```console
    $ mkdir build
    $ cd build
    $ cmake ..
    ```
At this point, the build directory should be setup and you should be able to build our `main` executable and test suite. 

### Building Main Executable
In the build directory you created above run the following commands.
```console
$ make main
```
An executable called `main` should now be created. You run it as follows:
```console
$ main [path to vertices.txt] [path to edges.txt] [start vertex] [stop vertex]
```
You can also run it as:
```console
$ ./main
```
If you do not provide the two necessary files and a start and end vertex, the executable will default to the dataset we used for our project and not run A*.
Running the executable will run our three graph algorithms (BFS, Kruskals, and AStar) on a graph derived from the input files. It will then output
the number of components (using BFS), density (using Kruskal's MST), and number of roads on the shortest path between the two provided points (using A*).

### Building Tests
In the build directory you created above run the following commands.
```console
$ make tests
```
The tests executable should now be created and you can use the following command to run it:
```console
$ ./tests
```
You can also run test cases for specific algorithms. To do so, replace name with the name of the algorithm, such as BFS, Kruskals, or AStar.
```console
$ ./tests [name]
```
Our test cases for AStar consist of checking that A* works on our dataset and a smaller custom dataset we created. In addition, we check that the shortest path matches our calculated shortest path. The test cases for BFS consists of checking that BFS returns the correct number of components for our dataset and two smaller custom dataset. We also check that BFS is traversing correctly using a map of distances. The test cases for Kruskals ensure our disjoint sets and priority queue implementations work and that the algorithm returns the correct MST from three smaller custom datasets. Finally, the test cases for our graph implementation check that the files are loaded correctly and that the get adjacent vertices and get weight functions work.
