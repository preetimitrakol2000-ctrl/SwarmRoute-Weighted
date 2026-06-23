// Interface placeholder for edge cost accumulation routines
#include "graph_nodes.h"
int inspect_direct_latency(SpatialNetworkGraph* g, int u, int v) {
    RouteEdge* head = g->links_head_ptr[u];
    while (head != NULL) {
        if (head->endpoint_node == v) return head->traversal_cost;
        head = head->link_next;
    }
    return -1; // Unreachable neighbor link marker
}
