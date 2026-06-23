#ifndef GRAPH_NODES_H
#define GRAPH_NODES_H

typedef struct RouteEdge {
    int endpoint_node;
    int traversal_cost; // Latency weight factor (e.g., network delays or distance)
    struct RouteEdge* link_next;
} RouteEdge;

typedef struct {
    int total_vertices;
    RouteEdge** links_head_ptr;
} SpatialNetworkGraph;

SpatialNetworkGraph* construct_network(int vertices);
void establish_weighted_edge(SpatialNetworkGraph* g, int source, int destination, int cost);
void clear_network_space(SpatialNetworkGraph* g);

#endif
