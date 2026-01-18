#include "map.h"

void InitMap(GameMap *map) {
    // 1. Tải ảnh từ thư mục resources
    // QUAN TRỌNG: Sửa "world_map.png" thành tên file ảnh thật của bạn nếu khác
    map->texture = LoadTexture("resources/thuvien.png"); 
    
    // 2. Chỉnh độ to của map. 
    // Để 1.0f là giữ nguyên, 2.0f là to gấp đôi.
    map->scale = 2.0f; 
}

void DrawMap(GameMap *map) {
    // Vẽ map tại vị trí (0,0) tức là góc trên cùng bên trái
    // Dùng hàm DrawTextureEx để có thể phóng to (scale) được
    DrawTextureEx(map->texture, (Vector2){0, 0}, 0.0f, map->scale, WHITE);
}

void UnloadMap(GameMap *map) {
    // Giải phóng bộ nhớ RAM chứa ảnh map
    UnloadTexture(map->texture);
}