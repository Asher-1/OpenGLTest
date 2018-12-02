//片元着色器代码
#version 330 core
out vec4 FragColor;
in vec3 ourColor;

void main()
{
	FragColor = vec4(ourColor, 1.0f);
	// FragColor = uniformColor;
}