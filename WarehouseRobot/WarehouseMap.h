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
            map[mapY][mapX] = 1; // Set the clicked tile as a shelf
        }

        if (pge->GetMouse(1).bPressed) { // Check if right mouse button is pressed
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
                        pge->FillRect(x*40, y*40, 40, 40, olc::GREY);
                        break;
                        // Add more cases as needed for other elements
                }
            }
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
