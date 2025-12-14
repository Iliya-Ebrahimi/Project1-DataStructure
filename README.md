# Project1-DataStructure  
**Mathematical Expression Evaluation using an Expression Tree**

## Project Team Members
- Iliya Ebrahimi  
- Mohammad Parsa Hassani  
- Alireza Sadr  
- Mobina Hassanzadeh  

## Overview
This project is implemented as part of the **Data Structures and Algorithms** course. It builds a **mathematical expression evaluator** that:
1. Parses an input string,
2. Constructs an **Expression Tree**,
3. Evaluates the final result while fully respecting **operator precedence** and parentheses.

---

## Key Features

The project processes mathematical expressions through a multi-stage pipeline:

### 1. Input Normalization (`normalizer.cpp`)
Cleans and simplifies the raw input expression:
- **Sign simplification**: Converts sequences like `++-+-` into a single `+` or `-`.
- **Whitespace removal**: Eliminates all unnecessary spaces.
- **Implicit multiplication**: Automatically inserts `*` where multiplication is implied (e.g., `2(3+4)` → `2*(3+4)`).

### 2. Variable Management (`variable_manager.cpp`)
Replaces variables in the expression with their assigned numeric values.

### 3. Tokenization (`tokenizer.cpp`)
Splits the normalized expression into tokens (numbers, variables, operators, parentheses).

### 4. Expression Tree Construction (`buildTree.cpp`)
Builds the expression tree using a **Recursive Descent Parser** to correctly reflect operator precedence:
- **Operator precedence (highest to lowest)**:
  1. Exponentiation (`^`) and square root (`√`)
  2. Multiplication (`*`) and division (`/`)
  3. Addition (`+`) and subtraction (`-`)
- Parentheses are fully supported to override default precedence.

### 5. Expression Evaluation (`CalculateTree.cpp`)
Computes the final value by performing a **post-order traversal** of the expression tree.

---

## Supported Operators
| Operator | Description      |
|----------|------------------|
| `+`      | Addition         |
| `-`      | Subtraction      |
| `*`      | Multiplication   |
| `/`      | Division         |
| `^`      | Exponentiation   |
| `√`      | Square root      |

---

## Error Handling
The evaluator includes robust error-checking for:
- **Division by zero**
- **Square root of a negative number**
- **Unbalanced parentheses** (e.g., extra `(` or `)`)

---

## Project Structure

| File                    | Description |
|-------------------------|-------------|
| `normalizer.cpp`        | Implements input normalization logic |
| `tokenizer.cpp`         | Tokenizes the mathematical expression |
| `variable_manager.cpp`  | Handles variable substitution |
| `buildTree.cpp`         | Defines `TreeNode` and builds the expression tree |
| `CalculateTree.cpp`     | Evaluates the expression via tree traversal |

---

## Technology Stack
- **Language**: C++
- **Version Control**: GitHub