## Leading Question

We are trying to understand the underlying structure of the city of Oldenburg. So we will implement algorithms that give us information such as the fastest road pathway between two intersections (defined as the shortest distance). We also will try to come up with connected components so that we can see if there is a route between those components. We can also use minimum spanning trees to analyze the density of such components(e.g. The sum of the distances along the minimum spanning tree divided by the total number of nodes)  

## Dataset Acquisition

We will use the City of Oldenburg Road Network Dataset provided at https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm. 

## Data Format

The source of our dataset is https://www.cs.utah.edu/~lifeifei/research/tpq/OL.cedge. The format of the dataset is a file containing four space-separated values which represents the edge ID, start node ID, end node ID, and L2 distance, respectively. The dataset contains 6104 nodes and 7034 edges. Since the dataset is quite small, we plan to use the entire dataset.

## Data Correction

To parse the input data we will create a file reader. To confirm that the data is correct we will define an expected number of entries per line, and an expected type for each entry. If this does not match then we will drop the entry. We will also sort the input data based on the second entry (which represents the first node along the edge) this way we can efficiently construct our adjacency matrix. 

## Data Storage

We will use a graph to store the data. We will build an adjacency matrix of all the nodes / road intersections, stored as a 2d vector, where we are storing the weight of each edge as the distance between each intersection. The storage will take up O(n2) space, but this is acceptable due to the relatively small size of our dataset. When we look up whether two nodes are adjacent, we can achieve O(1) linear time. 

## Algorithm 

### Kruskal’s Algorithm:
- Usage:  We can get a set of paths between all road intersections with the least overall distance traveled, or the minimum spanning tree. We can use this to do our density calculations, which will help us determine how cluttered or spread out the road network is. To do the density calculation we will just sum up the weights along all of the edges and then divide by the total number of nodes. 
- Data Structures:
    - Disjoint set
    - Priority Queue (array implementation) 
- Function inputs: the graph
- Function outputs: The minimum spanning tree for the computed connected component.  
- Estimated/Target Big O:
    - Time complexity: O(Elog(E)) Our Kruskal’s Algorithm will utilize a priority queue and a disjoint set. Building the priority queue will be O(E) and removing the minimum from the priority queue will be O(logE). The dominant term will come from looping through the edges and remove the minimum from the priority queue, which will be O(Elog(E)).
    - Space complexity O(E + V) We will need storage for our group of disjoint sets, to keep track of all our vertices, as well as all the edges in our priority queue, which becomes E + V.
### Breadth First Search:
- Usage: We will use Breadth First Search to find the number of connected components 
- Heuristics: none
- Function inputs: The graph
- Function outputs: Number of connected components, a vector of nodes representing the connected components (this way we can make sure that we are running A* on nodes that can be reached). We will print out the outputs and test on smaller data sets to make sure that we are doing this correctly. 
- Function data structures: 
    - Queue
- Estimated/Target Big O:
    - Time complexity: O(V + E) 
    - Space complexity: O(V)
### A* Algorithm: 
- Usage: We will use A* algorithm to determine the minimum distance between two nodes (first we will check if they are in the same connected component and then we will run A*). 
- Heuristics: For A* we will use the minimum distance between the point and the goal. This is doable because we are given the normalized x and y coordinates for each point so we can just store this as part of our data structure. 
- Function inputs: start, goal, evaluation heuristic
- Function outputs: The minimum path from the start node to the goal node, we will print out the output to confirm that we are doing this correctly and we will also test on smaller data sets. 
- Function data structures: 
    - PriorityQueue (implemented as an array) 
    - Map
- Big O:
    - Time complexity: O(b^d)
    - Space complexity: O(b^d)


## Timeline

Week 1:
- Project proposal
Make Github
Week 2: 
- Setup Github
- Setup cmake and repository(we will be running the project in the cs225 container) along with catch2
- Figure out how to load the graph into the adjacency list
- Write test cases for all of the algorithms 
Week 3: 
 - Implement Kruskals 
Week 4: 
- Implement A*
- Implement Breadth First Search 
Week 5: 
- Finalize algorithms / debug
- Create readme and presentation 
