# CSI2372
# **Final project for C++ CSI2372**

## Playing Dice


In this year’s project, you are asked to program a console game based on a simple games of rolling dice.
The points from a roll are recorded on a score sheet. The goal of the game is to achieve the highest score
overall. Interestingly, the players take turns rolling up to three dice but all players can record the points
for all rolls. The player who rolls the dice can decide to roll one, two or three dice. The dice are colourcoded
red, yellow and blue. The score sheet is organized in a sheared matrix with three rows and five
overlapping columns. The rows are also colour-coded red, yellow and blue. The players can enter points
only in a row if the dice of the corresponding colour was used but the score entered are the points from all
dice rolled, e.g., if the yellow and blue dice was rolled, the points from the yellow and blue dice can be
entered in the yellow or blue row. However, the numbers in each row must strictly increase and in each
overlapping column, no number is allowed to repeat. If a player cannot score his or her own roll of the
dice, it counts as a failed throw. Each failed throw will count as minus 5 points in the final score for the
player. After four failed throws, the game ends. The game also ends if one player has filled all the rows.
The scoring is a mixture between the number of scores entered in each row plus a special bonus for a
filled overlapping column. Completely filled rows are counted differently. Instead of counting the number
of entries, the score of the right-most entry is counted.
This prelude is meant to familiarize yourself with the game and implement a class representing a score
sheet. The score sheet needs 4 rows in our adaption: one row for each colour of dice: red, yellow and
blue, as well as as fourth row for the failed throws. We need a maximum of fourteen columns. The bonus
fields are marked within % while invalid fields are marked XX. Notice that since the scores have a range
form 1-18, we need a space of two characters.


An empty score sheet should look like this:
Player name:
 -------------------------------
Red | % % |XX| % % | | | |
 ----------------------------------
Yellow | | | | | |XX| % % | |
 ----------------------------------
Blue | | % % |XX| | | | % %
 -------------------------------
Failed throws: 
At the end of a game, a score sheet may look like as below:
Player name: Jane Doe Points: 28
 -------------------------------
Red | 2% 3% 6|XX| 9%11%12|13|15|16|
 ----------------------------------
Yellow | 1| 3| 4| 5| |XX|12%13% | |
 ----------------------------------
Blue | 1| 3% % 6|XX| 7| | |10% %
 -------------------------------
Failed throws: 1 2 3

Jane Doe scored 28 points: The red row is complete and hence the right most score is used (16 points).
The yellow row has 6 entries and the blue row has 5 entries. Two bonus columns are completed for an
extra of 3 plus 13 points (the scores in the corresponding fields marked with %) and three failed throws
are recorded at 3 times -5 = -15.
This game is an adaption of the game Qwinto by Bernhard Lach and Uwe Rapp which was published by
Gigamic, Nürnberger-Spielkarten-Verlag and White Goblin Games. You can find an English review at
https://www.boardgamegeek.com/boardgame/183006/qwinto.
Class Design
The class ScoreSheet should hold the scores for the 3 colours, the name of the player, the number of
failed attempts and the overall score. Give the class ScoreSheet a print function that accepts an
std::ostream and inserts the score sheet formatted as in the above example into the stream. You need
to implement and make use of a print function in the structure Dice. Add a constructor that accepts the
name of a player as a std::string. A score should be entered by the function score which accepts a
vector of the structure Dice and the user selected colour and position counted from the left. Colour
should be a scoped enumeration with the values RED, YELLOW and BLUE. The class will be expanded
later in the project. For this prelude, you should focus on printing the score sheet and creating a simple
test driver for your class. The class should be defined in the header scoresheet.h and the methods
in the source file scoresheet.cpp. Implement the test driver as a main routine with the class
ScoreSheet but with a compile switch TEST_SCORESHEET. 
