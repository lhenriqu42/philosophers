# Philosophers

This project simulates the classic "Dining Philosophers" problem using multithreading in C. The goal is to manage the behavior of philosophers who alternate between thinking, eating, and sleeping while avoiding deadlocks and ensuring that all philosophers get a chance to eat.

## Table of Contents

- [Philosophers](#philosophers)
  - [Table of Contents](#table-of-contents)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Building the Project](#building-the-project)
    - [Running the Project](#running-the-project)
  - [Project Structure](#project-structure)
  - [Usage](#usage)

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Make

### Building the Project

To build the project, navigate to the `philo` directory and run the following command:

```sh
make
```

This will compile the source files and create the `philo` executable.

### Running the Project

To run the project, use the following command:

```sh
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [times_each_philosopher_must_eat]
```

- `<number_of_philosophers>`: The number of philosophers (and forks).
- `<time_to_die>`: Time in milliseconds before a philosopher dies if they don't start eating.
- `<time_to_eat>`: Time in milliseconds it takes for a philosopher to eat.
- `<time_to_sleep>`: Time in milliseconds a philosopher spends sleeping.
- `[times_each_philosopher_must_eat]` (optional): Number of times each philosopher must eat before the simulation ends. If not specified, the simulation will run indefinitely.

Example:

```sh
./philo 5 800 200 200
```

## Project Structure

```
philo/
├── includes/
│   ├── colors.h
│   ├── ft_malloc.h
│   ├── ft_mutex.h
│   └── philosophers.h
├── src/
│   ├── errors.c
│   ├── exec.c
│   ├── init.c
│   ├── main.c
│   ├── task.c
│   ├── thread.c
│   ├── validation.c
│   └── utils/
│       ├── ft_malloc.c
│       ├── ft_mutex.c
│       ├── lib.c
│       ├── time.c
│       └── utils.c
├── Makefile
└── .gitignore
```

## Usage

After building the project, you can run the executable with the desired parameters. The philosophers will start their routines, and you will see their actions printed in the terminal.