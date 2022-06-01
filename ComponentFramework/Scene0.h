#ifndef SCENE0_H
#define SCENE0_H
#include "Scene.h"
#include "Vector.h"
#include "Matrix.h"
using namespace MATH;

/// Forward declarations 
union SDL_Event;
class Actor;
class Mesh;
class Shader;
class Texture;

class Scene0 : public Scene {
private:
	Actor* sphere;
	Mesh* mesh;
	Mesh* mesh2;
	Shader* shader;
	Texture* texture;
	Texture* texture1;
	Matrix4 projectionMatrix;
	Matrix4 viewMatrix;
	//Matrix4 modelMatrix1;
	Matrix4 modelMatrix2;
	Matrix4 modelMatrix3;
	
	Vec3 lightPos;

public:
	explicit Scene0();
	virtual ~Scene0();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event &sdlEvent) override;
};


#endif // SCENE0_H