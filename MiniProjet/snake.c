/*******************************************************************************************
*
*   raylib - classic game: snake
*
*   Sample game developed by Ian Eito, Albert Martos and Ramon Santamaria
*
*   This game has been created using raylib v1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <time.h>
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Some Defines
//----------------------------------------------------------------------------------
#define SNAKE_LENGTH   256
#define SQUARE_SIZE     31

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef struct Snake {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Snake;

typedef struct Ennemy {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    bool active;
    Color color;
    int kills;
} Ennemy;

typedef struct Laser {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    bool active;
    Color color;
} Laser;

typedef struct Food {
    Vector2 position;
    Vector2 size;
    bool active;
    Color color;
} Food;

struct Laser listOfLasers[15];

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

static int framesCounter = 0;
static bool gameOver = false;
static bool pause = false;

static Food fruit = { 0 };
static Snake snake[SNAKE_LENGTH] = { 0 };

static Food gunfood= {0};
static Ennemy ennemy = {0};



static Vector2 snakePosition[SNAKE_LENGTH] = { 0 };
static bool allowMove = false;
static Vector2 offset = { 0 };
static int counterTail = 0;

//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(void);  // Update and Draw (one frame)

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "classic game: snake");

    InitGame();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update and Draw
        //----------------------------------------------------------------------------------
        UpdateDrawFrame();
        //----------------------------------------------------------------------------------
    }
#endif
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame();         // Unload loaded data (textures, sounds, models...)

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Module Functions Definitions (local)
//------------------------------------------------------------------------------------

// Initialize game variables
void InitGame(void)
{
    framesCounter = 0;
    gameOver = false;
    pause = false;

    counterTail = 1;
    allowMove = false;

    offset.x = screenWidth%SQUARE_SIZE;
    offset.y = screenHeight%SQUARE_SIZE;

    for (int i = 0; i < SNAKE_LENGTH; i++)
    {
        snake[i].position = (Vector2){ offset.x/2, offset.y/2 };
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };

        if (i == 0) snake[i].color = DARKGREEN;
        else snake[i].color = GREEN;
    }

    for (int i = 0; i < SNAKE_LENGTH; i++)
    {
        snakePosition[i] = (Vector2){ 0.0f, 0.0f };
    }

    fruit.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    fruit.color = RED;
    fruit.active = false;
    listOfLasers[0].active = false;
    for (int i = 1; i < 5; i++)
    {
        listOfLasers[i].active = false;
    }
    
    
    
    
    
    ennemy.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    ennemy.color = BLACK;
    ennemy.active = false;
    ennemy.kills = 0;
    
    gunfood.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    gunfood.color = YELLOW;
    gunfood.active = false;
    gunfood.position=(Vector2){-100,-100};
    
   
}



// Update game (one frame)
void UpdateGame(void)
{
    if (!gameOver)
    {
        if (IsKeyPressed('P')) pause = !pause;

        if (!pause)
        {
            // Player control
            if (IsKeyPressed(KEY_RIGHT) && (snake[0].speed.x == 0) && allowMove)
            {
                snake[0].speed = (Vector2){ SQUARE_SIZE, 0 };
                allowMove = false;
            }
            if (IsKeyPressed(KEY_LEFT) && (snake[0].speed.x == 0) && allowMove)
            {
                snake[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
                allowMove = false;
            }
            if (IsKeyPressed(KEY_UP) && (snake[0].speed.y == 0) && allowMove)
            {
                snake[0].speed = (Vector2){ 0, -SQUARE_SIZE };
                allowMove = false;
            }
            if (IsKeyPressed(KEY_DOWN) && (snake[0].speed.y == 0) && allowMove)
            {
                snake[0].speed = (Vector2){ 0, SQUARE_SIZE };
                allowMove = false;
            }
            
            // ajout du laser lorsqu'on presse espace
            
            	if (IsKeyPressed(KEY_SPACE))
            	
           	 {
           	 
           	 int a = 0;
           	 if (gunfood.active) {
           	 while (listOfLasers[a].active==true){
           	
           	    a+=1;
           	 
           	 }
           	 }
           	 if ( listOfLasers[a].active==false) {
            		listOfLasers[a].size = (Vector2){ 0.5*SQUARE_SIZE, 0.5*SQUARE_SIZE };
   			listOfLasers[a].color = RED;
            		listOfLasers[a].position =(Vector2){ snake[0].position.x+snake[0].speed.x+0.25*SQUARE_SIZE, snake[0].position.y+0.25*SQUARE_SIZE+snake[0].speed.y };
              	  listOfLasers[a].speed = (Vector2){ 0.5*snake[0].speed.x, 0.5*snake[0].speed.y };
              	  
             	      listOfLasers[a].active = true;
              	  }
              }
      
              
            

            // Snake movement
            for (int i = 0; i < counterTail; i++) snakePosition[i] = snake[i].position;

            if ((framesCounter%5) == 0)
            {
                for (int i = 0; i < counterTail; i++)
                {
                    if (i == 0)
                    {
                        snake[0].position.x += snake[0].speed.x;
                        snake[0].position.y += snake[0].speed.y;
                        allowMove = true;
                    }
                    else snake[i].position = snakePosition[i-1];
                }
            }
            // Laser mouvement
            for (int i =0; i<5;i++) {
            if ((framesCounter%1) == 0 )
            {
             	
             		
            			listOfLasers[i].position.x += listOfLasers[i].speed.x;
            			listOfLasers[i].position.y += listOfLasers[i].speed.y;   
            		
            	}      	
            }
            
            // Ennemy position 
            if ((framesCounter%8) == 0)
            {
            	ennemy.position.x += ennemy.speed.x;
            	ennemy.position.y += ennemy.speed.y;            	
            }
            

            // Wall behaviour
            if (((snake[0].position.x) > (screenWidth - offset.x)) ||
                ((snake[0].position.y) > (screenHeight - offset.y)) ||
                (snake[0].position.x < 0) || (snake[0].position.y < 0))
            {
                gameOver = true;
            }
            // Wall behaviour laser
             for (int i =0; i<5;i++) {
            if(listOfLasers[i].active)
            
           	 if (((listOfLasers[i].position.x) > (screenWidth - offset.x)) ||
           	     ((listOfLasers[i].position.y) > (screenHeight - offset.y)) ||
           	     (listOfLasers[i].position.x < 0) || (listOfLasers[i].position.y < 0))
          	  {	
           	    listOfLasers[i].active = false;
          	  }
          	}  
	    // Wall behaviour ennemy
            if(ennemy.active )
            	
           	 if (((ennemy.position.x) > (screenWidth - offset.x)) ||
           	     ((ennemy.position.y) > (screenHeight - offset.y)) ||
           	     (ennemy.position.x < 0) || (ennemy.position.y < 0))
          	  {
           	    ennemy.active = false;		
          	  }
          	  
          	  
            // Collision with yourself	
            for (int i = 1; i < counterTail; i++)
            {
                if ((snake[0].position.x == snake[i].position.x) && (snake[0].position.y == snake[i].position.y)) gameOver = true;
            }
            
            // Collision with ennemy	
 	    for (int i = 0; i < counterTail; i++)
            {
                if ((snake[i].position.x == ennemy.position.x) && (snake[i].position.y == ennemy.position.y)  ) {
                   if (i ==0 ) {
                  	 gameOver = true;
                   }
                   else if (counterTail>1) {
                     for (int j = 0; j < counterTail-i; j++){
                      
                       snake[counterTail].position = snakePosition[counterTail + 1];
                       counterTail -= 1;
                       
                     }
                   }  
                }
                
            }
            
            // Fruit position calculation
            if (!fruit.active)
            {
                fruit.active = true;
               
                fruit.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };

                for (int i = 0; i < counterTail; i++)
                {
                    while ((fruit.position.x == snake[i].position.x) && (fruit.position.y == snake[i].position.y))
                    {
                        fruit.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };
                        i = 0;
                    }
                }
            }
            
            
            // Gunfood position calculation
           
            if (ennemy.kills == 5)
            {
            	
                ennemy.kills = 0;
                
               
                gunfood.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };

                for (int i = 0; i < counterTail; i++)
                {
                    while ((gunfood.position.x == snake[i].position.x) && (gunfood.position.y == snake[i].position.y))
                    {
                        gunfood.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };
                        i = 0;
                    }
                }
            }
            
            // Ennemy position calculation

	    if (!ennemy.active )
            {
            	int rdm;		
                ennemy.active = true;
                rdm = GetRandomValue(0,3);
                
                // Spawn en haut
                if (rdm==0) {
                	ennemy.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2 , offset.y/2  };
                	ennemy.speed = (Vector2){ 0, SQUARE_SIZE };
                }
                // Spawn à gauche
                else if (rdm==1) {
                	ennemy.position = (Vector2){ ((screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2 , GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };	
                	ennemy.speed = (Vector2){ -SQUARE_SIZE, 0 };
                }
                
                // Spawn en bas
                else if (rdm==2) {
                	ennemy.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2 , ((screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };	
                	ennemy.speed = (Vector2){ 0, -SQUARE_SIZE };
                }
                // Spawn à droite
                else 	  {
                	ennemy.position = (Vector2){ offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };	
                	ennemy.speed = (Vector2){ SQUARE_SIZE, 0 };
                }
               
            }

            // Collision
            if ((snake[0].position.x < (fruit.position.x + fruit.size.x) && (snake[0].position.x + snake[0].size.x) > fruit.position.x) &&
                (snake[0].position.y < (fruit.position.y + fruit.size.y) && (snake[0].position.y + snake[0].size.y) > fruit.position.y))
            {
                snake[counterTail].position = snakePosition[counterTail - 1];
                counterTail += 1;
                fruit.active = false;
            }
            
            // Collision avec gunfood
            if ((snake[0].position.x < (gunfood.position.x + gunfood.size.x) && (snake[0].position.x + snake[0].size.x) > gunfood.position.x) &&
                (snake[0].position.y < (gunfood.position.y + gunfood.size.y) && (snake[0].position.y + snake[0].size.y) > gunfood.position.y))
            {
            	gunfood.position = (Vector2) {-100,-100};
                gunfood.active=true;
            }
            // Collision missile ennemy
             for (int i =0; i<5;i++) {
            if ((listOfLasers[i].position.x < (ennemy.position.x + ennemy.size.x) && (listOfLasers[i].position.x + listOfLasers[i].size.x) > ennemy.position.x) &&
                (listOfLasers[i].position.y < (ennemy.position.y + ennemy.size.y) && (listOfLasers[i].position.y + listOfLasers[i].size.y) > ennemy.position.y))
            {
                
                listOfLasers[i].active = false;
                ennemy.kills +=1;
                ennemy.active = false;
                
            }
            }
          
           
            

            framesCounter++;
        }
    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            InitGame();
            gameOver = false;
        }
    }
}

// Draw game (one frame)
void DrawGame(void)
{
    BeginDrawing();

        ClearBackground(RAYWHITE);

        if (!gameOver)
        {
            // Draw grid lines
            for (int i = 0; i < screenWidth/SQUARE_SIZE + 1; i++)
            {
                DrawLineV((Vector2){SQUARE_SIZE*i + offset.x/2, offset.y/2}, (Vector2){SQUARE_SIZE*i + offset.x/2, screenHeight - offset.y/2}, LIGHTGRAY);
            }

            for (int i = 0; i < screenHeight/SQUARE_SIZE + 1; i++)
            {
                DrawLineV((Vector2){offset.x/2, SQUARE_SIZE*i + offset.y/2}, (Vector2){screenWidth - offset.x/2, SQUARE_SIZE*i + offset.y/2}, LIGHTGRAY);
            }

            // Draw snake
            for (int i = 0; i < counterTail; i++) DrawRectangleV(snake[i].position, snake[i].size, snake[i].color);
            
           // Draw laser
            for (int i =0; i<5;i++) {
            DrawRectangleV(listOfLasers[i].position, listOfLasers[i].size, listOfLasers[i].color);
	    }
            // Draw fruit to pick
            DrawRectangleV(fruit.position, fruit.size, fruit.color);
            
            // Draw ennemy
	    DrawRectangleV(ennemy.position, ennemy.size, ennemy.color);
	    
	    // Draw gunfood to pick
            DrawRectangleV(gunfood.position, gunfood.size, gunfood.color);
            
            if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY);
        }
        else DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, GetScreenHeight()/2 - 50, 20, GRAY);

    EndDrawing();
}

// Unload game variables
void UnloadGame(void)
{
    // TODO: Unload all dynamic loaded data (textures, sounds, models...)
}

// Update and Draw (one frame)
void UpdateDrawFrame(void)
{
    UpdateGame();
    DrawGame();
}
