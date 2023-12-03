#include "CollisionManager.hpp"


// bool CollisionManager::checkCollision(Car* car, Objects* object) {
//     SDL_Rect carRect = car->getMoverRect();
//     SDL_Rect objectRect = object->getMoverRect();
//     float angle = car->getAngle();
//     SDL_Point obCoord[2] = {{object->getMoverRect().x, object->getMoverRect().y}, {object->getMoverRect().x + object->getMoverRect().w, object->getMoverRect().y + object->getMoverRect().h}};
//     vector<vector<float>> coordinates = getCarCoordinates(car);
//     for (int i = 0; i< 4; i++){
//         if ((coordinates[i][0] >=obCoord[0].x) && (coordinates[i][0] <= obCoord[1].x)){
//             if ((coordinates[i][1] >=obCoord[0].y) && (coordinates[i][1] <= obCoord[1].y)){
//                 return true;
//             }
//         }
//     }
//     return false;
    
// }

// bool CollisionManager::checkCollision(Car* car, Objects* object) {
//   SDL_Rect carBox = car->getMoverRect();
//   SDL_Rect objectBox = object->getMoverRect();

//   // Get rotated car corners
//   vector<vector<float>> carCorners = getCarCoordinates(car);

//   // Check if car center intersects with obstacle
//   bool intersectsCenter = SDL_HasIntersection(&carBox, &objectBox);

//   // Check if any car corner lies within the obstacle
//   for (const auto& corner : carCorners) {
//     if (corner[0] >= objectBox.x && corner[0] <= objectBox.x + objectBox.w &&
//         corner[1] >= objectBox.y && corner[1] <= objectBox.y + objectBox.h) {
//       intersectsCenter = true;
//       break;
//     }
//   }

//   // Check if any obstacle corner lies within the car
//   // Implement logic to calculate the rotated bounding box for the obstacle
// //   vector<vector<float>> obstacleRotatedCorners = getObstacleBoxCorners(object);
// //   // based on its position, angle, width, and height

// //   // Similar loop as above to check obstacle corners against car boundaries
// //   for (const auto& corner : obstacleRotatedCorners) {
// //     if (corner[0] >= carBox.x && corner[0] <= carBox.x + carBox.w &&
// //         corner[1] >= carBox.y && corner[1] <= carBox.y + carBox.h) {
// //       intersectsCenter = true;
// //       break;
// //     }
// //   }

//   return intersectsCenter;
// }


bool CollisionManager::checkCollisionObs(Car* car, Objects* object) {
    SDL_Rect carBox = car->getMoverRect();
    SDL_Rect objectBox = object->getMoverRect();

    // Get rotated car corners
    vector<vector<float>> carCorners = getCarCoordinates(car);

    // Check if car center intersects with obstacle
    bool intersectsCenter = SDL_HasIntersection(&carBox, &objectBox);

    vector<vector<float>> obstacleCorners = getObstacleBoxCorners(object);
    // Check if any car corner lies within the obstacle
    for (const auto& carCorner : carCorners) {
      // Minimum distance to obstacle boundary from current car corner
      float minDistance = FLT_MAX;
      // check for screen corners
      if (carCorner[0]>=980|| carCorner[0]<=20|| carCorner[1]>=590|| carCorner[1]<=0){
        return true; //collided with screen boundary
      }
      // Loop through obstacle corners
      for (const auto& obstacleCorner : obstacleCorners) {
      // Calculate distance between car corner and obstacle corner
        float distance = sqrt(pow(carCorner[0] - obstacleCorner[0], 2) + pow(carCorner[1] - obstacleCorner[1], 2));

        // Update minimum distance if closer
        if (distance < minDistance) {
            minDistance = distance;
          }
      }

      // Check if minimum distance is less than car's collision radius (adjust threshold)
      if (minDistance < 1) {
        return true; // Collision detected!
      }
    }
    return intersectsCenter;
}

bool CollisionManager::checkParking(Car* car, ParkingSpot* parkingSpace) {
  // Boundary check with tolerance
  SDL_Rect carBox = car->getMoverRect();
  SDL_Rect parkingBox = parkingSpace->getMoverRect();


  if (!SDL_HasIntersection(&carBox, &parkingBox)) {
    return false; // Car not within parking space with tolerance
  }

  // Center alignment check
  float carCenterX = car->getPosition().x + car->getMoverRect().w / 2.0f;
  float carCenterY = car->getPosition().y + car->getMoverRect().h / 2.0f;
  float parkingCenterX = parkingSpace->getPosition().x + parkingSpace->getMoverRect().w / 2.0f;
  float parkingCenterY = parkingSpace->getPosition().y + parkingSpace->getMoverRect().h / 2.0f;
  float distance = sqrt(pow(carCenterX - parkingCenterX, 2) + pow(carCenterY - parkingCenterY, 2));

  float alignmentThreshold = parkingBox.w * 0.1f; // 10% threshold
  return distance < alignmentThreshold; // Car center within alignment threshold
}


bool CollisionManager::checkCollisionCoin(Car* car, Coin* coin) {
  if (coin->collected == false){
    SDL_Rect carBox = car->getMoverRect();
    SDL_Rect coinBox = coin->getMoverRect();
    vector<vector<float>> carCorners = getCarCoordinates(car);
    bool intersects = SDL_HasIntersection(&carBox, &coinBox);
    // std::cout<<"checking for collision"<<"\n";
    for (const auto& corner : carCorners) {
      if (corner[0] >= coinBox.x && corner[0] <= coinBox.x + coinBox.w &&
          corner[1] >= coinBox.y && corner[1] <= coinBox.y + coinBox.h) {
        intersects = true;
        break;
      }
    }
    // std::cout<<"checked for collision"<<"\n";
    return intersects;
  }
  return false;
}

vector<vector<float>> CollisionManager::getObstacleBoxCorners(Objects* obstacle) {
  SDL_Rect objectBox = obstacle->getMoverRect();

  vector<vector<float>> corners;
  corners.push_back({static_cast<float>(objectBox.x), static_cast<float>(objectBox.y)});
  corners.push_back({static_cast<float>(objectBox.x + objectBox.w), static_cast<float>(objectBox.y)});
  corners.push_back({static_cast<float>(objectBox.x + objectBox.w), static_cast<float>(objectBox.y + objectBox.h)});
  corners.push_back({static_cast<float>(objectBox.x), static_cast<float>(objectBox.y + objectBox.h)});
  return corners;
}

void CollisionManager::resolveCollision(Car* car, SDL_Rect prevPos){
    car->moverRect = prevPos;
    car->velocity -= car->velocity;
}

void CollisionManager::resolveCoinCollision(Coin* thisCoin){
    thisCoin->collected = true;
};

vector<vector<float>> CollisionManager::getCarCoordinates(Car* car) {
  SDL_Rect rect = car->getMoverRect();
  float angleInRadians = car->getAngle() * M_PI / 180.0f; // convert degrees to radians

  float centerX = rect.x + rect.w / 2.0f;
  float centerY = rect.y + rect.h / 2.0f;

  float halfWidth = rect.w / 2.0f;
  float halfHeight = rect.h / 2.0f;

  // Calculate rotated offsets for each corner
  float tlOffsetX = halfWidth * cos(angleInRadians);
  float tlOffsetY = halfWidth * sin(angleInRadians);
  float trOffsetX = -halfWidth * cos(angleInRadians + 90.0f);
  float trOffsetY = -halfWidth * sin(angleInRadians + 90.0f);
  float brOffsetX = -halfWidth * cos(angleInRadians + 180.0f);
  float brOffsetY = -halfWidth * sin(angleInRadians + 180.0f);
  float blOffsetX = halfWidth * cos(angleInRadians + 270.0f);
  float blOffsetY = halfWidth * sin(angleInRadians + 270.0f);

  // Calculate and return corner coordinates
  vector<vector<float>> corners;
  corners.push_back({centerX + tlOffsetX, centerY + tlOffsetY});
  corners.push_back({centerX + trOffsetX, centerY + trOffsetY});
  corners.push_back({centerX + brOffsetX, centerY + brOffsetY});
  corners.push_back({centerX + blOffsetX, centerY + blOffsetY});
  return corners;
}

