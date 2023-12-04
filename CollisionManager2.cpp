#include "CollisionManager2.hpp"


// bool CollisionManager2::checkCollision(Car* car, Objects* object) {
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

// bool CollisionManager2::checkCollision(Car* car, Objects* object) {
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


// 

// bool CollisionManager2::checkCollisionObs(Car* car, Objects* object, vector<int> levelBoundaries) {
//   // Get car and obstacle corners
//   vector<vector<float>> carCorners = getCarCoordinates(car);
//   vector<vector<float>> obstacleCorners = getObstacleBoxCorners(object);

//   // Define separating lines for car and obstacle based on their angles and edges
//   vector<pair<float, float>> carLines = getSeparatingLines(car);
//   vector<pair<float, float>> obstacleLines = getSeparatingLines(object);

//   // Check collisions between car and obstacle corners against each other's lines
//   for (const auto& carCorner : carCorners) {
//     for (const auto& obstacleLine : obstacleLines) {
//       if (getSideOfLine(obstacleLine, carCorner) == 0.0f) {
//         return true; // Car corner on wrong side of obstacle line, collision!
//       }
//     }
//   }

  

//   // Repeat for obstacle corners against car lines

//   // Check for collisions with screen boundaries

//   return false; // No collisions detected
// }


// float CollisionManager2::getSideOfLine(pair<float, float> line, vector<float> point) {
//   // Extract line slope and intercept
//   float m = line.first;
//   float b = line.second;

//   // Calculate the signed distance from point to line
//   float distance = (m * point[0] - point[1] + b) / sqrt(m * m + 1);

//   // Return positive/negative value based on side of the line
//   return distance;
// }



// vector<pair<float, float>> CollisionManager2::getSeparatingLines(Objects* mover) {
//   // Extract mover position, angle, width, and height
//   float centerX = mover->getPosition().x + mover->getMoverRect().w / 2.0f;
//   float centerY = mover->getPosition().y + mover->getMoverRect().h / 2.0f;
//   float width = mover->getMoverRect().w;
//   float height = mover->getMoverRect().h;
//   float angle = mover->getAngle();

//   // Calculate edge vectors based on angle and dimensions
//   vector<pair<float, float>> edges;
//   edges.push_back({-sin(angle), cos(angle)}); // Top edge
//   edges.push_back({sin(angle), -cos(angle)}); // Bottom edge
//   edges.push_back({cos(angle), sin(angle)}); // Right edge
//   edges.push_back({-cos(angle), -sin(angle)}); // Left edge

//   // Convert edges to lines in slope-intercept form (y = mx + b)
//   vector<pair<float, float>> lines;
//   for (const auto& edge : edges) {
//     float m = edge.first / edge.second; // Slope
//     float b = centerY - m * centerX; // Intercept
//     lines.push_back({m, b});
//   }

//   return lines;
// }



// bool CollisionManager2::checkParking(Car* car, ParkingSpot* parkingSpace) {
//   // Boundary check with tolerance
//   SDL_Rect carBox = car->getMoverRect();
//   SDL_Rect parkingBox = parkingSpace->getMoverRect();


//   if (!SDL_HasIntersection(&carBox, &parkingBox)) {
//     return false; // Car not within parking space with tolerance
//   }

//   // Center alignment check
//   float carCenterX = car->getPosition().x + car->getMoverRect().w / 2.0f;
//   float carCenterY = car->getPosition().y + car->getMoverRect().h / 2.0f;
//   float parkingCenterX = parkingSpace->getPosition().x + parkingSpace->getMoverRect().w / 2.0f;
//   float parkingCenterY = parkingSpace->getPosition().y + parkingSpace->getMoverRect().h / 2.0f;
//   float distance = sqrt(pow(carCenterX - parkingCenterX, 2) + pow(carCenterY - parkingCenterY, 2));

//   float alignmentThreshold = parkingBox.w * 0.1f; // 10% threshold
//   return distance < alignmentThreshold; // Car center within alignment threshold
// }


// bool CollisionManager2::checkCollisionCoin(Car* car, Coin* coin) {
//   if (coin->collected == false){
//     SDL_Rect carBox = car->getMoverRect();
//     SDL_Rect coinBox = coin->getMoverRect();
//     vector<vector<float>> carCorners = getCarCoordinates(car);
//     bool intersects = SDL_HasIntersection(&carBox, &coinBox);
//     // std::cout<<"checking for collision"<<"\n";
//     for (const auto& corner : carCorners) {
//       if (corner[0] >= coinBox.x && corner[0] <= coinBox.x + coinBox.w &&
//           corner[1] >= coinBox.y && corner[1] <= coinBox.y + coinBox.h) {
//         intersects = true;
//         break;
//       }
//     }
//     // std::cout<<"checked for collision"<<"\n";
//     return intersects;
//   }
//   return false;
// }

// vector<vector<float>> CollisionManager2::getObstacleBoxCorners(Objects* obstacle) {
//   SDL_Rect objectBox = obstacle->getMoverRect();

//   vector<vector<float>> corners;
//   corners.push_back({static_cast<float>(objectBox.x), static_cast<float>(objectBox.y)});
//   corners.push_back({static_cast<float>(objectBox.x + objectBox.w), static_cast<float>(objectBox.y)});
//   corners.push_back({static_cast<float>(objectBox.x + objectBox.w), static_cast<float>(objectBox.y + objectBox.h)});
//   corners.push_back({static_cast<float>(objectBox.x), static_cast<float>(objectBox.y + objectBox.h)});
//   return corners;
// }

// void CollisionManager2::resolveCollision(Car* car, SDL_Rect prevPos){
//     car->moverRect = prevPos;
//     car->velocity -= car->velocity;
// }

// void CollisionManager2::resolveCoinCollision(Coin* thisCoin){
//     thisCoin->collected = true;
// };

// vector<vector<float>> CollisionManager2::getCarCoordinates(Car* car) {
//   SDL_Rect rect = car->getMoverRect();
//   float angleInRadians = car->getAngle() * M_PI / 180.0f; // convert degrees to radians

//   float centerX = rect.x + rect.w / 2.0f;
//   float centerY = rect.y + rect.h / 2.0f;

//   float halfWidth = rect.w / 2.0f;
//   float halfHeight = rect.h / 2.0f;

//   // Calculate rotated offsets for each corner
//   float tlOffsetX = halfWidth * cos(angleInRadians);
//   float tlOffsetY = halfWidth * sin(angleInRadians);
//   float trOffsetX = -halfWidth * cos(angleInRadians + 90.0f);
//   float trOffsetY = -halfWidth * sin(angleInRadians + 90.0f);
//   float brOffsetX = -halfWidth * cos(angleInRadians + 180.0f);
//   float brOffsetY = -halfWidth * sin(angleInRadians + 180.0f);
//   float blOffsetX = halfWidth * cos(angleInRadians + 270.0f);
//   float blOffsetY = halfWidth * sin(angleInRadians + 270.0f);

//   // Calculate and return corner coordinates
//   vector<vector<float>> corners;
//   corners.push_back({centerX + tlOffsetX, centerY + tlOffsetY});
//   corners.push_back({centerX + trOffsetX, centerY + trOffsetY});
//   corners.push_back({centerX + brOffsetX, centerY + brOffsetY});
//   corners.push_back({centerX + blOffsetX, centerY + blOffsetY});
//   return corners;
// }



