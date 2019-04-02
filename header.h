#include <stdio.h>
#include<stdlib.h>


typedef struct state
{
    int Eigth_L_mug;
    int Five_L_mug;
    int Three_L_mug;
    int function_index;

}State;

typedef struct Node
{
	State st;
	struct Node* next;
	struct Node* prev;
}Node;

typedef struct List
{
	Node* head;
	Node* tail;
}List;

// The following are the set of operations that can be performed on the jugs.

void Initalise_sate(State* S);
void Display_state(State* S);
void pour_8to3(const State* S , State* R);
void pour_8to5(const State* S , State* R);
void pour_5to8(const State* S , State* R);
void pour_5to3(const State* S , State* R);
void pour_3to8(const State* S , State* R);
void pour_3to5(const State* S , State* R);
void Set_state(State* state , int Eight_jug_value , int Five_jug_value , int Three_jug_value);
int IsSafe(State* state);


// The following are the linked list manipulation operations.

void init_list(List *ptr_list);
void add_at_end(List *ptr_list, const State* ptr_state);
void remove_at_end(List *ptr_list);
void disp_list(const List *ptr_list);
int is_repeated(const List* ptr_list, const State* ptr_state);
int Compare(const State *lhs, const State *rhs);






