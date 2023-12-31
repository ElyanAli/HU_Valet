#include "objects.hpp"

Objects::Objects(){}

Objects::Objects(SDL_Renderer* rndr, SDL_Rect rect, SDL_Rect mrect){
    srcRect = rect;
    renderer = rndr;
    moverRect = mrect;
}

SDL_Rect Objects::getMoverRect() const{
    return moverRect;
}

void Objects::setImage(string img){
    string imgstr = "./images/"+img;
    image = loadImage(imgstr);
};

float Objects::getAngle(){
	return 0;
}

SDL_Texture* Objects::loadImage(string path) {
    SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	return newTexture;
}

void Objects::draw(){
    SDL_RenderCopy(renderer, image, &srcRect, &moverRect);
}

SDL_Point Objects::getPosition(){
	return {moverRect.x , moverRect.y};
}

Objects::~Objects(){
	SDL_DestroyTexture(image);
	image = nullptr;
}