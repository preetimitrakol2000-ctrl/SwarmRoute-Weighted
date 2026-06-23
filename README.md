# SwarmRoute-Weighted

A pure C99 path optimization core designed for autonomous robotic swarms and warehouse automation networks. By organizing local tracking coordinates as a **Weighted Adjacency List Graph**, this framework enables real-time edge navigation routines to evaluate alternative routing steps with minimal memory overhead.

## 🛠️ Graph Mechanics
* **State Layout Strategy:** Memory-aligned tracking chains pointing to linked destination structures.
* **Space Complexity:** Optimized to linear $O(V + E)$ configurations, avoiding the $O(N^2)$ footprint of dense matrices.
