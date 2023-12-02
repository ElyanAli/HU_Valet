#include "CollisionManager.hpp"



/*
bool CollisionManager::checkCollision(Car* car, Objects* object) {
    // Calculate bounding boxes for the cars
    SDL_Rect bounding_box1 = car->getMoverRect();
    SDL_Rect bounding_box2 = object->getMoverRect();

    // Calculate the positions and orientations of the cars
    SDL_Point pos1 = car->getPosition();
    float angle1 = car->getAngle();
    SDL_Point pos2 = object->getPosition();
    float angle2 = 0;

    // Apply rotation offsets to the bounding boxes based on their angles
    SDL_Rect rotated_bounding_box1;
    rotated_bounding_box1.x = pos1.x + bounding_box1.x * cosf(angle1) - bounding_box1.y * sinf(angle1);
    rotated_bounding_box1.y = pos1.y + bounding_box1.x * sinf(angle1) + bounding_box1.y * cosf(angle1);
    rotated_bounding_box1.w = bounding_box1.w;
    rotated_bounding_box1.h = bounding_box1.h;

    SDL_Rect rotated_bounding_box2;
    rotated_bounding_box2.x = pos2.x + bounding_box2.x * cosf(angle2) - bounding_box2.y * sinf(angle2);
    rotated_bounding_box2.y = pos2.y + bounding_box2.x * sinf(angle2) + bounding_box2.y * cosf(angle2);
    rotated_bounding_box2.w = bounding_box2.w;
    rotated_bounding_box2.h = bounding_box2.h;

    // Check for intersection between the rotated bounding boxes
    return SDL_IntersectRect(&rotated_bounding_box1, &rotated_bounding_box2, nullptr);
}


bool CollisionManager::checkCollision(Car* car, Objects* object) {
    // Calculate bounding boxes for the cars
    SDL_Rect bounding_box1 = car->getMoverRect();
    SDL_Rect bounding_box2 = object->getMoverRect();

    // Calculate the positions and orientations of the cars
    SDL_Point pos1 = car->getPosition();
    float angle1 = car->getAngle();
    SDL_Point pos2 = object->getPosition();
    float angle2 = 0;

    // Apply rotation offsets and adjust bounding boxes based on their angles
    SDL_Rect adjusted_bounding_box1;
    adjusted_bounding_box1.x = pos1.x - bounding_box1.w / 2.0f * cosf(angle1) - bounding_box1.h / 2.0f * sinf(angle1);
    adjusted_bounding_box1.y = pos1.y - bounding_box1.w / 2.0f * sinf(angle1) + bounding_box1.h / 2.0f * cosf(angle1);
    adjusted_bounding_box1.w = bounding_box1.w;
    adjusted_bounding_box1.h = bounding_box1.h;
    std::cout<<adjusted_bounding_box1.x<<", "<<adjusted_bounding_box1.y<<", "<<adjusted_bounding_box1.w<<", "<<adjusted_bounding_box1.h <<std::endl;

    SDL_Rect adjusted_bounding_box2;
    adjusted_bounding_box2.x = pos2.x - bounding_box2.w / 2.0f * cosf(angle2) - bounding_box2.h / 2.0f * sinf(angle2);
    adjusted_bounding_box2.y = pos2.y - bounding_box2.w / 2.0f * sinf(angle2) + bounding_box2.h / 2.0f * cosf(angle2);
    adjusted_bounding_box2.w = bounding_box2.w;
    adjusted_bounding_box2.h = bounding_box2.h;
    std::cout<<adjusted_bounding_box2.x<<", "<<adjusted_bounding_box2.y<<", "<<adjusted_bounding_box2.w<<", "<<adjusted_bounding_box2.h <<std::endl;

    // Check for intersection between the adjusted bounding boxes
    return SDL_IntersectRect(&adjusted_bounding_box1, &adjusted_bounding_box2, nullptr);
}
*/

bool CollisionManager::checkCollision(Car* car, Objects* object) {
    SDL_Rect carRect = car->getMoverRect();
    SDL_Rect objectRect = object->getMoverRect();
    float angle = car->getAngle();
    SDL_Point obCoord[2] = {{object->getMoverRect().x, object->getMoverRect().y}, {object->getMoverRect().x + object->getMoverRect().w, object->getMoverRect().y + object->getMoverRect().h}};
    vector<SDL_Point> coordinates = getCarCoordinates(car);
    for (int i = 0; i< 4; i++){
        if (obCoord[0].x<= coordinates[i].x <= obCoord[1].x){
            if (obCoord[0].y<= coordinates[i].y <= obCoord[1].y){
                return true;
            }
        }
    }
    return false;
    
}
vector<SDL_Point> CollisionManager::getCarCoordinates(Car* car){
    SDL_Rect rect = car->getMoverRect();
    float angleInRadians = car->getAngle();

    float centerX = rect.x + rect.w / 2;
    float centerY = rect.y + rect.h / 2;
    // float angleInRadians = angle * M_PI / 180;

    float topLeftOffsetX = 50 * cos(angleInRadians);
    float topLeftOffsetY = 50 * sin(angleInRadians);
    int topLeftX = centerX + topLeftOffsetX;
    int topLeftY = centerY + topLeftOffsetY;

    float topRightOffsetX = 50 * cos(angleInRadians + 90.0f);
    float topRightOffsetY = 50 * sin(angleInRadians + 90.0f);
    int topRightX = centerX + topRightOffsetX;
    int topRightY = centerY + topRightOffsetY;

    float bottomRightOffsetX = 50 * cos(angleInRadians + 180.0f);
    float bottomRightOffsetY = 50 * sin(angleInRadians + 180.0f);
    int bottomRightX = centerX + bottomRightOffsetX;
    int bottomRightY = centerY + bottomRightOffsetY;

    float bottomLeftOffsetX = 50 * cos(angleInRadians + 270.0f);
    float bottomLeftOffsetY = 50 * sin(angleInRadians + 270.0f);
    int bottomLeftX = centerX + bottomLeftOffsetX;
    int bottomLeftY = centerY + bottomLeftOffsetY;

    vector<SDL_Point> coordinates = {{topLeftX, topLeftY}, {topRightX, topRightY}, {bottomLeftX, bottomLeftY},{bottomRightX, bottomRightY}};
    return coordinates;
}
// Function to calculate the rotated bounding box for an object
SDL_Rect CollisionManager::calculate_rotated_bounding_box(Car* car) {
    // Get the object's position, angle, and bounding box
    SDL_Point position = car->getPosition();
    float angle = car->getAngle();
    SDL_Rect bounding_box = car->getMoverRect();

    // Calculate the half-widths and half-heights of the bounding box
    float half_width = bounding_box.w / 2.0f;
    float half_height = bounding_box.h / 2.0f;

    // Calculate the corners of the rotated bounding box
    SDL_Point corners[4];
    for (int i = 0; i < 4; i++) {
        int x = position.x + bounding_box.w * cosf(angle + ((float)i / 4.0f) * M_PI * 2.0f) - bounding_box.h * sinf(angle + ((float)i / 4.0f) * M_PI * 2.0f);
        int y = position.y + bounding_box.w * sinf(angle + ((float)i / 4.0f) * M_PI * 2.0f) + bounding_box.h * cosf(angle + ((float)i / 4.0f) * M_PI * 2.0f);
        corners[i] = {x, y};
    }

    // Find the minimum and maximum x and y coordinates of the rotated bounding box
    int min_x = corners[0].x, max_x = corners[0].x;
    int min_y = corners[0].y, max_y = corners[0].y;
    for (int i = 1; i < 4; i++) {
        if (corners[i].x < min_x) {
            min_x = corners[i].x;
        } else if (corners[i].x > max_x) {
            max_x = corners[i].x;
        }
        if (corners[i].y < min_y) {
            min_y = corners[i].y;
        } else
 
if (corners[i].y > max_y) {
            max_y = corners[i].y;
        }
    }

    // Create and return the rotated bounding box
    SDL_Rect rotated_bounding_box;
    rotated_bounding_box.x = min_x;
    rotated_bounding_box.y = min_y;
    rotated_bounding_box.w = max_x - min_x;
    rotated_bounding_box.h = max_y - min_y;

    return rotated_bounding_box;
}



