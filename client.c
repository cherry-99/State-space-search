#include "0896_A3_header.h"

int main()
{
	int solution_counter = 0;
	State start_state;
	Initalise_sate(&start_state);
	start_state.function_index = 0;
	Set_state(&start_state, 8, 0, 0);	// Setting the start state.
	State goal_state;
	Initalise_sate(&goal_state);
	Set_state(&goal_state, 4, 4, 0);	// Setting the ending or terminating state.
	List l;
	init_list(&l);
	State temp;
	int soln = 0;
	add_at_end(&l, &start_state);
	int index;
	void (*Transfer_milk[])(const State *src, State *dst) = {		// Creating an array of pointers to functions.
		pour_8to5,
		pour_8to3,
		pour_5to8,
		pour_5to3,
		pour_3to8,
        pour_3to5
	};

	while(l.head != NULL)
	{
		index = l.tail->st.function_index;
		Transfer_milk[index](&l.tail->st , &temp);
		if(IsSafe(&temp) && ! is_repeated(&l, &temp))
		{
			add_at_end(&l, &temp);
			soln = Compare(&temp, &goal_state);
			if(soln == 1)
			{
				disp_list(&l);
				printf("\n");
				solution_counter = solution_counter + 1;
				soln = 0;
			}
		}
		else
		{
			while(++l.tail->st.function_index == 6)
			{
				remove_at_end(&l);
				if(l.head == NULL || l.tail == NULL)
				{
					break;
				}
			}
		}
	}
	printf("\n");
	printf("Number of solutions : %d\n" , solution_counter);
}
