# Lecture 6: Nested Loops, Functions, and Modular Programming

**Course:** Programming Logic and Design  
**Language:** C

Programs often repeat operations at multiple levels, such as processing several quizzes for each student. As programs grow, functions help organize those operations into smaller, reusable parts.

This lecture covers:

- Nested loops and their execution.
- Function declarations, definitions, and calls.
- Parameters, return values, scope, and pass-by-value.
- Organizing a complete program using functions.

---

## 1. Nested Loops

A nested loop is a loop placed inside another loop.

For each iteration of the outer loop, the inner loop executes according to its own initialization, condition, and update.

### Example: Printing Rows and Columns

```c
#include <stdio.h>

int main(void)
{
    for (int row = 1; row <= 3; row++)
    {
        for (int column = 1; column <= 4; column++)
        {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}
```

**Output:**

```text
* * * *
* * * *
* * * *
```

The outer loop controls the three rows. The inner loop prints four symbols per row.

The newline is outside the inner loop because it should execute after a complete row.

### Execution Count

The symbol-printing statement executes:

```text
3 outer iterations × 4 inner iterations = 12 times
```

The newline executes three times.

The position of a statement determines how frequently it runs.

---

## 2. An Inner Loop Can Depend on the Outer Loop

The inner loop does not always perform the same number of iterations.

```c
for (int row = 1; row <= 4; row++)
{
    for (int column = 1; column <= row; column++)
    {
        printf("%d ", column);
    }

    printf("\n");
}
```

**Output:**

```text
1
1 2
1 2 3
1 2 3 4
```

| Value of `row` | Inner-loop iterations |
| -------------: | --------------------: |
|              1 |                     1 |
|              2 |                     2 |
|              3 |                     3 |
|              4 |                     4 |

The inner statement executes `1 + 2 + 3 + 4 = 10` times.

### Example: Multiplication Grid

```c
for (int row = 1; row <= 3; row++)
{
    for (int column = 1; column <= 4; column++)
    {
        printf("%4d", row * column);
    }

    printf("\n");
}
```

**Output:**

```text
   1   2   3   4
   2   4   6   8
   3   6   9  12
```

`%4d` uses a minimum field width of four characters to align the integers. It does not change their values.

---

## 3. Nested Loops for Related Data

Suppose three students each have two quiz scores.

```c
for (int student = 1; student <= 3; student++)
{
    double studentTotal = 0.0;

    for (int quiz = 1; quiz <= 2; quiz++)
    {
        double score;

        printf("Student %d, quiz %d: ", student, quiz);
        scanf("%lf", &score);

        studentTotal += score;
    }

    printf("Student %d average: %.2f\n",
           student, studentTotal / 2);
}
```

The outer loop selects the student. The inner loop processes that student’s quizzes.

### Initializing Accumulators

`studentTotal` is initialized inside the outer loop but before the inner loop.

- Before the outer loop: the total would carry over between students.
- Inside the inner loop: the total would reset before every score.
- Inside the outer loop, before the inner loop: each student begins with zero.

> Initialize a variable where a new independent calculation begins.

A class-wide total belongs before the student loop. A student-specific total belongs inside it.

### `break` and `continue`

In nested loops, these statements affect only the nearest enclosing loop:

- `break` exits that loop.
- `continue` skips the remaining statements in its current iteration.

A `break` inside the quiz loop does not automatically exit the student loop.

---

## 4. Functions

A function is a named block of code that performs an operation. It can receive values, perform work, and return a result.

### Complete Example

```c
#include <stdio.h>

double calculateArea(double length, double width);

int main(void)
{
    double area = calculateArea(5.0, 3.0);

    printf("Area: %.2f\n", area);

    return 0;
}

double calculateArea(double length, double width)
{
    return length * width;
}
```

**Output:**

```text
Area: 15.00
```

### Function Prototype

```c
double calculateArea(double length, double width);
```

The prototype declares the function’s name, return type, and parameter types before it is called.

It ends with a semicolon.

### Function Call

```c
area = calculateArea(5.0, 3.0);
```

The call executes the function. Its returned value is assigned to `area`.

### Function Definition

```c
double calculateArea(double length, double width)
{
    return length * width;
}
```

The definition contains the implementation.

A function definition may appear before `main()`, making a separate prototype unnecessary. A common organization is to place prototypes above `main()` and definitions below it.

---

## 5. Parameters and Arguments

**Parameters** are variables declared by a function to receive values.

```c
double calculateArea(double length, double width)
```

Here, `length` and `width` are parameters.

**Arguments** are values supplied when calling the function.

```c
calculateArea(5.0, 3.0);
```

Here, `5.0` and `3.0` are arguments.

Arguments can also be variables or expressions:

```c
double roomLength = 8.0;
double roomWidth = 4.0;

double area = calculateArea(roomLength, roomWidth);
```

Arguments match parameters by position, not by variable name.

```c
double subtract(double first, double second)
{
    return first - second;
}
```

```c
subtract(10.0, 4.0);  /* Returns 6.0 */
subtract(4.0, 10.0);  /* Returns -6.0 */
```

---

## 6. Return Values and `void`

The return type identifies the kind of value a function gives back.

```c
int getLarger(int first, int second)
{
    if (first > second)
    {
        return first;
    }

    return second;
}
```

A `return` statement immediately ends the current function call.

When `first > second` is true, the function returns `first`; it does not execute the later return statement.

Every reachable path through a value-returning function should return an appropriate value.

### Returning Is Different from Printing

```c
double calculateTotal(double price, int quantity)
{
    return price * quantity;
}
```

The caller can store, compare, print, or otherwise use the result:

```c
double total = calculateTotal(25.0, 4);

if (total >= 100.0)
{
    printf("Minimum purchase reached.\n");
}
```

A display function can instead return nothing:

```c
void displayTotal(double total)
{
    printf("Total: PHP %.2f\n", total);
}
```

As a return type, `void` means no value is returned. In a parameter list, `(void)` means no parameters are accepted.

### Common Function Forms

| Form                           | Example                                             |
| ------------------------------ | --------------------------------------------------- |
| No parameters, no return value | `void displayMenu(void);`                           |
| Parameters, no return value    | `void displayResult(double result);`                |
| No parameters, returns a value | `int readChoice(void);`                             |
| Parameters, returns a value    | `double calculateAverage(double total, int count);` |

Choose the form according to the operation’s purpose.

---

## 7. Variable Scope

Scope determines where a variable’s name can be used.

Variables and parameters declared inside a function are local to it.

```c
double calculateAverage(double total, int count)
{
    double average = total / count;
    return average;
}
```

`main()` cannot directly access this function’s local variable `average`. It obtains the result through the return value:

```c
double studentAverage = calculateAverage(240.0, 3);
```

Variables can also belong to smaller blocks:

```c
if (studentAverage >= 75.0)
{
    int passed = 1;
}

/* passed cannot be used here */
```

Prefer local variables, parameters, and return values over global variables. This makes it easier to identify which part of the program owns and changes a value.

---

## 8. Pass-by-Value

C passes arguments by value: each parameter receives a copy of the supplied value.

```c
#include <stdio.h>

void changeNumber(int number);

int main(void)
{
    int value = 10;

    changeNumber(value);

    printf("In main: %d\n", value);

    return 0;
}

void changeNumber(int number)
{
    number = 50;
    printf("Inside function: %d\n", number);
}
```

**Output:**

```text
Inside function: 50
In main: 10
```

Changing `number` does not change `value`.

To update a caller’s variable without introducing pointers, return the new value and assign it:

```c
int addFive(int number)
{
    return number + 5;
}
```

```c
value = addFive(value);
```

Calling `addFive(value);` without using its return value leaves `value` unchanged.

---

## 9. Modular Programming

Modular programming organizes a program into operations with clear responsibilities.

For a score-processing program, separate functions can:

- Read a valid integer.
- Read a valid score.
- Calculate an average.
- Display a student’s result.

`main()` coordinates these operations.

### Designing Useful Functions

A useful function has:

1. A clear responsibility.
2. Defined inputs.
3. A defined result or action.
4. Limited dependence on unrelated variables.

For example:

```c
double calculateAverage(double total, int count);
```

This function calculates an average and requires `count` to be greater than zero. It should not also display menus, collect student information, and reset class totals.

### Modular Does Not Necessarily Mean Multiple Files

A program can be modular while all functions remain in one `.c` file.

Larger projects may place related definitions in separate source files and declarations in header files. The first priority is learning to separate responsibilities and pass information correctly.

---

## 10. Worked Problem: Class Quiz Summary

### Problem

Create a program that accepts:

- Number of students: `1–10`.
- Quizzes per student: `1–5`.
- Each quiz score: `0–100`, including decimal values.

Display each student’s average and passing or failing result. The passing average is `75`.

After processing everyone, display the class average and the numbers who passed and failed.

Invalid values must be re-entered without advancing to the next student or quiz.

Assume users enter the requested numeric type. Handling nonnumeric input is outside this example.

### Program Organization

| Function                 | Responsibility                            |
| ------------------------ | ----------------------------------------- |
| `readIntInRange()`       | Read and validate an integer              |
| `readScore()`            | Read and validate one score               |
| `calculateAverage()`     | Return an average                         |
| `displayStudentResult()` | Display one student’s result              |
| `main()`                 | Coordinate processing and maintain totals |

### Complete Program

```c
#include <stdio.h>

int readIntInRange(int minimum, int maximum);
double readScore(void);
double calculateAverage(double total, int count);
void displayStudentResult(int studentNumber, double average);

int main(void)
{
    int studentCount;
    int quizCount;
    int passedCount = 0;
    double classTotal = 0.0;

    printf("Number of students (1-10): ");
    studentCount = readIntInRange(1, 10);

    printf("Quizzes per student (1-5): ");
    quizCount = readIntInRange(1, 5);

    for (int student = 1; student <= studentCount; student++)
    {
        double studentTotal = 0.0;

        printf("\nSTUDENT %d\n", student);

        for (int quiz = 1; quiz <= quizCount; quiz++)
        {
            double score;

            printf("Quiz %d score (0-100): ", quiz);
            score = readScore();

            studentTotal += score;
        }

        double studentAverage =
            calculateAverage(studentTotal, quizCount);

        displayStudentResult(student, studentAverage);

        classTotal += studentTotal;

        if (studentAverage >= 75.0)
        {
            passedCount++;
        }
    }

    int totalScores = studentCount * quizCount;
    int failedCount = studentCount - passedCount;

    double classAverage =
        calculateAverage(classTotal, totalScores);

    printf("\nCLASS SUMMARY\n");
    printf("Students processed: %d\n", studentCount);
    printf("Class average: %.2f\n", classAverage);
    printf("Passed: %d\n", passedCount);
    printf("Failed: %d\n", failedCount);

    return 0;
}

int readIntInRange(int minimum, int maximum)
{
    int value;

    do
    {
        scanf("%d", &value);

        if (value < minimum || value > maximum)
        {
            printf("Enter a value from %d to %d: ",
                   minimum, maximum);
        }

    } while (value < minimum || value > maximum);

    return value;
}

double readScore(void)
{
    double score;

    do
    {
        scanf("%lf", &score);

        if (score < 0.0 || score > 100.0)
        {
            printf("Invalid score. Enter a value from 0 to 100: ");
        }

    } while (score < 0.0 || score > 100.0);

    return score;
}

double calculateAverage(double total, int count)
{
    return total / count;
}

void displayStudentResult(int studentNumber, double average)
{
    printf("Student %d average: %.2f\n",
           studentNumber, average);

    if (average >= 75.0)
    {
        printf("Result: Passed\n");
    }
    else
    {
        printf("Result: Failed\n");
    }
}
```

The program uses C99-or-later declaration syntax.

### Sample Run

```text
Number of students (1-10): 2
Quizzes per student (1-5): 3

STUDENT 1
Quiz 1 score (0-100): 80
Quiz 2 score (0-100): 90
Quiz 3 score (0-100): 100
Student 1 average: 90.00
Result: Passed

STUDENT 2
Quiz 1 score (0-100): 60
Quiz 2 score (0-100): 120
Invalid score. Enter a value from 0 to 100: 70
Quiz 3 score (0-100): 80
Student 2 average: 70.00
Result: Failed

CLASS SUMMARY
Students processed: 2
Class average: 80.00
Passed: 1
Failed: 1
```

### Important Design Decisions

**Validation does not consume a quiz.**  
`readScore()` returns only after receiving a valid score. The quiz loop does not advance while the function requests a replacement.

**Student totals reset; class totals accumulate.**  
`studentTotal` starts at zero for each student. `classTotal` remains available throughout processing.

**One calculation function is reused.**  
`calculateAverage()` calculates both student and class averages. Its arguments determine which calculation it performs.

**The divisor is always positive.**  
Validated student and quiz counts prevent division by zero.

**Formatting does not change classification.**  
The program compares the calculated average with `75.0`. `%.2f` affects only the displayed form.

---

## 11. Common Errors

| Error                                              | Effect                                   | Correction                                         |
| -------------------------------------------------- | ---------------------------------------- | -------------------------------------------------- |
| Changing the outer counter inside the inner loop   | Skipped or incorrect iterations          | Use separate counters                              |
| Resetting a student total inside the quiz loop     | Earlier scores are lost                  | Reset before the student’s quiz loop               |
| Printing a newline inside the column loop          | Every value appears on a new line        | Print after the inner loop                         |
| Writing `int readChoice;`                          | Declares a variable                      | Use `int readChoice(void);`                        |
| Writing `displayMenu;`                             | Does not call the function               | Use `displayMenu();`                               |
| Printing instead of returning a calculation result | Caller cannot use the result as intended | Return the value                                   |
| Ignoring a returned value                          | Caller’s variable remains unchanged      | Store or use the returned value                    |
| Defining a function inside `main()`                | Invalid in standard C                    | Define functions outside other functions           |
| Missing a return on a reachable path               | No reliable result is supplied           | Return an appropriate value on every relevant path |

---

## 12. Testing the Worked Program

| Test                           | Expected behavior                            |
| ------------------------------ | -------------------------------------------- |
| One student, one score of `75` | Average `75.00`; passed                      |
| One student, one score of `0`  | Average `0.00`; failed                       |
| Score `100`                    | Accepted                                     |
| Score `-1` or `101`            | Rejected; same quiz requested again          |
| Student count `0` or `11`      | Rejected                                     |
| Students with different scores | Each average uses only that student’s scores |
| All students pass              | Failed count is zero                         |
| All students fail              | Passed count is zero                         |

Nested loops determine which operations repeat. Functions define the operations performed. Modular organization makes those operations easier to understand, test, and reuse.
