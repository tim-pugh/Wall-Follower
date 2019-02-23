Tim Pugh
Program 1 - The Wall Follower Program in the C Language
CS201
Professor David Baldwin
Portland State University



    For this assignment I have implemented the Wall Follower Algorithm using the right handed method.

    My code works 30 by first accepting command line arguments to load up external text files. The txt files must follow a particular format to have the program execute correctly.

    After a cmd line argument to a txt file is provided, we begin by creating a pointer to the txt file then opening up the file to extract integers from the first 3 lines.

    The first line is the dimensions of he maze. The second line is the entry point into the maze. The third line is the exit point in the maze (although please remember that we begin counting at 0 in programming). What follows after is a user created maze that has 0's as the walkable path, and X's as walls.

    We must traverse the maze and be diligent we are stepping only on the walkable path, and not going outside of the bounds of our grid else we risk crashing the program by a segfault.

    After the text file's first 3 lines are read and converted from text chars to integer values (being sure to throw away the commas separating the numbers as well as whitespace), we allocate memory so that we can store the maze and not have wasted memory. Thus, we are dynamically allocating memory so we do not waste resources. When we read our maze, we are also ignoring whitespace as well, so new lines (\n) are correctly not read into memory, since they are not part of the maze.

    After the memory is created and the maze's X's and 0's are read and stored into memory, we close our file down since we no longer need to read anything from it.

    Next we present a message to the user welcoming them to the program, and indicating we are are about to print the path to the exit, so that they understand what the program does while keeping things simple.

    We mark our entry point with a W to mark it's been walked on, and is apart of our right handed movement strategy to exit the maze, called the Wall Follower Algorithm.

    While we aren't at the exit coordinates, indicated by a integer called finished, which will be flipped to 1 once we match our current coordinates to the exit coordinates, we loop through a series of function calls.


    The function move houses other functions to keep our main function neat and tidy.

    The first thing we must do is offset our initial previous position X coordinate by -1 so that when we do our first orientation check (which direction we face), we get a accurate reading, else we will subtract our current position by a previous position that doesn't exist yet since we haven't stepped, and if we were to set our previous position to our entry position initially, when we attempt to find our orientation, we would receive a orientation and orientation value of 0, which will not help us determine if we moved north our south. Thus, a initial offset of -1 in the X coordinate for our previous Coordinate is necessary to begin with to ensure we get a accurate first reading of our orientation.

    Now the move function begins by finding our orientation, by subtracting our previous XY coordinates from the current one. If we are -1 in the X plane, we stepped west (right), and if it's +1 we stepped east (right). The same goes for the Y plane; -1 indicates we moved north (up), and +1 indicates we stepped south (down).

    Next we update a value called direction to be 1=We stepped North, 2=We stepped south, 3= We stepped East and 4=We stepped West. This is very important, since the direction indicates our movement rules using the right handled wall follower algorithm, and dictates which directions we out to attempt to move in a certain order first.

    Then we update our previous coordinates so that we can continue to obtain accurate readings.
    Depending on the direction we last moved, we check if we can move according to right handled wall follower algorithm, while checking if we will hit a wall, or go outside of the bounds of our maze. If all is good, we take a step, and mark the path as walked upon, and update or current coordinates. Then, we check if we are at the exit point.

    After these steps, if we are not at the exit, we loop again and follow the algorithm to attempt to find the exit once again.


    Once we find the exit, we print our maze which will show our walked path towards the exit.Please note, I initially attempted to mark the maze so that ONLY the true path towards the exit would be shown (thus dead ends would revert back to 0's if they didn't lead to the exit), which worked, except at intersections. Thus, our program will print every step taken, regardless if a step leads to a dead end. This is good although, since it will indicate that our algorithm truly was stepping in the correct procedure.

    The last thing we do is free up our memory and return it to the system to prevent memory leaks. We checked this using valgrind and GDB. Current indications from valgrind state that there is no memory leaks present in our program.



HOW TO RUN:

1.)First recompile the code by typing the command: make

2.) Next, type the command: ./hw1 easymaze.txt

3.)Replace the previous command's 'easy maze.txt' text with any maze file you would like to load into the program. I've created 4 additional test mazes to test initial movement points going up, going down, going left, and going right to ensure that the program will complete correctly.
4.)Please note that the wall follower algorithm doesn't anticipate a maze which will make our moment go in a circle, since the algorithm will run forever since it doesn't use any logic beyond what the wall follower algorithm is described as. There must not be circle spots, and there must always be a entry point and exit point!

5.) To contact the developer please direct all inquiries to the student Tim Pugh who developed the program without a partner. Thank you! Fun assignment!!


