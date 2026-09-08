# COS214_Prac_4
A hierarchical film-production work-management system, built to demonstrate the Composite, Iterator, State, and Decorator design patterns working together as one coherent system.

We are modelling: a film production, broken into Act -> Sequence -> Scene -> Shot. Shots move through a real lifecycle (Scripted -> Shooting -> Approved, with reshoots looping back), some shots carry optional stacked responsibilities (insurance, priority handling), and the whole tree can be traversed either completely or filtered to only what's currently urgent.

Team
Ngeletshedzo Mutwanamba (u25039769)
Ishmael Ngwasheng
Takunda Mugwagwa (u24667341)

--- Building and running locally ---

From the project root:

bash
make
./taskforge

To clean up build artifacts:

bash
make clean
Building and running with Docker

The Dockerfile installs g++, make, gdb, and valgrind, copies the project in, and builds it automatically on image creation.

Build the image:

bash
docker build -t taskforge .

Run it interactively (drops you into a bash shell inside the container, with the built taskforge binary already sitting in /taskforge):

bash
docker run -it taskforge

Once inside the container, run the program as normal:

bash
./taskforge

If you'd rather rebuild from scratch inside the container instead of using the image's pre-built binary:

bash
make clean
make
./taskforge

--- Debugging with GDB ---

Build with debug symbols (already included via -g in the Makefile), then:

bash
gdb -q ./taskforge

Inside GDB, to reproduce the state-transition investigation documented in our PDF:

gdb
break Shot::advance
run
n            # if prompted about debuginfod, decline
print this->state->getName()
next
print this->state->getName()

This shows a Shot's internal state pointer being swapped from Scripted to Shooting as a result of advance(), confirming the State pattern performs a genuine object swap at runtime rather than an internal flag change.

--- Checking memory with Valgrind ---
bash
valgrind --leak-check=full --show-leak-kinds=all ./taskforge

Expected result: 0 bytes in use at exit, all heap blocks freed, 0 errors.