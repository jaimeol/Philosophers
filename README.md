# Philosophers Project - My Project at 42

Welcome to my Philosophers project!

## Summary
The **Philosophers** project is a simulation of the "Dining Philosophers" problem, a classic synchronization challenge in computer science. The task is to manage multiple threads to simulate philosophers who alternate between thinking, eating, and sleeping, while avoiding deadlocks and ensuring that no philosopher starves.

## Implementation
This project requires the creation of a multithreaded program where each philosopher is represented by a thread. The philosophers sit around a table, and there is a fork between each of them. To eat, a philosopher must pick up the fork on their left and right simultaneously. The challenge is to implement a solution that prevents deadlocks and race conditions.

### Core Concepts:
- **Philosophers and Forks:** Philosophers alternate between three states: thinking, eating, and sleeping. To eat, they need two forks — one from the left and one from the right.
- **Mutex Locks:** Mutexes are used to ensure that no two philosophers can pick up the same fork at the same time.
- **Avoiding Deadlock:** The project requires implementing a strategy to avoid deadlock, where every philosopher is waiting indefinitely for a fork.

### Parameters:
The program takes the following command-line arguments:
1. `number_of_philosophers`: The number of philosophers and forks.
2. `time_to_die`: Maximum time (in milliseconds) a philosopher can go without eating before they die.
3. `time_to_eat`: Time (in milliseconds) a philosopher spends eating.
4. `time_to_sleep`: Time (in milliseconds) a philosopher spends sleeping.
5. `(optional) number_of_meals`: If specified, the simulation stops once each philosopher has eaten this number of times.

### Example:
```sh
./philo 5 800 200 200
