/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#pragma warning( push , 0)
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include <raygui.h>
#include <glm/glm.hpp>
#include "GameObject.h"
#include "Sphere.h"
#include "Transform.h"
#include <string>

#pragma warning(pop)

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(120);
   
    

    GameObject* sceneRoot = new GameObject(new MyTransform(glm::vec3(screenWidth / 2, screenHeight / 2, 0)));
    GameObject* gameObject1 = new Sphere(new MyTransform(glm::vec3(0, 0,0), 0.785, glm::vec3{1,2,1}), sceneRoot, 50, BLUE);
    
   
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        const float frameTime = GetFrameTime();
        const int fps = GetFPS();
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        gameObject1->Update(frameTime);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        sceneRoot->Draw();
        DrawText(std::to_string(fps).c_str(), 0, 0, 32, BLACK);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
   // delete sceneRoot;
    delete gameObject1;
    delete sceneRoot;
    
    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}