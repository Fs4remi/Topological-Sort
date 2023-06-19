## An implementation of topological sort 
Taking advantage of being a current student and having a list of classes with a complicated relationship to make use of Topological Sort.
Every upper-division Computer Science course has a list of prerequisites so I've created a graph out of all CS classes and performed a topological sort to find the an order to taking courses.

I've written an article to share the results 🚀 https://www.linkedin.com/pulse/experimenting-topological-sort-fatemeh-saremi/?trackingId=YhZBJ9axTQ6Al5D8Rpnf9g%3D%3D

### steps
- construct the graph by organizing the courses and the prerequisites 
- create the matrix representing the graph
- perform dfs recursively
- keep track of the order of pop from stack memory
