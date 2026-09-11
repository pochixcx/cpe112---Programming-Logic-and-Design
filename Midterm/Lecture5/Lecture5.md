# Programming Logic and Design

## Lecture 5: Conditional Statements and Loops in C

> **Main idea:** Conditional statements let a program choose an action. Loops let it repeat an action efficiently.

---

## Learning Outcomes

At the end of this lecture, students should be able to:

1. Construct conditions using relational and logical operators.
2. Use `if`, `if-else`, `else-if`, and nested conditions.
3. Use `switch` for appropriate menu-style choices.
4. Explain initialization, condition, body, and update in a loop.
5. Use `while`, `do-while`, and `for` loops.
6. Apply counters, accumulators, input validation, and sentinel values.
7. Trace conditions and loops and identify common logic errors.

---

# 1. First Look: Programs That Decide and Repeat

Before studying the formal syntax, examine two small C programs. Focus first on what each program does. The individual parts will be explained throughout the lecture.

## Preview A: A program that decides

```c
#include <stdio.h>

int main(void)
{
    int batteryLevel = 15;

    if (batteryLevel < 20)
    {
        printf("Low battery. Please charge the device.\n");
    }

    return 0;
}
```

Because `15 < 20` is true, the program displays a warning. This is **selection**: the program decides whether an action should happen.

## Preview B: A program that repeats

```c
#include <stdio.h>

int main(void)
{
    int count;

    for (count = 1; count <= 3; count++)
    {
        printf("System check %d complete.\n", count);
    }

    return 0;
}
```

Output:

```text
System check 1 complete.
System check 2 complete.
System check 3 complete.
```

This is **repetition**: one instruction is executed several times without copying the same `printf` statement.

Earlier programs followed a straight sequence:

```text
Input -> Calculate -> Display
```

Real programs also need to choose and repeat:

```text
Control structure
- Selection: choose an action
- Repetition: repeat an action
```

Examples include deciding whether a student passed, repeating a menu, validating input, and processing several scores.

---

# Part I: Conditional Statements

# 2. Conditions

A **condition** is an expression evaluated as true or false.

```c
grade >= 70
temperature > 30
balance >= amount
(age >= 18) && hasValidID
```

In C, `0` represents false and a nonzero value represents true.

## Seeing true and false in C

The following program prints the result of two conditions:

```c
#include <stdio.h>

int main(void)
{
    int age = 19;

    printf("Is age at least 18? %d\n", age >= 18);
    printf("Is age below 18? %d\n", age < 18);

    return 0;
}
```

Output:

```text
Is age at least 18? 1
Is age below 18? 0
```

The first condition is true, so C produces `1`. The second condition is false, so C produces `0`.

## Operators used in conditions

| Operator | Meaning                  | Example               |
| -------- | ------------------------ | --------------------- |
| `==`     | Equal to                 | `choice == 1`         |
| `!=`     | Not equal to             | `choice != 0`         |
| `>`      | Greater than             | `temperature > 30`    |
| `<`      | Less than                | `score < 70`          |
| `>=`     | Greater than or equal to | `grade >= 70`         |
| `<=`     | Less than or equal to    | `age <= 12`           |
| `&&`     | Logical AND              | `hasID && isEnrolled` |
| `\|`     | Logical OR               | `isSenior \|\| isPWD` |
| `!`      | Logical NOT              | `!isLocked`           |

Remember that `=` assigns a value, while `==` compares two values.

## Example: Combining two requirements

```c
int age = 19;
int hasValidID = 1;

if ((age >= 18) && (hasValidID == 1))
{
    printf("Entry allowed.\n");
}
```

The message appears only when both requirements are true. This shows how a condition can represent a real rule instead of merely comparing numbers.

---

# 3. The `if` Statement

An `if` statement executes a block only when its condition is true.

```c
if (condition)
{
    statements;
}
```

### Analogy

```text
IF it is raining
    Bring an umbrella
```

If it is not raining, the special action is skipped.

## Example: Temperature warning

```c
float temperature;

printf("Enter temperature: ");
scanf("%f", &temperature);

if (temperature > 30.0f)
{
    printf("Warning: High temperature.\n");
}

printf("Temperature check complete.\n");
```

The last message is always displayed because it is outside the `if` block.

Use braces and indentation to make the controlled block clear.

---

# 4. The `if-else` Statement

`if-else` chooses between two paths. Exactly one block is executed.

```c
if (condition)
{
    statementsWhenTrue;
}
else
{
    statementsWhenFalse;
}
```

## Example: Pass or fail

```c
float grade;

printf("Enter grade: ");
scanf("%f", &grade);

if (grade >= 70.0f)
{
    printf("Passed\n");
}
else
{
    printf("Failed\n");
}
```

The boundary value `70` passes because the condition uses `>=`.

```text
Condition is true  -> Execute the if block   -> Continue
Condition is false -> Execute the else block -> Continue

```

---

# 5. The `else-if` Ladder

An `else-if` ladder selects one path from several categories.

```c
if (grade >= 90.0f)
{
    printf("Excellent\n");
}
else if (grade >= 80.0f)
{
    printf("Very Good\n");
}
else if (grade >= 70.0f)
{
    printf("Passed\n");
}
else
{
    printf("Failed\n");
}
```

Conditions are checked from top to bottom. After the first true condition, the remaining branches are skipped.

## Why order matters

If `grade >= 70` appeared first, a grade of `95` would immediately enter that branch and could never reach `grade >= 90`. For ranges like these, arrange conditions from the highest boundary to the lowest.

---

# 6. Input Validation

Invalid input should be recognized before normal classification.

```c
if ((grade < 0.0f) || (grade > 100.0f))
{
    printf("Invalid grade.\n");
}
else if (grade >= 70.0f)
{
    printf("Passed\n");
}
else
{
    printf("Failed\n");
}
```

The invalid range is checked first so an impossible value is not classified as passed or failed.

---

# 7. Nested Conditions

A **nested condition** is an `if` statement inside another conditional block. It is useful when a second decision depends on the first.

```c
if (hasValidID == 1)
{
    if (isEnrolled == 1)
    {
        printf("Access granted.\n");
    }
    else
    {
        printf("Access denied: Not enrolled.\n");
    }
}
else
{
    printf("Access denied: Invalid ID.\n");
}
```

If only the final result matters, conditions may sometimes be combined:

```c
if ((hasValidID == 1) && (isEnrolled == 1))
{
    printf("Access granted.\n");
}
else
{
    printf("Access denied.\n");
}
```

Use nesting when dependent decisions or different failure messages are needed. Avoid deeply nested code when a simpler condition is clearer.

---

# 8. The `switch` Statement

`switch` selects an action by comparing one expression with several exact values.

```c
switch (choice)
{
    case 1:
        printf("Opening profile...\n");
        break;

    case 2:
        printf("Opening grades...\n");
        break;

    case 3:
        printf("Exiting...\n");
        break;

    default:
        printf("Invalid choice.\n");
}
```

- `case` identifies an exact choice.
- `break` exits the selected case.
- `default` handles unmatched choices.

Use `switch` for exact menu choices. Use `if` and `else-if` for ranges or compound conditions.

---

# Part II: Loops

# 9. Why Programs Need Loops

A **loop** repeats a statement or block of statements.

Without a loop:

```c
printf("Welcome!\n");
printf("Welcome!\n");
printf("Welcome!\n");
```

With a loop:

```c
for (int count = 1; count <= 3; count++)
{
    printf("Welcome!\n");
}
```

### Analogy

When checking attendance, a teacher repeats the same process for each student: read a name, record a status, and continue until all names are checked.

---

# 10. Four Parts of a Loop

| Part           | Purpose                    | Example       |
| -------------- | -------------------------- | ------------- |
| Initialization | Set the starting value     | `count = 1`   |
| Condition      | Decide whether to continue | `count <= 5`  |
| Body           | Perform the repeated work  | `printf(...)` |
| Update         | Move toward completion     | `count++`     |

```text
Initialize -> Check condition -> Execute body -> Update
                  ^                              |
                  |______________________________|
```

When the condition becomes false, repetition stops.

---

# 11. The `while` Loop

A `while` loop checks its condition before executing the body. The body may execute zero times.

```c
initialization;

while (condition)
{
    repeatedStatements;
    update;
}
```

## Example: Display 1 through 5

```c
int count = 1;

while (count <= 5)
{
    printf("%d\n", count);
    count++;
}
```

| `count` | Condition `count <= 5` | Action                   |
| ------: | ---------------------- | ------------------------ |
|       1 | True                   | Display 1; increase to 2 |
|       2 | True                   | Display 2; increase to 3 |
|       3 | True                   | Display 3; increase to 4 |
|       4 | True                   | Display 4; increase to 5 |
|       5 | True                   | Display 5; increase to 6 |
|       6 | False                  | End the loop             |

Use `while` when repetition depends on a condition and the exact number of repetitions may not be known.

---

# 12. Validating Input with `while`

```c
float grade;

printf("Enter a grade from 0 to 100: ");
scanf("%f", &grade);

while ((grade < 0.0f) || (grade > 100.0f))
{
    printf("Invalid grade. Try again: ");
    scanf("%f", &grade);
}

printf("Accepted grade: %.2f\n", grade);
```

The loop repeats until the value is inside the permitted range.

---

# 13. The `do-while` Loop

A `do-while` loop executes its body first and checks the condition afterward. Therefore, the body always runs at least once.

```c
do
{
    repeatedStatements;
}
while (condition);
```

Notice the required semicolon after the condition.

### Analogy

A user must enter a door code at least once before the system can decide whether another attempt is necessary.

## Example: Repeating a menu

```c
int choice;

do
{
    printf("\n1. View Profile\n");
    printf("2. View Grades\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Opening profile...\n");
            break;
        case 2:
            printf("Opening grades...\n");
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
}
while (choice != 3);
```

The menu must appear before the program can check whether Exit was selected.

---

# 14. The `for` Loop

A `for` loop places initialization, condition, and update in one header.

```c
for (initialization; condition; update)
{
    repeatedStatements;
}
```

## Example: Display 1 through 5

```c
int count;

for (count = 1; count <= 5; count++)
{
    printf("%d\n", count);
}
```

| Part           | Code         |
| -------------- | ------------ |
| Initialization | `count = 1`  |
| Condition      | `count <= 5` |
| Update         | `count++`    |

Use `for` when the number of repetitions is known or controlled by a counter.

## Counting backward

```c
for (count = 5; count >= 1; count--)
{
    printf("%d\n", count);
}
```

## Changing the step

```c
for (number = 2; number <= 10; number += 2)
{
    printf("%d\n", number);
}
```

This displays `2`, `4`, `6`, `8`, and `10`.

---

# 15. Choosing a Loop

| Situation                             | Suitable loop         |
| ------------------------------------- | --------------------- |
| Repeat a known number of times        | `for`                 |
| Repeat while a condition remains true | `while`               |
| Execute the body at least once        | `do-while`            |
| Display a menu before checking Exit   | `do-while`            |
| Request input until valid             | `while` or `do-while` |

These are guidelines. Choose the loop that expresses the intended logic most clearly.

---

# 16. Counters and Accumulators

A **counter** records how many times something occurs.

```c
passingCount++;
```

An **accumulator** maintains a running total.

```c
total += value;
```

### Analogy

An accumulator is like a coin jar. Each new amount is added to what is already stored.

Initialize an accumulator before the loop:

```c
float total = 0.0f;
```

## Example: Average of five scores

```c
int count;
float score;
float total = 0.0f;
float average;

for (count = 1; count <= 5; count++)
{
    printf("Enter score %d: ", count);
    scanf("%f", &score);
    total += score;
}

average = total / 5.0f;

printf("Total: %.2f\n", total);
printf("Average: %.2f\n", average);
```

---

# 17. Sentinel-Controlled Loops

A **sentinel value** is a special input that signals the end of repetition.

```c
float expense;
float total = 0.0f;

printf("Enter expense or -1 to stop: ");
scanf("%f", &expense);

while (expense != -1.0f)
{
    total += expense;

    printf("Enter expense or -1 to stop: ");
    scanf("%f", &expense);
}

printf("Total expenses: %.2f\n", total);
```

The sentinel `-1` is not added because the condition is checked before the body. Choose a sentinel that cannot be mistaken for valid data.

---

# 18. Combining Conditions and Loops

Useful programs frequently combine selection and repetition.

## Example: Count passing grades

```c
int count;
int passingCount = 0;
float grade;

for (count = 1; count <= 5; count++)
{
    printf("Enter grade %d: ", count);
    scanf("%f", &grade);

    if (grade >= 70.0f)
    {
        passingCount++;
    }
}

printf("Passing grades: %d\n", passingCount);
```

The loop processes five grades. The `if` statement checks each grade. The counter increases only when the grade passes.

---

# 19. `break` and `continue`

`break` immediately ends the nearest loop.

```c
for (int count = 1; count <= 10; count++)
{
    if (count == 6)
    {
        break;
    }

    printf("%d\n", count);
}
```

This displays `1` through `5`.

`continue` skips the remaining statements in the current iteration.

```c
for (int count = 1; count <= 5; count++)
{
    if (count == 3)
    {
        continue;
    }

    printf("%d\n", count);
}
```

This displays `1`, `2`, `4`, and `5`.

Use both statements carefully. A clear loop condition is often easier to understand than several early exits.

---

# 20. Common Errors

## Assignment instead of comparison

```c
if (choice = 1)       // Incorrect
if (choice == 1)      // Correct
```

## Semicolon after `if`

```c
if (grade >= 70);     // Incorrect
{
    printf("Passed");
}
```

The semicolon ends the `if`. Remove it.

## Incorrect boundary

```c
grade > 70            // Excludes exactly 70
grade >= 70           // Includes exactly 70
```

## Infinite loop

```c
int count = 1;

while (count <= 5)
{
    printf("%d\n", count);
    // Missing count++
}
```

The condition never becomes false.

## Off-by-one error

```c
count < 5             // Stops before 5
count <= 5            // Includes 5
```

## Wrong update direction

```c
for (count = 1; count <= 5; count--)  // Moves away from the limit
```

## Uninitialized accumulator

```c
float total;          // Risky
float total = 0.0f;   // Correct starting total
```

## Semicolon after a loop header

Do not write:

```c
while (count <= 5);
```

The `do-while` statement is the exception:

```c
do
{
    /* statements */
}
while (condition);
```

---

# 21. Complete Example: Grade Analyzer

```c
#include <stdio.h>

int main(void)
{
    int count;
    float grade;
    float total = 0.0f;
    float average;

    for (count = 1; count <= 3; count++)
    {
        printf("Enter grade %d: ", count);
        scanf("%f", &grade);

        while ((grade < 0.0f) || (grade > 100.0f))
        {
            printf("Invalid grade. Enter 0 to 100: ");
            scanf("%f", &grade);
        }

        total += grade;
    }

    average = total / 3.0f;
    printf("Average: %.2f\n", average);

    if (average >= 90.0f)
    {
        printf("Excellent\n");
    }
    else if (average >= 80.0f)
    {
        printf("Very Good\n");
    }
    else if (average >= 70.0f)
    {
        printf("Passed\n");
    }
    else
    {
        printf("Failed\n");
    }

    return 0;
}
```

## Program flow

```text
1. Repeat three times.
2. Receive one grade.
3. Repeat input while the grade is invalid.
4. Add each valid grade to the total.
5. Calculate the average.
6. Select and display the correct classification.
```

---

# 22. Key Relationships

```text
Condition -> True or false -> Choose an action
```

```text
Initialize -> Check -> Execute -> Update -> Repeat or stop
```

> **Conditionals answer:** Which action should happen?  
> **Loops answer:** How many times or how long should it happen?

---

# 23. Summary

- `if` performs an action when a condition is true.
- `if-else` selects between two paths.
- An `else-if` ladder selects one of several categories.
- Nested conditions represent dependent decisions.
- `switch` is useful for exact menu choices.
- Loops repeat instructions efficiently.
- `while` checks its condition before the body.
- `do-while` executes its body at least once.
- `for` is convenient for counter-controlled repetition.
- Counters record occurrences; accumulators maintain totals.
- Sentinel values can signal the end of input.
- Conditions and loops work together in complete programs.
- Correct boundaries, updates, and initialization prevent common logic errors.
