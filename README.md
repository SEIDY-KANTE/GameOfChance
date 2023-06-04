# GAME OF CHANCE

### MinGw (gcc) A game of chance is designed to be written in C language.
- The people who will play the game will be read from the Person.txt file. There is one person per line and will be in the following format: 
   -  #### Seidy Kante#47624.35#0.58#5
- Equivalents:  
   - #### name/surname # money # How much of his money he deposits in each round # the number of continuous deposits.
- The lucky number (including two between 1 and 10) coming in each round will be read from Numbers.txt respectively.
- If the person reaches the number in the relevant round, he wins 10 times the money he deposited. If he loses, he only loses his money. If the money falls below 1000 TL, it is eliminated from the game. 
- The game continues until all players are eliminated. Winners are paid from the table.
- The table has no money in the beginning. The lucky number, the number of rounds, the amount of money collected on the table and the richest person will be printed on the screen.
## IMPORTANT: 
- ### It is designed by emulating object-oriented and paying attention to modular programming.
 
> ## Note :
> - ### Please put the Person.txt and Numbers.txt files in the same place as the makefile, just like I did.
> - ### Use the mingw32-make command to run the program in cmd. (Note where the program is located).

## Folder Hierarchy:
##### In order to easily access my files, I have created a folder hierarchy according to the required file format in this assignment:
- ➔ In the 'include' folder: Person.h, Game.h, and File.h can be found.
- ➔ In the 'src' folder: Person.c, Game.c, File.c, and Test.c are located.
- ➔ In the 'lib' folder: Person.o, Game.o, and File.o can be found.
- ➔ In the 'bin' folder: Main.exe is located.
- ➔ 'Person.txt' file stores the information of the players for the game.
- ➔ 'Nummbers.txt' file holds the lucky numbers.
- And the 'makefile' is an extensionless file that facilitates running my program with Mingw
