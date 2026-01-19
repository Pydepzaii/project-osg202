#include "player.h"
#include <math.h> 

// --- CẤU HÌNH LẠI THỨ TỰ HÀNG (SỬA LỖI NGƯỢC) ---
// Mình đã đảo ngược lại: Hàng 0 là Trái, Hàng 3 là Phải
#define ROW_LEFT  0   // Hàng 1 (Trên cùng): Sang Trái
#define ROW_UP    1   // Hàng 2: Lên Trên
#define ROW_DOWN  2   // Hàng 3: Xuống Dưới
#define ROW_RIGHT 3   // Hàng 4 (Dưới cùng): Sang Phải

// --- SỐ CỘT (FRAME NGANG) ---
#define MAX_FRAME_COLS 6 

void InitPlayer(Player *player) {
    player->texture = LoadTexture("resources/main_hocba.png"); 
    
    player->position.x = 400;
    player->position.y = 225;
    player->speed = 4.0f;

    // Tính kích thước 1 ô
    player->spriteWidth = player->texture.width / MAX_FRAME_COLS;
    player->spriteHeight = player->texture.height / 4; 

    // Animation
    player->currentFrame = 0;
    player->framesCounter = 0;
    player->framesSpeed = 8; 

    // Mặc định ban đầu nhìn xuống
    player->frameRec.x = 0.0f;
    player->frameRec.y = (float)(ROW_DOWN * player->spriteHeight);
    player->frameRec.width = (float)player->spriteWidth;
    player->frameRec.height = (float)player->spriteHeight;
}

void UpdatePlayer(Player *player) {
    bool isMoving = false;
    int currentRow = ROW_DOWN; 

    // Lấy hướng hiện tại đang đứng
    int currentDir = (int)(player->frameRec.y / player->spriteHeight);

    // --- XỬ LÝ DI CHUYỂN ---
    if (IsKeyDown(KEY_RIGHT)) {
        player->position.x += player->speed;
        currentRow = ROW_RIGHT; // Sẽ lấy hàng 3
        isMoving = true;
    }
    else if (IsKeyDown(KEY_LEFT)) {
        player->position.x -= player->speed;
        currentRow = ROW_LEFT;  // Sẽ lấy hàng 0
        isMoving = true;
    }
    else if (IsKeyDown(KEY_UP)) {
        player->position.y -= player->speed;
        currentRow = ROW_UP;
        isMoving = true;
    }
    else if (IsKeyDown(KEY_DOWN)) {
        player->position.y += player->speed;
        currentRow = ROW_DOWN;
        isMoving = true;
    } else {
        // Không đi thì giữ nguyên hướng cũ
        currentRow = currentDir;
    }

    // Cập nhật hướng nhìn (Frame Y)
    player->frameRec.y = (float)(currentRow * player->spriteHeight);

    // --- XỬ LÝ ANIMATION (CHUYỂN ĐỘNG CHÂN) ---
    if (isMoving) {
        player->framesCounter++;

        if (player->framesCounter >= player->framesSpeed) {
            player->framesCounter = 0;
            player->currentFrame++;

            if (player->currentFrame >= MAX_FRAME_COLS) {
                player->currentFrame = 0;
            }

            // Cập nhật bước chân (Frame X)
            player->frameRec.x = (float)(player->currentFrame * player->spriteWidth);
        }
    } else {
        // Đứng yên: Về dáng đứng nghiêm
        player->currentFrame = 0;
        player->frameRec.x = 0.0f;
    }
}

void DrawPlayer(Player *player) {
    DrawTextureRec(player->texture, player->frameRec, player->position, WHITE);
}

void UnloadPlayer(Player *player) {
    UnloadTexture(player->texture);
}