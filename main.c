#include <stdio.h>
#include "graph_nodes.h"

extern int inspect_direct_latency(SpatialNetworkGraph* g, int u, int v);

int main() {
    printf("🤖 Activating SwarmRoute-Weighted Navigation Core...\n\n");

    int operational_hubs = 3;
    SpatialNetworkGraph* topology = construct_network(operational_hubs);

    // Map terrain movement costs between robotic charging terminals
    establish_weighted_edge(topology, 0, 1, 15); // Terminal 0 to 1 costs 15 seconds
    establish_weighted_edge(topology, 1, 2, 8);  // Terminal 1 to 2 costs 8 seconds

    int start_node = 1;
    int goal_node = 2;
    int weight_result = inspect_direct_latency(topology, start_node, goal_node);

    printf("📥 Graph Layout Verified: Enqueued Swarm Navigation Link Weights.\n");
    printf("🔍 Inspecting Edge Path: Terminal [%d] ---> Terminal [%d]\n", start_node, goal_node);
    
    if (weight_result != -1) {
        printf("   🔮 Traversal Cost Factor Isolated: %d Seconds\n", weight_result);
    } else {
        printf("   🚨 Path Unreachable via Direct Topology.\n");
    }

    clear_network_space(topology);
    return 0;
}
