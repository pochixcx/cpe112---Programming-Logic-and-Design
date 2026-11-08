# Strings: Representation, Operations, and Applications

**Course:** Programming Logic and Design  
**Language:** C

## Learning Objectives

After studying this lecture, the student should be able to:

1. Explain what a string is and how C represents one.
2. Declare, initialize, and access a string stored in a character array.
3. Use common functions from `<string.h>` to measure, copy, join, and compare strings.
4. Read and display strings while accounting for the array's capacity.
5. Apply strings to simple problems and trace string-processing code.

**Prior knowledge assumed:** variables, `char`, arrays, loops, functions, and basic `printf`/`scanf`.

---

## 1. Introduction

Programs often need to process text: a person's name, a menu choice, a product code, or a sentence. In C, text is commonly represented as a **string**: a sequence of characters ending with a special character called the **null character**.

Unlike some programming languages, C does not have a separate built-in string data type. Understanding how strings are stored helps prevent common errors such as reading past an array's capacity or forgetting the null character.

---

## 2. How C Represents Strings

### 2.1 A String Is a Character Array with a Terminator

A C string is stored in consecutive `char` elements and ends with the **null character**, written as `'\0'`. The null character marks where the text ends. It is not the same as the character `'0'`.

```c
char word[] = "CAT";
```

The compiler reserves four elements: three for the visible letters and one for the null character.

```text
index:     0      1      2      3
        +------+------+------+------+
word    | 'C'  | 'A'  | 'T'  | '\0' |
        +------+------+------+------+
```

The string has **3 characters**, but the array has **4 elements**. The final element is required so that string functions and output functions know where the text ends.

### 2.2 Declaration and Initialization

```c
char greeting[6] = "Hello";   /* 5 letters plus '\0' */
char city[] = "Cebu";         /* compiler reserves 5 elements */
char empty[10] = "";          /* an empty string: first element is '\0' */
```

The array must have room for every character **and** the terminating `'\0'`. For example, `"Hello"` needs 6 elements, not 5.

These are different:

```c
char letter = 'A';       /* one character */
char text[] = "A";       /* a string: 'A' followed by '\0' */
```

Single quotes denote a character constant; double quotes denote a string literal.

### 2.3 String Literals and Character Arrays

A string literal such as `"Hello"` includes a terminating null character. It can be used to initialize a character array:

```c
char message[] = "Hello";
```

Once initialized, `message` is an array whose elements can be changed individually:

```c
message[0] = 'h';    /* message now contains "hello" */
```

However, an array cannot be assigned a new string using `=` after its declaration:

```c
/* message = "Hi"; */  /* invalid: arrays cannot be assigned */
```

Use an appropriate string function to copy text into an existing character array, as discussed later.

### 2.4 Capacity, Length, and the Null Character

These terms describe different things:

- **Capacity:** the total number of elements reserved in the character array.
- **Length:** the number of characters before the first `'\0'`.
- **Terminator:** the `'\0'` element that marks the end of the string.

For `char name[20] = "Mina";`, the capacity is 20, the length is 4, and the string terminator is at index 4. The remaining elements are not part of the string.

Always keep the terminator within the array. If it is missing, functions expecting a C string may continue reading beyond the array, causing undefined behavior.

---

## 3. Reading and Displaying Strings

### 3.1 Displaying a String

Use `%s` with `printf` to display a null-terminated string:

```c
char name[] = "Mina";
printf("Name: %s\n", name);
```

`printf` prints characters until it reaches `'\0'`. It does not know the array's capacity, so the string must be properly terminated.

### 3.2 Reading a Word with `scanf`

The `%s` conversion reads a sequence of non-whitespace characters and stops at a space, tab, or newline.

```c
char firstName[20];

printf("Enter a first name: ");
scanf("%19s", firstName);
```

The field width `19` limits the input to at most 19 characters, leaving one element for `'\0'`. The width must be one less than the array capacity. Without a suitable width, input that is too long can write beyond the array.

`scanf("%s", ...)` is suitable for a single word, but not for a full name or sentence because it stops at whitespace.

### 3.3 Reading a Line with `fgets`

Use `fgets` when the input may contain spaces. It reads at most one fewer character than the array capacity and adds `'\0'` when it reads input successfully.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char fullName[50];

    printf("Enter your full name: ");
    if (fgets(fullName, sizeof fullName, stdin) != NULL)
    {
        fullName[strcspn(fullName, "\n")] = '\0';
        printf("Hello, %s!\n", fullName);
    }

    return 0;
}
```

`fgets` may keep the newline character if it fits in the array. The expression `strcspn(fullName, "\n")` finds the position of the first newline, if one is present. Replacing that character with `'\0'` removes it; if no newline was read, the expression finds the existing terminator and leaves the string correctly terminated.

If a line is longer than the array can hold, `fgets` reads only part of it. The remaining input stays in the input stream and may need to be handled separately in a larger program.

Do not use `gets`; it cannot limit how many characters are read and can overflow the destination array.

---

## 4. Common String Operations

The standard string functions are declared in the `<string.h>` header. They expect valid null-terminated strings. When a function writes to a destination array, that array must have enough capacity for the result, including `'\0'`.

### 4.1 Finding the Length: `strlen`

`strlen` returns the number of characters before `'\0'`. It does not count the terminator.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[] = "banana";
    size_t length = strlen(word);

    printf("Length: %zu\n", length);
    return 0;
}
```

**Output:**

```text
Length: 6
```

`size_t` is the type used for sizes and lengths. The `%zu` format specifier displays a `size_t` value.

### 4.2 Copying: `strcpy`

`strcpy(destination, source)` copies the source string, including its terminating `'\0'`, into the destination.

```c
char source[] = "Logic";
char copy[10];

strcpy(copy, source);     /* copy now contains "Logic" */
```

The destination needs at least `strlen(source) + 1` elements. `strcpy` does not check the destination's capacity.

### 4.3 Joining: `strcat`

`strcat(destination, source)` appends the source characters to the end of the destination string. The destination must already contain a valid string and have room for the combined text and its terminator.

```c
char greeting[20] = "Good";

strcat(greeting, " morning");   /* greeting now contains "Good morning" */
```

The destination needs capacity for `strlen(destination) + strlen(source) + 1` elements before the call.

### 4.4 Comparing: `strcmp`

`strcmp(first, second)` compares two strings character by character.

- It returns `0` when the strings are equal.
- It returns a value less than `0` when the first string comes before the second.
- It returns a value greater than `0` when the first string comes after the second.

The exact nonzero return value is not specified; test whether the result is less than, equal to, or greater than zero.

```c
char answer[] = "yes";

if (strcmp(answer, "yes") == 0)
{
    printf("The answers match.\n");
}
```

Use `strcmp` to compare string contents. The `==` operator does not compare the text stored in two character arrays.

### 4.5 Accessing and Traversing Characters

Because a string is stored in a character array, a loop can inspect each character. The loop can stop when it reaches `'\0'`.

```c
char word[] = "CAT";

for (int i = 0; word[i] != '\0'; i++)
{
    printf("%c\n", word[i]);
}
```

The loop visits `'C'`, `'A'`, and `'T'`, then stops at the terminator. It does not print `'\0'`.

### 4.6 Summary of Common Functions

| Function | Purpose | Important condition |
| -------- | ------- | ------------------ |
| `strlen(s)` | Finds the number of characters in `s` | `s` must be null-terminated |
| `strcpy(dest, src)` | Copies `src` into `dest` | `dest` must fit the source and `'\0'` |
| `strcat(dest, src)` | Appends `src` to `dest` | `dest` must fit both strings and `'\0'` |
| `strcmp(a, b)` | Compares string contents | Check whether the result is `< 0`, `== 0`, or `> 0` |

These functions do not automatically prevent a destination overflow. Before copying or joining strings, ensure the destination capacity is sufficient.

---

## 5. Worked Example: Build and Compare a Display Name

**Problem:** Given a first name and a family name, form a display name and check whether it matches an expected name.

**Input:** Two names stored in the program.  
**Output:** The combined name and whether it matches the expected name.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char firstName[] = "Mina";
    char familyName[] = "Reyes";
    char displayName[40];

    strcpy(displayName, firstName);
    strcat(displayName, " ");
    strcat(displayName, familyName);

    printf("Display name: %s\n", displayName);

    if (strcmp(displayName, "Mina Reyes") == 0)
    {
        printf("The names match.\n");
    }
    else
    {
        printf("The names do not match.\n");
    }

    printf("Number of characters: %zu\n", strlen(displayName));
    return 0;
}
```

**Output:**

```text
Display name: Mina Reyes
The names match.
Number of characters: 10
```

The display name contains 10 characters, including the space, plus a terminating `'\0'`. The `displayName` array has 40 elements, so it has enough capacity for the combined string and its terminator. The program uses `strcpy` to initialize the destination string, `strcat` to append the separator and family name, `strcmp` to compare contents, and `strlen` to measure the result.

---

## 6. String Use Cases

Strings are useful whenever a program needs to store or process text.

### 6.1 Names and Labels

Store a student's name, a menu label, or a product description in a character array. Use `fgets` if the text may contain spaces.

```c
char productName[40] = "Notebook";
printf("Product: %s\n", productName);
```

### 6.2 Matching Commands or Categories

Compare a user's choice against known options using `strcmp`:

```c
char choice[] = "save";

if (strcmp(choice, "save") == 0)
{
    printf("Saving...\n");
}
```

String comparisons are case-sensitive: `"Save"` and `"save"` are different strings.

### 6.3 Counting or Analyzing Text

Traverse characters to count letters that meet a condition. For example, this fragment counts lowercase vowels:

```c
int vowelCount = 0;

for (int i = 0; text[i] != '\0'; i++)
{
    if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' ||
        text[i] == 'o' || text[i] == 'u')
    {
        vowelCount++;
    }
}
```

This example intentionally counts only lowercase vowels. Handling uppercase letters would require adding those cases or converting characters before testing.

### 6.4 Formatting Information for Display

Use string operations to combine separate pieces of text, such as a first name and family name. Plan the destination array's capacity before joining them.

---

## 7. Common Errors to Avoid

1. **Forgetting the terminator:** `"CAT"` requires four elements, including `'\0'`.
2. **Confusing capacity with length:** an array's capacity may be larger than the text it currently stores.
3. **Comparing with `==`:** use `strcmp` to compare string contents.
4. **Copying into a small destination:** `strcpy` and `strcat` do not check destination capacity.
5. **Using `%s` for a sentence:** `%s` input stops at whitespace; use `fgets` to read a line.
6. **Using an unbounded `%s` input:** provide a field width that leaves room for `'\0'`.
7. **Using a string function on a non-string array:** the array must contain a `'\0'` within its bounds.
8. **Using `gets`:** it cannot protect the destination from overly long input.

---

## 8. Exercises

Write and test each program. Unless a task says otherwise, assume input fits within the arrays you declare and ensure every stored string is null-terminated.

### Exercise 1: Personal Greeting

Read a person's full name, including spaces, into a character array and display:

```text
Welcome, <name>!
```

Use `fgets`. Remove the newline if it was stored.

### Exercise 2: String Inspector

Read a line of text and report:

- its length;
- the number of lowercase vowels (`a`, `e`, `i`, `o`, `u`); and
- the number of spaces.

Do not count the null character as part of the text.

### Exercise 3: Compare Two Words

Read two single-word choices and determine whether they are identical using `strcmp`. If they are not identical, report which one comes first according to `strcmp`'s result. Do not assume the function returns exactly `-1` or `1`.

### Exercise 4: Construct a Product Label

Store a product category and product name in separate strings. Construct a label in the form:

```text
<category>: <product>
```

Display the label and its length. Choose a destination array large enough for both parts, the punctuation, the space, and the null character.

---

## 9. Key Takeaways

- C represents a string as characters ending with the null character `'\0'`.
- The character array must have capacity for all text characters plus the terminator.
- `strlen`, `strcpy`, `strcat`, and `strcmp` provide common string operations through `<string.h>`.
- Copying and concatenating require careful destination-capacity planning.
- Use `fgets` to read a line that may contain spaces, and use a field width with `%s` when reading a single word with `scanf`.
- Use `strcmp` to compare string contents; `==` does not perform that comparison for character arrays.
