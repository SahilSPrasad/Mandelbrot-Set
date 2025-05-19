# Mandelbrot Fractal Visualizer

This C++ application renders and explores the **Mandelbrot set** using a graphical interface built on **FLTK**. It includes interactive zooming, panning via user input, and unit tests to validate internal logic.

---

## 📸 Features

- 🌀 **Mandelbrot fractal rendering** at pixel level.
- 🎛️ **Interactive zoom and center control** (real & imaginary components).
- 📦 **Custom GUI with FLTK**, including input boxes and redrawing functionality.
- 🧪 **Built-in unit tests** to validate mathematical functions and rendering logic.
- 🎨 **Coloring based on escape-time iteration count.**

---

## 🧩 Components

### `ComplexPlane`
- Maps screen pixels to complex numbers.
- Iterates Mandelbrot function per pixel.
- Calculates coloring based on iteration count.
- Uses FLTK's `fl_draw_image` for display.

### `ZoomWindow`
- Inherits from `Simple_window`.
- Adds user inputs:
  - Real center (`Center r`)
  - Imaginary center (`Center i`)
  - Zoom level
- Refreshes the fractal on user interaction.

### `main.cpp`
- Runs the application.
- Launches the Mandelbrot viewer.
- Contains `unitTests()` for correctness verification.

---

## 🛠️ Build Instructions

### 🔧 Requirements

- **C++17**
- **FLTK** library
- Optional: [Stroustrup's GUI library](https://www.stroustrup.com/Programming/Graphics/) (for `Simple_window`, `In_box`, `Point`, etc.)

### 🧱 Compile

```bash
g++ -std=c++17 main.cpp ComplexPlane.cpp ZoomWindow.cpp -lfltk -lfltk_images -o MandelbrotVisualizer
