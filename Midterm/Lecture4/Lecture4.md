# Programming Logic and Design

## Lecture 4: Operators and Expressions in C

> **Main idea:** Variables store data, while operators and expressions tell the computer what to do with that data.

---

## Learning Outcomes

At the end of this lecture, students should be able to:

1. Explain the roles of operators, operands, and expressions.
2. Use arithmetic operators to perform calculations.
3. Explain integer division and the remainder operator.
4. Use assignment and compound-assignment operators correctly.
5. Use increment and decrement operators.
6. Construct relational expressions that compare values.
7. Construct logical expressions that combine or reverse conditions.
8. Apply operator precedence and parentheses correctly.
9. Translate mathematical formulas and word statements into valid C expressions.
10. Recognize how data types affect the result of an expression.

---

# 1. From Stored Data to Useful Results

In the previous lecture, we learned how to:

- Declare variables
- Select data types
- Store values
- Receive input with `scanf()`
- Display output with `printf()`

Storing data is only the beginning. A useful program must also calculate, compare, and make logical evaluations using that data.

Consider a simple purchase:

```c
int quantity = 3;
float price = 25.50f;
float totalCost;

totalCost = quantity * price;
```

The variables hold the data, while `*` tells the computer to multiply the values.

```text
Variables store the values.
Operators perform the actions.
Expressions describe the computation.
```

---

# 2. Operators, Operands, and Expressions

## Operator

An **operator** is a symbol that tells the computer to perform a particular operation.

Examples:

```text
+   -   *   /   %   >   ==   &&
```

---

## Operand

An **operand** is a value or variable on which an operator acts.

In the expression:

```c
length * width
```

- `length` is an operand.
- `width` is an operand.
- `*` is the operator.

---

## Expression

An **expression** is a combination of values, variables, and operators that produces a result.

Examples:

```c
length * width
score1 + score2 + score3
temperature > 30
hasID && isEnrolled
```

Expressions may produce:

- A numerical result
- A character value
- A true-or-false result

---

## Analogy: A sentence

An expression can be compared to a short sentence:

- Operands are the subjects or objects.
- Operators describe the action or relationship.
- The evaluated result is the meaning produced by the complete sentence.

For example:

```c
price * quantity
```

means:

> Multiply the item price by the number of items.

---

# 3. Arithmetic Operators

Arithmetic operators perform mathematical calculations.

| Operator | Meaning        | Example | Result |
| -------- | -------------- | ------- | -----: |
| `+`      | Addition       | `8 + 2` |   `10` |
| `-`      | Subtraction    | `8 - 2` |    `6` |
| `*`      | Multiplication | `8 * 2` |   `16` |
| `/`      | Division       | `8 / 2` |    `4` |
| `%`      | Remainder      | `8 % 3` |    `2` |

---

## Addition

```c
int quiz1 = 80;
int quiz2 = 90;
int total = quiz1 + quiz2;
```

After the expression is evaluated, `total` contains `170`.

---

## Subtraction

```c
float balance = 500.00f;
float expense = 125.50f;
float remainingBalance = balance - expense;
```

`remainingBalance` contains `374.50`.

---

## Multiplication

```c
int quantity = 4;
float unitPrice = 35.75f;
float totalCost = quantity * unitPrice;
```

`totalCost` contains `143.00`.

In C, multiplication must use the `*` symbol.

```c
area = length * width;   // Correct
```

Writing variables beside each other, as in ordinary algebra, is not valid C.

```c
area = length width;     // Incorrect
```

---

## Division

```c
float total = 240.0f;
float average = total / 3.0f;
```

`average` contains `80.0`.

Division requires special attention because the data types of the operands affect the result.

---

# 4. Integer and Floating-Point Division

## Integer division

When both operands are integers, C performs **integer division**.

```c
int result = 7 / 2;
```

The result is:

```text
3
```

The fractional part is discarded. The result is not rounded to `4`.

### Analogy: Sharing whole items

Suppose seven whole notebooks are shared equally by two students.

- Each student receives three whole notebooks.
- One notebook remains.

The whole-number quotient is `3`.

---

## Floating-point division

If at least one operand is a floating-point value, C keeps the fractional part.

```c
float result = 7.0f / 2.0f;
```

The result is:

```text
3.5
```

These expressions produce different results:

```c
7 / 2       // Result: 3
7.0 / 2     // Result: 3.5
7 / 2.0     // Result: 3.5
```

---

## A common average error

```c
int total = 250;
int count = 3;
float average = total / count;
```

Although `average` is a `float`, the division happens first using two integers.

```text
250 / 3 = 83
```

The integer result is then stored as `83.0`.

One correction is:

```c
float average = (float) total / count;
```

The conversion causes floating-point division, producing approximately `83.33`.

---

# 5. The Remainder Operator

The remainder operator `%` produces the remainder after integer division.

```c
int remainder = 17 % 5;
```

Because:

```text
17 ÷ 5 = 3 with a remainder of 2
```

`remainder` contains `2`.

---

## Common uses of `%`

### Checking whether a number is even

```c
number % 2
```

- A remainder of `0` means the number is even.
- A nonzero remainder means the number is odd.

The complete comparison can be written as:

```c
number % 2 == 0
```

### Extracting the last digit

```c
lastDigit = number % 10;
```

If `number` is `348`, `lastDigit` becomes `8`.

### Converting minutes

```c
hours = totalMinutes / 60;
remainingMinutes = totalMinutes % 60;
```

If `totalMinutes` is `135`:

```text
hours = 2
remainingMinutes = 15
```

The `%` operator is normally used with integer operands.

---

# 6. Assignment Operators

## Simple assignment

The assignment operator `=` stores the value on the right in the variable on the left.

```c
score = 90;
```

Read this as:

> Assign the value 90 to `score`.

---

## Assignment is not mathematical equality

Consider:

```c
score = score + 5;
```

In mathematics, this would appear impossible because a value cannot equal itself plus five.

In programming, the statement means:

```text
1. Get the current value of score.
2. Add 5.
3. Store the new value back in score.
```

If `score` initially contains `80`, it contains `85` afterward.

### Analogy: Updating a whiteboard

Imagine that a score is written on a whiteboard. You read the current score, calculate the updated score, erase the old value, and write the new one in the same place.

---

## Compound-assignment operators

Compound-assignment operators provide shorter ways to update variables.

| Long form            | Short form    | Meaning               |
| -------------------- | ------------- | --------------------- |
| `value = value + 5;` | `value += 5;` | Add 5 to value        |
| `value = value - 5;` | `value -= 5;` | Subtract 5 from value |
| `value = value * 5;` | `value *= 5;` | Multiply value by 5   |
| `value = value / 5;` | `value /= 5;` | Divide value by 5     |
| `value = value % 5;` | `value %= 5;` | Store the remainder   |

Example:

```c
float balance = 500.00f;
balance -= 125.50f;
```

After the update, `balance` contains `374.50`.

---

# 7. Increment and Decrement Operators

The increment and decrement operators update a variable by one.

## Increment

```c
count++;
```

This is equivalent to:

```c
count = count + 1;
```

or:

```c
count += 1;
```

---

## Decrement

```c
count--;
```

This is equivalent to:

```c
count = count - 1;
```

---

## Meaningful uses

```c
studentCount++;
remainingLives--;
itemQuantity++;
```

These operators are especially useful for counting repeated events. Their use inside loops will be discussed in a later lecture.

---

## Prefix and postfix forms

C supports both forms:

```c
++count;  // Prefix increment
count++;  // Postfix increment
```

When used alone as complete statements, both increase `count` by one.

They behave differently when used as part of a larger expression. For beginner programs, prefer using them as separate statements:

```c
count++;
printf("%d\n", count);
```

This is clearer than combining several actions in one expression.

---

# 8. Relational Operators

Relational operators compare two values.

The result of a relational expression is either **true** or **false**.

| Operator | Meaning                  | Example            |
| -------- | ------------------------ | ------------------ |
| `==`     | Equal to                 | `score == 100`     |
| `!=`     | Not equal to             | `choice != 0`      |
| `>`      | Greater than             | `temperature > 30` |
| `<`      | Less than                | `balance < cost`   |
| `>=`     | Greater than or equal to | `grade >= 70`      |
| `<=`     | Less than or equal to    | `age <= 12`        |

---

## Comparison examples

```c
int grade = 85;

grade >= 70   // True
grade < 70    // False
grade == 85   // True
grade != 85   // False
```

In C, a false relational expression evaluates to `0`, while a true relational expression evaluates to `1`.

```c
printf("%d\n", 85 >= 70);  // Displays 1
printf("%d\n", 85 < 70);   // Displays 0
```

---

## Assignment versus equality

These operators have different purposes:

```c
=     // Assignment
==    // Comparison for equality
```

Example:

```c
score = 90;      // Store 90 in score
score == 90;     // Ask whether score is equal to 90
```

Confusing `=` and `==` is one of the most common beginner mistakes in C.

---

## Boundary conditions

Carefully select the correct relational operator.

If the passing grade is 70:

```c
grade > 70
```

does not include exactly `70`.

The correct expression is:

```c
grade >= 70
```

The word **at least** usually suggests `>=`, while **at most** usually suggests `<=`.

| Statement                 | C expression        |
| ------------------------- | ------------------- |
| Age is greater than 18    | `age > 18`          |
| Age is at least 18        | `age >= 18`         |
| Temperature is below 30   | `temperature < 30`  |
| Temperature is at most 30 | `temperature <= 30` |
| Choice is not zero        | `choice != 0`       |

---

# 9. Logical Operators

Logical operators combine or reverse conditions.

| Operator | Name        | Meaning                            |
| -------- | ----------- | ---------------------------------- | ---------- | ---------------------------------------- |
| `&&`     | Logical AND | True when both conditions are true |
| `        |             | `                                  | Logical OR | True when at least one condition is true |
| `!`      | Logical NOT | Reverses true and false            |

---

## Logical AND: `&&`

```c
hasID && isEnrolled
```

The complete expression is true only when both conditions are true.

### Analogy: Laboratory access

A student may enter the laboratory only when:

- The student has a valid ID, **and**
- The student is enrolled in the class.

| `hasID` | `isEnrolled` | `hasID && isEnrolled` |
| ------: | -----------: | --------------------: |
|   False |        False |                 False |
|   False |         True |                 False |
|    True |        False |                 False |
|    True |         True |                  True |

---

## Logical OR: `||`

```c
isSenior || isPWD
```

The complete expression is true when at least one condition is true.

### Analogy: Discount qualification

A customer qualifies for a discount when the customer is a senior citizen **or** a person with disability.

| `isSenior` | `isPWD` | `isSenior |     | isPWD` |
| ---------: | ------: | --------: | --- | ------ |
|      False |   False |     False |
|      False |    True |      True |
|       True |   False |      True |
|       True |    True |      True |

The logical OR in C is inclusive: it remains true when both conditions are true.

---

## Logical NOT: `!`

```c
!isLocked
```

Logical NOT reverses the truth value.

| `isLocked` | `!isLocked` |
| ---------: | ----------: |
|      False |        True |
|       True |       False |

### Analogy

If `isLocked` means "the door is locked," then `!isLocked` means "the door is not locked."

---

## Combining relational and logical expressions

Logical operators commonly connect relational expressions.

```c
age >= 18 && age <= 60
```

This means:

> Age is at least 18 and at most 60.

Another example:

```c
temperature < 0 || temperature > 100
```

This means:

> Temperature is below 0 or above 100.

Parentheses are recommended when they make a combined condition easier to read:

```c
(age >= 18) && (age <= 60)
```

---

# 10. Truth Values in C

C represents false using `0`.

Any nonzero value is treated as true.

```c
0     // False
1     // True
-5    // Also treated as true
20    // Also treated as true
```

Relational and logical expressions normally produce `0` or `1`.

```c
int result = 10 > 5;
printf("%d\n", result);
```

Output:

```text
1
```

Although C represents truth numerically, conditions should still be written so their meaning is clear.

---

# 11. Operator Precedence

An expression may contain more than one operator.

**Operator precedence** determines which operation is performed first.

### Analogy: Order of operations in mathematics

Just as multiplication is normally performed before addition in mathematics, C follows an order for evaluating expressions.

Consider:

```c
result = 2 + 3 * 4;
```

Multiplication occurs first:

```text
2 + 12 = 14
```

The result is `14`, not `20`.

---

## Simplified precedence guide

From higher to lower precedence:

| Priority | Operators                             | Category                            |
| -------: | ------------------------------------- | ----------------------------------- | --- | ---------- |
|        1 | `()`                                  | Parentheses                         |
|        2 | `!`, unary `+`, unary `-`, `++`, `--` | Unary operators                     |
|        3 | `*`, `/`, `%`                         | Multiplication, division, remainder |
|        4 | `+`, `-`                              | Addition and subtraction            |
|        5 | `<`, `<=`, `>`, `>=`                  | Relational comparisons              |
|        6 | `==`, `!=`                            | Equality comparisons                |
|        7 | `&&`                                  | Logical AND                         |
|        8 | `                                     |                                     | `   | Logical OR |
|        9 | `=`, `+=`, `-=`, `*=`, `/=`, `%=`     | Assignment                          |

This table covers the operators used in this lecture. C contains additional operators that will be introduced when needed.

---

## Use parentheses for clarity

Parentheses change or clarify the order of evaluation.

```c
result = (2 + 3) * 4;
```

The parentheses are evaluated first:

```text
5 * 4 = 20
```

Compare:

```c
2 + 3 * 4       // 14
(2 + 3) * 4     // 20
```

Even when parentheses are not required, they can make an expression easier to understand.

```c
isEligible = (age >= 18) && (age <= 60);
```

> Do not rely on memory when an expression is difficult to read. Use parentheses to make the intended order explicit.

---

# 12. Associativity

When operators have the same precedence, **associativity** determines the evaluation direction.

Most arithmetic operators are evaluated from left to right.

```c
20 / 5 * 2
```

Evaluation:

```text
20 / 5 = 4
4 * 2 = 8
```

Subtraction is also evaluated from left to right:

```c
10 - 3 - 2
```

Evaluation:

```text
10 - 3 = 7
7 - 2 = 5
```

This is different from:

```c
10 - (3 - 2)   // Result: 9
```

Assignment operators are evaluated from right to left:

```c
a = b = 10;
```

The value `10` is assigned to `b`, and then the same value is assigned to `a`.

For beginner programs, separate assignments are often clearer:

```c
b = 10;
a = 10;
```

---

# 13. Translating Mathematics into C Expressions

Mathematical notation cannot always be copied directly into C.

| Mathematical idea             | C expression                       |
| ----------------------------- | ---------------------------------- |
| Length multiplied by width    | `length * width`                   |
| Sum of three scores           | `score1 + score2 + score3`         |
| Average of three scores       | `(score1 + score2 + score3) / 3.0` |
| Celsius to Fahrenheit         | `(celsius * 9.0 / 5.0) + 32.0`     |
| Simple interest               | `principal * rate * time`          |
| Rectangle perimeter           | `2 * (length + width)`             |
| Difference between two values | `firstValue - secondValue`         |

---

## Multiplication must be explicit

Mathematics:

```text
2lw
```

C:

```c
2 * length * width
```

---

## Use parentheses for grouped operations

Mathematics:

```text
       a + b + c
mean = ---------
           3
```

C:

```c
mean = (a + b + c) / 3.0;
```

Without parentheses:

```c
mean = a + b + c / 3.0;
```

only `c` is divided by `3.0`, producing a different result.

---

## No implied fractions

Mathematics:

```text
distance
--------
  time
```

C:

```c
speed = distance / time;
```

Every calculation must be expressed in a single valid sequence of C operators and operands.

---

# 14. Translating Word Statements into C Expressions

Certain words suggest particular operators.

| Word or phrase                      | Likely operator |
| ----------------------------------- | --------------- | --- | --- |
| Sum, total, increased by            | `+`             |
| Difference, decreased by, remaining | `-`             |
| Product, times, of                  | `*`             |
| Quotient, divided by, average       | `/`             |
| Remainder                           | `%`             |
| Greater than                        | `>`             |
| Less than                           | `<`             |
| At least                            | `>=`            |
| At most                             | `<=`            |
| Equal to                            | `==`            |
| Not equal to                        | `!=`            |
| Both, and                           | `&&`            |
| Either, or                          | `               |     | `   |
| Not                                 | `!`             |

Examples:

```text
The grade is at least 70.
```

```c
grade >= 70
```

```text
The student has an ID and is enrolled.
```

```c
hasID && isEnrolled
```

```text
The temperature is below 0 or above 100.
```

```c
temperature < 0 || temperature > 100
```

---

# 15. Type Conversion in Expressions

Expressions may combine values of different data types.

## Implicit conversion

C may automatically convert one operand to a compatible type.

```c
int quantity = 3;
float price = 25.50f;
float total = quantity * price;
```

The integer `quantity` is converted for the floating-point calculation. The result is `76.50`.

---

## Explicit conversion or casting

A **cast** tells C to temporarily treat a value as another type.

```c
int total = 250;
int count = 3;
float average = (float) total / count;
```

`(float) total` converts the value of `total` to a floating-point value for the expression.

The original variable `total` remains an `int`.

### Analogy: Using an adapter

A cast is similar to using an adapter so one kind of connection can work in a different context. It changes how the value is treated for the current operation; it does not permanently replace the original variable's type.

---

## Possible loss of information

Converting a decimal value to an integer removes the fractional part.

```c
float measurement = 12.75f;
int wholePart = (int) measurement;
```

`wholePart` becomes `12`.

The value is truncated, not rounded.

Use conversions only when the result matches the intended logic.

---

# 16. Sample Program: Purchase Calculator

```c
#include <stdio.h>

int main(void)
{
    int quantity;
    float unitPrice;
    float totalCost;

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter unit price: ");
    scanf("%f", &unitPrice);

    totalCost = quantity * unitPrice;

    printf("Total cost: %.2f\n", totalCost);

    return 0;
}
```

## Program logic

```text
1. Receive the quantity.
2. Receive the unit price.
3. Multiply the quantity by the unit price.
4. Display the total cost.
```

## Expression used

```c
quantity * unitPrice
```

Because `unitPrice` is a `float`, the multiplication produces a floating-point result.

---

# 17. Sample Program: Average Calculator

```c
#include <stdio.h>

int main(void)
{
    int score1;
    int score2;
    int score3;
    float average;

    printf("Enter three scores: ");
    scanf("%d %d %d", &score1, &score2, &score3);

    average = (score1 + score2 + score3) / 3.0f;

    printf("Average: %.2f\n", average);

    return 0;
}
```

## Why parentheses are needed

```c
(score1 + score2 + score3) / 3.0f
```

The three scores must be added before the total is divided.

## Why `3.0f` is used

`3.0f` ensures that the division keeps the fractional part.

---

# 18. Sample Program: Time Converter

```c
#include <stdio.h>

int main(void)
{
    int totalMinutes;
    int hours;
    int minutes;

    printf("Enter total minutes: ");
    scanf("%d", &totalMinutes);

    hours = totalMinutes / 60;
    minutes = totalMinutes % 60;

    printf("%d minute(s) = %d hour(s) and %d minute(s)\n",
           totalMinutes, hours, minutes);

    return 0;
}
```

## Operators used

```c
totalMinutes / 60
```

produces the number of complete hours.

```c
totalMinutes % 60
```

produces the remaining minutes.

---

# 19. Sample Program: Expression Demonstration

The following program displays the numerical results of relational and logical expressions. It does not yet use conditional statements.

```c
#include <stdio.h>

int main(void)
{
    int age = 19;
    int hasID = 1;
    int isEnrolled = 1;

    printf("Age is at least 18: %d\n", age >= 18);
    printf("Has ID and is enrolled: %d\n", hasID && isEnrolled);
    printf("Does not have an ID: %d\n", !hasID);

    return 0;
}
```

Output:

```text
Age is at least 18: 1
Has ID and is enrolled: 1
Does not have an ID: 0
```

The values `1` and `0` represent true and false. In a later lecture, these expressions will control which instructions a program executes.

---

# 20. Common Beginner Errors

## Confusing `=` with `==`

```c
score = 100;     // Assignment
score == 100;    // Equality comparison
```

---

## Expecting a decimal result from integer division

```c
float result = 5 / 2;       // Stores 2.0
float result = 5.0f / 2;    // Stores 2.5
```

---

## Forgetting parentheses in an average

Incorrect:

```c
average = score1 + score2 + score3 / 3.0f;
```

Correct:

```c
average = (score1 + score2 + score3) / 3.0f;
```

---

## Using `x` for multiplication

Incorrect:

```c
area = length x width;
```

Correct:

```c
area = length * width;
```

---

## Using one symbol for logical operators

Incorrect:

```c
hasID & isEnrolled
isSenior | isPWD
```

For the logical operations discussed here, use:

```c
hasID && isEnrolled
isSenior || isPWD
```

Single `&` and `|` are different operators in C and should not be substituted for logical AND and OR in these examples.

---

## Writing a chained mathematical comparison

Incorrect:

```c
18 <= age <= 60
```

C does not interpret this in the same way as ordinary mathematical notation.

Correct:

```c
(age >= 18) && (age <= 60)
```

---

## Misreading `!`

```c
!isAvailable
```

means "not available." It does not mean "different from." The not-equal operator is `!=`.

---

## Overcomplicating expressions

Avoid modifying the same variable multiple times inside one expression.

Unsafe and incorrect practice:

```c
result = value++ + ++value;
```

This expression modifies `value` more than once without a defined evaluation order, so its behavior is undefined. It must not be used.

Clear code separates the updates:

```c
value++;
value++;
result = value;
```

Simple expressions are easier to understand, test, and debug.

---

# 21. Reading an Expression Step by Step

Consider:

```c
finalAmount = (price * quantity) - discount;
```

Read it in this order:

```text
1. Get the values of price and quantity.
2. Multiply price by quantity.
3. Subtract discount from the product.
4. Store the result in finalAmount.
```

Consider another expression:

```c
isValid = (score >= 0) && (score <= 100);
```

Read it as:

```text
1. Check whether score is at least 0.
2. Check whether score is at most 100.
3. Combine the two results using logical AND.
4. Store the resulting truth value in isValid.
```

Reading expressions in words helps confirm that they match the intended logic.

---

# 22. Key Relationships

```text
Variables
    ↓
Store values
    ↓
Operators
    ↓
Perform calculations or comparisons
    ↓
Expressions
    ↓
Produce a numerical or logical result
    ↓
Assignment
    ↓
Stores the result in a variable
```

Another way to remember the concepts is:

> **Operands are the data.**  
> **Operators describe the action.**  
> **Expressions produce the result.**

---

# 23. Summary

- An operator tells C to perform an operation.
- An operand is a value or variable used by an operator.
- An expression combines operands and operators to produce a result.
- Arithmetic operators perform calculations.
- Integer division discards the fractional part.
- Floating-point division preserves the fractional part.
- The `%` operator produces the remainder of integer division.
- Assignment stores a value in a variable.
- Compound-assignment operators provide shorter variable updates.
- `++` and `--` increase or decrease a variable by one.
- Relational operators compare values and produce true or false.
- `=` assigns a value, while `==` compares two values for equality.
- `&&`, `||`, and `!` represent logical AND, OR, and NOT.
- In C, zero represents false and a nonzero value represents true.
- Operator precedence determines which operation is evaluated first.
- Parentheses clarify or change the order of evaluation.
- Data types affect the result of an expression.
- Casting temporarily converts a value to another type.
- Mathematical and word statements must be translated into explicit C syntax.
- Clear, simple expressions are easier to verify and maintain.
