#include "npc.h"

void InitNpc(Npc *npc, Vector2 pos) {
    // 1. Tải ảnh cô đầu bếp
    npc->texture = LoadTexture("resources/codaubep.png");
    npc->position = pos;

    // 2. Cài đặt hoạt hình
    npc->frameCount = 4;        // Ảnh có 4 hình
    npc->currentFrame = 0;
    npc->frameTimer = 0.0f;
    npc->frameSpeed = 0.2f;     // 0.2 giây đổi hình 1 lần (chậm hơn player chút)
}

void UpdateNpc(Npc *npc) {
    // TỰ ĐỘNG CẬP NHẬT KHUNG HÌNH (Luôn chạy)
    npc->frameTimer += GetFrameTime();

    if (npc->frameTimer >= npc->frameSpeed) {
        npc->frameTimer = 0.0f;
        npc->currentFrame++;

        // Nếu hết hình 3 thì quay về 0
        if (npc->currentFrame >= npc->frameCount) {
            npc->currentFrame = 0;
        }
    }
}

void DrawNpc(Npc *npc) {
    // 1. Tính chiều rộng 1 khung hình
    float frameWidth = (float)npc->texture.width / npc->frameCount;

    // 2. Cắt ảnh (Source)
    Rectangle source = {
        npc->currentFrame * frameWidth, // Dịch chuyển vùng cắt
        0.0f,
        frameWidth,
        (float)npc->texture.height
    };

    // 3. Vị trí vẽ (Dest)
    Rectangle dest = {
        npc->position.x,
        npc->position.y,
        frameWidth, // Vẽ đúng kích thước gốc
        (float)npc->texture.height
    };

    // 4. Vẽ
    DrawTexturePro(npc->texture, source, dest, (Vector2){0,0}, 0.0f, WHITE);
}

void UnloadNpc(Npc *npc) {
    UnloadTexture(npc->texture);
}