#include "contiki.h"
#include "net/routing/rpl-lite/rpl.h"
#include "net/routing/rpl-lite/rpl-dag.h"
#include <stdio.h>
#include <math.h> 

/* LoRa-RPL Rank Calculation by Rafik */


static uint16_t calculate_rank(rpl_parent_t *parent, rpl_instance_t *instance) {
    if (parent == NULL) {
        return ROOT_RANK(instance);  // Sink node rank
    }
    
    uint16_t parent_rank = parent->rank;
    float DR_P = get_data_rate_index(parent->link_metric);    // Assuming link metric as Data Rate Index
    float E_res = parent->energy;      // residual energy
    float d_n = parent->depth;         // Hop distance from root
    float W_n = parent->num_child;  // Weight based on number of childs
    
    // Rank Increment Calculation 
    float rank_inc = (DR_P + (d_n * W_n)) / E_res;
    
    // New Rank Calculation 
    uint16_t new_rank = parent_rank + (uint16_t)rank_inc;
    
    //printf("RPL: Node %d calculating rank: Parent Rank=%d, Rank_inc=%.2f, New Rank=%d\n", 
      //      linkaddr_node_addr.u8[0], parent_rank, rank_inc, new_rank);
    
    return new_rank;
}

/* Function to update rank in RPL */
void lora_rpl_update_rank(rpl_instance_t *instance) {
    if (instance->current_dag == NULL) {
        return;
    }
    instance->current_dag->rank = calculate_rank(instance->current_dag->preferred_parent, instance);
}


static int get_data_rate_index(float etx) {
    if(etx <= 1.5) return 5;  // Excellent link → Highest Data Rate
    if(etx <= 3.0) return 4;  // Good link
    if(etx <= 5.0) return 3;  // Moderate link
    if(etx <= 7.0) return 2;  // Weak link
    return 1;                 // Very weak link → Lowest Data Rate
}
