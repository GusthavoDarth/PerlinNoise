
# Perlin Noise Terrain Generator

![GitHub repo size](https://img.shields.io/github/repo-size/GusthavoDarth/PerlinNoise)
![GitHub stars](https://img.shields.io/github/stars/GusthavoDarth/PerlinNoise?style=social)
![GitHub license](https://img.shields.io/github/license/GusthavoDarth/PerlinNoise)

![GIF do programa em ação](https://github.com/GusthavoDarth/PerlinNoise/blob/main/gif/perlin_noise.gif)

## 📋 Description

This project is a real-time Perlin noise generator written in C, designed to create natural-looking procedural terrain textures. It demonstrates core concepts used in game development (like Minecraft's terrain generation) and computer graphics: algorithmic noise generation, interpolation, and visual output.

The program displays a grayscale grid representing Perlin noise values, which can be dynamically updated and have its resolution changed.

## 🎮 Controls

- **Interactive generation:** Press `SPACE` to generate a new random noise grid.
- **Resolution control:** Press `UP` and `DOWN` arrow keys to increase or decrease the grid resolution.
- **Two visualization modes:** Press `1` or `2` to toggle between different visual representations of the noise (e.g., grayscale vs. color mapping).

## 🚀 How to Run

### Dependencies

- **Raylib**: The project uses the [Raylib](https://www.raylib.com/) library for graphics and input. You need to have it installed on your system.
  - On **Windows**, you can download the pre-compiled library from the [official site](https://www.raylib.com/) or use a package manager like vcpkg.
  - On **Linux**, you can install it via your package manager (e.g., `sudo apt install libraylib-dev` on Debian/Ubuntu).
  - On **macOS**, you can use Homebrew: `brew install raylib`.

### Compilation

This project includes a **Makefile** for easy compilation. After installing Raylib:

1.  Clone the repository:
    ```bash
    git clone https://github.com/GusthavoDarth/PerlinNoise.git
    ```
2.  Navigate to the project directory:
    ```bash
    cd PerlinNoise
    ```
3.  Run `make` to compile the program:
    ```bash
    make
    ```
    This will generate an executable named `Perlin` (or `Perlin.exe` on Windows).

### Running

- After compilation, simply run the executable:
  ```bash
  ./Perlin      # Linux/macOS
  Perlin.exe    # Windows
