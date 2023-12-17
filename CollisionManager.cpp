
#include "CollisionManager.hpp"


bool CollisionManager::checkCollisionBnd(Car* car, vector<int> boundary) {
  // Calculate car's position relative to camera
  int margin = 15;
  float carX = car->getPosition().x;
  float carY = car->getPosition().y;
  float carWidth = car->getMoverRect().w;
  float carHeight = car->getMoverRect().h;

  // Check for collision with margins around screen edges
  return (carX - margin < boundary[0] || carX + carWidth + margin > boundary[1] ||
          carY - margin < boundary[2] || carY + carHeight + margin > boundary[3]);
};

bool CollisionManager::checkCollisionObs(Car* car, Objects* obstacle) {

  // Define axes (car edges, obstacle edges, etc.)
  vector<pair<float, float>> axes;

  // Add axes aligned with car edges
  float carAngle = car->getAngle() * M_PI / 180.0f; // Convert degrees to radians
  axes.push_back({sin(carAngle), -cos(carAngle)}); // Top edge
  axes.push_back({-sin(carAngle), cos(carAngle)}); // Bottom edge
  axes.push_back({cos(carAngle), sin(carAngle)}); // Right edge
  axes.push_back({-cos(carAngle), -sin(carAngle)}); // Left edge

  // Add axes aligned with obstacle edges (modify as needed)
  axes.push_back({obstacle->getMoverRect().w, 0}); // Horizontal axis for obstacle
  axes.push_back({0, obstacle->getMoverRect().h}); // Vertical axis for obstacle

  // Project car and obstacle onto axes
  vector<pair<float, float>> carProjections;
  vector<pair<float, float>> obstacleProjections;
  for (const auto& axis : axes) {
    carProjections.push_back(projectObjectOnAxis(car, axis));
    obstacleProjections.push_back(projectObjectOnAxis(obstacle, axis));
  }

  // Check for overlap on each axis
  for (int i = 0; i < axes.size(); ++i) {
    if (!overlap(carProjections[i], obstacleProjections[i])) {
      // No overlap on this axis, objects separated
      car->collided = false;
      return false;
    }
  }
  car->collided = true;
  cout<<car->collided<<endl;
  // All axes have overlap, collision confirmed!
  return true;
}

// Project object onto an axis
pair<float, float> CollisionManager::projectObjectOnAxis(Objects* obj, pair<float, float> axis) {
  // Get object vertices
  vector<vector<float>> vertices = getVertices(obj);

  // Calculate dot products with axis for each vertex
  vector<float> dotProducts;
  for (const auto& vertex : vertices) {
    dotProducts.push_back(axis.first * vertex[0] + axis.second * vertex[1]);
  }

  // Find minimum and maximum dot product values
  float minDot = *std::min_element(dotProducts.begin(), dotProducts.end());
  float maxDot = *std::max_element(dotProducts.begin(), dotProducts.end());

  return {minDot, maxDot};
}

// Check for overlap between two intervals
bool CollisionManager::overlap(pair<float, float> interval1, pair<float, float> interval2) {
  // Check if one interval completely encloses the other
  if (interval1.first <= interval2.first && interval1.second >= interval2.second) {
    return true;
  } else if (interval2.first <= interval1.first && interval2.second >= interval1.second) {
    return true;
  }

  // Check if intervals overlap on the number line
  if (interval1.first < interval2.second && interval1.second > interval2.first) {
    return true;
  }

  return false;
}

// Get object vertices based on type
vector<vector<float>> CollisionManager::getVertices(Objects* obj) {
  // Check object type and implement specific logic for each
  if (dynamic_cast<Car*>(obj)) {
    return getCarVertices(obj);
  } else if (dynamic_cast<Obstacle*>(obj)) {
    return getObstacleVertices(obj);
  } else {
    // Add default behavior for unknown object types
    return {};
  }
}

// Get car vertices based on position, angle, width, and height
vector<vector<float>> CollisionManager::getCarVertices(Objects* obj) {
  Car* car = static_cast<Car*>(obj);
  float centerX = car->getPosition().x + car->getMoverRect().w / 2.0f;
  float centerY = car->getPosition().y + car->getMoverRect().h / 2.0f;
  float halfWidth = car->getMoverRect().w / 2.0f;
  float halfHeight = car->getMoverRect().h / 2.0f;
  float angleInRadians = car->getAngle() * M_PI / 180.0f; // Convert degrees to radians

  // Calculate rotated corner coordinates using sine and cosine of the angle
  vector<vector<float>> vertices;
  vertices.push_back({centerX + halfWidth * cos(angleInRadians) - halfHeight * sin(angleInRadians),
                     centerY + halfWidth * sin(angleInRadians) + halfHeight * cos(angleInRadians)}); // Top right
  vertices.push_back({centerX - halfWidth * cos(angleInRadians) - halfHeight * sin(angleInRadians),
                     centerY - halfWidth * sin(angleInRadians) + halfHeight * cos(angleInRadians)}); // Top left
  vertices.push_back({centerX - halfWidth * cos(angleInRadians) + halfHeight * sin(angleInRadians),
                     centerY - halfWidth * sin(angleInRadians) - halfHeight * cos(angleInRadians)}); // Bottom left
  vertices.push_back({centerX + halfWidth * cos(angleInRadians) + halfHeight * sin(angleInRadians),
                     centerY + halfWidth * sin(angleInRadians) - halfHeight * cos(angleInRadians)}); // Bottom right

  return vertices;
}

vector<vector<float>> CollisionManager::getObstacleVertices(Objects* obj) {
  Obstacle* obstacle = static_cast<Obstacle*>(obj);

  // Extract obstacle position and dimensions
  float x = obstacle->getPosition().x;
  float y = obstacle->getPosition().y;
  float width = obstacle->getMoverRect().w;
  float height = obstacle->getMoverRect().h;

  // Define vertices based on bounding box corners
  vector<vector<float>> vertices;
  vertices.push_back({x, y}); // Top left
  vertices.push_back({x + width, y}); // Top right
  vertices.push_back({x + width, y + height}); // Bottom right
  vertices.push_back({x, y + height}); // Bottom left

  return vertices;
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
    vector<vector<float>> carCorners = getCarVertices(car);
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


void CollisionManager::resolveCoinCollision(Coin* thisCoin){
    thisCoin->collected = true;
};

void CollisionManager::resolveCollision(Car* car){
  car->collided = true;
  car->velocity -= car->velocity;
}

void CollisionManager::revive(Car* car){
  std::cout<< car->savedRect.x<<", "<<car->savedRect.y<<", "<<car->savedRect.w<<", "<<car->savedRect.h<<std::endl;
  car->moverRect = car->savedRect;
  car->angle = car->savedAngle;
  std::cout<< car->savedRect.x<<", "<<car->savedRect.y<<", "<<car->savedRect.w<<", "<<car->savedRect.h<<std::endl;
}



