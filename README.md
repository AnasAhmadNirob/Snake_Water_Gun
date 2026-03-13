# Snake Water Gun Game (C)

This project was developed as part of my **CSE-1210 course** at university.  
It is a simple console-based **Snake-Water-Gun game** implemented in the **C programming language** to practice basic programming concepts.

---

## Project Description

This is a simple C-based game where the **user chooses a number** and the **computer randomly generates another number**.  
Based on predefined game logic, the program compares both choices and determines the **winner of each round**.

The game runs for several rounds and finally displays the **final score**.  
It also saves the game results in a file so that previous score history can be viewed later.

---

## Features

- Interactive **menu-based system**
- **Random number generation** for computer moves
- **Score tracking system**
- **File handling** to store and display score history
- **ASCII graphics** for better console interface
- Modular program design using **multiple functions**

---

## Concepts Used

The following C programming concepts were used in this project:

- Struct
- Pointer
- File Handling
- Random Number Generation
- Menu System
- ASCII Graphics
- Function Modularization
- Arrays and Strings
- Conditional Statements
- Loops

---

## Game Rules

0 → Snake  
1 → Water  
2 → Gun  

Game Logic:

- Snake drinks Water → Snake wins  
- Water damages Gun → Water wins  
- Gun kills Snake → Gun wins  
- Same choices → Draw  

---

## Files Used

- `main.c` → Main source code of the project  
- `score.txt` → Stores previous game score history  

---

## How to Run

Compile the program:

```
gcc main.c -o game
```

Run the program:

```
./game
```

---

## Learning Purpose

This project was created to improve my understanding of:

- C programming fundamentals
- Function design and modular coding
- File input/output operations
- Basic game logic implementation

---

## Author

**Anas Ahmad Nirob**  
ECE Student
KUET
