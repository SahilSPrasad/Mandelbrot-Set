
# Mandelbrot Fractal Visualizer

This C++ application renders and explores the **Mandelbrot set** using a graphical interface built on **FLTK**. It includes interactive zooming, panning via user input, and unit tests to validate internal logic.

---

## Features

- Mandelbrot fractal rendering at pixel level.
- Interactive zoom and center control (real & imaginary components).
- Built-in unit tests for key logic and math functions.
- Coloring based on escape-time iteration count.
- GUI controls using Stroustrup-style FLTK wrappers (`Simple_window`, `In_box`, etc.).

---

## Project Structure

- `main.cpp` — App entry point and unit tests.
- `ComplexPlane.cpp` — Handles fractal generation and rendering.
- `ZoomWindow.cpp` — GUI logic for user input and image refreshing.
- `GUI/` — Contains `Simple_window`, `Window`, `Graph`, and `GUI` source files.

---

## Build Instructions

### Requirements

- C++17 or later
- [FLTK](https://www.fltk.org/) (Fast Light Toolkit)
- Bjarne Stroustrup's FLTK GUI headers (e.g., `Simple_window.h`, `GUI.h`)

### Build Using Makefile

Make sure FLTK and GUI headers are correctly referenced in the Makefile:

```bash
make
````

To clean up object files:

```bash
make clean
```

To run the app after build:

```bash
make run
```

---

## Usage

1. Launch the app (`./MandelbrotVisualizer`).
2. Enter:

   * **Center r** (real part of center)
   * **Center i** (imaginary part of center)
   * **Zoom Level**
3. Click the GUI button to re-render the Mandelbrot set with new settings.

---

## Unit Tests

When the program starts, unit tests are executed:

* Prompts you to enter test values in the GUI.
* Automatically tests:

  * `mapRange()`
  * `countIterations()`
  * `writePixel()`

Console output will show test results and score.

---

## Example Settings

Try zooming in on interesting parts of the Mandelbrot set:

* Zoom: `50.0`
* Center r: `-0.7453`
* Center i: `0.1127`

These reveal intricate details and spirals.

---

## To Do

* [ ] Mouse-based zooming/panning
* [ ] Save rendered image to PNG
* [ ] Support Julia sets
* [ ] Multithreaded or GPU-based rendering

---

