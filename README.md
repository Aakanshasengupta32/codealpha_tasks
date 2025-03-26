# codealpha_tasks

TASK 1 : CGPA CALCULATOR :
     A **CGPA Calculator** computes the **Cumulative Grade Point Average**, 
     which is the weighted average of grade points earned across all semesters, 
     divided by the total credit hours. 
     It's a quick way for students to track overall academic performance.


TASK 2 : LOGIN AND REGISTRATION SYSTEM :
     A **Login and Registration System** is used for user account management.
     It lets users **register** by creating accounts 
     and **login** by verifying their credentials (username and password), 
     ensuring secure access to an application or website. 
     It typically includes data validation, session management, 
     and protection for sensitive information like passwords.


TASK 3 : SUDOKU SOLVER :
    The code solves a Sudoku puzzle using **backtracking**.
    Here's the logic in brief:
    1. **Find an Empty Cell**: Search for a cell with `0`.
    2. **Try Numbers**: Place numbers `1-9` in that cell.
    3. **Validate**: Use `isSafe` to check if the number is valid (row, column, and 3x3 sub-grid rules).
    4. **Recur or Backtrack**:
   - If valid, recursively solve the next empty cell.
   - If invalid or no solution, reset the cell to `0` (backtrack).

