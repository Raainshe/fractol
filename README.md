# Fractal Viewer

A graphical program that renders interactive Mandelbrot and Julia sets using the MLX42 library. This project is part of the 42 School curriculum.

## Features

- Interactive Mandelbrot set visualization
- Multiple Julia set variations with customizable parameters
- Smooth color gradients based on iteration count
- Real-time interaction capabilities:
  - Zoom in/out using mouse scroll
  - Pan using arrow keys
  - Smooth window termination with ESC key

## Prerequisites

- GCC compiler
- CMake (for MLX42 library)
- GLFW library
- Git (for cloning the repository)

## Installation

1. Clone the repository:
```bash
git clone https://github.com/Raainshe/fractol.git
cd fractol
```

2. Build the project:
```bash
make
```

This will automatically:
- Build the MLX42 library
- Compile the libft library
- Create the executable 'fractol'

## Usage

Run the program with one of the following commands:

For Mandelbrot set:
```bash
./fractol mandelbrot
```

For Julia set (with various preset parameters):
```bash
./fractol julia <real> <imaginary>
```

Recommended Julia set parameters:
- `./fractol julia -0.4 0.6`
- `./fractol julia -0.123 0.745`
- `./fractol julia 0.36 0.1`
- `./fractol julia -0.391 -0.587`
- `./fractol julia -0.7269 0.1889`
- `./fractol julia -0.75 0.0`
- `./fractol julia 0.285 0.01`

## Controls

- **Arrow Keys**: Move around the fractal
- **Mouse Scroll**: Zoom in/out
- **ESC**: Close window
- **Window Close Button**: Terminate program

## Technical Details

- Resolution: 800x800 pixels
- Maximum iterations: 50
- Color scheme: RGB based on iteration count
- Smooth rendering with double-precision calculations

## Project Structure

- `fractol.c`: Main program logic and initialization
- `mandelbrot.c`: Mandelbrot set calculations and rendering
- `julia.c`: Julia set calculations and rendering
- `hooks.c`: Event handling for user interactions
- `initialise.c`: Setup and initialization functions
- `para_checks.c`: Parameter validation and error handling

## Dependencies

- [MLX42](https://github.com/codam-coding-college/MLX42): Graphics library
- Custom libft library: String manipulation and standard functions

## Error Handling

The program includes comprehensive error checking for:
- Invalid command line arguments
- Memory allocation failures
- MLX initialization errors
- Invalid Julia set parameters

## License

This project is part of the 42 School curriculum and is intended for educational purposes.

## Author

- rmakoni (42 Heilbronn)
