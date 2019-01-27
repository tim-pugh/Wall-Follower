#include "prog1Functions.h" /*Including our functions and variables*/

int main (int argc, char * argv[])/*argc/argv allows us to pass into main command line arguments to use*/
{

    FILE * mazeFilePointer; /*file pointer for opening up our maze txt filesa*/
    int z;                  /*used in our for loop to allocate memory*/
    finished = 0;   /*setting finished variable to 0 since we do not begin at the exit point*/

    mazeFilePointer = fopen(argv[1], "r");  /*opens up txt file from cmd line arg. "r" means we intend to read from it*/
    readCoordinates(mazeFilePointer);       /*reads our coordinatesa*/

    maze = (char**)malloc(sizeof(char*)*rows);  /*creates our multi-dimensional array's rows*/
    for(z = 0; z < rows; z++)   /*loops through our rows and creates our multi-dimensional array's columns*/
    {
        maze[z] = (char*)malloc(sizeof(char)*columns);

        fscanf(mazeFilePointer, "%s ", maze[z]);    /*Populating our 2D array with the contents of our maze*/
    }

    fclose(mazeFilePointer);    /*Closing the external file*/
 
    printf("\n\nWelcome to the Maze Traversal Program!\n\n");
    printf("The path to the exit is:\n\n");

    maze[currentYCoordinate][currentXCoordinate]='W';   /*Since we start at our entry point, we mark it as walked upon*/

    while(finished != 1)    /*While we haven't reached the exit, finished will stay at 0*/
    {
        move(); /*We move according to our Rules dictating which way to attempt to step first via the wall follower algorithm*/
        checkExit();    /*And we check if we're at the exit*/
    }

    printMultiDimensionalArray();   /*Then we print our maze when we're at the exit that shows the paath we walked*/

    freeMemory();   /*And finally we free our memory and return it to the system*/

    return 0;
}
