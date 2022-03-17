#version 410 
       
layout (location = 0) in vec3 vertex_main;
uniform mat4 matrix_main;
layout (location = 1) in vec2 color_main;
         
out vec2 finalColor;
        
void main ()
{

   gl_Position = matrix_main * vec4(vertex_main, 1);
   finalColor = color_main;
}
