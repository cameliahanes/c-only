/*

For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

*/

class Node {
public:
    unordered_set<int> neighbors;
    bool isLeaf() const {
        return neighbors.size() == 1;
    }
    Node(){
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> buffer1, buffer2;
        vector<int> *pB1 = &buffer1, *pB2 = &buffer2;
  
        if ( n == 1 ){
            buffer1.emplace_back(0); return buffer1;
        }
        
        if ( n == 2 ){
            buffer1.emplace_back(0);
            buffer1.emplace_back(1);
            return buffer1;
        }
        
        /// build graph
        vector<Node> nodes(n);
        for ( auto& p : edges ){
            nodes[p.first].neighbors.insert(p.second);
            nodes[p.second].neighbors.insert(p.first);
        }
        
        /// find all leaves
        for ( int i = 0; i < n; ++ i ){
            if ( nodes[i].isLeaf() ) pB1->emplace_back(i);
        }
        
        /// remove leaves layer by layer
        while ( true ){
            for ( int i : *pB1 ){
                for ( auto& n : nodes[i].neighbors ){
                    nodes[n].neighbors.erase(i);
                    if ( nodes[n].isLeaf()) pB2->emplace_back(n);
                }
            }
            if ( pB2->empty() ) return *pB1;
            pB1->clear();
            swap(pB1, pB2);
        }
    }
};
