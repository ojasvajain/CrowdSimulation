// Link statically with GLEW
#define GLEW_STATIC

// Headers
#include <windows.h>
#include <glew.h>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace sf;
//MAX source size of the kernel string
#define MAX_Source_size1 (0x100000)
#define MAX_Source_size2 (0x100000)
#define MAX_Source_size3 (0x100000)

// Shader sources
const GLchar* vertexSource =
"#version 150 core\n"
"in vec2 position;"
"void main()"
"{"
"    gl_Position = vec4(position, 0.0, 1.0);"
"}";

const GLchar* fragmentSource1 =
"#version 150 core\n"
"out vec4 outColor;"
"void main()"
"{"
"    outColor = vec4(1.0, 0.0, 0.0, 0.0);"
"}";

const GLchar* fragmentSource2 =
"#version 150 core\n"
"out vec4 outColor;"
"void main()"
"{"
"    outColor = vec4(0.0, 1.0, 0.0, 0.0);"
"}";

const GLchar* fragmentSource3 =
"#version 150 core\n"
"out vec4 outColor;"
"void main()"
"{"
"    outColor = vec4(0.0, 0.0, 1.0, 0.0);"
"}";

ContextSettings settings(24,8,0,0,0);
Window window(VideoMode(800, 600, 32), "OpenGL", Style::Titlebar | Style::Close, settings);

void graphics(GLfloat *vertices1, GLfloat *vertices2, GLfloat *vertices3, int n)
{
	GLint posAttrib;
	GLuint vao1,vao2,vao3;
	GLuint vbo1,vbo2,vbo3;
	GLuint vertexShader1, vertexShader2, vertexShader3;
	GLuint fragmentShader1, fragmentShader2, fragmentShader3;
	GLuint shaderProgram1, shaderProgram2, shaderProgram3;

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();
	// Clear the screen to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);;

	// Create Vertex Array Object
	glGenVertexArrays(1, &vao1);
	glBindVertexArray(vao1);

	// Create a Vertex Buffer Object and copy the vertex data to it
	glGenBuffers(1, &vbo1);

	glBindBuffer(GL_ARRAY_BUFFER, vbo1);
	glBufferData(GL_ARRAY_BUFFER, n*sizeof(*vertices1), vertices1, GL_STATIC_DRAW);

	// Create and compile the vertex shader
	vertexShader1 = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader1, 1, &vertexSource, NULL);
	glCompileShader(vertexShader1);

	// Create and compile the fragment shader
	fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader1, 1, &fragmentSource1, NULL);
	glCompileShader(fragmentShader1);

	// Link the vertex and fragment shader into a shader program
	shaderProgram1 = glCreateProgram();
	glAttachShader(shaderProgram1, vertexShader1);
	glAttachShader(shaderProgram1, fragmentShader1);
	glBindFragDataLocation(shaderProgram1, 0, "outColor");
	glLinkProgram(shaderProgram1);
	glUseProgram(shaderProgram1);

	// Specify the layout of the vertex data
	posAttrib = glGetAttribLocation(shaderProgram1, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_POINTS, 0, n/2);

	


	glGenVertexArrays(1, &vao2);
	glBindVertexArray(vao2);

	// Create a Vertex Buffer Object and copy the vertex data to it
	glGenBuffers(1, &vbo2);

	glBindBuffer(GL_ARRAY_BUFFER, vbo2);
	glBufferData(GL_ARRAY_BUFFER, n* sizeof(*vertices2), vertices2, GL_STATIC_DRAW);

	// Create and compile the vertex shader
	vertexShader2 = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader2, 1, &vertexSource, NULL);
	glCompileShader(vertexShader2);

	// Create and compile the fragment shader
	fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader2, 1, &fragmentSource2, NULL);
	glCompileShader(fragmentShader2);

	// Link the vertex and fragment shader into a shader program
	shaderProgram2 = glCreateProgram();
	glAttachShader(shaderProgram2, vertexShader2);
	glAttachShader(shaderProgram2, fragmentShader2);
	glBindFragDataLocation(shaderProgram2, 0, "outColor");
	glLinkProgram(shaderProgram2);
	glUseProgram(shaderProgram2);

	// Specify the layout of the vertex data
	posAttrib = glGetAttribLocation(shaderProgram2, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_POINTS, 0, n / 2);


	//window.display();


	
	glGenVertexArrays(1, &vao3);

	glBindVertexArray(vao3);

	// Create a Vertex Buffer Object and copy the vertex data to it
	glGenBuffers(1, &vbo3);

	glBindBuffer(GL_ARRAY_BUFFER, vbo3);
	glBufferData(GL_ARRAY_BUFFER, n * sizeof(*vertices3), vertices3, GL_STATIC_DRAW);

	// Create and compile the vertex shader
	vertexShader3 = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader3, 1, &vertexSource, NULL);
	glCompileShader(vertexShader3);

	// Create and compile the fragment shader
	fragmentShader3 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader3, 1, &fragmentSource3, NULL);
	glCompileShader(fragmentShader3);

	// Link the vertex and fragment shader into a shader program
	shaderProgram3 = glCreateProgram();
	glAttachShader(shaderProgram3, vertexShader3);
	glAttachShader(shaderProgram3, fragmentShader3);
	glBindFragDataLocation(shaderProgram3, 0, "outColor");
	glLinkProgram(shaderProgram3);
	glUseProgram(shaderProgram3);

	// Specify the layout of the vertex data
	posAttrib = glGetAttribLocation(shaderProgram3, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);


	// Draw a triangle from the 3 vertices
	glDrawArrays(GL_POINTS, 0, n/2);
	window.display();


	glClear(GL_COLOR_BUFFER_BIT);

	glDetachShader(shaderProgram1, vertexShader1);
	glDetachShader(shaderProgram2, vertexShader2);
	glDetachShader(shaderProgram3, vertexShader3);
	glDeleteProgram(shaderProgram1);
	glDeleteProgram(shaderProgram2);
	glDeleteProgram(shaderProgram3);

	glDeleteShader(fragmentShader1);
	glDeleteShader(fragmentShader2);
	glDeleteShader(fragmentShader3);

	glDeleteShader(vertexShader1);
	glDeleteShader(vertexShader2);
	glDeleteShader(vertexShader3);

	glDeleteBuffers(1, &vbo1);
	glDeleteBuffers(1, &vbo2);
	glDeleteBuffers(1, &vbo3);
	glDeleteVertexArrays(1, &vao1);
	glDeleteVertexArrays(1, &vao2);
	glDeleteVertexArrays(1, &vao3);
//	window.close();
}


int main(void)
{
	//Create the two input vectors
	int i;
	float position_x[3000], position_y[3000], direction_x[3000], direction_y[3000],velocity[3000];
	float radius_repulsion=0.005f, radius_attraction=0.1f, delta_time = 0.002f;
	int color[3000];
	int n = 150, offset1 = 0, offset2 = n / 3, offset3 = 2 * n / 3;
	for (i = 0; i < n; i++)
	{
		position_x[i] =(float) (i-n/2)/n;
		position_y[i] = (float)(i-n/2)/n;
		direction_x[i] = (float)cos(i);
		direction_y[i] = (float)sin(i);
		velocity[i] = 5.0f;
		if (i < n / 3)
			color[i] = 0;
		else if (i >= (n / 3)&&i<(2*n/3))
			color[i] = 1;
		else
			color[i] = 2;
	}

	GLfloat vertices1[20000];
	GLfloat vertices2[20000];
	GLfloat vertices3[20000];
	
	//Load the kernel source code into array source_str1
	FILE *fp1, *fp2,*fp3;
	char *source_str1, *source_str2, *source_str3;
	size_t source_size1, source_size2, source_size3;

	fp1 = fopen("new_direction.cl", "r");
	if (!fp1)
	{
		fprintf(stderr, "Failed to load kernel\n");
		getchar();
		exit(1);
	}
	source_str1 = (char*)malloc(MAX_Source_size1);
	source_size1 = fread(source_str1, 1, MAX_Source_size1, fp1);
	fclose(fp1);

	fp2 = fopen("new_position.cl", "r");
	if (!fp2)
	{
		fprintf(stderr, "Failed to load kernel\n");
		getchar();
		exit(1);
	}
	source_str2 = (char*)malloc(MAX_Source_size2);
	source_size2 = fread(source_str2, 1, MAX_Source_size2, fp2);
	fclose(fp2);

	fp3 = fopen("copy.cl", "r");
	if (!fp3)
	{
		fprintf(stderr, "Failed to load kernel\n");
		getchar();
		exit(1);
	}
	source_str3 = (char*)malloc(MAX_Source_size3);
	source_size3 = fread(source_str3, 1, MAX_Source_size3, fp3);
	fclose(fp3);

	//Get platform and device information
	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;

	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ALL, 1, &device_id, &ret_num_devices);

	//Create an OpenCL context
	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

	//Create an command queue
	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);

	//Create memory buffers on the device for each vector A, B, C
	cl_mem position_x_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, n * sizeof(float), NULL, &ret);
	cl_mem position_y_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, n * sizeof(float), NULL, &ret);
	cl_mem direction_x_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, n * sizeof(float), NULL, &ret);
	cl_mem direction_y_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, n * sizeof(float), NULL, &ret);
	cl_mem velocity_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, n * sizeof(float), NULL, &ret);
	cl_mem color_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, n * sizeof(int), NULL, &ret);
	cl_mem vertices1_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, (2*n/3) * sizeof(float), NULL, &ret);
	cl_mem vertices2_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, (2*n/3) * sizeof(float), NULL, &ret);
	cl_mem vertices3_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, (2*n/3) * sizeof(float), NULL, &ret);

	//Copy the lists A and B to their respective memory buffers
	ret = clEnqueueWriteBuffer(command_queue, position_x_mem_obj, CL_TRUE, 0, n * sizeof(float), position_x, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, position_y_mem_obj, CL_TRUE, 0, n * sizeof(float), position_y, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, direction_x_mem_obj, CL_TRUE, 0, n * sizeof(float), direction_x, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, direction_y_mem_obj, CL_TRUE, 0, n * sizeof(float), direction_y, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, velocity_mem_obj, CL_TRUE, 0, n * sizeof(float), velocity, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, color_mem_obj, CL_TRUE, 0, n * sizeof(int), color, 0, NULL, NULL);
	

	//Create a program from the kernel source
	cl_program program1 = clCreateProgramWithSource(context, 1, (const char **)&source_str1, (const size_t *)&source_size1, &ret);
	cl_program program2 = clCreateProgramWithSource(context, 1, (const char **)&source_str2, (const size_t *)&source_size2, &ret);
	cl_program program3 = clCreateProgramWithSource(context, 1, (const char **)&source_str3, (const size_t *)&source_size3, &ret);
	//Build the program
	ret = clBuildProgram(program1, 1, &device_id, NULL, NULL, NULL);
	ret = clBuildProgram(program2, 1, &device_id, NULL, NULL, NULL);
	ret = clBuildProgram(program3, 1, &device_id, NULL, NULL, NULL);

	//Create the OpenCL kernel object
	cl_kernel kernel1 = clCreateKernel(program1, "next_direction", &ret);
	cl_kernel kernel2 = clCreateKernel(program2, "next_position", &ret);
	cl_kernel kernel3 = clCreateKernel(program3, "copy_value", &ret);
	cl_kernel kernel4 = clCreateKernel(program3, "copy_value", &ret);
	cl_kernel kernel5 = clCreateKernel(program3, "copy_value", &ret);

	//Set the arguments of the kernel
	ret = clSetKernelArg(kernel1, 0, sizeof(cl_mem), (void *)&position_x_mem_obj);
	ret = clSetKernelArg(kernel1, 1, sizeof(cl_mem), (void *)&position_y_mem_obj);
	ret = clSetKernelArg(kernel1, 2, sizeof(cl_mem), (void *)&direction_x_mem_obj);
	ret = clSetKernelArg(kernel1, 3, sizeof(cl_mem), (void *)&direction_y_mem_obj);
	ret = clSetKernelArg(kernel1, 4, sizeof(cl_mem), (void *)&velocity_mem_obj);
	ret = clSetKernelArg(kernel1, 5, sizeof(cl_mem), (void *)&color_mem_obj);
	ret = clSetKernelArg(kernel1, 6, sizeof(float), &radius_repulsion);
	ret = clSetKernelArg(kernel1, 7, sizeof(float), &radius_attraction);

	ret = clSetKernelArg(kernel2, 0, sizeof(cl_mem), (void *)&position_x_mem_obj);
	ret = clSetKernelArg(kernel2, 1, sizeof(cl_mem), (void *)&position_y_mem_obj);
	ret = clSetKernelArg(kernel2, 2, sizeof(cl_mem), (void *)&direction_x_mem_obj);
	ret = clSetKernelArg(kernel2, 3, sizeof(cl_mem), (void *)&direction_y_mem_obj);
	ret = clSetKernelArg(kernel2, 4, sizeof(cl_mem), (void *)&velocity_mem_obj);
	ret = clSetKernelArg(kernel2, 5, sizeof(float), &delta_time);

	ret = clSetKernelArg(kernel3, 0, sizeof(cl_mem), (void *)&position_x_mem_obj);
	ret = clSetKernelArg(kernel3, 1, sizeof(cl_mem), (void *)&position_y_mem_obj);
	ret = clSetKernelArg(kernel3, 2, sizeof(cl_mem), (void *)&vertices1_mem_obj);
	ret = clSetKernelArg(kernel3, 3, sizeof(int), &offset1);

	ret = clSetKernelArg(kernel4, 0, sizeof(cl_mem), (void *)&position_x_mem_obj);
	ret = clSetKernelArg(kernel4, 1, sizeof(cl_mem), (void *)&position_y_mem_obj);
	ret = clSetKernelArg(kernel4, 2, sizeof(cl_mem), (void *)&vertices2_mem_obj);
	ret = clSetKernelArg(kernel4, 3, sizeof(int), &offset2);

	ret = clSetKernelArg(kernel5, 0, sizeof(cl_mem), (void *)&position_x_mem_obj);
	ret = clSetKernelArg(kernel5, 1, sizeof(cl_mem), (void *)&position_y_mem_obj);
	ret = clSetKernelArg(kernel5, 2, sizeof(cl_mem), (void *)&vertices3_mem_obj);
	ret = clSetKernelArg(kernel5, 3, sizeof(int), &offset3);

	//Execute the OpenCL kernel on the array
	size_t global_item_size = n;
	size_t local_item_size = 1;

	size_t global_item_size_copy = 2 * n / 3;
	//Execute the kernel on the device
	cl_event event;
	
	
	ret = clEnqueueNDRangeKernel(command_queue, kernel3, 1, NULL, &global_item_size_copy, &local_item_size, 0, NULL, NULL);
	ret = clEnqueueNDRangeKernel(command_queue, kernel4, 1, NULL, &global_item_size_copy, &local_item_size, 0, NULL, NULL);
	ret = clEnqueueNDRangeKernel(command_queue, kernel5, 1, NULL, &global_item_size_copy, &local_item_size, 0, NULL, NULL);

	ret = clEnqueueReadBuffer(command_queue, vertices1_mem_obj, CL_TRUE, 0, (2*n/3)* sizeof(GLfloat), vertices1, 0, NULL, NULL);
	//ret = clEnqueueWriteBuffer(command_queue, vertices1_mem_obj, CL_TRUE, 0, (2*n/3)* sizeof(float), vertices1, 0, NULL, NULL);
	ret = clEnqueueReadBuffer(command_queue, vertices2_mem_obj, CL_TRUE, 0, (2*n/3)* sizeof(GLfloat), vertices2, 0, NULL, NULL);
	//ret = clEnqueueWriteBuffer(command_queue, vertices2_mem_obj, CL_TRUE, 0, (2*n/3)* sizeof(float), vertices2, 0, NULL, NULL);
	ret = clEnqueueReadBuffer(command_queue, vertices3_mem_obj, CL_TRUE, 0, (2*n/3)* sizeof(GLfloat), vertices3, 0, NULL, NULL);
	//ret = clEnqueueWriteBuffer(command_queue, vertices3_mem_obj, CL_TRUE, 0, (2*n/3)* sizeof(float), vertices3, 0, NULL, NULL);

	/*//for (i = 0; i < 2 * n / 3; i++)
		//printf("%f ", vertices1[i]);
	//printf("\n");
	//for (i = 0; i < 2 * 6 / 3; i++)
		//printf("%f %f %f,", vertices1[i], vertices2[i], vertices3[i]);
	for (i = 0; i < 2 * 6 / 3; i++)
		printf("%f %f,\n", position_x[i], position_y[i]);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");*/
	graphics(vertices1, vertices2, vertices3, 2 * n / 3);
	//getchar();
	int c = 0;
	while(1)
	{
		printf("iteration=%d\n", c);
		c++;
		ret = clEnqueueNDRangeKernel(command_queue, kernel1, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);
		ret = clEnqueueNDRangeKernel(command_queue, kernel2, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);
		

		ret = clEnqueueNDRangeKernel(command_queue, kernel3, 1, NULL, &global_item_size_copy, &local_item_size, 0, NULL, NULL);
		ret = clEnqueueNDRangeKernel(command_queue, kernel4, 1, NULL, &global_item_size_copy, &local_item_size, 0, NULL, NULL);
		ret = clEnqueueNDRangeKernel(command_queue, kernel5, 1, NULL, &global_item_size_copy, &local_item_size, 0, NULL, NULL);
		
		ret = clEnqueueReadBuffer(command_queue, vertices1_mem_obj, CL_TRUE, 0, (2*n/3)* sizeof(GLfloat), vertices1, 0, NULL, NULL);
		ret = clEnqueueReadBuffer(command_queue, vertices2_mem_obj, CL_TRUE, 0, (2*n/3)* sizeof(GLfloat), vertices2, 0, NULL, NULL);
		ret = clEnqueueReadBuffer(command_queue, vertices3_mem_obj, CL_TRUE, 0, (2*n/3)* sizeof(GLfloat), vertices3, 0, NULL, NULL);
		
		graphics(vertices1,vertices2,vertices3,2*n/3);
		//getchar();
		_sleep(1000/6);
	//	if (c == 54)
		//{
		//	break;
	//	}
	}


	//Clean Up
	ret = clFinish(command_queue);
	ret = clFinish(command_queue);
	ret = clReleaseKernel(kernel1);
	ret = clReleaseKernel(kernel2);
	ret = clReleaseKernel(kernel3);
	ret = clReleaseKernel(kernel4);
	ret = clReleaseKernel(kernel5);
	ret = clReleaseProgram(program1);
	ret = clReleaseProgram(program2);
	ret = clReleaseProgram(program3);
	ret = clReleaseMemObject(position_x_mem_obj);
	ret = clReleaseMemObject(position_y_mem_obj);
	ret = clReleaseMemObject(direction_x_mem_obj);
	ret = clReleaseMemObject(direction_x_mem_obj);
	ret = clReleaseMemObject(vertices1_mem_obj);
	ret = clReleaseMemObject(vertices2_mem_obj);
	ret = clReleaseMemObject(vertices3_mem_obj);
	ret = clReleaseMemObject(color_mem_obj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);
	getchar(); getchar();
	window.close();
	return 0;

}