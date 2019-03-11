#include "my_materia.h"

MyMateria::MyMateria(MyShader *_shader, glm::vec3 _diffuse, glm::vec3 _specular, float _ambientCoe, float _shinness):
	shader(_shader),
	diffuse(_diffuse),
	specular(_specular),
	ambientCoe(_ambientCoe),
	shinness(_shinness)
{
}

void MyMateria::setVec3(const string &name, const glm::vec3 &val) const
{
	this->shader->setVec3(name, val);
}

void MyMateria::setInt(const string &name, int val) const
{
	this->shader->setInt(name, val);
}

void MyMateria::setFloat(const string &name, float val) const
{
	this->shader->setFloat(name, val);
}

MyShader * MyMateria::getShader()
{
	return this->shader;
}

glm::vec3 MyMateria::getDiffuse()
{
	return this->diffuse;
}

glm::vec3 MyMateria::getAmbient()
{
	return this->diffuse * this->ambientCoe;
}

glm::vec3 MyMateria::getSpecular()
{
	return this->specular;
}

float MyMateria::getShininess()
{
	return this->shinness;
}