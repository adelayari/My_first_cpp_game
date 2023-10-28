# My First Game

![Game Screenshot](https://github.com/adelayari/My_first_cpp_game/assets/69399646/03d59420-879d-4dc4-b236-04d9c42097ba)

## Description

This is "My First Game". It's a simple game developed using the [raylib](https://www.raylib.com/) library and c/c++.

## How to Play

- Use the arrow keys to move the circle.
- Avoid collisions with the moving rectangle.
- If you collide with the rectangle, the game will be over.
- You can restart the game by clicking the "Start" button.


## Author

**© 2023 AYARI Adel**
- LinkedIn: [AYARI Adel - LinkedIn](https://www.linkedin.com/in/ayari-adel-esim/)


## License

This game is not licensed and is available for educational purposes.

# How to Use

To compile and run "My First Game," follow these steps:

1. Open your terminal or command prompt.

2. Navigate to the project directory.

3. Run the following command to build the game:

   ```bash
   g++ src/main.cc -o main.exe -O2 -Wall -Wno-enum-compare -Wno-missing-braces -I./include -I./include/raylib-cpp -L./lib -lraylib -mwindows -lopengl32 -lgdi32 -lwinmm -mno-sse
4. After successful compilation, run the game using:
    ```bash
    ./main.exe
5. Enjoy playing "My First Game"!
