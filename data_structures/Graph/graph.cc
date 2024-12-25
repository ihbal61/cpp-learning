/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2024-12-24 15:50
 * @author: yikebaer·aizezi
 * @file: graph.cc
 * @brief: graph related algorithm
*/

#include "graph.h"

namespace graph_algo {

/*
 * Time: O(1)
 * Space: O(1)
 */
void GraphAlgo::addEdge(Graph& g, int from, int to, int weight) {
    if (from >= g.size()) {
        g.resize(from + 1);
    }
    if (to >= g.size()) {
        g.resize(to + 1);
    }
    g[from].push_back({to, weight});
}

/*
 * Time: O(E) where E is number of edges from vertex 'from'
 * Space: O(1)
 */
void GraphAlgo::removeEdge(Graph& g, int from, int to) {
    if (from < g.size()) {
        auto& edges = g[from];
        edges.erase(std::remove_if(edges.begin(), edges.end(),
            [to](const auto& p) { return p.first == to; }), edges.end());
    }
}

/*
 * Time: O(V + E) where V is number of vertices and E is number of edges
 * Space: O(V) for visited array and queue
 */
std::vector<int> GraphAlgo::bfs(const Graph& g, int start) {
    std::vector<int> result;
    if (g.empty() || start >= g.size()) {
        return result;
    }

    std::vector<bool> visited(g.size(), false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        result.push_back(vertex);

        for (const auto& edge : g[vertex]) {
            if (!visited[edge.first]) {
                visited[edge.first] = true;
                q.push(edge.first);
            }
        }
    }
    return result;
}

void GraphAlgo::dfsHelper(const Graph& g, int vertex, std::vector<bool>& visited, std::vector<int>& result) {
    visited[vertex] = true;
    result.push_back(vertex);

    for (const auto& edge : g[vertex]) {
        if (!visited[edge.first]) {
            dfsHelper(g, edge.first, visited, result);
        }
    }
}

/*
 * Time: O(V + E) where V is number of vertices and E is number of edges
 * Space: O(V) for visited array and recursion stack
 */
std::vector<int> GraphAlgo::dfs(const Graph& g, int start) {
    std::vector<int> result;
    if (g.empty() || start >= g.size()) {
        return result;
    }

    std::vector<bool> visited(g.size(), false);
    dfsHelper(g, start, visited, result);
    return result;
}

/*
 * Time: O((V + E)logV) where V is number of vertices and E is number of edges
 * Space: O(V) for distance array and priority queue
 */
std::vector<int> GraphAlgo::dijkstra(const Graph& g, int start) {
    std::vector<int> dist(g.size(), std::numeric_limits<int>::max());
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, 
                       std::greater<std::pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (const auto& edge : g[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

/*
 * Time: O(VE) where V is number of vertices and E is number of edges
 * Space: O(V) for distance array
 */
std::vector<int> GraphAlgo::bellmanFord(const Graph& g, int start, int V) {
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (const auto& edge : g[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != std::numeric_limits<int>::max() && 
                    dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    return dist;
}

/*
 * Time: O((V + E)logV) where V is number of vertices and E is number of edges
 * Space: O(V) for visited array, key array, parent array and priority queue
 */
std::vector<std::pair<int, int>> GraphAlgo::primMST(const Graph& g) {
    std::vector<std::pair<int, int>> result;
    if (g.empty()) {
        return result;
    }

    std::vector<bool> visited(g.size(), false);
    std::vector<int> key(g.size(), std::numeric_limits<int>::max());
    std::vector<int> parent(g.size(), -1);

    key[0] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                       std::greater<std::pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        if (parent[u] != -1) {
            result.push_back({parent[u], u});
        }

        for (const auto& edge : g[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    return result;
}

GraphAlgo::DisjointSet::DisjointSet(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int GraphAlgo::DisjointSet::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void GraphAlgo::DisjointSet::unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
        return;
    }

    if (rank[px] < rank[py]) {
        parent[px] = py;
    } else if (rank[px] > rank[py]) {
        parent[py] = px;
    } else {
        parent[py] = px;
        rank[px]++;
    }
}

/*
 * Time: O(ElogE) where E is number of edges
 * Space: O(V) for DisjointSet data structure
 */
std::vector<std::pair<int, int>> GraphAlgo::kruskalMST(const Graph& g) {
    std::vector<std::pair<int, int>> result;
    if (g.empty()) {
        return result;
    }

    std::vector<std::tuple<int, int, int>> edges;
    for (int u = 0; u < g.size(); u++) {
        for (const auto& edge : g[u]) {
            edges.push_back({edge.second, u, edge.first});
        }
    }
    std::sort(edges.begin(), edges.end());

    DisjointSet ds(g.size());
    for (const auto& edge : edges) {
        int weight = std::get<0>(edge);
        int u = std::get<1>(edge);
        int v = std::get<2>(edge);

        if (ds.find(u) != ds.find(v)) {
            ds.unite(u, v);
            result.push_back({u, v});
        }
    }
    return result;
}

bool GraphAlgo::hasCycleHelper(const Graph& g, int vertex, std::vector<bool>& visited, std::vector<bool>& recStack) {
    visited[vertex] = true;
    recStack[vertex] = true;

    for (const auto& edge : g[vertex]) {
        if (!visited[edge.first]) {
            if (hasCycleHelper(g, edge.first, visited, recStack)) {
                return true;
            }
        } else if (recStack[edge.first]) {
            return true;
        }
    }

    recStack[vertex] = false;
    return false;
}

/*
 * Time: O(V + E) where V is number of vertices and E is number of edges
 * Space: O(V) for visited and recursion stack arrays
 */
bool GraphAlgo::hasCycle(const Graph& g) {
    std::vector<bool> visited(g.size(), false);
    std::vector<bool> recStack(g.size(), false);

    for (int i = 0; i < g.size(); i++) {
        if (!visited[i]) {
            if (hasCycleHelper(g, i, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}

void GraphAlgo::topologicalSortHelper(const Graph& g, int vertex, std::vector<bool>& visited, std::stack<int>& stack) {
    visited[vertex] = true;

    for (const auto& edge : g[vertex]) {
        if (!visited[edge.first]) {
            topologicalSortHelper(g, edge.first, visited, stack);
        }
    }

    stack.push(vertex);
}

/*
 * Time: O(V + E) where V is number of vertices and E is number of edges
 * Space: O(V) for visited array and stack
 */
std::vector<int> GraphAlgo::topologicalSort(const Graph& g) {
    std::vector<int> result;
    if (g.empty()) {
        return result;
    }

    std::vector<bool> visited(g.size(), false);
    std::stack<int> stack;

    for (int i = 0; i < g.size(); i++) {
        if (!visited[i]) {
            topologicalSortHelper(g, i, visited, stack);
        }
    }

    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }

    return result;
}

} // namespace graph_algo