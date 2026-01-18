#ifndef MAP_H
#define MAP_H

#include "raylib.h"

// Định nghĩa cấu trúc Map
typedef struct {
    Texture2D texture; // Biến chứa hình ảnh
    float scale;       // Biến chỉnh độ to nhỏ của map
} GameMap;

// Khai báo các hàm sẽ dùng
void InitMap(GameMap *map);     // Hàm nạp map
void DrawMap(GameMap *map);     // Hàm vẽ map
void UnloadMap(GameMap *map);   // Hàm xóa map khi tắt game

#endif