#include <glew.h>
#include <iostream>
#include <SDL.h>
#include "Debug.h"
#include "Scene0.h"
#include "MMath.h"
#include "Debug.h"
#include "Actor.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

Scene0::Scene0() :sphere{ nullptr }, mesh{ nullptr }, shader{ nullptr } {

	Debug::Info("Created Scene0: ", __FILE__, __LINE__);
}

Scene0::~Scene0() {
	Debug::Info("Deleted Scene0: ", __FILE__, __LINE__);
}

bool Scene0::OnCreate() {
	
	sphere = new Actor(nullptr);
	mesh = new Mesh(nullptr, "meshes/Skull.obj");
	bool status = mesh->OnCreate();

	shader = new Shader(nullptr, "shaders/textVert.glsl", "shaders/textFrag.glsl");
	status = shader->OnCreate();

	texture = new Texture();
	texture->LoadImage("textures/skull_texture.jpg");

	projectionMatrix = MMath::perspective(45.0f, (16.0f / 9.0f), 0.5f, 100.0f);
	viewMatrix = MMath::lookAt(Vec3(0.0f, 0.0f, 5.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));

	//modelMatrix1 = MMath::translate(Vec3(3.0f, 0.0f, 0.0f)) * 
		         // MMath::rotate(0.0f, Vec3(0.0f, 1.0f, 0.0f)) * 
		          //MMath::scale(0.5f, 0.5f, 0.5f);

	lightPos = Vec3(10.0f,10.0f,10.0f);
    Debug::Info("Loading assets Scene0: ", __FILE__, __LINE__);
	return true;
}

void Scene0::OnDestroy() {
	delete sphere;
	sphere = nullptr;
	delete mesh;
	mesh = nullptr;
	delete shader;
	shader = nullptr;
	delete texture;
	texture = nullptr;
	Debug::Info("Deleting assets Scene0: ", __FILE__, __LINE__);
}

void Scene0::HandleEvents(const SDL_Event &sdlEvent) {
	switch( sdlEvent.type ) {
    case SDL_KEYDOWN:
		std::cout << "hello";
		break;

	case SDL_MOUSEMOTION:      
		std::cout << "hello mouse";
		break;

	case SDL_MOUSEBUTTONDOWN:              
		break; 

	case SDL_MOUSEBUTTONUP:            
	break;

	default:
		break;
    }
}

void Scene0::Update(const float deltaTime) {
	static float totalTime = 0.0f;
	totalTime += deltaTime;
	//modelMatrix1 = MMath::rotate(totalTime * 50.0f, Vec3(0.0f, 1.0f, 0.0f))*
		          MMath::translate(Vec3(3.0f, 0.0f, 0.0f))*
		          MMath::rotate(180.0f, Vec3(0.0f, 1.0f, 0.0f))*
		          MMath::scale(0.5f, 0.5f, 0.5f);
	modelMatrix2 = MMath::rotate(totalTime * -50.0f, Vec3(0.0f, 1.0f, 0.0f));

}

void Scene0::Render() const {
	glEnable(GL_DEPTH_TEST);
	/// Clear the screen
	            //red green  blue "alpha"//
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glUseProgram(shader->GetProgram());
	glUniformMatrix4fv(shader->GetUniformID("projectionMatrix"), 1, GL_FALSE, projectionMatrix);
	glUniformMatrix4fv(shader->GetUniformID("viewMatrix"), 1, GL_FALSE, viewMatrix);
	glUniform3fv(shader->GetUniformID("lightPos"), 1, lightPos);
	glBindTexture(GL_TEXTURE_2D, texture->getTextureID());
	//glUniformMatrix4fv(shader->GetUniformID("modelMatrix"), 1, GL_FALSE, modelMatrix1);
	//mesh->Render(GL_TRIANGLES);

	glUniformMatrix4fv(shader->GetUniformID("modelMatrix"), 1, GL_FALSE, modelMatrix2);
	mesh->Render(GL_TRIANGLES);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}



	
