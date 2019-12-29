# Flatulan City

This project was developed in XCode, and is therefore only guaranteed to run in a MacOS environment. However, it should be fairly straightforward to build an executable from the provided files in any environment that supports C++.


Flatulan City is a text-based game. It has a grid, which is filled with one of the following characters:

  '.':    empty space
  
  '@':    your avatar
  
  'F':    flatulan city citizen
  
  '2-9':  when more than one citizen occupies the same spot, a number from 2-9 represents how many citizens occupy that space


The dimensions of the grid and how many citizens are in it are defined in the constants at the top of the main.cpp file; you may edit these numbers as you please.


The objective of the game is to convert all of the citizens to a healthier diet; one that will not result in gassy citizens. In order to accomplish this, utilize the following controls:

  'u':      move your avatar up one space
  
  'd':      move your avatar down one space
  
  'l':      move your avatar left one space
  
  'r':      move your avatar right one space
  
  'ENTER':  attempt to conver the citizens in the surrounding 8 places (less than 8 if you are against a wall). If the conversion is succesful, that citizen is no longer troublesome and is therefore removed from the grid.
  
  'h':      display the history of unconverted citizens. This will display a grid of equal dimensions that is filled with '.' or a capital letter which indicates the number of unsuccesful conversions at that place (A=1, B=2, ..., Z=26).
  
  'q':      quit the game


While you can control your movements, the citizens are erratic and blow gas at each move; a health point will be deducted for every citizen you find yourself orthogonal to. You start the game with 10 health points, however, this can be adjusted by changing the 'INITIAL_PLAYER_HEALTH' constant in the file 'globals.h'.


To build and run the game, open the XCode Project provided and press the play button in the top left corner. In order for this to work, make sure that all of the provided files, except for the XCode file, are inside the same directory, which is in turn inside of the same directory as the XCode Project.
