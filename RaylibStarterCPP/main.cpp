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
#include "AABB.h"


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

    glm::vec3 boxMin = { 100,100,0 };
    glm::vec3 boxMax = { 200,200,0 };
    AABB box = {boxMin, boxMax};

    glm::vec3 boxMin2 = {150,150,0 };
    glm::vec3 boxMax2 = { 500,500,0 };
    AABB box2 = { boxMin2, boxMax2 };
   
    
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

        //DrawRectangleV({ box2.Center().x, box2.Center().y }, { box2.Extents().x, box2.Extents().y }, YELLOW);
        DrawRectangle(box2.min.x, box2.min.y, box2.Extents().x * 2, box2.Extents().y * 2, YELLOW);
        if (box.Overlaps(box2))
        {
            //DrawRectangleV({ box.Center().x, box.Center().y}, {box.Extents().x, box.Extents().y}, RED);
            DrawRectangle(box.min.x, box.min.y, box.Extents().x * 2, box.Extents().y * 2, RED);
        }
        else
        {
            //DrawRectangleV({ box.Center().x, box.Center().y }, { box.Extents().x, box.Extents().y }, BLACK);
            DrawRectangle(box.min.x, box.min.y, box.Extents().x * 2, box.Extents().y * 2, BLACK);
        }


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