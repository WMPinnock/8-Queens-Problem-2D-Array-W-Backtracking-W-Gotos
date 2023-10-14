#include <iostream>
using namespace std;

int main() {
  int sol_num = 1;  // Solution counter
  int q[8][8] = {};  // Creating the chessboard
  int r = 0, c = 0;  // Top left of chessboard
  q[r][c] = 1;  // Start by placing the first queen in the upper left corner


nc:  // Next Row
  c++;  // Move to the next column index position
  if(c == 8) {  // If we placed 8 queens
    goto print;  // We found a solution, therefore print
  }
  r = -1;  // Move back up to the top of the row

nr:
 r++;  // Move down a Row
  if(r == 8) {  // If we have moved through all 8 rows
    goto backtrack;  // Backtrack
  };

   // Go through every row at current column from up to down tos ee if this row is a usable position (Where same row and diagonals has no queen)
  // Loops thru every row at current col
  for (int i = 0; i < c; i++) {  // Current Row Check, loops through each column in current row
    if(q[r][i] == 1) {  // If there is a queen in the current row
      goto nr;  // Goto next row code block
    };
  };

  for (int ud = 1; (r - ud) >= 0 && (c - 1) >= 0; ud++) {  // Upper Diagonal Check loops through upper diagonals checking position on if there is a queen in the diagonal using the DIagonal Formula
    if(q[r - ud][c - ud] == 1) {  // If there is a queen in the upper diagonal
      goto nr;  // Goto next row code block
    };
  };

  for (int ld = 1; (r + ld) < 8 && (c - ld) >= 0; ld++) {  // Lower DIagonal Check loops through lower diagonals using diagonal formula
    if(q[r + ld][c - ld] == 1) {  // If there is a queen in the lower diagonal
      goto nr;  // Goto next row code block
    };
  };

  q[r][c] = 1;  // If Row Check, Upper Check, and Lower Diagonal check pass, place a Queen down
  goto nc;  // Goto next column code block
  

  
backtrack:
  c--;  // Move vack to the previous column
  r = 0;  // Go back to the first row
  if(c < 0) {  // If c is less than zero, which means we backtracked all possible positions,
    return 0;  // We end the program
  };
  while(q[r][c] != 1) {  // Find the last queen position
    r++;  // Move to the next row
  };
  q[r][c] = 0;  // Remove the last queen position
  goto nr;  // GOto nect row code block

  

print:
  cout << "Solution #: " << sol_num++ << endl;
  
  for (int r = 0; r < 8; r++) {  // For-loop to print a solution
    for (int c = 0; c < 8; c++) {
      cout << q[r][c];
     };
    cout << endl;
    
  };
  goto backtrack;  // Backtrack to look for next solution

  return 0;
}