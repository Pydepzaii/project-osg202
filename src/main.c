// FILE: src/main.c
#include "raylib.h"
#include "settings.h"
#include "player.h"
#include "map.h"
#include "npc.h"
<<<<<<< Updated upstream
#include "debug.h" // <--- Đã thêm file debug vào đây
=======
#include "debug.h" 
#include "renderer.h" 
>>>>>>> Stashed changes
#include <stdio.h> 

int main() {
    // 1. SETUP CỬA SỔ
<<<<<<< Updated upstream
    SetConfigFlags(FLAG_WINDOW_HIGHDPI); // Hỗ trợ màn hình độ phân giải cao
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS); // Khóa FPS lại (thường là 60)

    // 2. KHỞI TẠO DỮ LIỆU (INIT)
    // - Tạo Player
    Player mainCharacter;
    InitPlayer(&mainCharacter, CLASS_STUDENT); 

    // - Tạo Map
    GameMap currentMap;
    currentMap.texture.id = 0; // Đánh dấu ID = 0 (chưa load gì)
    LoadMap(&currentMap, MAP_THU_VIEN); // Load map đầu tiên

    // - Tạo NPC (Dùng mảng để quản lý nhiều NPC)
    Npc npcList[MAX_NPCS];
    int npcCount = 0;

    // NPC 01: Cô Đầu Bếp
    InitNpc(&npcList[0], MAP_THU_VIEN, "resources/codaubep.png", (Vector2){500, 300}, "Co Dau Bep");
    npcCount++;

    // 3. VÒNG LẶP GAME (GAME LOOP)
    while (!WindowShouldClose()) {
        // --- PHẦN LOGIC (UPDATE) ---
        // (Tính toán mọi thay đổi trước khi vẽ)
        
        // Debug: Phím tắt chuyển map nhanh
        if (IsKeyPressed(KEY_F1)) LoadMap(&currentMap, MAP_THU_VIEN);
        if (IsKeyPressed(KEY_F2)) LoadMap(&currentMap, MAP_NHA_AN);

        // Upda te Người chơi (Truyền map và npc vào để check va chạm)
        UpdatePlayer(&mainCharacter, &currentMap, npcList, npcCount);

        // Update NPC: Chỉ update những NPC đang ở cùng map với người chơi
=======
    SetConfigFlags(FLAG_WINDOW_HIGHDPI); 
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS); 

    // 2. KHỞI TẠO DỮ LIỆU (INIT)
    InitRenderer(); 

    // --- Tạo Player ---
    Player mainCharacter;
    InitPlayer(&mainCharacter, CLASS_STUDENT); 

    // --- Tạo Map ---
    GameMap currentMap;
    currentMap.texture.id = 0; 
    LoadMap(&currentMap, MAP_THU_VIEN); 

    // --- Tạo NPC ---
    Npc npcList[MAX_NPCS];
    int npcCount = 0;

    // NPC 01: Cô Đầu Bếp
    InitNpc(&npcList[0], MAP_THU_VIEN, "resources/codaubep.png", (Vector2){206, 250}, "Co Dau Bep");
    npcCount++;

    // --- Vật Cản Tĩnh ---
    GameProp cotNha;
    cotNha.texture = LoadTexture("resources/cot_nha.png"); 
    cotNha.position = (Vector2){ 400, 200 }; 
    cotNha.sourceRec = (Rectangle){0, 0, (float)cotNha.texture.width, (float)cotNha.texture.height};
    cotNha.originY = (float)cotNha.texture.height - 10; 

    // 3. VÒNG LẶP GAME (GAME LOOP)
    while (!WindowShouldClose()) {
        // --- PHẦN LOGIC (UPDATE) ---
        if (IsKeyPressed(KEY_F1)) LoadMap(&currentMap, MAP_THU_VIEN);
        if (IsKeyPressed(KEY_F2)) LoadMap(&currentMap, MAP_NHA_AN);

        UpdatePlayer(&mainCharacter, &currentMap, npcList, npcCount);
>>>>>>> Stashed changes
        for (int i = 0; i < npcCount; i++) {
            if (npcList[i].mapID == currentMap.currentMapID) {
                UpdateNpc(&npcList[i]);
            }
        }

        // --- PHẦN VẼ (DRAW) ---
        BeginDrawing();
<<<<<<< Updated upstream
            ClearBackground(RAYWHITE); // Xóa màn hình cũ
            
            // Lớp 1: Vẽ nền Map
            DrawMap(&currentMap);
            // (Phần vẽ tường Debug cũ đã được chuyển sang hàm Debug_UpdateAndDraw bên dưới)
            
            // Lớp 2: Vẽ NPC
            for (int i = 0; i < npcCount; i++) {
                if (npcList[i].mapID == currentMap.currentMapID) {
                    DrawNpc(&npcList[i]);
                }
            }

            // Lớp 3: Vẽ Player (Vẽ sau cùng để đè lên trên nền)
            DrawPlayer(&mainCharacter);

            // --- [TOOL DEBUG] ---
            // Gọi hàm này để: 
            // 1. Ấn phím 0 thì hiện tường đỏ
            // 2. Kéo chuột thì hiện tường xanh để lấy tọa độ
            Debug_UpdateAndDraw(&currentMap); 

            // Lớp 4: UI (Giao diện người dùng)
            DrawText("F1: Thu Vien | F2: Nha An (Trong)", 10, 10, 20, BLACK);
=======
            ClearBackground(RAYWHITE); 
            
            // LỚP 1: Nền đất
            DrawMap(&currentMap);
            
            // LỚP 2: CÁC VẬT THỂ NỔI
            Render_Clear(); 
            Render_AddPlayer(&mainCharacter);
            for (int i = 0; i < npcCount; i++) {
                if (npcList[i].mapID == currentMap.currentMapID) {
                    Render_AddNpc(&npcList[i]);
                }
            }
            if (currentMap.currentMapID == MAP_THU_VIEN) {
                Render_AddProp(&cotNha);
            }
            Render_DrawAll();

            // LỚP 3: Debug & UI (Luôn nằm trên cùng)
            // [CẬP NHẬT] Truyền thêm mainCharacter và npcList vào đây
            Debug_UpdateAndDraw(&currentMap, &mainCharacter, npcList, npcCount); 
            
            DrawText("F1: Thu Vien | F2: Nha An", 10, 10, 20, BLACK);
>>>>>>> Stashed changes
            DrawText(TextFormat("HP: %d/%d", mainCharacter.stats.hp, mainCharacter.stats.maxHp), 10, 40, 20, RED);

        EndDrawing();
    }

    // 4. DỌN DẸP (UNLOAD)
<<<<<<< Updated upstream
    // Giải phóng RAM trước khi tắt
    UnloadPlayer(&mainCharacter);
    UnloadMap(&currentMap);
    for (int i = 0; i < npcCount; i++) UnloadNpc(&npcList[i]);
    
=======
    UnloadPlayer(&mainCharacter);
    UnloadMap(&currentMap);
    for (int i = 0; i < npcCount; i++) UnloadNpc(&npcList[i]);
    UnloadTexture(cotNha.texture);

>>>>>>> Stashed changes
    CloseWindow();
    return 0;
}