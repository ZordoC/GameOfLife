#include <curses.h>

// We need to define what are the parameters of our struct
typedef struct cells {

}cell;


int main()
{


	initscr(); // Start curses mode
	cbreak();
	keypad(stdscr, TRUE); //Enable keys

	inic_x=0; //first position of the screen
	final_x=COLS //COLS, LINES which are initialized to 
	inic_y=0;
	final_y=LINES// the screen sizes after initscr()



	// Allocating memory for a 2D array of cell type
	// Array of pointers
	int  fsize = 20;
	cell **  field = (cell  **)  malloc(fsize * sizeof(cell  *));

	// Array of cells
	for (int i = 0; i < fsize; ++i)
		field[i] = (cell *)  malloc(fsize * sizeof(cell ));

// Game: we need to update all the cells until the user press F1

while(getch() != KEY_F(1))
	{	
		for(i = inic_x; i <= final_x; ++i)
			for(j = inic_y; j <= final_y; ++j)
				/* Verify all the rules
				Populated cells
					Each cell with one or no neighbors dies, as if by solitude.
					Each cell with four or more neighbors dies, as if by overpopulation.
					Each cell with two or three neighbors survives.

				Empty cells
					Each cell with three neighbors becomes populated.
				*/
				// Uptade the screen with the necessary changes 
				

	}
/* To update the screen we need create a function that uses:
mvaddch(row,col,ch) -> is used to move the cursor to a given point, and then print
refresh();	-> Print it on to the real screen 


*/

for (int i = 0; i < fsize; ++i)
	free(field[i]); //  free each array of cells d
free(field); // free the array of pointers field
}