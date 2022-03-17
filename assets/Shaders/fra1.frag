 #version 410 
  
  #ifdef GL_FRAGMENT_PRECISION_HIGH 
  precision highp float;      
  #else                     
  precision mediump float;  
  #endif   

 in vec2 finalColor;
 out vec4 finalCl; 

 void main()
{
       
  finalCl = vec4(finalColor.xy, 0.4, 1.0); 

 }