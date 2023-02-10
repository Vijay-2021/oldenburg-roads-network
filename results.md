An analysis of each algorithim: 

Each algorithim worked correctly. This is highlighted in our test files. For each algorithim, we made datasets to test the correct traversal method and end result. 

A*: In the case of AStar we checked two things in our test file. First we checked that the nodes in the shortest path were all ajacent. Then we checked that the start and end node were the desired start and end node. We also made a test file to check that AStar was truly choosing the shortest path and not just a path between the two nodes. We then wrote code in the main file to run AStar to get the path between two vertices that the user inputs. 

BFS: In the case of BFS we checked several things. We made test files to make sure that BFS was finding the correct number of connected components. We also wrote code to ensure that BFS was performing the traversal in the correct order. Finally we ran BFS on our own dataset, and found that there was only one connected component which means that each road can be reached from the other nodes. 

Kruskals: In the case of Kruskals we first checked that Kruskals was creating the correct sized minimum spanning trees by ensuring that the number of edges was equal to one minus the number of vertices. Next we checked the weight(the sum of all the edges) of the minimum spanning trees on sample graphs to ensure that Kruskals was truly finding the minimum spanning tree. Finally we ran Kruskals on our own dataset. We found that the minimum spanning tree contained all the nodes in our graph which confirmed the observation by BFS that our entire graph was connected. We also wrote the density calculation code. 


Overall, we calculated that the density of the Oldenburg road network was high. Additionally, we figured out that Oldenburg is all connected and dense. We answered our question by mainly utilizing the three algorithms of A*, BFS, and Kruskals. We discovered that Oldenburg is an interesting city based on it's road networks.
