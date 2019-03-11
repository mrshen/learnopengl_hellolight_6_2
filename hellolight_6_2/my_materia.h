#pragma once
#ifndef MY_MATERIA_H
#define MY_MATERIA_H

#include "my_shader.h"

class MyMateria
{
public:
	MyMateria(MyShader *, glm::vec3, glm::vec3, float, float);

	void setVec3(const string &, const glm::vec3 &) const;
	void setInt(const string &, int) const;
	void setFloat(const string &, float) const;

	MyShader * getShader();
	glm::vec3 getDiffuse();
	glm::vec3 getAmbient();
	glm::vec3 getSpecular();
	float getShininess();
private:
	MyShader *shader;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float ambientCoe;
	float shinness;
};


#endif // !MY_MATERIA_H
