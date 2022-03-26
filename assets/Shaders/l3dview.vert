#version 410

layout (location = 0)in vec3 vertex3d;
layout (location = 1)in vec2 fragment3d;

uniform mat4 matrix3d_mv;
uniform mat4 matrix3d_p;
uniform vec3 vLight;
uniform vec3 vCam;
        
out vec2 fragCol;
        
void main()
 {
            
            gl_Position = matrix3d_p * matrix3d_mv * vec4(vertex3d, 1.0);
            fragCol = fragment3d;
       //     normalPout = normalPos;
        
            
};