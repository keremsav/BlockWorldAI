#ifndef DATA_TYPES_H
#define DATA_TYPES_H

// ==================== WRITE YOUR OPTIONAL DATA TYPES IF YOU NEED =============

enum BLOCKS
{
    A, B, C, D, E 
};


// ====== WRITE YOUR COMPULSORY (BUT SPECIFIC TO THE PROBLEM) DATA TYPES =======

enum ACTIONS // All possible actions
{
	p_to_q, p_to_r, q_to_r, q_to_p, r_to_p, r_to_q
};

typedef struct position{
	int len_p;
	int len_q;
	int len_r;
	int position_p[20];
	int position_q[20];
	int position_r[20];
}POSITION;

typedef struct State  
{
    POSITION position;
    float h_n;   // Heuristic function

}State;

// ================== YOU DO NOT NEED TO CHANGE THIS PART ======================

enum METHODS  // This part must be updated if a new algorithm is added.
{
	BreastFirstSearch = 1,   UniformCostSearch = 2,        DepthFirstSearch = 3,    
	DepthLimitedSearch= 4,   IterativeDeepeningSearch = 5, GreedySearch = 6,
    AStarSearch = 7 
};

// This struct is used to determine a new state in transition model
typedef struct Transition_Model
{
    State new_state;
    float step_cost;

}Transition_Model;

typedef struct Node
{
    State state;
    float path_cost;
    enum ACTIONS action; //The action applied to the parent to generate this node
    struct Node *parent;
    int Number_of_Child; // required for depth-first search algorithms
}Node;

typedef struct Queue  // Used for frontier
{
    Node *node;
    struct Queue *next;
}Queue;



#endif
