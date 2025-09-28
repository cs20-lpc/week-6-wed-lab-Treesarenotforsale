[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/tK_n8eql)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=20754189&assignment_repo_type=AssignmentRepo)
# Week 6 Wed Lab

## Directions

For this lab activity, you are going to practice writing tail recursive functions. The starting code contains five recursive functions that we've studied so far in class. Your job is to refactor the functions to be tail recursive (so yes, you can change the parameter list). Do not rely on the compiler automatically optimizing for you, write the tail recursion yourself. The `main` function has already been written for you to run test cases.

Creating a tail recursive version of the Fibonacci function is tricky. But if you do it right, it will reduce the time complexity from $\mathcal{O}(2^n)$ to $\mathcal{O}(n)$. Amazing improvement!

## Sample Run

The following is what your program should display (quickly!) if you converted all the functions into tail recursion:

```text
6 * 123000 = 738000
3 ^ 10 = 59049
8 * 9 * ... * 15 = 259459200
10! = 3628800
50th Fibonacci number is 3996334433
```

