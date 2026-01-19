#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

// Struct chứa mọi thông tin của nhân vật
typedef struct {
    Vector2 position;     // Vị trí x, y trên bản đồ
    Texture2D texture;    // Hình ảnh (Sprite sheet)
    float speed;          // Tốc độ di chuyển

    // --- CÁC BIẾN ANIMATION MỚI (Bắt buộc phải có) ---
    Rectangle frameRec;   // Khung hình chữ nhật dùng để cắt ảnh
    int currentFrame;     // Số thứ tự khung hình hiện tại (0, 1, 2...)
    int framesCounter;    // Bộ đếm thời gian để làm chậm tốc độ chuyển hình
    int framesSpeed;      // Tốc độ chuyển hình (số càng lớn càng chậm)
    
    int spriteWidth;      // Chiều rộng của 1 nhân vật nhỏ
    int spriteHeight;     // Chiều cao của 1 nhân vật nhỏ
} Player;

// Khai báo các hàm
void InitPlayer(Player *player);        
void UpdatePlayer(Player *player);      
void DrawPlayer(Player *player);        
void UnloadPlayer(Player *player);      

#endif