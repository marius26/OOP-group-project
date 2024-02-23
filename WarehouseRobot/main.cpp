
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "WarehouseMap.h" // Include the map header

class WarehouseSimulator : public olc::PixelGameEngine
{
public:
    WarehouseSimulator() {
        sAppName = "Warehouse path finder";
    }

private:
    olc::vf2d playerPos = {50.0f, 50.0f};
    olc::vf2d playerSize = {10.0f, 10.0f};
    float fSpeed = 100.0f;

public:
    bool OnUserCreate() override {
        // Called once at the start
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        // Handle player input and move the player
        olc::vf2d direction = {0, 0};
        if (GetKey(olc::Key::W).bHeld) direction.y -= 1;
        if (GetKey(olc::Key::S).bHeld) direction.y += 1;
        if (GetKey(olc::Key::A).bHeld) direction.x -= 1;
        if (GetKey(olc::Key::D).bHeld) direction.x += 1;

        // Normalize direction vector to have unit length, then scale by speed and elapsed time
        if (direction.mag2() > 0) direction = direction.norm() * fSpeed * fElapsedTime;

        // Update player position
        olc::vf2d newPos = playerPos + direction;

        // Ensure the player remains within bounds
        newPos.x = std::clamp(newPos.x, 0.0f, (float)ScreenWidth() - playerSize.x);
        newPos.y = std::clamp(newPos.y, 0.0f, (float)ScreenHeight() - playerSize.y);

// Simple collision detection against map walls and shelves (values 1 and 2)
        bool canMove = true;
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                int tile = WarehouseMap::map[y][x];
                // Check for collision with walls (2) and shelves (1)
                if (tile == 1 || tile == 2) {
                    olc::vf2d tilePos = {x * 40.0f, y * 40.0f};
                    olc::vf2d tileSize = {40.0f, 40.0f};
                    if (IsColliding(newPos + direction, playerSize, tilePos, tileSize)) {
                        canMove = false; // Collision detected, prevent movement
                        break;
                    }
                }
            }
            if (!canMove) break;
        }

        if (canMove) {
            // Update player position only if no collision was detected
            playerPos = newPos;
        }

        // Drawing
        Clear(olc::BLACK);
        WarehouseMap::DrawMap(this); // Draw the warehouse map
        FillRect(playerPos, playerSize, olc::YELLOW); // Draw player

        return true;
    }

    // Collision detection function (AABB)
    bool IsColliding(const olc::vf2d& pos1, const olc::vf2d& size1, const olc::vf2d& pos2, const olc::vf2d& size2) {
        return pos1.x < pos2.x + size2.x && pos1.x + size1.x > pos2.x &&
               pos1.y < pos2.y + size2.y && pos1.y + size1.y > pos2.y;
    }
};

int main() {
    WarehouseSimulator demo;
    if (demo.Construct(1092, 1080, 1, 1))
        demo.Start();
    return 0;
}
