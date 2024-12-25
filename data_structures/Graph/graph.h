/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2024-12-24 15:50
 * @author: yikebaer·aizezi
 * @file: graph.h
 * @brief: header for graph related algorithm
*/
#pragma once

#ifndef GRAPH_H
#define GRAPH_H
#endif // GRAPH_H

#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>

namespace graph_algo {

class GraphAlgo {
    public:
        // Graph representation using adjacency list
        using Graph = std::vector<std::vector<std::pair<int, int>>>; // {vertex, weight}
        
        // Basic graph operations
        void addEdge(Graph& g, int from, int to, int weight);
        void removeEdge(Graph& g, int from, int to);
        
        // Graph traversal algorithms
        std::vector<int> bfs(const Graph& g, int start);
        std::vector<int> dfs(const Graph& g, int start);
        
        // Shortest path algorithms
        std::vector<int> dijkstra(const Graph& g, int start);
        std::vector<int> bellmanFord(const Graph& g, int start, int V);
        
        // Minimum spanning tree
        std::vector<std::pair<int, int>> primMST(const Graph& g);
        std::vector<std::pair<int, int>> kruskalMST(const Graph& g);
        
        // Cycle detection
        bool hasCycle(const Graph& g);
        
        // Topological sort
        std::vector<int> topologicalSort(const Graph& g);

    private:
        // Helper functions for DFS
        void dfsHelper(const Graph& g, int vertex, std::vector<bool>& visited, std::vector<int>& result);
        
        // Helper for cycle detection
        bool hasCycleHelper(const Graph& g, int vertex, std::vector<bool>& visited, std::vector<bool>& recStack);
        
        // Helper for topological sort
        void topologicalSortHelper(const Graph& g, int vertex, std::vector<bool>& visited, std::stack<int>& stack);
        
        // Helper for Kruskal's algorithm
        class DisjointSet {
            std::vector<int> parent, rank;
        public:
            DisjointSet(int n);
            int find(int x);
            void unite(int x, int y);
        };
};

} // namespace graph_algo