#include "prog1Functions.h"


/*Loop to deallocate memory*/
int freeMemory()
{
    for(freeIndex = 0; freeIndex <rows; ++freeIndex)
    {
        free(maze[freeIndex]);  /*freeIndex delcared in .h file*/
    }

    free(maze);/*Deallocates 2D array*/

    return 1;
}


/*Finds the direction we stepped by subtracting coordinates*/
int findOrientation()
{
    orientationX = currentXCoordinate - previousXCoordinate;/*If orientationX is 1, we stepped left. Else, right*/
    orientationY = currentYCoordinate - previousYCoordinate;/*If orientationX is 1, we stepped up. Else, down*/

    return 1;
}


/*this function updates the direction we are facing (East, West, North or South)*/
int updateDirection()
{
    if(orientationY == -1 && orientationX == 0)/*We face North*/
        direction = 1;

    else if (orientationY == 1 && orientationX == 0)/*We face South*/
        direction = 2;

    else if(orientationX == 1 && orientationY == 0)/*We face East*/
        direction = 3;

    else                        /*We face West*/
        direction = 4;

    return 1;
}


/*Updating our previous coordinates*/
int updatePreviousCoordinates()
{
    previousXCoordinate = currentXCoordinate;
    previousYCoordinate = currentYCoordinate;

    return 1;
}


/*Check to see if we are safe to move West(left) by making sure we are in the bounds of the maze and not a wall*/
int checkXWest()
{
    if(currentXCoordinate-1< 0 || maze[currentYCoordinate][currentXCoordinate-1] == 'X')
        return 0; /*If we can't move we return 0 and continue with the wall follower algorithm*/

    else
        return 1;/*we return 1 indicating it's safe to move*/
}


/*Check to see if we are safe to move East(right) by making sure we are in the bounds of the maze and not a wall*/
int checkXEast()
{
    if(currentXCoordinate+1 >= columns || maze[currentYCoordinate][currentXCoordinate+1] == 'X')
        return 0;

    else
        return 1;
}

/*Check to see if we are safe to move North(up) by making sure we are in the bounds of the maze and not a wall*/
int checkYNorth()
{
    if(currentYCoordinate-1 < 0 || maze[currentYCoordinate-1][currentXCoordinate] == 'X')
        return 0;

    else
        return 1;
}


/*Check to see if we are safe to move South(down) by making sure we are in the bounds of the maze and not a wall*/
int checkYSouth()
{
    if(currentYCoordinate+1 >= rows || maze[currentYCoordinate+1][currentXCoordinate] == 'X')
        return 0;

    else
        return 1;
}


/*Updates the previous coordinate variables*/
int updatePreviousXY()
{
    previousXCoordinate = currentXCoordinate;
    previousYCoordinate = currentYCoordinate;

    return 1;
}


/*checks if our current coordinates are the exit coordinates*/
int checkExit()
{
    if(currentXCoordinate == exitPointXCoordinate && currentYCoordinate ==exitPointYCoordinate)
        finished = 1;/*if we're at the exit, we set finished = 1, and end the program*/
 
    return 1;
}


/*Our function that incorporates many of the other functions to simplify our main functions*/
int move()
{
    findOrientation();
    updateDirection();
    updatePreviousCoordinates();

    if(direction == 1)/*Rule 1, we face North*/
    {
        if(checkXEast())/*So we check if we can go right, and return 0 if we can't*/
        {
            ++currentXCoordinate;/*If we can go right, we step right*/
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

        if(checkYNorth())/*If we can't go right, we go up*/
        {
            --currentYCoordinate;/*Decrementing our Y coordinate means we step up*/
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

        if(checkXWest())/*If not up either, we try to go left*/
        {
            --currentXCoordinate;/*Decrementing our X coordinate mimics going left*/
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }
            
        if(checkYSouth())/*If we can't go any of the other directions, we must step down*/
        {
            ++currentYCoordinate;/*incrementing our Y coordinate mimics heading down*/
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

    }

    else if (direction ==2)/*Rule 2, we face south, and check our proper directions in order*/
    {
        if(checkXWest())
        {
            --currentXCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }
            
        if(checkYSouth())
        {
            ++currentYCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

        if(checkXEast())
        {
            ++currentXCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

        if(checkYNorth())
        {
            --currentYCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }
    }

    else if (direction ==3)/*Rule 3, we face East, and check the correct directions in order*/
    {
        if(checkYSouth())
        {
            ++currentYCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

        if(checkXEast())
        {
            ++currentXCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

        if(checkYNorth())
        {
            --currentYCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

        if(checkXWest())
        {
            --currentXCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

    }

    else if(direction == 4)/*Rule 4, we face West and check the correct directions in order*/
    {
        if(checkYNorth())
        {
            --currentYCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

        if(checkXWest())
        {
            --currentXCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }
            
        if(checkYSouth())
        {
            ++currentYCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }

        if(checkXEast())
        {
            ++currentXCoordinate;
            maze[currentYCoordinate][currentXCoordinate]='W';
            return 1;
        }
    }

    return 0;   /*If we make it here, a error has occured with our direcion not updating correctly*/
}


/*Reads from our external text file populates our row, column, entry and exit point data */
int readCoordinates(FILE * mazeFilePointer)
{
    char tempCharArray[100];    /*used to temporary store txt from our txt files*/

    if(!mazeFilePointer)    /*if the file doesn't exist we will notify the user*/
    {
        printf("We could not read the external text file\n\n");
        return 0;
    }

    fscanf(mazeFilePointer, "%d", &columns);    /*setting columns integer value*/
    fscanf(mazeFilePointer,"%c", tempCharArray);/*reading in comma (junk char)*/
    fscanf(mazeFilePointer, "%d", &rows);   /*setting rows integer value*/

    fscanf(mazeFilePointer,"%c", tempCharArray);    /*reading in /n char (junk char)*/
  
    fscanf(mazeFilePointer, "%d", &entryPointXCoordinate);  /*setting our entry point x coordinate int value*/
    fscanf(mazeFilePointer,"%c", tempCharArray);   /*reading in comma (junk char)*/
    fscanf(mazeFilePointer, "%d", &entryPointYCoordinate);  /*setting our entry point y coordinate int value*/

    fscanf(mazeFilePointer,"%c", tempCharArray);
   
    fscanf(mazeFilePointer, "%d", &exitPointXCoordinate);   /*setting our exit point x coordinate int value*/
    fscanf(mazeFilePointer,"%c", tempCharArray);   /*reading in comma (junk char)*/
    fscanf(mazeFilePointer, "%d", &exitPointYCoordinate);  /*setting our exit point y coordinate int value*/

    fscanf(mazeFilePointer,"%c", tempCharArray);    /*At this point we're primed and ready to read in our maze*/

    /*To begin our algorithm, we MUST offest either our X or Y coordinate by -1 so that we get a correct reading of the first step we take. Else, we can get stuck in a loop where we can't 
     * compute which direction we first step correctly*/
    currentXCoordinate = entryPointXCoordinate;
    currentYCoordinate = entryPointYCoordinate;
    previousXCoordinate = entryPointXCoordinate-1;
    previousYCoordinate = entryPointYCoordinate;

    return 1;
}


int printCoordinates() /*used for debugging*/
{
    printf("%d", columns);
    printf("%d", rows);
    printf("%d", entryPointXCoordinate);
    printf("%d", entryPointYCoordinate);
    printf("%d", exitPointXCoordinate);
    printf("%d", exitPointYCoordinate);
    return 1;
}


/*Simply prints our 2D array*/
int printMultiDimensionalArray()
{
    int i;

    for(i = 0; i<rows; ++i)
    {
       printf("%s", maze[i]);
       printf("\n");
    }

    return 1;
}
