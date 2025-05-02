#include <iostream>
using namespace std;
#include <random>
#include <typeinfo>
#include <cstdlib>
#include "raylib.h"
#include "board.h"
#include "cat.h"
#include "dog.h"
#include "tree.h"


void checkAnimals(Animal* animals[], bool* toDelete, bool* toReplace, int numAnimals) {
    for (int i = 0; i < numAnimals; ++i) {
        if (animals[i] == nullptr) continue; // Skip already deleted animals

        Animal* current = animals[i];
        if (current->getHealth() <= 0) {
            // Mark for deletion or replacement
            if (typeid(*current) == typeid(Cat)) {
                toDelete[i] = true; // Mark cats for deletion
            } else if (typeid(*current) == typeid(Dog)) {
                toReplace[i] = true; // Mark dogs for replacement (dog -> cat)
            }
        }
    }

    // Handle deletion and replacement after the loop
    for (int i = 0; i < numAnimals; ++i) {
        if (toDelete[i]) {
            delete animals[i];  // Delete animal
            animals[i] = nullptr;  // Set to nullptr to avoid future processing
            cout << "Animal has been deleted!" << endl;
        } else if (toReplace[i]) {
            int x = animals[i]->getXPosition();
            int y = animals[i]->getYPosition();
            delete animals[i];  // Delete dog
            animals[i] = new Cat(x, y);  // Replace with a cat
            toReplace[i] = false;  // Reset flag to avoid repeating the transformation
            cout << "Dog transformed into Cat!" << endl;
        }
    }
}

int main() {
    // Initialize window
    const int screenWidth = 1200;
    const int screenHeight = 800;

    // Timer setup
    double lastMoveTime = 0;
    double moveInterval = 0.5; // seconds

    InitWindow(screenWidth, screenHeight, "Cat and Dog Sim");

    SetTargetFPS(60);
    Board board = Board();

    // Animals
    Animal* cat = new Cat(0, 0);
    Animal* cat1 = new Cat(20, 5);
    Animal* cat2 = new Cat(5, 20);
    Animal* cat3 = new Cat(20, 0);
    Animal* cat4 = new Cat(20, 5);
    Animal* cat5 = new Cat(5, 5);
    Animal* cat6 = new Cat(20, 20);
    Animal* dog2 = new Dog(20, 10);
    Animal* dog = new Dog(50, 5);
    Animal* dog1 = new Dog(50, 10);
    Animal* dog3 = new Dog(25, 30);
    Animal* dog4 = new Dog(10, 50);
    Animal* dog5 = new Dog(50, 5);
    Animal* dog6 = new Dog(30, 10);
    Animal* dog7 = new Dog(45, 30);
    
    Animal* animals[] = {cat, cat1,cat2,cat3,cat4,cat5,cat6,dog, dog1, dog2,dog3,dog4,dog5,dog6,dog7};
    int numAnimals = sizeof(animals) / sizeof(animals[0]);

    bool* toDelete = new bool[numAnimals]();  // Initialize to false
    bool* toReplace = new bool[numAnimals](); // Initialize to false

    // Animal selected for stats on side UI
    Animal* selectedAnimal = nullptr;

    //Trees
    Tree* tree1 = new Tree(25, 20);
    Tree* tree2 = new Tree(10, 10);
    Tree* tree3 = new Tree(30, 50);
    Tree* tree4 = new Tree(20, 40);
    Tree* tree5 = new Tree(15, 15);
    Tree* tree6 = new Tree(5, 5);
    Tree* tree7 = new Tree(45, 50);
    Tree* trees[] = {tree1,tree2,tree3,tree4,tree5,tree6,tree7};
    int numTrees = sizeof(trees) /sizeof(trees[0]);
    // Main game loop
    while (true) {
        checkAnimals(animals, toDelete, toReplace, numAnimals);

        double currentTime = GetTime();
    
        // Move with timing
        if (currentTime - lastMoveTime >= moveInterval) {
            for (int i = 0; i < numAnimals; ++i) {
                if (animals[i] != nullptr) {
                    animals[i]->move();  // Move each animal
                }
            }
            lastMoveTime = currentTime;
        }
    
        // Mouse for stat selection (hover-based)
        Vector2 mouse = GetMousePosition();
        int cellSize = 20;  // The size of the grid cells in pixels
    
        for (int i = 0; i < numAnimals; ++i) {
            // Get position for each animal in pixels (based on the grid cell position)
            if (animals[i] != nullptr) {
                float animalX = animals[i]->getXPosition() * cellSize;  // Convert grid position to pixel position
                float animalY = animals[i]->getYPosition() * cellSize;  // Convert grid position to pixel position
                
                // Check if the mouse is hovering over the animal
                if (CheckCollisionPointCircle(mouse, (Vector2){animalX, animalY}, 10)) { // 10 is the radius for hover
                    selectedAnimal = animals[i];  // Set selected animal
                    break; 
                }
            }
        }


        // fighting
        for (int i = 0; i < numAnimals; ++i) {
            if (animals[i] == nullptr) continue;

            if (typeid(*animals[i]) == typeid(Cat)) {
                for (int j = 0; j < numAnimals; ++j) {
                    if (i == j || animals[j] == nullptr) continue;
                    
                    if (typeid(*animals[j]) == typeid(Dog)) {
                        float dx = animals[i]->getXPosition() - animals[j]->getXPosition();
                        float dy = animals[i]->getYPosition() - animals[j]->getYPosition();
                        float distance = sqrt(dx * dx + dy * dy);
        
                        if (distance <= 2.0f) {
                            animals[i]->fight(*animals[j]); // Cat fights Dog
                            break;
                        }
                    }
                }
            }
        }

        BeginDrawing();
        // Draw right-side panel
        ClearBackground(WHITE);
    
        board.drawBoard();

        // Draw all animals
        for (int i = 0; i < numAnimals; ++i) {
            if (animals[i] != nullptr) {
                animals[i]->draw();
            }

        }
        //Draw all trees
        for (int i =0; i< numTrees; ++i){
            trees[i]->draw();
        }
        // Draw right-side UI rectangle
        DrawRectangle(screenWidth - 200, 0, 200, screenHeight, LIGHTGRAY);
        DrawText("Animal Stats", screenWidth - 180, 20, 20, DARKGRAY);
        DrawText("Number of Cats: 2", screenWidth - 180, 60, 16, RED);
        DrawText("Number of Dogs: 2", screenWidth - 180, 90, 16, BLUE);
    
        if (selectedAnimal != nullptr) {
            string type = typeid(*selectedAnimal).name(); // shows class type
    
            DrawText(("Type: " + type).c_str(), screenWidth - 180, 120, 16, BLACK);
            DrawText(TextFormat("Health: %.1f", selectedAnimal->getHealth()), screenWidth - 180, 150, 16, RED);
            DrawText(TextFormat("Stamina: %.1f", selectedAnimal->getStamina()), screenWidth - 180, 180, 16, BLUE);
            DrawText(TextFormat("X: %d", selectedAnimal->getXPosition()), screenWidth - 180, 210, 16, DARKGREEN);
            DrawText(TextFormat("Y: %d", selectedAnimal->getYPosition()), screenWidth - 180, 240, 16, DARKGREEN);
        }
    
        EndDrawing();
    }

    // Clean up dynamic memory
    delete[] toDelete;
    delete[] toReplace;

    return 0;
}
