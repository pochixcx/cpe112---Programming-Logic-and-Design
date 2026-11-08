# Structures in C: Modeling Related Data

**Course:** Programming Logic and Design  
**Language:** C

## Learning Objectives

After studying this lecture, the student should be able to:

1. Explain what a structure is and why a program may use one.
2. Define a structure type and declare, initialize, and access its members.
3. Distinguish a structure from an array and use an array of structures.
4. Model a more complex object by nesting structures and combining them with arrays.
5. Pass structures to functions and use structure pointers to update records.
6. Design a small C program that represents and processes real-world records.

**Prior knowledge assumed:** variables, data types, arrays, strings, functions, and loops. Pointers are introduced where needed.

---

## 1. Introduction: Keeping Related Information Together

Suppose a program stores information about a product. For each product, it needs an ID, a name, a price, and a quantity in stock. Separate arrays could store each kind of information:

```c
int ids[100];
char names[100][30];
double prices[100];
int quantities[100];
```

The program must remember that `ids[4]`, `names[4]`, `prices[4]`, and `quantities[4]` all describe the same product. If one array is sorted or updated differently from the others, the records can become mismatched.

A **structure** lets a programmer define one type that groups those related values under one name:

```c
struct Product
{
    int id;
    char name[30];
    double price;
    int quantity;
};
```

Each individual value inside a structure is called a **member** or **field**. A `struct Product` value represents one product, and each member represents one piece of that product's data.

---

## 2. Why Use Structures?

An array groups many values of the **same type**. A structure groups related values that can have **different types**.

| Structure | Array |
| --------- | ----- |
| Groups related members, which may have different types | Groups elements of one type |
| Members are accessed by name, such as `product.price` | Elements are accessed by index, such as `prices[0]` |
| Often represents one record or object | Often represents a collection or sequence |

Structures are useful because they:

- keep the fields belonging to one record together;
- give the fields meaningful names;
- make it easier to pass a complete record to a function;
- allow arrays of records, such as a class list or inventory; and
- support modeling objects composed of smaller objects.

The word **object** here means a thing represented by a program, such as a product or student. A C structure stores data; unlike objects in some other languages, a C `struct` does not automatically include methods.

---

## 3. Defining and Using a Structure

### 3.1 Define a Structure Type

A structure definition describes the members that every value of that type will have:

```c
struct Student
{
    int id;
    char name[40];
    double score;
};
```

This defines the type `struct Student`; it does not, by itself, create a student variable. The definition normally appears before the functions that use that type.

### 3.2 Declare Structure Variables

After the type is defined, declare variables of that type:

```c
struct Student student1;
struct Student student2;
```

Each variable has its own `id`, `name`, and `score` members.

Variables may also be declared as part of the definition:

```c
struct Point
{
    int x;
    int y;
} origin, destination;
```

For teaching and readability, it is often clearer to define the type first and declare variables separately.

### 3.3 Access Members with the Dot Operator

Use the dot operator (`.`) to access a member of a structure variable:

```c
student1.id = 1001;
student1.score = 92.5;

printf("ID: %d\n", student1.id);
printf("Score: %.1f\n", student1.score);
```

The member name is written after the variable name. `student1.score` means the `score` member of `student1`.

### 3.4 Initialize a Structure

An initializer list supplies values in the order the members appear in the definition:

```c
struct Student student1 = {1001, "Mina Reyes", 92.5};
```

C99 also supports **designated initializers**, which identify members by name:

```c
struct Student student2 = {
    .id = 1002,
    .name = "Kai Santos",
    .score = 87.0
};
```

Designated initializers make it easier to see which value belongs to which member. The string must still fit in the `name` array, including its terminating `'\0'`.

### 3.5 Update Members

Members can be updated individually:

```c
student1.score = 95.0;
```

An entire structure can also be assigned to another variable of the same structure type:

```c
student2 = student1;
```

This copies the member values, including the contents of any array members. However, an array member cannot be assigned a new string directly:

```c
/* student1.name = "Mina"; */   /* invalid: arrays cannot be assigned */
```

To change an existing string member, use a suitable string function and make sure the member has enough capacity:

```c
#include <string.h>

strcpy(student1.name, "Mina");
```

---

## 4. Arrays of Structures

Most programs need to keep multiple records. An array of structures stores multiple values of the same record type:

```c
struct Student classList[3] = {
    {1001, "Mina Reyes", 92.5},
    {1002, "Kai Santos", 87.0},
    {1003, "Ari Cruz", 90.0}
};
```

The array index selects a student; the dot operator selects a member of that student:

```c
printf("%s\n", classList[1].name);   /* Kai Santos */
classList[2].score = 94.0;
```

Use a loop to process all the records:

```c
for (int i = 0; i < 3; i++)
{
    printf("%d: %s, %.1f\n",
           classList[i].id,
           classList[i].name,
           classList[i].score);
}
```

The expression `classList[i].score` means: select element `i` of the array, then access that element's `score` member.

---

## 5. Modeling More Complex Objects

A real-world record can contain smaller structured parts. For example, a date has a month, day, and year; an appointment has a date, time, and description.

```c
struct Date
{
    int month;
    int day;
    int year;
};

struct Appointment
{
    char description[50];
    struct Date date;
    int hour;
    int minute;
};
```

The `date` member is itself a structure. This is called a **nested structure**. It represents the idea that an appointment has a date, and that date has its own fields.

```c
struct Appointment meeting = {
    .description = "Project meeting",
    .date = {11, 12, 2026},
    .hour = 14,
    .minute = 30
};

printf("%s\n", meeting.description);
printf("%02d/%02d/%04d\n",
       meeting.date.month,
       meeting.date.day,
       meeting.date.year);
```

Nested structures help avoid a flat list of unrelated field names. They also allow a type such as `struct Date` to be reused in appointments, orders, or student records.

A structure can also contain arrays, other structures, and ordinary values together:

```c
struct Course
{
    char code[10];
    char title[50];
};

struct StudentRecord
{
    int id;
    char name[40];
    struct Course courses[5];
    int courseCount;
};
```

`StudentRecord` combines an ID, a name, and a collection of courses. This is a more detailed data model made by composing simpler parts.

---

## 6. Structures and Functions

### 6.1 Passing a Structure by Value

A function can receive a structure as a parameter. Passing by value gives the function a copy:

```c
double getScore(struct Student student)
{
    return student.score;
}
```

Changing a member of `student` inside this function would not change the caller's original structure, because the parameter is a copy.

A function can also return a structure:

```c
struct Point makePoint(int x, int y)
{
    struct Point result = {x, y};
    return result;
}
```

Returning a structure by value returns its member values to the caller.

### 6.2 Passing a Structure Pointer to Modify the Original

To let a function update the caller's structure, pass its address. Use `->` to access a member through a structure pointer:

```c
void addStock(struct Product *product, int amount)
{
    product->quantity += amount;
}
```

Call the function with the address of a structure variable:

```c
struct Product item = {101, "Notebook", 2.50, 20};
addStock(&item, 5);
```

In the parameter declaration, `struct Product *product` means `product` is a pointer: a variable that holds the address of a `struct Product`. The `&` operator obtains the address of `item`, so the function receives access to the original variable rather than a copy. After the call, `item.quantity` is 25. For a pointer `product`, the expression `product->quantity` is shorthand for `(*product).quantity`.

Use a structure pointer when the function must modify the original record or when copying a large structure would be unnecessary. For small records that only need to be read, passing by value may be simpler.

---

## 7. Type Names with `typedef`

Writing `struct Student` each time can be verbose. `typedef` creates a shorter alias for a type:

```c
typedef struct
{
    int id;
    char name[40];
    double score;
} Student;
```

Now variables can be declared as `Student`:

```c
Student student1 = {1001, "Mina Reyes", 92.5};
```

Both `struct Student` and `typedef` style are common in C. The alias does not change how the structure works; it only provides another name for the type.

---

## 8. Worked Program: Small Product Inventory

**Problem:** Store several products, display each product's information and inventory value, and calculate the value of all products in stock.

**Input:** The product records are initialized in the program.  
**Output:** Each product's details and the combined inventory value.

```c
#include <stdio.h>

#define PRODUCT_COUNT 3

typedef struct
{
    int id;
    char name[30];
    double unitPrice;
    int quantity;
} Product;

double productValue(Product product)
{
    return product.unitPrice * product.quantity;
}

double inventoryValue(Product products[], int count)
{
    double total = 0.0;

    for (int i = 0; i < count; i++)
    {
        total += productValue(products[i]);
    }

    return total;
}

int main(void)
{
    Product products[PRODUCT_COUNT] = {
        {101, "Notebook", 2.50, 20},
        {102, "Pencil", 0.75, 50},
        {103, "Folder", 1.80, 15}
    };

    for (int i = 0; i < PRODUCT_COUNT; i++)
    {
        printf("%d  %-10s  $%.2f each  Quantity: %d  Value: $%.2f\n",
               products[i].id,
               products[i].name,
               products[i].unitPrice,
               products[i].quantity,
               productValue(products[i]));
    }

    printf("Total inventory value: $%.2f\n",
           inventoryValue(products, PRODUCT_COUNT));

    return 0;
}
```

**Output:**

```text
101  Notebook    $2.50 each  Quantity: 20  Value: $50.00
102  Pencil      $0.75 each  Quantity: 50  Value: $37.50
103  Folder      $1.80 each  Quantity: 15  Value: $27.00
Total inventory value: $115.50
```

Each `Product` keeps an ID, name, unit price, and quantity together. `products` is an array of those records. The loop selects each record by index, then reads its members. `productValue` calculates the value for one product, and `inventoryValue` adds those values.

`productValue` receives a copy of one record because it only needs to read its members. The inventory function receives the array and its element count; the count is provided separately because a C array parameter does not carry its length.

---

## 9. Common Errors and Good Practices

1. **Using a member before defining its structure type:** define the type before functions and variables that use it.
2. **Confusing array indexing and member access:** use `records[i].member` for a member in array element `i`.
3. **Using `==` to compare strings:** use `strcmp` to compare character-array string contents.
4. **Trying to assign an array member directly:** use an appropriate string operation for a character-array member.
5. **Overfilling a character-array member:** ensure the text and its `'\0'` fit within the member's capacity.
6. **Forgetting that a by-value parameter is a copy:** pass a pointer when a function must change the caller's structure.
7. **Assuming a structure's memory size is just the sum of its member sizes:** C may add padding between members; use `sizeof` when the actual size is needed.
8. **Putting unrelated data into one structure:** group fields that describe one coherent record or concept.

---

## 10. Key Takeaways

- A structure is a programmer-defined type that groups related members, possibly of different types.
- The dot operator accesses a member of a structure variable; the arrow operator accesses a member through a structure pointer.
- An array of structures represents many records of the same kind.
- Nested structures and arrays let a program represent more complex data in organized parts.
- Structures can be passed to and returned from functions. Passing by value copies the record; passing a pointer lets a function access or modify the original.
- Structures make data easier to organize, process, and understand when related values belong together.
