 #version 410 
  
  #ifdef GL_FRAGMENT_PRECISION_HIGH 
  precision highp float;      
  #else                     
  precision mediump float;  
  #endif   

 in vec2 finalColor; 
 uniform sampler2D fontSampl;
      uniform float texLevels;
  uniform float texW;
        
        out vec4 color;
        //    0.827,0.968,0.105 - yellow     
        vec3 glyph_color    = vec3(1.0,1.0,1.0);  // was 1.0,1.0,1.0
        const float glyph_center   = 0.50;   // was 0.50
        vec3 outline_color  = vec3(0.0,0.0,0.0);  // was 0.0,0.0,0.0
        const float outline_center = 0.55; // was 0.55
        vec3 glow_color     = vec3(1.0,1.0,1.0);  //was 1.0,1.0,1.0
        const float glow_center    = 0.15; // was 1.25
        
        
        vec2 remap(vec2 floatdata) {
            return floatdata * (texLevels-1.0) / texLevels * 2.0 - 1.0;
        }
        
        void main()
        {
        //    vec2 uv = finalColor.xy;
        //    vec3 colorMain = vec3(0.74, 0.301, 0.874);
        //    float t = texture(fontSampl, uv).r;
        //    color = vec4(t * colorMain.rgb, 1.0);
            
        //        vec3 texel = texture(fontSampl, finalColor.xy).rgb;
        //        vec2 distvec = remap(texel.rg);
        //         
        //        float dist = length(distvec) + (texel.b-0.5)/texW;
        //        color = vec4(vec2(mod(10.0*dist, 1.0)), texel.b, 1.0);
            
            
        //       vec3 texel = texture(fontSampl, finalColor.xy).rgb;
        //       vec2 distvec = remap(texel.rg);
        //             
        //       vec2 rainbow = 0.5+0.5*(normalize(distvec));
        //       color = vec4(rainbow, 1.0 - (length(distvec)+texel.b-0.5)*4.0, 1.0); 
        
        
        //        float D = texture(fontSampl, finalColor).r;
        //        float aastep = 0.5 * fwidth(D);
        //        float pattern = smoothstep(-aastep, aastep, D);
        //        color = vec4(vec3(pattern), 1.0);
            vec4  colorK = texture(fontSampl, finalColor);
            float dist  = colorK.r;
            float width = fwidth(dist);
            float alpha = smoothstep(glyph_center-width, glyph_center+width, dist);
              
            // Smooth
            // color = vec4(glyph_color, alpha);
            
            // Outline
            // float mu = smoothstep(outline_center-width, outline_center+width, dist);
            // vec3 rgb = mix(outline_color, glyph_color, mu);
            // color = vec4(rgb, max(alpha,mu));
            
            // Glow
             // vec3 rgb = mix(glow_color, glyph_color, alpha);
            // float mu = smoothstep(glyph_center, glow_center, sqrt(dist));
         //   color = vec4(rgb, max(alpha,mu));
            
            // Glow + outline
            
      vec3 rgb = mix(glow_color, glyph_color, alpha);
      float mu = smoothstep(glyph_center, glow_center, sqrt(dist));
     colorK = vec4(rgb, max(alpha,mu));
    float beta = smoothstep(outline_center-width, outline_center+width, dist);
    rgb = mix(outline_color, colorK.rgb, beta);
               //vec4 aUU = texture(fontSampl, finalColor); 
              //color = aUU * vec4(0.234, 0.875, 0.744, 1.0); 
             // color = vec4( aUU.rgb, 0.9); 
                                           
    color = vec4(rgb, max(colorK.a,beta));
 

 }