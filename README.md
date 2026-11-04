# Task-Taker

A small, fast command-line to-do manager written in C++. Add tasks, update them, track their progress, and list them by status, all from your terminal. Tasks are stored in a plain text file in the directory you run the program from, so every project folder can have its own to-do list.

![Task-Taker demo](assets/demo.gif)

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Development](#development)

## Features

- Add, update and delete tasks
- Track progress with three statuses: `todo`, `in-progress` and `done`
- List all tasks, or filter by status
- Per-directory task lists (stored in a local `.tasks` file)
- Changes are saved to disk immediately
- No dependencies beyond the C++ standard library
- Object-oriented design with a separate `Task` and `TaskManager`
- Makefile with incremental builds, `install` and `uninstall` targets

## Requirements

- A C++17 compatible compiler (GCC 9+, Clang 10+)
- `make`

On Debian/Ubuntu, `sudo apt install build-essential` provides both. On macOS, run `xcode-select --install`. On Windows, use WSL.

## Installation

### 1. Clone the repository

```bash
git clone https://github.com/ChamalInd/Task-Taker.git
cd Task-Taker
```

### 2. Build

```bash
make
```

This compiles the sources into `build/` and produces an executable named `task-cli` in the project root.

You can override the compiler or flags if needed:

```bash
make CXX=clang++
make CXXFLAGS="-std=c++17 -O0 -g"
```

**Without make:**

```bash
g++ -std=c++17 -Wall -Wextra -o task-cli main.cpp scripts/libraries/*.cpp
```

### 3. Run

```bash
./task-cli help
```

### 4. (Optional) Install system-wide

```bash
sudo make install      # installs to /usr/local/bin
task-cli help          # now usable from anywhere
```

Install somewhere else with `make install PREFIX=$HOME/.local`. To remove it later, run `sudo make uninstall` (or `make uninstall PREFIX=$HOME/.local` to match).

## Usage

```
task-cli <command> [arguments]
```

| Command | Description |
| --- | --- |
| `add "<task>"` | Add a new task. It starts with the status `todo`. |
| `update <task-id> "<new-task>"` | Change the description of an existing task. |
| `delete <task-id>` | Delete a task. |
| `mark-in-progress <task-id>` | Set a task's status to `in-progress`. |
| `mark-done <task-id>` | Set a task's status to `done`. |
| `list` | List all tasks. |
| `list todo` | List only tasks with status `todo`. |
| `list in-progress` | List only tasks with status `in-progress`. |
| `list done` | List only tasks with status `done`. |
| `help` | Print the help message. |

Running `task-cli` with no arguments prints a short hint to use `help`.

**Notes**

- Wrap task descriptions in quotes so the shell treats them as a single argument.
- Task IDs are shown when you list tasks and when you create one.
- When a task is deleted, the remaining tasks are renumbered, so run `list` before deleting several tasks in a row.
- A command with the wrong number of arguments prints an error and exits with code `1`.

## Examples

### Add some tasks

```console
$ task-cli add "Write project proposal"
New Task Created Successfully. [ID : 1]

$ task-cli add "Review pull requests"
New Task Created Successfully. [ID : 2]
```

### Update progress

```console
$ task-cli mark-in-progress 1
Task 1: Marked as in-progress.

$ task-cli mark-done 2
Task 2: Marked as done.
```

### Change a description

```console
$ task-cli update 1 "Write and send project proposal"
Task 1: Description changed as Write and send project proposal.
```

### List tasks

```console
$ task-cli list
1:
Description: Write and send project proposal
Status: in-progress

2:
Description: Review pull requests
Status: done
```

```console
$ task-cli list done
2:
Description: Review pull requests
Status: done
```

### Delete a task

```console
$ task-cli delete 2
Task with ID 2 has been removed.
```

## Project Structure

```
Task-Taker/
├── main.cpp                      # Entry point and command-line parsing
├── Makefile                      # Build rules
├── README.md
├── .gitignore
├── assets/
│   └──demo.gif                   # A demo video of the application
└── scripts/
    ├── headers/
    │   ├── includes.h            # Shared standard-library includes
    │   ├── task.h                # Task class declaration
    │   └── task-manager.h        # TaskManager class declaration
    └── libraries/
        ├── task.cpp              # Task implementation
        └── task-manager.cpp      # TaskManager implementation
```

## Development

### Build targets

| Command | What it does |
| --- | --- |
| `make` | Build the `task-cli` executable |
| `make clean` | Remove the `build/` directory and the executable |
| `make install` | Install to `/usr/local/bin` (override with `PREFIX=...`) |
| `make uninstall` | Remove the installed binary |

The Makefile generates dependency files (`.d`) next to each object file, so editing a header only rebuilds the files that include it.

### Debug build with sanitizers

Sanitizers catch out-of-range accesses and undefined behaviour early:

```bash
make clean
make CXXFLAGS="-std=c++17 -g -Wall -Wextra -fsanitize=address,undefined"
```

### Resetting your data

To start fresh, delete the `.tasks` file in your working directory:

```bash
rm .tasks
```
