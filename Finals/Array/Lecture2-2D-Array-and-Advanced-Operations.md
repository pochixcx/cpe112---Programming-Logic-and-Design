# Arrays II: Two-Dimensional Arrays and Operations

**Course:** Programming Logic and Design  
**Language:** C

## Learning Objectives

After studying this lecture, the student should be able to:

1. Explain how a two-dimensional array stores data in rows and columns.
2. Declare, initialize, and access elements of a two-dimensional array.
3. Traverse a two-dimensional array using nested loops.
4. Implement row totals, column totals, and matrix addition.
5. Pass a two-dimensional array to a function.
6. Find the largest value and search for a value in a two-dimensional array.

**Prior knowledge assumed:** one-dimensional arrays, nested loops, and basic functions.

---

## 1. Introduction

A one-dimensional array holds a list. Many kinds of data are tables instead: the scores of several students on several quizzes, or the seats in a classroom. A **two-dimensional (2D) array** holds a table, and each element is identified by two indices: a row and a column.

---

## 2. Two-Dimensional Arrays

### 2.1 Declaration

```text
data_type array_name[rows][columns];
```

```c
#define ROWS 3
#define COLS 4

int grid[ROWS][COLS];     /* 3 rows, 4 columns, 12 elements */
```

`grid[r][c]` is the element in row `r` and column `c`. Indices start at 0, so valid rows are `0` to `ROWS - 1` and valid columns are `0` to `COLS - 1`.

```text
           col 0       col 1       col 2       col 3
row 0   grid[0][0]  grid[0][1]  grid[0][2]  grid[0][3]
row 1   grid[1][0]  grid[1][1]  grid[1][2]  grid[1][3]
row 2   grid[2][0]  grid[2][1]  grid[2][2]  grid[2][3]
```

### 2.2 Initialization

Inner braces group the values of each row:

```c
int m[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

- Missing values are set to zero.
- `int z[2][3] = {0};` sets every element to zero.

### 2.3 Accessing Elements

```c
m[1][2] = 60;                  /* row 1, column 2 */
printf("%d\n", m[0][1]);       /* prints 2 */
```

Write `m[r][c]`, not `m[r, c]`. The second form is valid C but does not mean row `r`, column `c`.

---

## 3. Traversing a Two-Dimensional Array

Use nested loops. The outer loop selects a row; the inner loop moves across its columns.

```c
for (int r = 0; r < ROWS; r++)
{
    for (int c = 0; c < COLS; c++)
    {
        /* use m[r][c] */
    }
}
```

The inner statement runs `ROWS × COLS` times.

### 3.1 Example: Display a Table with Row Totals

```c
#include <stdio.h>

#define ROWS 2
#define COLS 3

int main(void)
{
    int m[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int r = 0; r < ROWS; r++)
    {
        int rowTotal = 0;

        for (int c = 0; c < COLS; c++)
        {
            printf("%4d", m[r][c]);
            rowTotal += m[r][c];
        }

        printf("  | %d\n", rowTotal);
    }

    return 0;
}
```

**Output:**

```text
   1   2   3  | 6
   4   5   6  | 15
```

`rowTotal` is declared inside the outer loop so it restarts at `0` for every row.

### 3.2 Column Totals

For a column total, fix the column and vary the row, so the loops are exchanged:

```c
for (int c = 0; c < COLS; c++)
{
    int colTotal = 0;

    for (int r = 0; r < ROWS; r++)
    {
        colTotal += m[r][c];
    }

    printf("Column %d total: %d\n", c, colTotal);
}
```

For the table above:

```text
Column 0 total: 5
Column 1 total: 7
Column 2 total: 9
```

### 3.3 Reading Input

```c
for (int r = 0; r < ROWS; r++)
{
    for (int c = 0; c < COLS; c++)
    {
        printf("Enter element [%d][%d]: ", r, c);
        scanf("%d", &m[r][c]);
    }
}
```

---

## 4. Matrix Addition

A matrix is a table of numbers, so a 2D array represents it naturally. Two matrices can be added only if they have the same dimensions. Each result element is the sum of the matching elements:

```text
sum[r][c] = a[r][c] + b[r][c]
```

```c
#include <stdio.h>

#define ROWS 2
#define COLS 3

int main(void)
{
    int a[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};
    int b[ROWS][COLS] = {{10, 20, 30}, {40, 50, 60}};
    int sum[ROWS][COLS];

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            sum[r][c] = a[r][c] + b[r][c];
        }
    }

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%4d", sum[r][c]);
        }
        printf("\n");
    }

    return 0;
}
```

**Output:**

```text
  11  22  33
  44  55  66
```

---

## 5. Passing a Two-Dimensional Array to a Function

As with 1D arrays, the function works on the caller's array, not a copy. The function must be told the **number of columns** (written in the parameter); the number of rows is passed separately.

```c
#include <stdio.h>

#define COLS 3

void printTable(int t[][COLS], int rows);

int main(void)
{
    int data[2][COLS] = {{1, 2, 3}, {4, 5, 6}};

    printTable(data, 2);

    return 0;
}

void printTable(int t[][COLS], int rows)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%4d", t[r][c]);
        }
        printf("\n");
    }
}
```

**Output:**

```text
   1   2   3
   4   5   6
```

---

## 6. Finding the Largest Value and Searching

These operations use the same nested loops as totals. They are the 2D versions of the maximum and linear search from the 1D lecture.

- **Largest value:** start with `m[0][0]` as the largest, then compare every element with it. Starting with `0` would be wrong when all values are negative.
- **Search:** visit every element and record the row and column of the first match. A value of `-1` means "not found", because it is never a valid index.

**Problem:** Find the largest value in a 2 × 3 table, and search for the value `8`.

```c
#include <stdio.h>

#define ROWS 2
#define COLS 3

int main(void)
{
    int m[ROWS][COLS] = {
        {4, 9, 2},
        {7, 1, 8}
    };
    int target = 8;

    int max = m[0][0];
    int maxRow = 0;
    int maxCol = 0;
    int foundRow = -1;
    int foundCol = -1;

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (m[r][c] > max)
            {
                max = m[r][c];
                maxRow = r;
                maxCol = c;
            }

            if (foundRow == -1 && m[r][c] == target)
            {
                foundRow = r;
                foundCol = c;
            }
        }
    }

    printf("Largest: %d at row %d, column %d\n", max, maxRow, maxCol);

    if (foundRow != -1)
    {
        printf("%d found at row %d, column %d\n", target, foundRow, foundCol);
    }
    else
    {
        printf("%d not found\n", target);
    }

    return 0;
}
```

**Output:**

```text
Largest: 9 at row 0, column 1
8 found at row 1, column 2
```

The condition `foundRow == -1` is true only until the first match is recorded, so later matches do not replace it.

---

## 7. Worked Example: Quiz Scores Table

**Problem:** Three students took three quizzes. Display each student's total score and the total of each quiz.

**Input:** scores stored in the array at declaration.  
**Output:** the score table with a total at the end of each row, and a final row of quiz totals.

**Design:** each row is a student and each column is a quiz. Row totals fix the row (Section 3.1); column totals fix the column (Section 3.2).

```c
#include <stdio.h>

#define STUDENTS 3
#define QUIZZES 3

int main(void)
{
    int scores[STUDENTS][QUIZZES] = {
        {8, 9, 7},
        {10, 6, 8},
        {5, 7, 9}
    };

    printf("Student  Q1  Q2  Q3  Total\n");

    for (int r = 0; r < STUDENTS; r++)
    {
        int total = 0;

        printf("%7d", r + 1);
        for (int c = 0; c < QUIZZES; c++)
        {
            printf("%4d", scores[r][c]);
            total += scores[r][c];
        }
        printf("%7d\n", total);
    }

    printf("  Total");
    for (int c = 0; c < QUIZZES; c++)
    {
        int colTotal = 0;

        for (int r = 0; r < STUDENTS; r++)
        {
            colTotal += scores[r][c];
        }
        printf("%4d", colTotal);
    }
    printf("\n");

    return 0;
}
```

**Output:**

```text
Student  Q1  Q2  Q3  Total
      1   8   9   7     24
      2  10   6   8     24
      3   5   7   9     21
  Total  23  22  24
```

**Check:** 8 + 9 + 7 = 24, 10 + 6 + 8 = 24, 5 + 7 + 9 = 21; quiz 1: 8 + 10 + 5 = 23, quiz 2: 9 + 6 + 7 = 22, quiz 3: 7 + 8 + 9 = 24.

---

## 8. Common Mistakes

| Mistake | Problem | Correction |
| ------- | ------- | ---------- |
| `m[r, c]` | Not a 2D access | `m[r][c]` |
| Using `COLS` for the row loop (or the reverse) | Out-of-bounds access | Rows use `ROWS`; columns use `COLS` |
| Declaring a total before the outer loop | The total carries over between rows | Declare it inside the outer loop |
| Omitting the column size in a function parameter | Compile-time error | `int t[][COLS]` |
| Adding matrices of different sizes | Not defined | Check that dimensions match |
| Starting a maximum at `0` | Wrong when all values are negative | Start from `m[0][0]` |

---

## Key Takeaways

- A 2D array stores a table; `a[r][c]` is row `r`, column `c`, and nested loops traverse it.
- Row totals fix the row in the outer loop; column totals exchange the loops. Reset a total at the right loop level.
- Matrix addition adds matching elements of same-sized matrices.
- A function that receives a 2D array needs its column size.
- Finding the largest value or searching a table uses the same nested loops as totals.
