#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 vertNormal;
layout(location = 1) in vec3 eyeDir;
layout(location = 2) in vec3 lightDir;

layout(location = 0) out vec4 fragColor;

void main() {
vec4 ks = vec4(1.3, 0.3, 0.3, 0.0);
vec4 kd = vec4(0.0, 0.3, 0.28, 0.0);
vec4 ka = 0.5* kd;

//https://en.wikipedia.org/wiki/Phong_reflection_model //
float diff = max(dot(lightDir, vertNormal),0.0);
//This is the incident beam
vec3 reflection =  reflect(-lightDir, vertNormal);

float spec = max(dot(eyeDir, reflection), 0.0);
spec = pow(spec, 14.0);
//          ka + 
fragColor = ka + (kd* diff) + (ks* spec);
  
}