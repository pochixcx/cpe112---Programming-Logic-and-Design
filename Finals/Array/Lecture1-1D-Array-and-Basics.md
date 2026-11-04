# Arrays I: One-Dimensional Arrays and Basics

**Course:** Programming Logic and Design  
**Language:** C

## Learning Objectives

After studying this lecture, the student should be able to:

1. Explain why an array is needed to store a collection of related values.
2. Declare and initialize one-dimensional arrays of an appropriate type and size.
3. Access and modify array elements using indices.
4. Trace loops that traverse an array.
5. Implement common array operations: input, output, sum, average, maximum, minimum, and linear search.
6. Pass an array to a function and explain how the function can modify the caller's array.
7. Identify and correct out-of-bounds access and related common errors.

**Prior knowledge assumed:** variables, data types, `printf`/`scanf`, selection statements, loops, and basic functions.

---

## 1. Introduction

Suppose a program must process the scores of 30 students. With only the tools covered so far, the program would need 30 separate variables (`score1`, `score2`, ..., `score30`). Computing an average would require writing all 30 names, and changing the class size would require rewriting the program.

An **array** solves this problem. It stores many values of the same type under one name, and a loop can then process every value.

| Without arrays | With an array |
| -------------- | ------------- |
| One variable name per value | One name for the whole collection |
| Loops cannot select "the next variable" | Loops select elements by position |
| Size changes require rewriting code | Size changes require changing one constant |

---

## 2. What Is an Array?

An **array** is a fixed-size collection of elements of the same data type stored in consecutive memory locations.

Three properties define it:

- **Homogeneous:** every element has the same type.
- **Fixed size:** the number of elements is decided when the array is declared and cannot change afterward.
- **Indexed:** each element is identified by an integer **index** (position number).

In C, indices start at **0**. An array with `n` elements has valid indices `0` through `n - 1`.

```text
int scores[5] = {85, 90, 78, 92, 88};

index:     0     1     2     3     4
        +-----+-----+-----+-----+-----+
scores  |  85 |  90 |  78 |  92 |  88 |
        +-----+-----+-----+-----+-----+
```

`scores[0]` is the first element (85) and `scores[4]` is the last (88). There is no `scores[5]`.

---

## 3. Declaring an Array

### Syntax

```text
data_type array_name[size];
```

```c
int scores[5];        /* five integers */
double prices[10];    /* ten doubles */
char grades[30];      /* thirty characters */
```

The size must be a positive integer. In this lecture, use a constant so that the size is stated in one place:

```c
#define SIZE 5

int scores[SIZE];
```

`#define SIZE 5` tells the preprocessor to replace `SIZE` with `5` before compilation. Using a named constant makes the code easier to read and to modify.

### Uninitialized Arrays

A local array that is declared but not initialized contains **indeterminate values**: leftover data whose contents cannot be predicted. Never read an element before assigning it.

---

## 4. Initializing an Array

### Initializer List

```c
int scores[5] = {85, 90, 78, 92, 88};
```

### Omitting the Size

If an initializer list is given, the compiler can count the elements:

```c
int scores[] = {85, 90, 78, 92, 88};   /* size is 5 */
```

### Partial Initialization

If the list has fewer values than the size, the remaining elements are set to zero:

```c
int a[5] = {1, 2};     /* 1, 2, 0, 0, 0 */
int b[5] = {0};        /* 0, 0, 0, 0, 0 */
```

This is the standard way to initialize every element to zero.

If the list has *more* values than the size, the compiler reports an error or warning.

---

## 5. Accessing and Modifying Elements

An element is accessed with the array name and an index in square brackets. The index may be a constant, a variable, or an expression that evaluates to an integer.

```c
#include <stdio.h>

int main(void)
{
    int scores[5] = {85, 90, 78, 92, 88};
    int i = 2;

    printf("First: %d\n", scores[0]);
    printf("Third: %d\n", scores[i]);
    printf("Last: %d\n", scores[5 - 1]);

    scores[2] = 80;                       /* replace a value */
    scores[0] = scores[0] + 5;            /* update using its old value */

    printf("scores[2] = %d\n", scores[2]);
    printf("scores[0] = %d\n", scores[0]);

    return 0;
}
```

**Output:**

```text
First: 85
Third: 78
Last: 88
scores[2] = 80
scores[0] = 90
```

Each element behaves like an ordinary variable of the array's type. It can be assigned, printed, used in expressions, and passed to `scanf` with `&`.

> **Terminology:** `scores[2]` is an *element*; the `2` is the *index* (also called a *subscript*). In the declaration `int scores[5]`, the `5` is the *size*, not an index.

---

## 6. Traversing an Array with a Loop

**Traversal** means visiting each element once. A `for` loop with an index running from `0` to `SIZE - 1` is the standard pattern.

```c
for (int i = 0; i < SIZE; i++)
{
    /* use scores[i] */
}
```

The condition is `i < SIZE`, not `i <= SIZE`, because `SIZE` is not a valid index.

### Example: Reading and Displaying Values

**Problem:** Read five integers into an array, then display them.  
**Input:** five integers. **Output:** the stored values with their indices.

```c
#include <stdio.h>

#define SIZE 5

int main(void)
{
    int values[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("\nStored values:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("values[%d] = %d\n", i, values[i]);
    }

    return 0;
}
```

**Sample run (input shown after each prompt):**

```text
Enter value 1: 4
Enter value 2: 8
Enter value 3: 15
Enter value 4: 16
Enter value 5: 23

Stored values:
values[0] = 4
values[1] = 8
values[2] = 15
values[3] = 16
values[4] = 23
```

The prompt shows `i + 1` because people count from 1, while the array index starts at 0. Keeping the two numbering systems distinct avoids many mistakes.

*Assumption:* the user enters valid integers. Input validation is omitted to keep the focus on arrays.

---

## 7. Common Array Operations

Most array algorithms are variations of traversal. Each uses an **accumulator** or **tracking variable** that is updated as the loop visits elements.

### 7.1 Sum and Average

Initialize the accumulator to `0` before the loop, then add each element.

```c
int sum = 0;
for (int i = 0; i < SIZE; i++)
{
    sum += values[i];
}
double average = (double)sum / SIZE;
```

The cast `(double)sum` is required. Without it, `sum / SIZE` is integer division, which discards the fractional part (for example, `7 / 2` yields `3`, not `3.5`).

### 7.2 Maximum and Minimum

Start by assuming the first element is the maximum, then compare it with the rest.

```c
int max = values[0];
for (int i = 1; i < SIZE; i++)
{
    if (values[i] > max)
    {
        max = values[i];
    }
}
```

The loop starts at `1` because `values[0]` has already been used as the initial value. Initializing `max` to `0` would be incorrect when all values are negative.

**Trace** for `values = {4, 9, 2, 7, 5}`:

| `i` | `values[i]` | `values[i] > max`? | `max` after step |
| :-: | :---------: | :----------------: | :--------------: |
| (start) | | | 4 |
| 1 | 9 | yes | 9 |
| 2 | 2 | no | 9 |
| 3 | 7 | no | 9 |
| 4 | 5 | no | 9 |

The minimum uses the same pattern with `<`.

To find the *position* of the maximum rather than its value, store the index:

```c
int maxIndex = 0;
for (int i = 1; i < SIZE; i++)
{
    if (values[i] > values[maxIndex])
    {
        maxIndex = i;
    }
}
```

### 7.3 Linear Search

**Linear search** checks each element in order until the target is found or the array ends.

```c
int found = -1;                     /* -1 means "not found" */
for (int i = 0; i < SIZE; i++)
{
    if (values[i] == target)
    {
        found = i;
        break;
    }
}
```

`-1` is used as the "not found" signal because it can never be a valid index. The `break` statement stops the loop at the first match. In the worst case (target absent or last), all `SIZE` elements are checked.

### 7.4 Counting Elements That Satisfy a Condition

```c
int passed = 0;
for (int i = 0; i < SIZE; i++)
{
    if (scores[i] >= 75)
    {
        passed++;
    }
}
```

### 7.5 Reversing an Array in Place

Swap the first element with the last, the second with the second-to-last, and so on, stopping at the middle.

```c
for (int i = 0; i < SIZE / 2; i++)
{
    int temp = values[i];
    values[i] = values[SIZE - 1 - i];
    values[SIZE - 1 - i] = temp;
}
```

A temporary variable is needed so that one value is not overwritten before it is saved. Looping all the way to `SIZE` would swap every pair twice and restore the original order.

| Before | After |
| :----: | :---: |
| 1 2 3 4 5 | 5 4 3 2 1 |

For an odd size, the middle element stays in place, which is correct. (`5 / 2` is `2`, so the pairs swapped are indices 0↔4 and 1↔3.)

---

## 8. Array Bounds

C does **not** check whether an index is valid. Accessing `scores[5]` in a five-element array, or `scores[-1]`, usually compiles and is **undefined behavior**: the program may crash, produce wrong results, or appear to work. The result cannot be predicted, and it may differ between runs or compilers.

**Incorrect:**

```c
int scores[5] = {85, 90, 78, 92, 88};

for (int i = 0; i <= 5; i++)           /* wrong: i reaches 5 */
{
    printf("%d\n", scores[i]);         /* scores[5] is out of bounds */
}
```

**Correct:**

```c
for (int i = 0; i < 5; i++)
{
    printf("%d\n", scores[i]);
}
```

The programmer is responsible for keeping every index in the range `0` to `size - 1`. When an index comes from user input, check it before use:

```c
if (index >= 0 && index < SIZE)
{
    printf("%d\n", scores[index]);
}
else
{
    printf("Invalid index.\n");
}
```

---

## 9. Other Rules to Remember

### Arrays Cannot Be Assigned or Compared as a Whole

```c
int a[3] = {1, 2, 3};
int b[3];

b = a;           /* incorrect: compile-time error */
if (a == b) { }  /* incorrect in intent: compares addresses, not contents */
```

To copy or compare arrays, use a loop over the elements.

```c
for (int i = 0; i < 3; i++)
{
    b[i] = a[i];
}
```

### Finding the Number of Elements

`sizeof` gives the size in bytes. Dividing the total size of the array by the size of one element gives the element count:

```c
int n = sizeof(scores) / sizeof(scores[0]);
```

This works only where the array was declared (not inside a function that received it as a parameter; see Section 10). The result has type `size_t`, so assigning it to `int` is acceptable for small arrays.

---

## 10. Passing Arrays to Functions

A function can process an array if it receives the array and its size.

```c
void printArray(const int arr[], int size);
```

At the call, only the array's name is written:

```c
printArray(scores, SIZE);
```

### Arrays Are Not Copied

With ordinary variables, a function receives a **copy** of the value, so changes inside the function do not affect the caller. Arrays behave differently: the function receives the **address of the first element**, not a copy of the elements. Therefore, **changes made to `arr[i]` inside the function change the caller's array**.

Because the function receives only an address, it has no way to know the array's length. The size must be passed as a separate argument, and `sizeof(arr)` inside the function does not give the array's size.

### Protecting an Array with `const`

When a function only reads the array, mark the parameter `const`. The compiler then rejects any attempt to modify the elements.

### Example: Functions That Read and Modify an Array

```c
#include <stdio.h>

#define SIZE 5

void printArray(const int arr[], int size);
int sumArray(const int arr[], int size);
void addBonus(int arr[], int size, int bonus);

int main(void)
{
    int scores[SIZE] = {70, 85, 90, 60, 75};

    printf("Before: ");
    printArray(scores, SIZE);
    printf("Sum: %d\n", sumArray(scores, SIZE));

    addBonus(scores, SIZE, 5);

    printf("After:  ");
    printArray(scores, SIZE);
    printf("Sum: %d\n", sumArray(scores, SIZE));

    return 0;
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumArray(const int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void addBonus(int arr[], int size, int bonus)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] += bonus;
    }
}
```

**Output** (each array line ends with a trailing space):

```text
Before: 70 85 90 60 75 
Sum: 380
After:  75 90 95 65 80 
Sum: 405
```

`addBonus` returns nothing, yet `scores` in `main` has changed, because `arr` refers to the same memory as `scores`. `sumArray` and `printArray` only read, so they use `const`.

---

## 11. Worked Example: Quiz Score Analysis

**Problem:** A teacher records the scores of eight students on a 50-point quiz. Determine the average score, the highest and lowest scores, and how many students scored at or above the average. Also let the teacher search for a particular score and report where it first appears.

**Inputs:** eight integer scores (0 to 50) and a score to search for.  
**Outputs:** average (two decimal places), highest, lowest, count at or above average, and the position of the searched score.

**Assumptions:** the user enters integers from 0 to 50. Positions are reported starting at 1 for readability.

**Algorithm (pseudocode):**

```text
read 8 scores into array
sum <- 0; max <- scores[0]; min <- scores[0]
for each score:
    add it to sum
    update max and min
average <- sum / 8
count <- number of scores >= average
read target
search the array for target
display results
```

**Program:**

```c
#include <stdio.h>

#define SIZE 8

int main(void)
{
    int scores[SIZE];
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter score of student %d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    int max = scores[0];
    int min = scores[0];

    for (int i = 0; i < SIZE; i++)
    {
        sum += scores[i];

        if (scores[i] > max)
        {
            max = scores[i];
        }
        if (scores[i] < min)
        {
            min = scores[i];
        }
    }

    double average = (double)sum / SIZE;

    int atOrAbove = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (scores[i] >= average)
        {
            atOrAbove++;
        }
    }

    int target;
    printf("Score to search for: ");
    scanf("%d", &target);

    int position = -1;
    for (int i = 0; i < SIZE; i++)
    {
        if (scores[i] == target)
        {
            position = i + 1;
            break;
        }
    }

    printf("\nAverage: %.2f\n", average);
    printf("Highest: %d\n", max);
    printf("Lowest: %d\n", min);
    printf("At or above average: %d\n", atOrAbove);

    if (position != -1)
    {
        printf("Score %d first appears at position %d.\n", target, position);
    }
    else
    {
        printf("Score %d was not found.\n", target);
    }

    return 0;
}
```

**Sample run:**

```text
Enter score of student 1: 42
Enter score of student 2: 35
Enter score of student 3: 48
Enter score of student 4: 29
Enter score of student 5: 35
Enter score of student 6: 50
Enter score of student 7: 38
Enter score of student 8: 41
Score to search for: 35

Average: 39.75
Highest: 50
Lowest: 29
At or above average: 4
Score 35 first appears at position 2.
```

**Verification:** the sum is 42 + 35 + 48 + 29 + 35 + 50 + 38 + 41 = 318, and 318 / 8 = 39.75. The scores at or above 39.75 are 42, 48, 50, and 41, so the count is 4. The value 35 appears at positions 2 and 5; the search stops at the first.

**Design notes:**

- The array is required because the scores must be examined more than once: first to find the average, then again to count scores relative to it. A running total alone could not support the second pass.
- `average` is a `double`, so the comparison `scores[i] >= average` is made without losing the fractional part.
- `position` is initialized to `-1`, a value no real position can take, so it distinguishes "found" from "not found".

---

## 12. Common Mistakes

| Mistake | Problem | Correction |
| ------- | ------- | ---------- |
| `for (i = 0; i <= SIZE; i++)` | Reads or writes one element past the end (undefined behavior) | Use `i < SIZE` |
| Believing the first element is `a[1]` | Skips the first element and overruns the last | The first element is `a[0]` |
| Reading elements of an uninitialized array | Indeterminate values | Initialize or assign before use |
| `sum / SIZE` with integer `sum` | Integer division drops the fraction | Use `(double)sum / SIZE` |
| Initializing `max` to `0` | Wrong when all values are negative | Initialize to `values[0]` |
| `b = a;` to copy an array | Not allowed | Copy element by element |
| Using `sizeof(arr)` inside a function to count elements | Gives the size of an address, not the array | Pass the size as a parameter |
| `scanf("%d", values[i]);` | Missing `&`; invalid argument | `scanf("%d", &values[i]);` |

---

## Key Takeaways

- An array stores a fixed number of same-type elements under one name, accessed by index.
- Indices run from `0` to `size - 1`; C does not check bounds, and going outside them is undefined behavior.
- A `for` loop from `0` to `size - 1` is the standard traversal; sum, average, extremes, counting, and searching are variations of it.
- Arrays cannot be assigned or compared with `=` or `==`; use loops.
- A function receives the array's address, not a copy, so it can modify the caller's array. Pass the size separately and use `const` for read-only access.
