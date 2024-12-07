# ParallelGoL
A multithreaded implementation of Conway's Game of Life

## Building
To build the executable:
  - Ensure CMake is installed
  - Clone this repo, and go to its local directory
  - Run the following commands:
      - `mkdir build`
      - `cd build`
      - `cmake ..`
      - `cmake --build .`

## Usage
This implementation of Conway's game of Life takes text files for the intial state.
In these text files there are two legal characters:
  - `0` Represents a live cell
  - `*` Represents a dead cell


New lines are ignored, and the starting state must be a square (the width matches the height) See the `examples` directory for an example of a valid starting state.
