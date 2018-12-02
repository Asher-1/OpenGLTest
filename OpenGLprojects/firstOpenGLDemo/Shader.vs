//顶点着色器代码
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 ourColor;

uniform vec4 uniformColor;
uniform float xOffset;
void main()
{
	gl_Position = vec4(aPos.x, -aPos.y, aPos.z, 1.0);
	ourColor = uniformColor.xyz;
	// ourColor = aColor;
}
