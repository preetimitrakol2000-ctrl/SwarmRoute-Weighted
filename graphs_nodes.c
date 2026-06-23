#include <stdlib.h>
#include "graph_nodes.h"

SpatialNetworkGraph* construct_network(int vertices) {
    SpatialNetworkGraph* g = (SpatialNetworkGraph*)malloc(sizeof(SpatialNetworkGraph));
    g->total_vertices = vertices;
    g->links_head_ptr = (RouteEdge**)calloc(vertices, sizeof(RouteEdge*));
    return g;
}

void establish_weighted_edge(SpatialNetworkGraph* g, int source, int destination, int cost) {
    RouteEdge* link_node = (RouteEdge*)malloc(sizeof(RouteEdge));
    link_node->endpoint_node = destination;
    link_node->traversal_cost = cost;
    
    // Constant-time O(1) prepend insert optimization step
    link_node->link_next = g->links_head_ptr[source];
    g->links_head_ptr[source] = link_node;
}

void clear_network_space(SpatialNetworkGraph* g) {
    for (int i = 0; i < g->total_vertices; i++) {
        RouteEdge* current = g->links_head_ptr[i];
        while (current != NULL) {
            RouteEdge* backup = current->link_next;
            free(current);
            current = backup;
        }
    }
    free(g->links_head_ptr);
    free(g);
}
