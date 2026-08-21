# Programming Logic and Design

## Lecture 3: Introduction to C, Data Types, and Variables

> **Main idea:** A program works with data. Data types describe what kind of data is being used, while variables provide named places where that data can be stored.

---

## Learning Outcomes

At the end of this lecture, students should be able to:

1. Explain the basic purpose and relevance of the C programming language.
2. Describe how a simple C program is organized.
3. Identify the purpose of common C program elements.
4. Differentiate the basic data types `int`, `float`, `double`, and `char`.
5. Declare, initialize, assign, and display variables.
6. Select an appropriate data type for a given value.
7. Apply valid and meaningful variable-naming conventions.
8. Use constants for values that should not change.
9. Accept simple user input and display formatted output.

---

# 1. Beginning C Programming

In the previous lectures, we designed solutions using algorithms, pseudocode, and flowcharts. We will now begin translating those logical solutions into instructions that a computer can execute.

```text
Problem
   ↓
Algorithm
   ↓
Pseudocode or flowchart
   ↓
C source code
   ↓
Executable program
```

The logic still comes first. C is the language we will use to express that logic precisely.

---

## What is C?

**C** is a general-purpose programming language developed for creating efficient and structured programs.

It is widely used in areas such as:

- Operating systems
- Embedded systems
- Microcontrollers
- Device drivers
- Robotics and automation
- Communication systems
- Engineering and scientific applications

C is particularly relevant to Computer Engineering because it allows programmers to work with both high-level program logic and lower-level computer resources.

---

## Why learn C?

C provides a strong foundation for learning programming because it introduces important concepts clearly:

- Data types and variables
- Input and output
- Operators and expressions
- Decisions and loops
- Functions
- Arrays and strings
- Memory and data representation

Many ideas learned in C also appear in languages such as C++, Java, C#, and Python.

> Learning C is not only about memorizing commands. It is about learning how data and instructions work together inside a program.

---

## C is a compiled language

A C program must be translated by a **compiler** before the computer can execute it.

```text
C source code
      ↓
   Compiler
      ↓
Executable program
      ↓
    Output
```

The usual development cycle is:

```text
Write → Compile → Correct errors → Run → Check the result
```

- **Write:** Create the source code in a `.c` file.
- **Compile:** Translate the code and check its syntax.
- **Correct errors:** Fix problems reported by the compiler.
- **Run:** Execute the translated program.
- **Check:** Determine whether the output is correct.

---

# 2. Your First C Program

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, world!\n");
    return 0;
}
```

This small program contains several important parts.

---

## `#include <stdio.h>`

```c
#include <stdio.h>
```

This line gives the program access to standard input and output functions, including `printf()` and `scanf()`.

For now, think of a **header file** as a toolbox. Including `stdio.h` makes input and output tools available to the program.

---

## The `main()` function

```c
int main(void)
```

Every basic C program begins execution inside the `main()` function.

You may think of `main()` as the front door of the program. When the program starts, this is where the computer enters.

- `int` indicates that `main()` returns an integer value.
- `main` is the name of the function.
- `void` indicates that this version of `main()` receives no information from outside the program.

---

## Braces

```c
{
    /* program instructions */
}
```

The opening and closing braces mark the beginning and end of the function body.

Instructions belonging to `main()` are written between these braces.

---

## The `printf()` function

```c
printf("Hello, world!\n");
```

`printf()` displays formatted output on the screen.

The text enclosed in double quotation marks is called a **string literal**.

The sequence `\n` moves the cursor to a new line after the message is displayed.

---

## `return 0;`

```c
return 0;
```

This ends the `main()` function and reports that the program completed successfully.

---

## Semicolons

Most C statements end with a semicolon.

```c
printf("Welcome!\n");
return 0;
```

A semicolon is similar to a period at the end of a sentence: it marks the end of a complete instruction.

Forgetting a semicolon is a common syntax error.

---

## C is case-sensitive

C treats uppercase and lowercase letters as different characters.

```c
age
Age
AGE
```

These are three different names in C.

Similarly, `printf` is correct, while `Printf` is not the same function.

---

# 3. Comments

Comments are notes written inside source code for human readers. The compiler ignores them.

## Single-line comment

```c
// Display a welcome message
printf("Welcome!\n");
```

## Multi-line comment

```c
/*
    This program displays
    a welcome message.
*/
```

Comments are useful for:

- Describing the purpose of a program
- Explaining an important section of logic
- Recording assumptions or limitations
- Making code easier to maintain

Comments should explain **why** something is done when the reason is not obvious. They should not repeat every simple instruction.

```c
// Good: The passing grade required by the university
const int PASSING_GRADE = 70;
```

---

# 4. Data in a Program

A program receives, stores, processes, and displays data.

Examples of data include:

- A student's age
- A product price
- A temperature reading
- A letter grade
- A sensor measurement
- The number of items in an inventory

Different kinds of data require different representations.

For example:

- `25` is a whole number.
- `25.75` contains a fractional part.
- `'A'` is a single character.

C requires the programmer to identify the type of each stored value.

---

# 5. Variables

## What is a variable?

A **variable** is a named storage location in the computer's memory. Its value may change while the program is running.

### Analogy: A labeled container

Imagine several labeled containers:

```text
[ age: 18 ]
[ price: 25.50 ]
[ grade: A ]
```

- The label is the variable name.
- The container has a specific type.
- The content is the stored value.
- The content may be replaced by another compatible value.

A container intended for whole numbers should not be used as though it stores a letter or a decimal measurement.

---

## Declaring a variable

Before using a variable, we normally declare it.

```c
int age;
```

This declaration tells C:

- Create a variable named `age`.
- Use it to store an integer.

The general form is:

```text
dataType variableName;
```

Additional examples:

```c
float price;
double distance;
char section;
```

---

## Initialization

**Initialization** gives a variable its first value when it is declared.

```c
int age = 18;
float temperature = 29.5f;
char grade = 'A';
```

Initialization is useful because it prevents the program from accidentally using an unknown value.

---

## Assignment

**Assignment** places a value into an existing variable.

```c
int score;
score = 85;
```

The assignment symbol `=` means:

> Store the value on the right inside the variable on the left.

It does not mean exactly the same thing as mathematical equality.

```c
score = 90;
```

This replaces the previous value of `score` with `90`.

---

## A variable can change

```c
int batteryLevel = 100;

batteryLevel = 80;
batteryLevel = 50;
```

At the end of these statements, `batteryLevel` contains `50`.

The variable keeps its name, but its stored value changes.

---

## Declaring multiple variables

Variables of the same type may be declared together:

```c
int quiz1, quiz2, quiz3;
```

For beginners, separate declarations can sometimes be easier to read:

```c
int quiz1;
int quiz2;
int quiz3;
```

Readability is more important than writing the fewest possible lines.

---

# 6. Basic Data Types

A **data type** tells the computer:

- What kind of value a variable can store
- How the value should be interpreted
- How much memory is generally needed
- What operations are appropriate for the value

### Analogy: Different types of containers

A water bottle, document envelope, and coin purse are all containers, but each is designed for a different kind of content.

Similarly, C provides different data types for different kinds of values.

---

## Overview of basic data types

| Data type | Used for                     | Example values      | Typical declaration           |
| --------- | ---------------------------- | ------------------- | ----------------------------- |
| `int`     | Whole numbers                | `0`, `18`, `-25`    | `int age = 18;`               |
| `float`   | Decimal numbers              | `3.5`, `29.75`      | `float temperature = 29.75f;` |
| `double`  | More precise decimal numbers | `3.1415926535`      | `double pi = 3.1415926535;`   |
| `char`    | A single character           | `'A'`, `'7'`, `'#'` | `char grade = 'A';`           |

The exact storage size and range of some types can depend on the computer and compiler. At this stage, the important skill is choosing a type appropriate for the data.

---

## The `int` data type

`int` stores whole numbers without a fractional part.

```c
int studentCount = 45;
int floorNumber = 3;
int balance = -100;
```

Appropriate uses include:

- Age in completed years
- Number of students
- Number of items
- Menu choices
- Whole-number scores

Do not use `int` when the fractional part is important.

```c
int price = 25.75;  // The fractional part cannot be represented correctly as an int
```

---

## The `float` data type

`float` stores numbers that may contain a fractional part.

```c
float price = 25.75f;
float temperature = 30.5f;
float height = 1.68f;
```

The suffix `f` tells C that the literal is a `float` value.

Appropriate uses include:

- Basic measurements
- Prices for introductory programs
- Temperature readings
- Percentages and averages

Floating-point values are approximations. Some decimal values cannot be represented perfectly in binary, so very small rounding differences may occur.

---

## The `double` data type

`double` also stores numbers with fractional parts, but it normally provides greater precision than `float`.

```c
double distance = 12345.678901;
double voltage = 3.1415926535;
```

Use `double` when a calculation requires more precision or when values may be much larger or smaller.

For beginner programs, both `float` and `double` can represent decimals. The main distinction is their level of precision.

---

## The `char` data type

`char` stores one character.

```c
char grade = 'A';
char section = 'B';
char answer = 'Y';
```

A character literal uses **single quotation marks**.

```c
char letter = 'C';
```

Do not confuse a character with a string:

```c
'A'    // One character
"A"    // A string containing a character
```

Strings will be discussed in a later lesson.

---

## Choosing an appropriate data type

Ask what kind of value the variable must store.

| Information         | Suitable type       | Reason                                      |
| ------------------- | ------------------- | ------------------------------------------- |
| Number of students  | `int`               | It is a whole-number count                  |
| Product price       | `float` or `double` | It may contain a fractional part            |
| Temperature reading | `float` or `double` | Measurements may contain decimals           |
| Middle initial      | `char`              | It contains one character                   |
| Menu selection      | `int` or `char`     | It may be represented by a number or letter |

Choosing the correct data type makes the meaning of the program clearer and helps the computer interpret the value correctly.

---

# 7. Variable Names and Identifiers

An **identifier** is a name created by the programmer for a variable, function, or another program element.

## Basic identifier rules

A C identifier:

- May contain letters, digits, and underscores
- Must not begin with a digit
- Must not contain spaces
- Must not contain symbols such as `@`, `#`, `%`, or `-`
- Must not be a reserved C keyword
- Is case-sensitive

## Examples

| Identifier    | Valid? | Explanation                                  |
| ------------- | ------ | -------------------------------------------- |
| `studentAge`  | Yes    | Begins with a letter and has no spaces       |
| `quiz_score`  | Yes    | An underscore is allowed                     |
| `score2`      | Yes    | A digit is allowed after the first character |
| `2ndScore`    | No     | It begins with a digit                       |
| `student age` | No     | Spaces are not allowed                       |
| `total-price` | No     | A hyphen is not allowed                      |
| `float`       | No     | It is a C keyword                            |

---

## Use meaningful names

Weak names:

```c
int a;
float x;
```

Meaningful names:

```c
int studentCount;
float totalPrice;
```

A good variable name explains the purpose of the stored value.

---

## Recommended naming style

One common style is **camel case**:

```c
studentAge
totalCost
averageGrade
temperatureReading
```

The first word begins with a lowercase letter, and each following word begins with an uppercase letter.

The important requirement is consistency throughout the program.

---

# 8. Constants

A **constant** is a named value that should not change while the program is running.

```c
const int PASSING_GRADE = 70;
const float TAX_RATE = 0.12f;
```

By convention, constant names are often written using uppercase letters and underscores.

## Why use constants?

- They prevent accidental changes.
- They give meaning to important values.
- They make a program easier to update.
- They avoid unexplained numbers inside the code.

Compare these statements:

```c
if (grade >= 70)
```

```c
if (grade >= PASSING_GRADE)
```

The second statement explains what `70` represents.

The full use of conditions will be discussed later. Here, the example simply shows why a named constant is easier to understand.

---

# 9. Displaying Variables with `printf()`

To display a variable, `printf()` uses a **format specifier** as a placeholder.

| Data type | Common format specifier | Example                   |
| --------- | ----------------------- | ------------------------- |
| `int`     | `%d`                    | `printf("%d", age);`      |
| `float`   | `%f`                    | `printf("%f", price);`    |
| `double`  | `%f`                    | `printf("%f", distance);` |
| `char`    | `%c`                    | `printf("%c", grade);`    |

## Displaying an integer

```c
int age = 18;
printf("Age: %d\n", age);
```

Output:

```text
Age: 18
```

---

## Displaying a decimal value

```c
float price = 25.75f;
printf("Price: %.2f\n", price);
```

Output:

```text
Price: 25.75
```

`%.2f` displays two digits after the decimal point.

---

## Displaying a character

```c
char grade = 'A';
printf("Grade: %c\n", grade);
```

Output:

```text
Grade: A
```

---

## Displaying several variables

```c
int studentNumber = 25;
float average = 86.50f;
char section = 'B';

printf("Student number: %d\n", studentNumber);
printf("Average: %.2f\n", average);
printf("Section: %c\n", section);
```

The format specifier must match the kind of value being displayed.

---

# 10. Receiving Input with `scanf()`

`scanf()` allows a program to receive formatted input from the user.

## Reading an integer

```c
int age;

printf("Enter your age: ");
scanf("%d", &age);
```

The `&` before `age` tells `scanf()` where the variable is located so the entered value can be stored there.

A complete explanation of memory addresses and pointers is not necessary yet. For now, remember that basic `scanf()` input normally requires `&` before variables such as `int`, `float`, `double`, and `char`.

---

## Input format specifiers

| Data type | `scanf()` format specifier | Example                    |
| --------- | -------------------------- | -------------------------- |
| `int`     | `%d`                       | `scanf("%d", &age);`       |
| `float`   | `%f`                       | `scanf("%f", &price);`     |
| `double`  | `%lf`                      | `scanf("%lf", &distance);` |
| `char`    | `%c`                       | `scanf(" %c", &grade);`    |

Notice that `double` uses `%lf` with `scanf()`.

The space before `%c` in `" %c"` tells `scanf()` to ignore leftover whitespace before reading the character.

---

## Complete input example

```c
#include <stdio.h>

int main(void)
{
    int age;
    float height;
    char section;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    printf("Enter your section letter: ");
    scanf(" %c", &section);

    printf("\nStudent Information\n");
    printf("Age: %d\n", age);
    printf("Height: %.2f meters\n", height);
    printf("Section: %c\n", section);

    return 0;
}
```

This program demonstrates declaration, user input, storage, and formatted output.

---

# 11. Sample Programs

## Sample Program 1: Student profile

```c
#include <stdio.h>

int main(void)
{
    int age = 18;
    float height = 1.68f;
    char section = 'A';

    printf("Student Profile\n");
    printf("Age: %d\n", age);
    printf("Height: %.2f meters\n", height);
    printf("Section: %c\n", section);

    return 0;
}
```

### Concepts demonstrated

- Declaring variables
- Initializing values
- Using `int`, `float`, and `char`
- Displaying values with matching format specifiers

---

## Sample Program 2: Product information

```c
#include <stdio.h>

int main(void)
{
    int quantity;
    float unitPrice;
    char category;

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter unit price: ");
    scanf("%f", &unitPrice);

    printf("Enter category letter: ");
    scanf(" %c", &category);

    printf("\nProduct Information\n");
    printf("Quantity: %d\n", quantity);
    printf("Unit price: %.2f\n", unitPrice);
    printf("Category: %c\n", category);

    return 0;
}
```

### Concepts demonstrated

- Declaring variables before use
- Receiving values from the user
- Storing different kinds of data
- Producing readable output

This program intentionally stores and displays the data without calculating the total cost. Calculations using operators and expressions belong to the following lecture.

---

## Sample Program 3: Engineering measurement record

```c
#include <stdio.h>

int main(void)
{
    const char SENSOR_ID = 'A';
    double voltage;
    float temperature;

    printf("Enter voltage reading: ");
    scanf("%lf", &voltage);

    printf("Enter temperature reading: ");
    scanf("%f", &temperature);

    printf("\nSensor %c Reading\n", SENSOR_ID);
    printf("Voltage: %.3f V\n", voltage);
    printf("Temperature: %.2f C\n", temperature);

    return 0;
}
```

### Concepts demonstrated

- Using a named constant
- Using `double` for a more precise measurement
- Using `float` for a basic decimal measurement
- Controlling the number of displayed decimal places

---

# 12. Common Beginner Errors

## Missing a semicolon

Incorrect:

```c
int age = 18
```

Correct:

```c
int age = 18;
```

---

## Using a variable before declaring it

Incorrect:

```c
age = 18;
```

Correct:

```c
int age = 18;
```

---

## Using an uninitialized variable

Risky:

```c
int score;
printf("%d\n", score);
```

The program attempts to display `score` before a meaningful value has been assigned.

Better:

```c
int score = 0;
printf("%d\n", score);
```

---

## Using the wrong quotation marks

```c
char grade = 'A';       // Correct for one character
printf("Grade: %c", grade);  // Correct for text and formatted output
```

Single quotation marks are used for one character. Double quotation marks are used for strings.

---

## Using the wrong format specifier

Incorrect:

```c
float price = 25.50f;
printf("%d", price);
```

Correct:

```c
float price = 25.50f;
printf("%.2f", price);
```

---

## Forgetting `&` in basic `scanf()` input

Incorrect:

```c
scanf("%d", age);
```

Correct:

```c
scanf("%d", &age);
```

---

## Using the wrong `scanf()` specifier for `double`

Incorrect:

```c
double voltage;
scanf("%f", &voltage);
```

Correct:

```c
double voltage;
scanf("%lf", &voltage);
```

---

## Ignoring case sensitivity

```c
int studentAge = 18;
printf("%d", StudentAge);  // Incorrect: different identifier
```

`studentAge` and `StudentAge` are not the same name.

---

# 13. Reading a Program Step by Step

Consider the following program:

```c
#include <stdio.h>

int main(void)
{
    int yearLevel;
    float allowance;
    char section;

    printf("Enter year level: ");
    scanf("%d", &yearLevel);

    printf("Enter daily allowance: ");
    scanf("%f", &allowance);

    printf("Enter section: ");
    scanf(" %c", &section);

    printf("\nRecorded Information\n");
    printf("Year level: %d\n", yearLevel);
    printf("Daily allowance: %.2f\n", allowance);
    printf("Section: %c\n", section);

    return 0;
}
```

The program follows this sequence:

```text
1. Include the standard input/output tools.
2. Begin the main function.
3. Declare variables and specify their data types.
4. Ask the user for values.
5. Store the entered values in the variables.
6. Display the stored information.
7. End the program successfully.
```

The program is a direct implementation of the following IPO model:

| Input                                    | Process                                               | Output                           |
| ---------------------------------------- | ----------------------------------------------------- | -------------------------------- |
| Year level, daily allowance, and section | Store the entered values using appropriate data types | Display the recorded information |

---

# 14. Key Relationships

```text
Data
  ↓
Data type describes the kind of value
  ↓
Variable provides a name and storage location
  ↓
scanf() receives and stores a value
  ↓
printf() displays the value
```

Another way to remember the relationship is:

> **Data type = kind of container**  
> **Variable = label on the container**  
> **Value = content inside the container**

---

# 15. Summary

- C is a compiled, general-purpose programming language widely used in engineering systems.
- A basic C program begins execution inside `main()`.
- Braces group the instructions belonging to a function.
- Most C statements end with a semicolon.
- C is case-sensitive.
- Comments help human readers understand the program.
- A variable is a named storage location whose value may change.
- A data type describes the kind of value stored in a variable.
- `int` stores whole numbers.
- `float` and `double` store values with fractional parts.
- `double` generally provides greater precision than `float`.
- `char` stores one character.
- Variables should have valid and meaningful names.
- A constant represents a value that should not change.
- `printf()` displays formatted output.
- `scanf()` receives formatted input from the user.
- Format specifiers must match the corresponding data types.
- Program logic should remain clear even when the program is syntactically correct.
