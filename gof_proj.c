#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

// We need to define what are the parameters of our struct
typedef struct cells {
	int alive;
}cell;

void display(WINDOW *win, cell **area, int startx, int starty, int endx, int endy)
{	int i, j;
	wclear(win);
	for(i = startx; i <= endx; ++i)
		for(j = starty;j <= endy; ++j)
			if(area[i][j].alive == 1)
				mvwaddch(win, j, i, '*');
	wrefresh(win);
}

int main()
{


	initscr(); // Start curses mode
	cbreak();
	keypad(stdscr, TRUE); //Enable keys

	int inic_x=0; //first position of the screen
	int final_x=COLS; //COLS, LINES which are initialized to 
	int inic_y=0;
	int final_y=LINES;// the screen sizes after initscr()



	// Allocating memory for a 2D array of cell type
	// Array of pointers
	int  fsize = 20;
	cell **  field = (cell  **)  malloc(fsize * sizeof(cell  *));

	int i=0;
	int j=0;

	// Array of cells
	for (i = 0; i < fsize; ++i)
		field[i] = (cell *)  malloc(fsize * sizeof(cell ));

	printw("Please indicate the intial configuration you would like to effect\n");
	printw("L :1");
	raw();
	char answer = getch();
	printw("Answer is %c \n", answer);

	if(answer=='1')
	{
		field[0][0].alive = 1;
		field[1][0].alive = 1;
		field[2][0].alive = 1;
	}

	display(stdscr, field, inic_x, inic_y, final_x, final_y);
// Game: we need to update all the cells until the user press F1

while(getch() != KEY_F(1))
	{	
		for(i = inic_x; i <= final_x; ++i)
		{
			for(j = inic_y; j <= final_y; ++j)
			{
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
		}		
	}
/* To update the screen we need create a function that uses:
mvaddch(row,col,ch) -> is used to move the cursor to a given point, and then print
refresh();	-> Print it on to the real screen 


*/

for (i = 0; i < fsize; ++i)
	free(field[i]); //  free each array of cells d
free(field); // free the array of pointers field
}