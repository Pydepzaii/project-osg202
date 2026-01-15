#include "raylib.h"

int main() {
    // 1. Cấu hình cho màn hình độ phân giải cao
    SetConfigFlags(FLAG_WINDOW_HIGHDPI); 
    InitWindow(800, 450, "RPG Game - Buoc dau tien");

    // 2. Khởi tạo vị trí nhân vật
    Vector2 playerPos = { 400, 225 };
    float speed = 5.0f;

    SetTargetFPS(60); // Khóa khung hình 60fps để game chạy mượt

    while (!WindowShouldClose()) {
        // 3. Xử lý Input (Điều khiển nhân vật)
        if (IsKeyDown(KEY_RIGHT)) playerPos.x += speed;
        if (IsKeyDown(KEY_LEFT)) playerPos.x -= speed;
        if (IsKeyDown(KEY_UP)) playerPos.y -= speed;
        if (IsKeyDown(KEY_DOWN)) playerPos.y += speed;

        // 4. Vẽ đồ họa
        BeginDrawing();
            ClearBackground(RAYWHITE); // Xóa màn hình bằng màu trắng
            
            DrawText("Dung phim mui ten de di chuyen nhan vat", 10, 10, 20, DARKGRAY);
            
            // Vẽ nhân vật là một hình vuông màu đỏ
            DrawRectangleV(playerPos, (Vector2){40, 40}, RED);
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}