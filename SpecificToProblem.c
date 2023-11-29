/*
    These functions are compulsory for tree search algorithms but they are specific
    to problems. More clearly, you must must update their blocks but do not change
    their input and output parameters.
    
    Also, if you need, you can add new functions at the end of file by declaring them in TREE_SEARCH.h
*/

#include "GRAPH_SEARCH.h"
#include "data_types.h"
#include <stdio.h>
#include <stdlib.h>

int selectedPosition;

//______________________________________________________________________________
State* Create_State()
{
    State *state = (State*)malloc(sizeof(State));
    if(state==NULL)
        Warning_Memory_Allocation();
    int i;
    char selectedPositionChar;
    int selectedPosition;

    printf("Enter the number of blocks on position p;");
    scanf("%d", &state->position.len_p);
    getchar(); // önceki scanf'ten kalan '\n' karakterini tüketir

    for(i=0; i<state->position.len_p; i++){
        printf("Enter the blocks on position p;");
        scanf("%c", &state->position.position_p[i]);
        getchar(); // önceki scanf'ten kalan '\n' karakterini tüketir
    }


    printf("Enter the number of blocks on position q;");
    scanf("%d", &state->position.len_q);
    getchar(); // önceki scanf'ten kalan '\n' karakterini tüketir

    for(i=0; i<state->position.len_q; i++){
        printf("Enter the blocks on position q;");
        scanf("%c", &state->position.position_q[i]);
        getchar(); // önceki scanf'ten kalan '\n' karakterini tüketir
    }


    printf("Enter the number of blocks on position r;");
    scanf("%d", &state->position.len_r);
    getchar(); // önceki scanf'ten kalan '\n' karakterini tüketir

    for(i=0; i<state->position.len_r; i++){
        printf("Enter the blocks on position r;");
        scanf("%c", &state->position.position_r[i]);
        getchar(); // önceki scanf'ten kalan '\n' karakterini tüketir
    }

    printf("Enter your goal position (p,q,r);");
    scanf(" %c", &selectedPositionChar); // boşluk karakteri, önceki scanf'ten kalan '\n' karakterini tüketir
    getchar();

    if(selectedPositionChar == 'p')
        selectedPosition = 1;

    else if(selectedPositionChar == 'q')
        selectedPosition = 2;

    else if(selectedPositionChar == 'r')
        selectedPosition = 3;

    return state;
}

//______________________________________________________________________________
void Print_State(const State *const state)
{
    int i;
	printf("Position P: ");
	for(i=0; i<state->position.len_p; i++){
		printf("%d ",state->position.position_p[i]);
	}

	printf("Position Q: ");
	for(i=0; i<state->position.len_q; i++){
		printf("%d ",state->position.position_q[i]);
	}

	printf("Position R: ");
	for(i=0; i<state->position.len_r; i++){
		printf("%d ",state->position.position_r[i]);
	}
}

//______________________________________________________________________________
void Print_Action(const enum ACTIONS action)
{
   switch(action){
         case  p_to_q:      printf("P to Q"); break;
         case  p_to_r: printf("P to R"); break;
         case  q_to_r:   printf("Q to R"); break;
         case  q_to_p:   printf("Q to P"); break;
         case  r_to_p:    printf("R to P"); break;
         case  r_to_q:   printf("R to Q"); break;
    }        
}

//______________________________________________________________________________
int Result(const State *const parent_state, const enum ACTIONS action, Transition_Model *const trans_model)
{
    State new_state;
    int i;
    
    switch(action){
    	case p_to_q:
    		if(parent_state->position.len_p == 0)
    			return FALSE;

    		for(i=0; i<parent_state->position.len_p-1; i++){
    			new_state.position.position_p[i] = parent_state->position.position_p[i];
			}
			for(i=0; i<parent_state->position.len_q; i++){
    			new_state.position.position_q[i] = parent_state->position.position_q[i];
			}

			new_state.position.position_q[parent_state->position.len_q] = parent_state->position.position_p[parent_state->position.len_p-1];

			new_state.position.len_q = parent_state->position.len_q+1;
			new_state.position.len_p = parent_state->position.len_p-1;
			new_state.position.len_r = parent_state->position.len_r;
    		break;
    	case p_to_r:
    		if(parent_state->position.len_p == 0)
    			return FALSE;

    		for(i=0; i<parent_state->position.len_p-1; i++){
    			new_state.position.position_p[i] = parent_state->position.position_p[i];
			}
			for(i=0; i<parent_state->position.len_r; i++){
    			new_state.position.position_r[i] = parent_state->position.position_r[i];
			}

			new_state.position.position_r[parent_state->position.len_r] = parent_state->position.position_p[parent_state->position.len_p-1];

			new_state.position.len_q = parent_state->position.len_q;
			new_state.position.len_p = parent_state->position.len_p-1;
			new_state.position.len_r = parent_state->position.len_r +1;
    		break;
    	case q_to_r:
    		if(parent_state->position.len_q == 0)
    			return FALSE;

    		for(i=0; i<parent_state->position.len_q-1; i++){
    			new_state.position.position_q[i] = parent_state->position.position_q[i];
			}
			for(i=0; i<parent_state->position.len_r; i++){
    			new_state.position.position_r[i] = parent_state->position.position_r[i];
			}

			new_state.position.position_r[parent_state->position.len_r] = parent_state->position.position_q[parent_state->position.len_q-1];

			new_state.position.len_q = parent_state->position.len_q-1;
			new_state.position.len_p = parent_state->position.len_p;
			new_state.position.len_r = parent_state->position.len_r+1;
    		break;
    	case q_to_p:
    		if(parent_state->position.len_q == 0)
    			return FALSE;

    		for(i=0; i<parent_state->position.len_q-1; i++){
    			new_state.position.position_q[i] = parent_state->position.position_q[i];
			}
			for(i=0; i<parent_state->position.len_p; i++){
    			new_state.position.position_p[i] = parent_state->position.position_p[i];
			}

			new_state.position.position_p[parent_state->position.len_p] = parent_state->position.position_q[parent_state->position.len_q-1];

			new_state.position.len_q = parent_state->position.len_q-1;
			new_state.position.len_p = parent_state->position.len_p+1;
			new_state.position.len_r = parent_state->position.len_r;
    		break;
    	case r_to_p:
    		if(parent_state->position.len_r == 0)
    			return FALSE;

    		for(i=0; i<parent_state->position.len_r-1; i++){
    			new_state.position.position_r[i] = parent_state->position.position_r[i];
			}
			for(i=0; i<parent_state->position.len_p; i++){
    			new_state.position.position_p[i] = parent_state->position.position_p[i];
			}

			new_state.position.position_p[parent_state->position.len_p] = parent_state->position.position_r[parent_state->position.len_r-1];

			new_state.position.len_q = parent_state->position.len_q;
			new_state.position.len_p = parent_state->position.len_p+1;
			new_state.position.len_r = parent_state->position.len_r-1;
    		break;
    	case r_to_q:
    		if(parent_state->position.len_r == 0)
    			return FALSE;

			for(i=0; i<parent_state->position.len_r-1; i++){
    			new_state.position.position_r[i] = parent_state->position.position_r[i];
			}
			for(i=0; i<parent_state->position.len_q; i++){
    			new_state.position.position_q[i] = parent_state->position.position_q[i];
			}

			new_state.position.position_q[parent_state->position.len_q] = parent_state->position.position_r[parent_state->position.len_r-1];

			new_state.position.len_q = parent_state->position.len_q+1;
			new_state.position.len_p = parent_state->position.len_p;
			new_state.position.len_r = parent_state->position.len_r-1;
	}

	trans_model->new_state = new_state;
    trans_model->step_cost = 1;

	return TRUE;
}

float Compute_Heuristic_Function(const State *const state, const State *const goal)
{
		int i;
		int stateCount = 0, goalCount = 0;
		
		if(selectedPosition == 1){
			for(i=0; i<state->position.len_p-1; i++){
				if(state->position.position_p[i] > state->position.position_p[i+1])
					stateCount++;
			}        
			
			
			for(i=0; i<goal->position.len_p-1; i++){
				if(goal->position.position_p[i] > goal->position.position_p[i+1])
					goalCount++;
			}   
		}
		
		else if(selectedPosition == 2){
			for(i=0; i<state->position.len_q-1; i++){
				if(state->position.position_q[i] > state->position.position_q[i+1])
					stateCount++;
			}        
			
			
			for(i=0; i<goal->position.len_q-1; i++){
				if(goal->position.position_q[i] > goal->position.position_q[i+1])
					goalCount++;
			} 
		}
		
		else if(selectedPosition == 3){
			for(i=0; i<state->position.len_r-1; i++){
				if(state->position.position_r[i] > state->position.position_r[i+1])
					stateCount++;
			}        
			
			for(i=0; i<goal->position.len_r-1; i++){
				if(goal->position.position_r[i] > goal->position.position_r[i+1])
					goalCount++;
			} 
		}
		
    
        return (float)goalCount - stateCount;   
}

// ==================== WRITE YOUR OPTIONAL FUNCTIONS ==========================
