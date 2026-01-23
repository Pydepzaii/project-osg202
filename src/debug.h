// FILE: src/debug.h
#ifndef DEBUG_H
#define DEBUG_H

#include "raylib.h"
<<<<<<< Updated upstream
#include "map.h" // Cần file này để lấy thông tin Map

// Hàm này làm 2 việc:
// 1. Kiểm tra phím 0 để Bật/Tắt hiển thị tường cũ
// 2. Cho phép kéo chuột vẽ tường mới
void Debug_UpdateAndDraw(GameMap *map);
=======
#include "map.h"
#include "player.h" // [MỚI] Cần struct Player
#include "npc.h"    // [MỚI] Cần struct Npc

// Hàm này làm 2 việc:
// 1. Kiểm tra phím 0 để Bật/Tắt hiển thị tường cũ + Hitbox nhân vật
// 2. Cho phép kéo chuột vẽ tường mới
// [CẬP NHẬT] Thêm tham số player, npcList, npcCount
void Debug_UpdateAndDraw(GameMap *map, Player *player, Npc *npcList, int npcCount);
>>>>>>> Stashed changes

#endif