# CS225 Fall 2022 Final Project | oldenburg-roads-network
# Group Info
- Group Name: 225finalProjGroup
- Members:
  - Vijay Shah (vijays2)
  - Ben Guan (bg16)
  - Edwin Ing (edwinji2)
  - Justin Leong (jyleong2)
  
# Overview

# Github Organization

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
3. Running commands to setup the build folder and cmake.
  ```console
  $ mkdir build
  $ cd build
  $ cmake ..
  ```
At this point the build directory should be setup and you should be able to build our `main` executable and test suite. 

### Building Main Executable
In the build directory you created above run the following commands.
```console
$ make main
```
An executable called `main` should now be created. You run it as follows:
```console
$ main [path to vertices.txt] [path to edges.txt]
```
If you do not provide the two necessary files, the executable will default to the dataset we used for our project.
Running the executable will run our three graph algorithms (BFS, Kruskals, and AStar) on a graph derived from the input files. It will then output
the number of components, minimal spanning tree, and .

### Building Tests
In the build directory you created above run the following commands.
```console
$ make tests
```
The tests executable should now be created and you can use the following command to run it:
```console
$ ./tests
```
