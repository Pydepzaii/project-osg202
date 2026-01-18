#ifndef NPC_H
#define NPC_H

#include "raylib.h"

typedef struct {
    Vector2 position;     // Vị trí đứng
    Texture2D texture;    // Ảnh (Sprite sheet)
    
    // Biến hoạt hình (Animation)
    int frameCount;       // Tổng số khung hình (4)
    int currentFrame;     // Khung hình hiện tại
    float frameTimer;     // Bộ đếm thời gian
    float frameSpeed;     // Tốc độ nhún nhảy
} Npc;

// Khai báo hàm
void InitNpc(Npc *npc, Vector2 pos); // Truyền vị trí muốn đặt NPC
void UpdateNpc(Npc *npc);            // Tự động chuyển hình
void DrawNpc(Npc *npc);              // Vẽ ra màn hình
void UnloadNpc(Npc *npc);            // Dọn dẹp

#endif