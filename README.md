
# Perlin Noise Terrain Generator

![GitHub repo size](https://img.shields.io/github/repo-size/GusthavoDarth/PerlinNoise)
![GitHub stars](https://img.shields.io/github/stars/GusthavoDarth/PerlinNoise?style=social)
![GitHub license](https://img.shields.io/github/license/GusthavoDarth/PerlinNoise)

[**AQUI VOCÊ DEVE ADICIONAR UM GIF MOSTRANDO O PROGRAMA EM AÇÃO, COM AS TECLAS ESPAÇO E SETAS MUDANDO O RUÍDO**]

## 📋 Description

This project is a real-time Perlin noise generator written in C, designed to create natural-looking procedural terrain textures. It demonstrates core concepts used in game development (like Minecraft's terrain generation) and computer graphics: algorithmic noise generation, interpolation, and visual output.

The program displays a grayscale grid representing Perlin noise values, which can be dynamically updated and have its resolution changed.

## 🎮 Controls

- **Interactive generation:** Press `SPACE` to generate a new random noise grid.
- **Resolution control:** Press `UP` and `DOWN` arrow keys to increase or decrease the grid resolution.
- **Two visualization modes:** Press `1` or `2` to toggle between different visual representations of the noise (e.g., grayscale vs. color mapping).

## How to Run

### Prerequisites
- GCC compiler (or any C compiler)
- Windows (for the compiled .exe) or compile for your OS.

### Compilation from Source
1.  Clone the repository:
    ```bash
    git clone https://github.com/GusthavoDarth/PerlinNoise.git
    ```
2.  Navigate to the project directory:
    ```bash
    cd PerlinNoise
    ```
3.  Compile the code:
    ```bash
    gcc -o Perlin Perlin.c -Iinclude
    ```
    *(Adjust the `-Iinclude` flag if your header files are in a different location.)*

### Running
- **On Windows:** Double-click the `Perlin.exe` file.
- **On Linux/macOS:** Run `./Perlin` from the terminal in the project directory.

### Compilation
Navigate to the project root and run:
```bash
gcc -o Perlin Perlin.c -Iinclude
