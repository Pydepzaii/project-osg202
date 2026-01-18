#include "raylib.h"
#include "settings.h"
#include "player.h"
#include "map.h"
#include "npc.h"      // <--- 1. THÊM DÒNG NÀY

int main() {
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS);

    // Khởi tạo Player
    Player knight;
    InitPlayer(&knight);

    // Khởi tạo Map
    GameMap world;
    InitMap(&world);

    // --- KHỞI TẠO NPC ---
    Npc chef; 
    // Đặt cô đầu bếp đứng ở tọa độ x=500, y=300 (Góc bếp)
    InitNpc(&chef, (Vector2){500, 300}); 
    // --------------------

    while (!WindowShouldClose()) {
        // Update
        UpdatePlayer(&knight);
        UpdateNpc(&chef); // <--- 2. THÊM: Cho cô ấy cử động

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            DrawMap(&world);      // Vẽ nền
            DrawNpc(&chef);       // <--- 3. THÊM: Vẽ cô đầu bếp (Vẽ trước Player để Player đi đè lên được)
            DrawPlayer(&knight);  // Vẽ người chơi

            DrawText("RPG Game - Team Project", 10, 10, 20, BLACK);

        EndDrawing();
    }

    // Unload
    UnloadPlayer(&knight);
    UnloadMap(&world);
    UnloadNpc(&chef); // <--- 4. THÊM: Dọn dẹp
    
    CloseWindow();
    return 0;
}