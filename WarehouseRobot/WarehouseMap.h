#ifndef WAREHOUSEMAP_H
#define WAREHOUSEMAP_H

#include "olcPixelGameEngine.h"

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 15;

class WarehouseMap {
public:
    static int map[MAP_HEIGHT][MAP_WIDTH];

    static void HandleInput(olc::PixelGameEngine* pge) {
        // Example: Handle mouse input
        if (pge->GetMouse(0).bPressed) { // Check if left mouse button is pressed
            int mouseX = pge->GetMouseX();
            int mouseY = pge->GetMouseY();
            // Convert mouse coordinates to map coordinates
            int mapX = mouseX / 40; // Assuming tile size is 40x40
            int mapY = mouseY / 40;
            // Update map based on mouse click
            map[mapY][mapX] = 2; // Set the clicked tile as a wall
        }

        if (pge->GetMouse(1).bPressed) { // Check if right mouse button is pressed
            int mouseX = pge->GetMouseX();
            int mouseY = pge->GetMouseY();
            // Convert mouse coordinates to map coordinates
            int mapX = mouseX / 40; // Assuming tile size is 40x40
            int mapY = mouseY / 40;
            // Update map based on mouse click
            map[mapY][mapX] = 0; // Clear the clicked tile (or set it to floor)
        }

        if (pge->GetMouse(2).bPressed) { // Check if wheel mouse button is pressed
            int mouseX = pge->GetMouseX();
            int mouseY = pge->GetMouseY();
            // Convert mouse coordinates to map coordinates
            int mapX = mouseX / 40; // Assuming tile size is 40x40
            int mapY = mouseY / 40;
            // Update map based on mouse click
            map[mapY][mapX] = 0; // Clear the clicked tile
        }
    }

    static void DrawMap(olc::PixelGameEngine* pge) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                switch (map[y][x]) {
                    case 1: // Shelf
                        pge->FillRect(x*40, y*40, 40, 40, olc::DARK_GREY);
                        break;
                    case 2: // Wall
                        pge->FillRect(x*40, y*40, 40, 40, olc::DARK_BLUE);
                        break;
                        // Add more cases as needed for other elements
                }
            }
        }
        // Define the legend, add
        std::unordered_map<int, std::string> legend = {
                {0, "Empty"},     // 0 represents empty tile
                {1, "Obstacle"},  // 1 represents obstacle
                {2, "Player"},    // 2 represents player

        };

        // Draw the legend
            int legendX = 1000;  // X position of the legend
            int legendY = 10;  // Y position of the legend
            int legendSpacing = 20;  // Spacing between legend items

            for (const auto& entry : legend) {
                pge->DrawString(legendX, legendY, entry.second, olc::WHITE);
                legendY += legendSpacing;
            }
        }
};


// Initialize the map array
// 0 = FLOOR / 1 = SHELF / 2 = WALL
int WarehouseMap::map[MAP_HEIGHT][MAP_WIDTH] = {
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
};





#endif // WAREHOUSEMAP_H
