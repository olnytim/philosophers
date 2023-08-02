# Philosophers Project - 42 School

## Description
The "Philosophers" project is part of the curriculum at 42 school and focuses on applying multithreading and synchronization concepts in C to solve the "Dining Philosophers Problem."

## The Dining Philosophers Problem
The Dining Philosophers Problem is a classic synchronization problem in computer science. It involves a group of philosophers sitting around a circular table, with each philosopher holding a fork on their left and right. To eat, a philosopher needs both forks. However, there are only as many forks as there are philosophers, and the philosophers must share forks.

The challenge is to design a solution that prevents deadlocks (where all philosophers are waiting for a fork indefinitely) and avoids resource contention (multiple philosophers trying to grab the same fork simultaneously).

## Project Objectives
The goal of this project is to implement a solution for the Dining Philosophers Problem using threads and synchronization mechanisms in C. The implementation should satisfy the following requirements:

1. Philosophers must alternate between eating, sleeping, and thinking.
2. A philosopher can only eat if they have both forks (left and right).
3. Each fork is shared between two neighboring philosophers.
4. There should be no deadlocks or resource contention.

## Project Requirements
- The project must be written in C language.
- The solution should use threads and synchronization mechanisms like mutexes and/or semaphores.
- The program should take three arguments: the number of philosophers, the time to die (in milliseconds), and the time to eat/think/sleep (in milliseconds).
- The program must output the actions of each philosopher and their state (eating, sleeping, thinking).
- The program should terminate gracefully if any philosopher dies.

## How to Run the Program
1. Clone the repository or copy the project files to your local machine.
2. Compile the project using the appropriate compiler (e.g., gcc).
3. Run the compiled executable with the required arguments (e.g., ./philosophers 5 800 200 200).

## Additional Notes
- The "Philosophers" project is meant to challenge students' understanding of concurrency and synchronization. It requires careful design to ensure that the solution is deadlock-free and efficient.