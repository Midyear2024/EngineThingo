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


#include "TankGameScene.h"
#include "GameManager.h"
#include "Sphere.h"
#include "Transform.h"
#include <string>
#include "AABB.h"
#include "Plane.h"


#pragma warning(pop)



int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------

    SetTargetFPS(120);

    GameManager::GetGameManager().Init();
 
    

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        const float frameTime = GetFrameTime();
        const int fps = GetFPS();
        GameManager::GetGameManager().Run(frameTime);
    }
    //delete sceneRoot;
    //delete gameObject1;
    //delete sceneRoot;
    
    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}