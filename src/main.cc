/* 

******************************************************************
*                       MY FIRST GAME                            *
*                       by AYARI Adel (c) 2023                   *
******************************************************************

*/

#include "raylib.h"



#define BACKGROUND_COLOR CLITERAL   (Color){244,217,174,255}
#define CIRCLE_COLOR CLITERAL       (Color){222,158,70,255}
#define RECTANGLE_COLOR CLITERAL    (Color){44, 109, 109,255}
#define GAME_OVER CLITERAL          (Color){204, 79, 65,255}

int main()
{

    // Screen size:
    const int width{500};
    const int heigth{500};
    
    // Circle coordinates:
    int circle_x{width / 5} , circle_y{heigth / 2};
    double circle_radius{20};

    //Circles edges:
    int l_circle_x{circle_x - (int)circle_radius};
    int r_circle_x{circle_x + (int)circle_radius};
    int u_circle_y{circle_y - (int)circle_radius};
    int b_circle_y{circle_y + (int)circle_radius};

    // Rectangle coordinates:
    int axe_x{width/2}, axe_y{heigth/2};

    // Rectangle edges:
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + (int)(circle_radius * 2)};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + (int)(circle_radius * 4)};

    int direction{5};
    bool collision_with_axe = (l_circle_x <= r_axe_x) &&
                              (r_circle_x >= l_axe_x) &&
                              (u_circle_y <= b_axe_y) &&
                              (b_circle_y >= u_axe_y);

    InitWindow(width,heigth,"AYARI FIRST GAME");

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        
        if (collision_with_axe)
        {
            DrawText("Game over!",190,200,20,GAME_OVER);
            // Draw a "Start" button
            Rectangle startButton = {190, 240, 110, 40};
            DrawRectangleLinesEx(startButton, 2, GAME_OVER);
            DrawText("Start", 215, 250, 20, GAME_OVER);

            // © AYARI Adel
            DrawText("© AYARI Adel", 210, 350, 10, GAME_OVER);

            // 
            if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                collision_with_axe = false;
                // Reset other game variables to their initial state
                circle_x = width / 5;
                circle_y = heigth / 2;
                axe_x = width / 2;
                axe_y = heigth / 2;
                direction = 5;
            }
            
        }else
        {
            // Game logic begins:

            // Update edges:
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + circle_radius * 2;
            u_axe_y = axe_y;
            b_axe_y = axe_y + circle_radius * 4;

            // Update collision with axes:
            collision_with_axe = (l_circle_x <= r_axe_x) && (r_circle_x >= l_axe_x) && (u_circle_y <= b_axe_y) && (b_circle_y >= u_axe_y);

            DrawCircle(circle_x, circle_y, circle_radius, CIRCLE_COLOR);
            DrawRectangle(axe_x, axe_y, circle_radius * 2, circle_radius * 4, RECTANGLE_COLOR);

            

            // Update circle postion:
            if (IsKeyDown(KEY_RIGHT) && circle_x < width - circle_radius)       circle_x = circle_x + 10;
            if (IsKeyDown(KEY_LEFT) && circle_x > circle_radius)                circle_x = circle_x - 10;
            if (IsKeyDown(KEY_DOWN) && circle_y < heigth - circle_radius)       circle_y = circle_y + 10;
            if (IsKeyDown(KEY_UP) && circle_y > circle_radius)                  circle_y = circle_y - 10;

            // Update rectangle position 
            axe_y += direction;
            if(axe_y > 500 - 4*circle_radius || axe_y < 0) direction = -direction;
            
            
            //Game logic ends:
        }

        EndDrawing();
    }
    return 0;
}