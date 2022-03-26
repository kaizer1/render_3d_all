#version 410
        
precision mediump float;
        
in vec2 fragCol;
        
uniform sampler2D basecolor;
   //   uniform float fAmbient;
 //     uniform sampler2D BumpLos;
        
out vec4 ColorOut;
        
 void main()
{
 
 ColorOut = texture2D(basecolor, fragCol);
            
};