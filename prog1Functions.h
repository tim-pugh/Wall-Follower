#include <stdlib.h>
#include <stdio.h>


int readCoordinates(FILE * mazeFilePointer);    /*Reads our external file via command line argument*/
char ** maze;       /*Multidimensional Dynamically Allocated Array to store our Maze*/
int columns;    /*First value from first line is the mazes columns (x-axis)*/
int rows;       /*Second value from first line is the mazes rows (y-axis)*/


int entryPointXCoordinate;   /*The first value from the second line is the mazes x-coordinate entry point*/
int entryPointYCoordinate;  /*The second value from the second line is the mazes y-coordinate entry point*/


int exitPointXCoordinate;   /*The first value from the third line is the mazes x-coordinate exit point*/
int exitPointYCoordinate;   /*The second value from the third line is the mazes y-coordinate exit point*/


int currentXCoordinate;     /*Our current X coordinate while traversing the maze*/
int currentYCoordinate;     /*Our current Y coordinate while taversing the maze*/


int previousXCoordinate;    /*Our previous X coordinate while traversing the maze*/
int previousYCoordinate;    /*Our Previous Y coordinate while traversing the maze*/
int updatePreviousCoordinates();    /*A function to update our previous coordinates*/


int  orientationX;   /*If this value is -1 we stepped East (left). If this value is 1, we stepped West (right)*/
int  orientationY;  /*If this value is -1, we stepped North (up). If this value is 1, we stepped South (down)*/
int findOrientation();/*Subtracts our current coordinates from our previous coordinates to find the direction we stepped*/
int  direction;     /*If 1, we face North. If 2, we face South. If 3, we face East. If 4, we face West*/


int freeIndex;      /*Used for the for loop to deallocate memory*/
int freeMemory();   /*A simple function to return memory to the system*/


int move();         /*A function that houses a collection of others to reduce the code in our movement loop*/
int checkXWest();   /*Checks if we are about to head off the grid going West and if a wall exists to the West*/
int checkXEast();   /*Checks if we are about to head off the grid going East and if a wall exists to the East*/
int checkYNorth();  /*Checks if we are about to head off the grid going North and if a wall exists to the North*/
int checkYSouth();  /*Checks if we are about to head off the grid going South and if a wall exists to the South*/


int finished;       /*We run a function that will change this value to 1 if we are at the Exit coordinates*/
int checkExit();    /*Checks if our current coordinates are the exit coordinates*/


int printCoordinates(); /*Function for debugging. Simply prints our coordinates*/
int printMultiDimensionalArray();/*Prints our Multi-Dimensional Array to the client*/
