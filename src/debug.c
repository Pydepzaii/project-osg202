// FILE: src/debug.c
// Module quản lý công cụ Debug & Level Design
<<<<<<< Updated upstream
// Chức năng chính: Vẽ hitbox tường va chạm trực tiếp trong game
=======
// Chức năng chính: Vẽ hitbox tường, và hiển thị vùng va chạm của Player/NPC
>>>>>>> Stashed changes

#include "debug.h"
#include <stdio.h> 

// --- CONFIG ---
#define MAX_TEMP_WALLS 100 // Sức chứa tối đa cho bộ nhớ tạm (Undo/Redo)

// --- STATE VARIABLES ---
static Vector2 devStartPos = {0};       // Điểm bắt đầu khi click chuột
static bool devIsDragging = false;      // Trạng thái đang kéo chuột
static bool showDebugWalls = false;     // Trạng thái bật/tắt Debug Mode

// Bộ nhớ tạm (Buffer) để lưu các tường vừa vẽ xong (Màu Xanh Lá)
<<<<<<< Updated upstream
// Giúp Dev nhìn thấy ngay kết quả trước khi copy code vào map.c
static Rectangle tempWalls[MAX_TEMP_WALLS];
static int tempWallCount = 0;

void Debug_UpdateAndDraw(GameMap *map) {
=======
static Rectangle tempWalls[MAX_TEMP_WALLS];
static int tempWallCount = 0;

void Debug_UpdateAndDraw(GameMap *map, Player *player, Npc *npcList, int npcCount) {
>>>>>>> Stashed changes
    // =============================================================
    // 1. INPUT HANDLING (TOGGLE & UTILS)
    // =============================================================
    
    // Phím 0: Bật / Tắt chế độ Debug
    if (IsKeyPressed(KEY_ZERO)) {
        showDebugWalls = !showDebugWalls; 
    }

    // Phím C: Undo (Xóa tường vừa vẽ gần nhất)
    if (IsKeyPressed(KEY_C)) { 
        if (tempWallCount > 0) {
<<<<<<< Updated upstream
            // Lấy thông tin tường sắp xóa để log ra màn hình
            Rectangle del = tempWalls[tempWallCount - 1]; 
            
            // Xóa khỏi bộ nhớ tạm
            tempWallCount--; 

            // LOG CẢNH BÁO: Giúp Dev biết dòng code bên trên đã bị hủy
=======
            Rectangle del = tempWalls[tempWallCount - 1]; 
            tempWallCount--; 

>>>>>>> Stashed changes
            printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            printf("!!! [UNDO] DA XOA DONG CODE TREN -> DUNG COPY !!!\n");
            printf("!!! (Deleted Wall at: x=%.0f, y=%.0f)                 !!!\n", del.x, del.y);
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
        }
    }

    // =============================================================
    // 2. RENDER & LOGIC LOOP
    // =============================================================
    
    // Chỉ chạy logic vẽ vời khi đang bật Debug
    if (showDebugWalls) {
        
        // --- LAYER 1: TƯỜNG ĐÃ SAVE (MÀU ĐỎ) ---
<<<<<<< Updated upstream
        // Gọi hàm vẽ từ map.c (Dữ liệu cứng đã nạp vào game)
        DrawMapDebug(map); 
        
        // --- LAYER 2: TƯỜNG VỪA VẼ (MÀU XANH LÁ - LIME) ---
        // Duyệt mảng tạm và vẽ đè lên
=======
        DrawMapDebug(map); 
        
        // --- LAYER 2: TƯỜNG VỪA VẼ (MÀU XANH LÁ - LIME) ---
>>>>>>> Stashed changes
        for (int i = 0; i < tempWallCount; i++) {
            DrawRectangleRec(tempWalls[i], Fade(LIME, 0.5f)); 
            DrawRectangleLinesEx(tempWalls[i], 3.0f, LIME);   
        }

<<<<<<< Updated upstream
        // --- UI HƯỚNG DẪN ---
        DrawText("MODE: DEBUG LEVEL DESIGNER", 10, 70, 20, RED);
        DrawText("   [DO]   : Tuong da Save (Trong map.c)", 10, 95, 18, RED);
        DrawText("   [LUC]  : Tuong vua Ve  (Chua Save)", 10, 115, 18, LIME);
        DrawText("   [XANH] : Dang keo chuot", 10, 135, 18, BLUE);
        DrawText("   [Key C]: Undo (Xoa buoc cuoi)", 10, 160, 18, DARKGRAY);

        // --- LAYER 3: TOOL VẼ (MOUSE LOGIC) ---
        
        // A. Bắt đầu click (Start Drag)
=======
        // --- LAYER 3: HITBOX NPC (MÀU TÍM - PURPLE) ---
        for (int i = 0; i < npcCount; i++) {
            if (npcList[i].mapID == map->currentMapID) {
                // Tính toán Hitbox Chân NPC (Logic khớp với player.c)
                float npcW = (float)npcList[i].texture.width / npcList[i].frameCount;
                float npcH = (float)npcList[i].texture.height;
                float feetHeight = 20.0f; 
                
                Rectangle npcHitbox = { 
                    npcList[i].position.x + 15,            
                    npcList[i].position.y + npcH - feetHeight, 
                    npcW - 30,                             
                    feetHeight                             
                };

                DrawRectangleRec(npcHitbox, Fade(PURPLE, 0.5f));
                DrawRectangleLinesEx(npcHitbox, 2.0f, PURPLE);
                
                // Vẽ điểm Pivot (Điểm dùng để so sánh Render Y)
                DrawCircle(npcHitbox.x + npcHitbox.width/2, npcHitbox.y + npcHitbox.height, 3, PURPLE);
            }
        }

        // --- LAYER 4: HITBOX PLAYER (MÀU VÀNG - YELLOW) ---
        float pW = (float)player->spriteWidth;
        float pH = (float)player->spriteHeight;
        float pFeetH = 20.0f;

        Rectangle playerHitbox = {
            player->position.x + 15,
            player->position.y + pH - pFeetH,
            player->spriteWidth - 30,
            pFeetH
        };

        DrawRectangleRec(playerHitbox, Fade(YELLOW, 0.5f));
        DrawRectangleLinesEx(playerHitbox, 2.0f, YELLOW);
        
        // Vẽ điểm Pivot của Player
        DrawCircle(playerHitbox.x + playerHitbox.width/2, playerHitbox.y + playerHitbox.height, 3, YELLOW);

        // --- UI HƯỚNG DẪN ---
        DrawText("MODE: DEBUG LEVEL DESIGNER & HITBOX", 10, 70, 20, RED);
        DrawText("   [DO]   : Tuong da Save", 10, 95, 18, RED);
        DrawText("   [LUC]  : Tuong vua Ve", 10, 115, 18, LIME);
        DrawText("   [TIM]  : Hitbox NPC (Chan)", 10, 135, 18, PURPLE);
        DrawText("   [VANG] : Hitbox Player (Chan)", 10, 155, 18, YELLOW);
        DrawText("   [Key C]: Undo (Xoa buoc cuoi)", 10, 180, 18, DARKGRAY);

        // --- LAYER 5: TOOL VẼ (MOUSE LOGIC) ---
>>>>>>> Stashed changes
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            devStartPos = GetMousePosition();
            devIsDragging = true;
        }

<<<<<<< Updated upstream
        // B. Đang giữ chuột (Dragging) -> Vẽ khung XANH DƯƠNG preview
=======
>>>>>>> Stashed changes
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && devIsDragging) {
            Vector2 currentPos = GetMousePosition();
            float width = currentPos.x - devStartPos.x;
            float height = currentPos.y - devStartPos.y;
<<<<<<< Updated upstream
            
=======
>>>>>>> Stashed changes
            Rectangle rec = { devStartPos.x, devStartPos.y, width, height };

            DrawRectangleRec(rec, Fade(BLUE, 0.5f)); 
            DrawRectangleLinesEx(rec, 3.0f, BLUE);   
<<<<<<< Updated upstream
            
            // Hiện tọa độ realtime cạnh con chuột
            DrawText(TextFormat("W:%.0f H:%.0f", width, height), currentPos.x + 10, currentPos.y, 20, BLUE);
        }

        // C. Thả chuột (Release) -> Finalize
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && devIsDragging) {
            devIsDragging = false;
            Vector2 endPos = GetMousePosition();
            
            // Tính toán kích thước chuẩn hóa (tránh giá trị âm khi kéo ngược)
=======
            DrawText(TextFormat("W:%.0f H:%.0f", width, height), currentPos.x + 10, currentPos.y, 20, BLUE);
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && devIsDragging) {
            devIsDragging = false;
            Vector2 endPos = GetMousePosition();
>>>>>>> Stashed changes
            float x = devStartPos.x;
            float y = devStartPos.y;
            float w = endPos.x - devStartPos.x;
            float h = endPos.y - devStartPos.y;

            if (w < 0) { x += w; w = -w; }
            if (h < 0) { y += h; h = -h; }

<<<<<<< Updated upstream
            // Bước 1: Lưu vào bộ nhớ tạm (Hiện màu Xanh Lá ngay lập tức)
=======
>>>>>>> Stashed changes
            if (tempWallCount < MAX_TEMP_WALLS) {
                tempWalls[tempWallCount] = (Rectangle){ x, y, w, h };
                tempWallCount++;
            }

<<<<<<< Updated upstream
            // Bước 2: In Code Generator ra Terminal
=======
>>>>>>> Stashed changes
            printf("\n--- [COPY CODE DUOI DAY] ---\n");
            printf("map->walls[map->wallCount++] = (Rectangle){ %.0f, %.0f, %.0f, %.0f };\n", x, y, w, h);
            printf("----------------------------\n");
        }
    } 
    else {
<<<<<<< Updated upstream
        // Trạng thái bình thường (Ẩn tool)
=======
>>>>>>> Stashed changes
        DrawText("DEV TIP: Nhan phim '0' de bat Tool Ve Map", 10, 70, 20, DARKGRAY);
    }
}