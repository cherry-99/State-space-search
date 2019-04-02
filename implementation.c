#include"0896_A3_header.h"

void Initalise_sate(State* S)       // To initialise to a meaningful state. So that the values don't become junk.
{
    S -> Eigth_L_mug = 8;
    S -> Five_L_mug = 0;
    S -> Three_L_mug = 0;
}

void Display_state(State* S)    // Displays the quantity in each of the jug in the order 8L , 5L , 3L
{
    printf("%d %d %d\n" , S -> Eigth_L_mug , S -> Five_L_mug , S -> Three_L_mug);
}

void pour_8to3(const State* S , State* R)   // Function to pour from 8L jug to 3L jug with boundary conditions taken care of
{
    if(S -> Three_L_mug == 3 || S -> Eigth_L_mug == 0)
    {
        R -> Eigth_L_mug = S -> Eigth_L_mug;
        R -> Five_L_mug = S -> Five_L_mug;
        R -> Three_L_mug = S -> Three_L_mug;
    }
    else
    {
        int temp = 3 - S -> Three_L_mug;
        if(S -> Eigth_L_mug <= temp)
        {
            R -> Three_L_mug = S -> Three_L_mug + S -> Eigth_L_mug;
            R -> Eigth_L_mug = 0;
        }
        else
        {
            R -> Three_L_mug = 3;
            R -> Eigth_L_mug = S -> Eigth_L_mug - temp;
        }
    }
    R -> Five_L_mug = S -> Five_L_mug;
    R -> function_index = 0;
}

void pour_8to5(const State* S , State* R)   // Function to pour from 8L jug to 5L jug with boundary conditions taken care of
{
    if(S -> Eigth_L_mug == 0 || S -> Five_L_mug == 5)
    {
        R -> Eigth_L_mug = S -> Eigth_L_mug;
        R -> Five_L_mug = S -> Five_L_mug;
        R -> Three_L_mug = S -> Three_L_mug;
    }
    else
    {
        int temp = 5 - S ->Five_L_mug;
        if(S -> Eigth_L_mug <= temp)
        {
            R -> Five_L_mug = S -> Five_L_mug + S -> Eigth_L_mug;
            R -> Eigth_L_mug = 0;
        }
        else
        {
            R -> Five_L_mug = 5;
            R -> Eigth_L_mug = S -> Eigth_L_mug - temp;
        }
    }
    R -> Three_L_mug = S -> Three_L_mug;
    R -> function_index = 0;
}

void pour_5to8(const State* S , State* R)       // Function to pour from 5L jug to 8L jug with boundary conditions taken care of
{
    if(S -> Five_L_mug == 0 || S -> Eigth_L_mug == 8)
    {
        R -> Eigth_L_mug = S -> Eigth_L_mug;
        R -> Five_L_mug = S -> Five_L_mug;
        R -> Three_L_mug = S -> Three_L_mug;
    }
    else
    {
        int temp = 8 - S -> Eigth_L_mug;
        if(S -> Five_L_mug <= temp)
        {
            R -> Eigth_L_mug = S -> Eigth_L_mug + S -> Five_L_mug;
            R -> Five_L_mug = 0;
        }
        else        // This is a case we'll never come across. But still defined just for modularity.
        {
            R -> Eigth_L_mug = 8;
            R -> Five_L_mug = S -> Five_L_mug - temp;
        }
    }
    R -> Three_L_mug = S -> Three_L_mug;
    R -> function_index = 0;
}

void pour_5to3(const State* S , State* R)       // Function to pour from 5L jug to 3L jug with boundary conditions taken care of
{
    if(S -> Five_L_mug == 0 || S -> Three_L_mug == 3)
    {
        R -> Eigth_L_mug = S -> Eigth_L_mug;
        R -> Five_L_mug = S -> Five_L_mug;
        R -> Three_L_mug = S -> Three_L_mug;
    }
    else
    {
        int temp = 3 - S -> Three_L_mug;
        if(S -> Five_L_mug <= temp)
        {
            R -> Three_L_mug = S -> Five_L_mug + S -> Three_L_mug;
            R -> Five_L_mug = 0;
        }
        else
        {
            R -> Three_L_mug = 3;
            R -> Five_L_mug = S -> Five_L_mug - temp;
        }
    }
    R -> Eigth_L_mug = S -> Eigth_L_mug;
    R -> function_index = 0;
    
}

void pour_3to8(const State* S , State* R)       // Function to pour from 3L jug to 8L jug with boundary conditions taken care of
{
    if(S -> Three_L_mug == 0 || S -> Eigth_L_mug == 8)
    {
        R -> Eigth_L_mug = S -> Eigth_L_mug;
        R -> Three_L_mug = S -> Three_L_mug;
        R -> Five_L_mug = S -> Five_L_mug;
    }
    else
    {
        int temp = 8 - S -> Eigth_L_mug;
        if(S -> Three_L_mug <= temp)
        {
            R -> Eigth_L_mug = S -> Eigth_L_mug + S -> Three_L_mug;
            R -> Three_L_mug = 0;
        }
        else            // This is a case we'll never come across. But still defined just for modularity.
        {
            R -> Eigth_L_mug = 8;
            R -> Three_L_mug = S -> Three_L_mug - temp;
        }
        
    }
    R -> Five_L_mug = S -> Five_L_mug;
    R -> function_index = 0;
    
}

void pour_3to5(const State* S , State* R)       // Function to pour from 3L jug to 5L jug with boundary conditions taken care of
{
    if(S -> Three_L_mug == 0 || S -> Five_L_mug == 5)
    {
        R -> Eigth_L_mug = S -> Eigth_L_mug;
        R -> Five_L_mug = S -> Five_L_mug;
        R -> Three_L_mug = S -> Three_L_mug;
    }
    else
    {
        int temp = 5 - S -> Five_L_mug;
        if(S -> Three_L_mug <= temp)
        {
            R -> Five_L_mug = S -> Five_L_mug + S -> Three_L_mug;
            R -> Three_L_mug = 0;
        }
        else        // This is a case we'll never come across. But still defined just for modularity.
        {
            R -> Five_L_mug = 5;
            R -> Three_L_mug = S -> Three_L_mug - temp;
        }
    }
    R -> Eigth_L_mug = S -> Eigth_L_mug; 
    R -> function_index = 0;   
}


void Set_state(State* state , int Eight_jug_value , int Five_jug_value , int Three_jug_value)   // To set the values of the fields to some particuar pararmeter passed value
{
    state -> Eigth_L_mug = Eight_jug_value;
    state -> Five_L_mug = Five_jug_value;
    state -> Three_L_mug = Three_jug_value;
}

int IsSafe(State* state)    // To check that the quntity is not exceeded in any of the jugs.
{
    if(state -> Eigth_L_mug <= 8 && state -> Five_L_mug <= 5 && state -> Three_L_mug <= 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void init_list(List *ptr_list)  // To initialise the pointers to NULL initially.
{
	ptr_list->head = NULL;
	ptr_list->tail = NULL;
}

void add_at_end(List *ptr_list, const State* ptr_state) // Function to add to the end of the list

{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->st = *ptr_state; 
	temp->next = temp->prev = NULL;

	if(ptr_list->tail == NULL)
	{
		temp->prev = temp->next = NULL;
		ptr_list->head = ptr_list->tail = temp;
	}
	else
	{
		temp->prev = ptr_list->tail;
		temp->next = NULL;
		ptr_list->tail = ptr_list->tail->next = temp;
	}
}
void remove_at_end(List *ptr_list)  // Function to remove at the end of the list.
{
	if(ptr_list->tail == NULL)
	{
		printf("empty list\n");
	}
	else  
	{
		Node* temp = ptr_list->tail;
		//Display_state(&temp->st);
		ptr_list->tail = ptr_list->tail->prev;	
		if(ptr_list->tail == NULL)
		{
			ptr_list->head = NULL;
		}
		else
		{
			ptr_list->tail->next = NULL;
		}
		free(temp);		
	}
}
void disp_list(const List *ptr_list)    // Function to display.
{
	Node* temp = ptr_list->head;
	while(temp)
	{
		Display_state(&temp->st);
		temp = temp->next;
	}
}


int is_repeated(const List* ptr_list, const State* ptr_state)   // Function to check for repeated states.
{
	Node* temp = ptr_list->head;
	int found = 0;
	while(temp && ! found)
	{
		found  = Compare(&temp->st, ptr_state);
		temp = temp->next;
	}
	return found;
}

int Compare(const State *lhs, const State *rhs) // Function to compare if the new state after transition is same as the final/goal state.
{
	return lhs->Eigth_L_mug == rhs->Eigth_L_mug && lhs->Five_L_mug == rhs->Five_L_mug && lhs->Three_L_mug == rhs->Three_L_mug;
}

