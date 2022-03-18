#version 410
        
precision mediump float;
        
in vec2 fragColor;
        
uniform sampler2D basecolor;
   //   uniform float fAmbient;
 //     uniform sampler2D BumpLos;
        
out vec4 ColorOut;
        
 void main()
{
 
 ColorOut = texture(basecolor, fragColor.uv);
            
};