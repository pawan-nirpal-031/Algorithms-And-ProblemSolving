# Graph Thoery 

> Cycle detection : Cycle has important property of, it provides multiple paths between two nodes. A cycle exits in an undirected graph if it has a back-edge, A back-edge is an edge of some node v with it's non parent ancestor, so to check for cycle, we need to find out for any node v we need to check if any of it's non-parent ancestor's are visited or not, if yes return true. 

> InOut Times of a graph help us in Answring queries related to if a node v lies in the subtree of another node u in O(1) time per query, if a node v lies in a subtree of node u then, In-time of v will be higher than In-time of u and Out-time of v will be smaller than out-time of u, ie.( Node[v].in > Node[u].in and Node[v].out < Node[v].out ).