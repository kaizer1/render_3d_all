#version 410 
       
layout (location = 0) in vec2 vertexFont;
uniform mat4 matrix;
layout (location = 1) in vec2 textureCoord;
         
out vec2 finalColor;
        
void main ()
{

   gl_Position = matrix * vec4(vertexFont, 0, 1);
   finalColor = textureCoord;
}
