## Philosophers

### 🗺️ Project Description

The Philosophers project involves solving the dining philosophers problem using threads and synchronization mechanisms. The aim is to find a solution where the philosophers alternate between eating, thinking, and sleeping while adhering to certain constraints to avoid resource conflicts and ensure fairness in their actions.

### 🍝 Key Features

Philosophers Simulation: Simulates a specific number of philosophers sitting around a table, each with their own fork and plate of spaghetti.

Concurrency & Threads: Uses threads to represent each philosopher and simulate their actions concurrently.

Eating, Thinking, Sleeping: Philosophers alternate between three states: eating, thinking, and sleeping based on specific rules to avoid conflicts.

Synchronization: Implements synchronization mechanisms (mutex, semaphore, etc.) to control access to shared resources (forks, plates, etc.) and prevent race conditions.

Avoiding Deadlock: Ensures that no deadlock occurs among the philosophers, meaning that they can continue to perform their actions without getting stuck in a state where none can proceed. So we can use mutexes to lock memory resources.

### 🚀 How to Run
To compile and execute the Philosophers program, follow these steps:

#### Compilation:

```shell
make
```

#### Execution:

```shell
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [optional: number_of_times_each_philosopher_must_eat]
```

Replace number_of_philosophers, time_to_die, time_to_eat, and time_to_sleep with appropriate numerical values for the simulation parameters. The last parameter is optional and represents the number of times each philosopher must eat before the program stops.
