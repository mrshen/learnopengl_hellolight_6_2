#version 330 core

in vec3 normal;
in vec3 fragPos;

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float shinness;
};
uniform Material objMaterial;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 camPos;


out vec4 FragColor;
void main()
{
	vec3 norm = normalize(normal);

	// ambient color
	vec3 ambient = objMaterial.ambient * lightColor * vec3(0.5);

	// diffuse color
	vec3 lightDir = normalize(lightPos - fragPos);
	vec3 diffuse = (max(dot(lightDir, norm), 0.0) * objMaterial.diffuse) * lightColor * vec3(0.2);

	// specular color
	vec3 reflectDir = reflect(-lightDir, norm);
	vec3 viewDir = normalize(camPos - fragPos);
	float specCoe = max(dot(reflectDir, viewDir), 0.0);
	vec3 specular = pow(specCoe, objMaterial.shinness) * objMaterial.specular * lightColor;

	FragColor = vec4(ambient + diffuse + specular, 1.0);
}