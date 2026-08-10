# Lewcture 1 Introdction to Programming Logic and Design

## Lecture 1: Logic, Computer Systems, and Programming Fundamentals

> **Main idea:** A computer can execute instructions quickly and consistently, but people must design the logic that makes those instructions useful.

---

## Learning Outcomes

At the end of this lecture, students should be able to:

1. Explain why logic is important in engineering.
2. Describe a computer system using the Input-Process-Output-Storage model.
3. Distinguish a problem, logic, algorithm, program, and programming language.
4. Explain how a human solution becomes an executable computer program.
5. Explain the relationship among a problem, algorithm, program, and computer output.

---

# 1. Importance of Logic in Engineering

## What is logic?

**Logic** is an organized way of reasoning that helps us reach a valid conclusion or decide the correct action.

In engineering, logic helps us answer questions such as:

- What problem must be solved?
- What information is available?
- What conditions must be checked?
- What steps must be followed?
- What result should the system produce?
- What could go wrong?

Engineering is not only about building things. It is about designing solutions that are **correct, safe, reliable, efficient, and testable**.

---

## How logic supports engineering

Logic allows engineers to:

- Break a complex problem into smaller parts.
- Arrange operations in the correct sequence.
- Make decisions based on conditions.
- Repeat an operation when necessary.
- Consider normal, boundary, and failure conditions.
- Test whether a proposed solution behaves correctly.
- Explain a solution clearly to other people.

---

## Example: Automatic cooling system

Consider a system that controls a cooling fan.

### Basic requirements

- Read the current temperature.
- Turn the fan on when the temperature is above 30 degrees Celsius.
- Keep the fan off when the temperature is 30 degrees Celsius or below.
- Report an error when the sensor reading is invalid.

### Logical solution

```text
Read the temperature

IF the sensor reading is invalid
    Display an error
ELSE IF the temperature is greater than 30
    Turn the fan ON
ELSE
    Turn the fan OFF
END IF
```

The sensor and fan are hardware, but **logic determines how the system responds**.

> **Key idea:** Hardware performs the action; logic determines when, why, and how the action should happen.

---

## Logic in Computer Engineering

Computer engineers use logic when designing:

- Embedded systems
- Automated machines
- Robots
- Digital circuits
- Control systems
- Communication systems
- Computer programs

For example, a laboratory access system may ask:

```text
Does the student have a valid ID?
Is the student enrolled in the class?
Is the required safety equipment complete?
```

The system grants access only when all required conditions are satisfied.

---

# 2. Brief Introduction to Computer Systems

## What is a computer system?

A **computer system** is a collection of components that work together to receive data, process it according to instructions, produce useful information, and store data or results when necessary.

A complete computer system includes:

| Component  | Description                                    | Examples                                     |
| ---------- | ---------------------------------------------- | -------------------------------------------- |
| Hardware   | Physical components                            | Processor, keyboard, monitor, sensor         |
| Software   | Programs and instructions                      | Operating system, application, C program     |
| Data       | Raw values processed by the system             | Numbers, text, images, measurements          |
| Users      | People who operate or interact with the system | Student, engineer, administrator             |
| Procedures | Rules for operating the system                 | Login procedure, backup process, safety rule |

---

## The Input-Process-Output-Storage model

Most computer systems can be understood through four basic operations:

```text
Input --> Processing --> Output
              |
           Storage
```

### Input

The data or instruction received by the computer.

Examples: keyboard entry, button press, file contents, or sensor reading.

### Processing

The operation performed on the input according to a program.

Examples: calculation, comparison, sorting, or decision-making.

### Output

The information or action produced by the system.

Examples: displayed result, printed report, warning sound, or motor movement.

### Storage

The retention of data or results for later use.

Examples: file, memory card, solid-state drive, or database.

---

## Example: Student grade system

| Operation  | Example                                |
| ---------- | -------------------------------------- |
| Input      | Quiz, activity, and examination scores |
| Processing | Calculate the weighted final grade     |
| Output     | Final grade and pass/fail result       |
| Storage    | Save the student's grade record        |

---

## Capabilities and limitations of computers

### A computer can:

- Execute instructions very quickly.
- Repeat operations consistently.
- Store and retrieve large amounts of data.
- Perform calculations accurately when given correct instructions and data.

### A computer cannot automatically:

- Understand an unclear problem.
- Know what the programmer intended.
- Correct faulty logic by itself.
- Determine whether an answer is meaningful without suitable rules.

> **Garbage In, Garbage Out:** Incorrect data or incorrect logic can produce an incorrect result.

---

# 3. Fundamental Programming Concepts

## Problem

A **problem** is a situation with a current condition and a desired result that requires a solution.

Example:

> Determine whether a student's final grade meets the passing requirement.

---

## Problem-solving

**Problem-solving** is the process of understanding a problem, designing a solution, implementing it, and checking whether it works.

A general problem-solving process is:

```text
1. Understand the problem
2. Identify the inputs and expected outputs
3. Determine the required processing and decisions
4. Design a logical solution
5. Implement the solution
6. Test and correct the solution
7. Improve and document the result
```

---

## Algorithm

An **algorithm** is a finite and ordered set of clear instructions for solving a problem or completing a task.

It describes the logical solution before that solution is written in a particular programming language.

### Simple example

**Problem:** Calculate the area of a rectangle.

```text
1. Get the length.
2. Get the width.
3. Multiply the length by the width.
4. Display the area.
5. Stop.
```

| Input            | Process                 | Output                |
| ---------------- | ----------------------- | --------------------- |
| Length and width | `area = length x width` | Area of the rectangle |

An algorithm helps the programmer organize and examine a solution before dealing with programming-language syntax.

---

## Program

A **program** is a set of instructions written in a form that can be translated and executed by a computer.

A program tells the computer:

- What data to receive
- What operations to perform
- What conditions to evaluate
- What information or action to produce

---

## Programming

**Programming** is more than typing code. It involves:

- Analyzing the problem
- Designing the solution
- Writing source code
- Testing the program
- Finding and correcting errors
- Improving and documenting the solution

> **Key idea:** Coding is one part of programming. Logical problem-solving comes first.

---

## Programming language

A **programming language** is a formal language used to express instructions for a computer.

Examples include C, C++, Java, Python, and JavaScript.

In this course, we will use **C** to implement our solutions.

---

## Compiled and interpreted programming languages

Programming languages are often introduced according to how their programs are translated and executed.

### Compiled languages

In a **compiled language**, a compiler translates the source code into machine code or another executable form before the program is run.

```text
Source code --> Compiler --> Executable program --> Program output
```

Common examples include **C, C++, and Rust**.

#### General advantages

- The translated program usually executes quickly.
- Many errors can be detected before execution.
- The executable program can be run repeatedly without translating the entire source code again.

#### General limitations

- The program must be compiled again after the source code is changed.
- An executable created for one platform may not work directly on another platform.

C is commonly described as a compiled language. We will write C source code, compile it, correct any reported errors, and then run the resulting program.

### Interpreted languages

In an **interpreted language**, an interpreter reads and executes the program through a runtime environment, usually without first producing a standalone machine-code executable in the same way as a traditional C compiler.

```text
Source code --> Interpreter or runtime --> Program output
```

Common introductory examples include **Python, Ruby, and JavaScript**.

#### General advantages

- Programs can often be tested immediately.
- The development process can be convenient and interactive.
- The same source code may run on different systems that have the required interpreter or runtime.

#### General limitations

- The interpreter or runtime is normally required to execute the program.
- Execution may be slower than a directly compiled native program.
- Some errors may only appear when the affected instruction is executed.

### Important note

The distinction is not always absolute. A programming language is a set of rules, while compilation and interpretation are implementation methods. Some systems combine both approaches by compiling code into an intermediate form and executing it through a virtual machine or just-in-time compiler.

For this introductory course, remember the basic distinction:

| Compiled approach                              | Interpreted approach                                   |
| ---------------------------------------------- | ------------------------------------------------------ |
| Translates the program before normal execution | Executes the program through an interpreter or runtime |
| Common example: C                              | Common example: Python                                 |
| Usually produces a separate executable form    | Usually requires the interpreter or runtime            |

---

## Why use C?

C is useful to Computer Engineering students because it:

- Supports structured programming.
- Is efficient and widely used.
- Provides a close connection to computer hardware.
- Is commonly used in embedded systems and microcontrollers.
- Builds concepts that transfer to many other programming languages.

---

## Source code, compiler, and executable program

### Source code

The human-readable instructions written in a programming language. A C source file normally uses the `.c` extension.

### Compiler

A program that translates C source code into a form the computer can execute. It also reports violations of the language's syntax rules.

### Executable program

The translated program that can be run by the computer.

```text
C source code --> Compiler --> Executable program
```

---

## Three general types of programming errors

| Error         | Meaning                                        | Simple example                      |
| ------------- | ---------------------------------------------- | ----------------------------------- |
| Syntax error  | A rule of the programming language is violated | Missing semicolon                   |
| Runtime error | A problem occurs while the program is running  | Attempting an invalid operation     |
| Logic error   | The program runs but produces a wrong result   | Dividing a three-score total by two |

Detailed testing and debugging techniques will be discussed later in the course.

---

# 4. Connecting the Concepts

The main concepts in this lecture are connected as follows:

```text
Real-world engineering problem
              |
              v
     Logical problem-solving
              |
              v
          Algorithm
              |
              v
       C source code
              |
              v
          Compiler
              |
              v
     Executable program
              |
              v
        Computer output
              |
              v
      Testing and improvement
```

The computer is the tool that performs the instructions. The programmer is responsible for designing instructions that correctly solve the problem.

---

# 5. Individual Activity: Design Your Own System

## Objective

Apply engineering logic and the Input-Process-Output-Storage model by designing a useful computer-controlled system.

## Instructions

Create your own useful computer-controlled system. It may address a problem at home, in school, in the community, or in an engineering environment.

Examples include an automatic device, monitoring system, safety system, record-management program, or decision-support program. Do not copy an existing example exactly.

Submit one page containing:

1. **System name**
2. **Purpose** - What problem does it solve?
3. **Input** - What data, signal, or user entry does it receive?
4. **Processing** - What calculations, comparisons, or decisions does it perform?
5. **Output** - What information or action does it produce?
6. **Storage** - What information should it save, if any?
7. **Program logic** - Write detailed, numbered steps showing how the system operates from start to finish, including at least one decision or condition.

The instructions must be clear enough that another person could understand exactly how the proposed system should work.

## Example Output

### System Name

**Smart Classroom Energy Saver**

### Purpose

The system reduces wasted electricity by controlling classroom lights based on room occupancy and available daylight.

### Input

- Occupancy-sensor reading
- Light-sensor reading
- Manual override button

### Processing

- Determine whether the classroom is occupied.
- Determine whether the room is already bright enough.
- Check whether the manual override is active.

### Output

- Turn the classroom lights on or off.
- Display the current lighting status.

### Storage

- Time when the lights were turned on or off
- Estimated duration of light usage

### Program Logic

```text
1. Start the system.
2. Read the occupancy sensor, light sensor, and manual override button.
3. If the manual override is active, use the setting selected by the user.
4. Otherwise, check whether the classroom is occupied.
5. If the classroom is empty, turn the lights off.
6. If the classroom is occupied, check the amount of available daylight.
7. If the room is dark, turn the lights on; otherwise, keep them off.
8. Display and record the current lighting status.
9. Continue monitoring the classroom.
```

---

# 6. Summary

- Logic provides an organized method for designing engineering solutions.
- A computer system combines hardware, software, data, users, and procedures.
- A computer accepts input, processes it, produces output, and may store data.
- Computers follow the instructions provided; they do not automatically understand human intention.
- Programming includes problem analysis, solution design, coding, testing, and improvement.
- An algorithm describes the logical solution before it is implemented as a program.
- C will be our main tool for translating algorithms into executable programs.

---

# 7. Review Questions

1. Why is logic important in engineering?
2. What are the major components of a computer system?
3. Differentiate input, processing, output, and storage.
4. Why can a computer produce a wrong answer even when a program runs successfully?
5. What is the difference between a problem, an algorithm, and a program?
6. What is the role of a compiler?
7. Why is programming more than writing source code?
8. How does an algorithm connect a real-world problem to a C program?
9. What is the basic difference between compiled and interpreted execution?
