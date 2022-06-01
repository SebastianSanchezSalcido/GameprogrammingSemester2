#ifndef SCENE_H
#define SCENE_H
#include "Component.h"
union SDL_Event;
class Scene : public Component {
public:	
	Scene(): Component(nullptr) {} 
	virtual ~Scene() {}
	virtual void HandleEvents(const SDL_Event &sdlEvent) = 0;
	
};
#endif