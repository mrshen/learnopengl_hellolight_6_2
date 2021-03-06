#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

//用4个vec4输入构造这个mat4
layout (location = 2) in mat4 model;

//uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 normal;
out vec3 fragPos;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);

 	normal = mat3(transpose(inverse(model))) * aNormal;
 	fragPos = vec3(model * vec4(aPos, 1.0));
}