#include <curses.h>

// We need to define what are the parameters of our struct
typedef struct cells {
	int xpos;
	int ypos;
	int state
}cell;


int main()
{
	cell **field

	initscr(); // Start curses mode
	cbreak();
	keypad(stdscr, TRUE); //Enable keys

	inic_x=0; //first position of the screen
	final_x=COLS //COLS, LINES which are initialized to 
	inic_y=0;
	final_y=LINES// the screen sizes after initscr()

	CELL_CHAR=*;



	// Allocating memory for a 2D array of cell type
	// Array of pointers
	int  fsize = 20;
	cell **field = (cell  **)  malloc(fsize * sizeof(cell  *));

	// Array of cells
	for (int i = 0; i < fsize; ++i)
		field[i] = (cell *)  malloc(fsize * sizeof(cell ));

// Game: we need to update all the cells until the user press F1

while(getch() != KEY_F(1))
	{	
		for(i = inic_x; i <= final_x; ++i)
			for(j = inic_y; j <= final_y; ++j)


				//PSEUDO-CODE
				neighbors= field[i][j+1]+field[i][j-1]+field[i+1][j]+field[i-1][j]+field[i+1][j+1]+field[i+1][j-1]+field[i-1][j+1]+field[i-1][j-1];
				
				if (field[i][j].state=1)
					if (neighbors=2 || neighbors=3)
						cell.state=1
					else
						cell.state=0

				else 
					if (neighbors=3)
						cell.state=1
					else
						cell.state=0

			if (field[i][j].state=1)
				mvwaddch(win, j, i, CELL_CHAR);

				wrefresh(win);




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



// Ideia to create a window

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}