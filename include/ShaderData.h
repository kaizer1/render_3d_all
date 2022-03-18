// Loskutnikov Games inc. 2022 
#pragma once


const char vertexShader [] =
        "#version 410 \n"
        "layout (location = 0) in vec2 vertexFont;\n"
        "uniform mat4 matrix;\n"
        "layout (location = 1) in vec2 textureCoord;\n"
        " \n"
        "out vec2 finalColor;\n"
        "\n"
        "void main ()\n"
        "{\n"
        "    gl_Position = matrix * vec4(vertexFont, 0, 1);\n"
        "    finalColor = textureCoord;\n"
        "}";

const char fragmentShader [] =
        "#version 410 \n"
        "#ifdef GL_FRAGMENT_PRECISION_HIGH   \n"
        "precision highp float;      \n"
        "#else                     \n"
        "precision mediump float;   \n"
        "#endif      \n"
        "in vec2 finalColor;\n"
        "uniform sampler2D fontSampl;\n"
        "uniform float texLevels;\n"
        "uniform float texW;\n"
        "\n"
        "out vec4 color;\n"
        "//    0.827,0.968,0.105 - yellow     \n"
        "vec3 glyph_color    = vec3(1.0,1.0,1.0);  // was 1.0,1.0,1.0\n"
        "const float glyph_center   = 0.50;   // was 0.50\n"
        "vec3 outline_color  = vec3(0.0,0.0,0.0);  // was 0.0,0.0,0.0\n"
        "const float outline_center = 0.55; // was 0.55\n"
        "vec3 glow_color     = vec3(1.0,1.0,1.0);  //was 1.0,1.0,1.0\n"
        "const float glow_center    = 0.15; // was 1.25\n"
        "\n"
        "\n"
        "vec2 remap(vec2 floatdata) {\n"
        "    return floatdata * (texLevels-1.0) / texLevels * 2.0 - 1.0;\n"
        "}\n"
        "\n"
        "void main()\n"
        "{\n"
        "//    vec2 uv = finalColor.xy;\n"
        "//    vec3 colorMain = vec3(0.74, 0.301, 0.874);\n"
        "//    float t = texture(fontSampl, uv).r;\n"
        "//    color = vec4(t * colorMain.rgb, 1.0);\n"
        "    \n"
        "//        vec3 texel = texture(fontSampl, finalColor.xy).rgb;\n"
        "//        vec2 distvec = remap(texel.rg);\n"
        "//         \n"
        "//        float dist = length(distvec) + (texel.b-0.5)/texW;\n"
        "//        color = vec4(vec2(mod(10.0*dist, 1.0)), texel.b, 1.0);\n"
        "    \n"
        "    \n"
        "//       vec3 texel = texture(fontSampl, finalColor.xy).rgb;\n"
        "//       vec2 distvec = remap(texel.rg);\n"
        "//             \n"
        "//       vec2 rainbow = 0.5+0.5*(normalize(distvec));\n"
        "//       color = vec4(rainbow, 1.0 - (length(distvec)+texel.b-0.5)*4.0, 1.0); \n"
        "\n"
        "\n"
        "//        float D = texture(fontSampl, finalColor).r;\n"
        "//        float aastep = 0.5 * fwidth(D);\n"
        "//        float pattern = smoothstep(-aastep, aastep, D);\n"
        "//        color = vec4(vec3(pattern), 1.0);\n"
        "    vec4  colorK = texture(fontSampl, finalColor);\n"
        "    float dist  = colorK.r;\n"
        "    float width = fwidth(dist);\n"
        "    float alpha = smoothstep(glyph_center-width, glyph_center+width, dist);\n"
        "      \n"
        "    // Smooth\n"
        "    // color = vec4(glyph_color, alpha);\n"
        "    \n"
        "    // Outline\n"
        "    // float mu = smoothstep(outline_center-width, outline_center+width, dist);\n"
        "    // vec3 rgb = mix(outline_color, glyph_color, mu);\n"
        "    // color = vec4(rgb, max(alpha,mu));\n"
        "    \n"
        "    // Glow\n"
        "     // vec3 rgb = mix(glow_color, glyph_color, alpha);\n"
        "    // float mu = smoothstep(glyph_center, glow_center, sqrt(dist));\n"
        " //   color = vec4(rgb, max(alpha,mu));\n"
        "    \n"
        "    // Glow + outline\n"
        "    \n"
        "      vec3 rgb = mix(glow_color, glyph_color, alpha);\n"
        "      float mu = smoothstep(glyph_center, glow_center, sqrt(dist));\n"
        "      colorK = vec4(rgb, max(alpha,mu));\n"
        "      float beta = smoothstep(outline_center-width, outline_center+width, dist);\n"
        "      rgb = mix(outline_color, colorK.rgb, beta);\n"
        "       //vec4 aUU = texture(fontSampl, finalColor); \n"
        "      //color = aUU * vec4(0.234, 0.875, 0.744, 1.0); \n"
        "     // color = vec4( aUU.rgb, 0.9); \n"
        "                                   \n"
        "      color = vec4(rgb, max(colorK.a,beta));\n"
        "     \n"
        "      \n"
        "}";




         // gl version = 
         // GL_AMD_multi_draw_indirect 
         // GL_AMD_seamless_cubemap_per_texture 
         // GL_AMD_vertex_shader_viewport_index 
         // GL_AMD_vertex_shader_layer
         // GL_ARB_arrays_of_arrays 
         // GL_ARB_base_instance 
         // GL_ARB_bindless_texture 
         // GL_ARB_blend_func_extended 
         // GL_ARB_buffer_storage 
         // GL_ARB_clear_buffer_object 
         // GL_ARB_clear_texture 
         // GL_ARB_clip_control 
         // GL_ARB_color_buffer_float 
         // GL_ARB_compatibility 
         // GL_ARB_compressed_texture_pixel_storage 
         // GL_ARB_conservative_depth 
         // GL_ARB_compute_shader 
         // GL_ARB_compute_variable_group_size 
         // GL_ARB_conditional_render_inverted 
         // GL_ARB_copy_buffer 
         // GL_ARB_copy_image 
         // GL_ARB_cull_distance 
         // GL_ARB_debug_output 
         // GL_ARB_depth_buffer_float 
         // GL_ARB_depth_clamp 
         // GL_ARB_depth_texture 
         // GL_ARB_derivative_control 
         // GL_ARB_direct_state_access 
         // GL_ARB_draw_buffers 
         // GL_ARB_draw_buffers_blend 
         // GL_ARB_draw_indirect 
         // GL_ARB_draw_elements_base_vertex 
         // GL_ARB_draw_instanced 
         // GL_ARB_enhanced_layouts 
         // GL_ARB_ES2_compatibility 
         // GL_ARB_ES3_compatibility 
         // GL_ARB_ES3_1_compatibility 
         // GL_ARB_ES3_2_compatibility 
         // GL_ARB_explicit_attrib_location 
         // GL_ARB_explicit_uniform_location 
         // GL_ARB_fragment_coord_conventions 
         // GL_ARB_fragment_layer_viewport 
         // GL_ARB_fragment_program 
         // GL_ARB_fragment_program_shadow 
         // GL_ARB_fragment_shader 
         // GL_ARB_fragment_shader_interlock 
         // GL_ARB_framebuffer_no_attachments 
         // GL_ARB_framebuffer_object 
         // GL_ARB_framebuffer_sRGB 
         // GL_ARB_geometry_shader4 
         // GL_ARB_get_program_binary 
         // GL_ARB_get_texture_sub_image 
         // GL_ARB_gl_spirv 
         // GL_ARB_gpu_shader5 
         // GL_ARB_gpu_shader_fp64 
         // GL_ARB_gpu_shader_int64 
         // GL_ARB_half_float_pixel 
         // GL_ARB_half_float_vertex 
         // GL_ARB_imaging 
         // GL_ARB_indirect_parameters 
         // GL_ARB_instanced_arrays 
         // GL_ARB_internalformat_query 
         // GL_ARB_internalformat_query2 
         // GL_ARB_invalidate_subdata 
         // GL_ARB_map_buffer_alignment 
         // GL_ARB_map_buffer_range 
         // GL_ARB_multi_bind 
         // GL_ARB_multi_draw_indirect 
         // GL_ARB_multisample 
         // GL_ARB_multitexture 
         // GL_ARB_occlusion_query 
         // GL_ARB_occlusion_query2 
         // GL_ARB_parallel_shader_compile 
         // GL_ARB_pipeline_statistics_query 
         // GL_ARB_pixel_buffer_object 
         // GL_ARB_point_parameters 
         // GL_ARB_point_sprite 
         // GL_ARB_polygon_offset_clamp 
         // GL_ARB_post_depth_coverage 
         // GL_ARB_program_interface_query 
         // GL_ARB_provoking_vertex 
         // GL_ARB_query_buffer_object 
         // GL_ARB_robust_buffer_access_behavior 
         // GL_ARB_robustness 
         // GL_ARB_sample_locations 
         // GL_ARB_sample_shading 
         // GL_ARB_sampler_objects 
         // GL_ARB_seamless_cube_map 
         // GL_ARB_seamless_cubemap_per_texture 
         // GL_ARB_separate_shader_objects 
         // GL_ARB_shader_atomic_counter_ops 
         // GL_ARB_shader_atomic_counters 
         // GL_ARB_shader_ballot 
         // GL_ARB_shader_bit_encoding 
         // GL_ARB_shader_clock 
         // GL_ARB_shader_draw_parameters 
         // GL_ARB_shader_group_vote 
         // GL_ARB_shader_image_load_store 
         // GL_ARB_shader_image_size 
         // GL_ARB_shader_objects 
         // GL_ARB_shader_precision 
         // GL_ARB_shader_storage_buffer_object 
         // GL_ARB_shader_subroutine 
         // GL_ARB_shader_texture_image_samples 
         // GL_ARB_shader_texture_lod 
         // GL_ARB_shading_language_100 
         // GL_ARB_shader_viewport_layer_array 
         // GL_ARB_shading_language_420pack 
         // GL_ARB_shading_language_include 
         // GL_ARB_shading_language_packing 
         // GL_ARB_shadow 
         // GL_ARB_sparse_buffer 
         // GL_ARB_sparse_texture 
         // GL_ARB_sparse_texture2 
         // GL_ARB_sparse_texture_clamp 
         // GL_ARB_spirv_extensions 
         // GL_ARB_stencil_texturing 
         // GL_ARB_sync 
         // GL_ARB_tessellation_shader 
         // GL_ARB_texture_barrier 
         // GL_ARB_texture_border_clamp 
         // GL_ARB_texture_buffer_object 
         // GL_ARB_texture_buffer_object_rgb32 
         // GL_ARB_texture_buffer_range 
         // GL_ARB_texture_compression 
         // GL_ARB_texture_compression_bptc 
         // GL_ARB_texture_compression_rgtc 
         // GL_ARB_texture_cube_map 
         // GL_ARB_texture_cube_map_array 
         // GL_ARB_texture_env_add 
         // GL_ARB_texture_env_combine 
         // GL_ARB_texture_env_crossbar 
         // GL_ARB_texture_env_dot3 
         // GL_ARB_texture_filter_anisotropic 
         // GL_ARB_texture_filter_minmax 
         // GL_ARB_texture_float 
         // GL_ARB_texture_gather 
         // GL_ARB_texture_mirror_clamp_to_edge 
         // GL_ARB_texture_mirrored_repeat 
         // GL_ARB_texture_multisample 
         // GL_ARB_texture_non_power_of_two 
         // GL_ARB_texture_query_levels 
         // GL_ARB_texture_query_lod 
         // GL_ARB_texture_rectangle 
         // GL_ARB_texture_rg 
         // GL_ARB_texture_rgb10_a2ui 
         // GL_ARB_texture_stencil8 
         // GL_ARB_texture_storage 
         // GL_ARB_texture_storage_multisample 
         // GL_ARB_texture_swizzle 
         // GL_ARB_texture_view 
         // GL_ARB_timer_query 
         // GL_ARB_transform_feedback2 
         // GL_ARB_transform_feedback3 
         // GL_ARB_transform_feedback_instanced 
         // GL_ARB_transform_feedback_overflow_query 
         // GL_ARB_transpose_matrix 
         // GL_ARB_uniform_buffer_object 
         // GL_ARB_vertex_array_bgra 
         // GL_ARB_vertex_array_object 
         // GL_ARB_vertex_attrib_64bit 
         // GL_ARB_vertex_attrib_binding 
         // GL_ARB_vertex_buffer_object 
         // GL_ARB_vertex_program 
         // GL_ARB_vertex_shader 
         // GL_ARB_vertex_type_10f_11f_11f_rev 
         // GL_ARB_vertex_type_2_10_10_10_rev 
         // GL_ARB_viewport_array 
         // GL_ARB_window_pos 
         // GL_ATI_draw_buffers 
         // GL_ATI_texture_float 
         // GL_ATI_texture_mirror_once 
         // GL_S3_s3tc 
         // GL_EXT_texture_env_add 
         // GL_EXT_abgr 
         // GL_EXT_bgra 
         // GL_EXT_bindable_uniform 
         // GL_EXT_blend_color 
         // GL_EXT_blend_equation_separate 
         // GL_EXT_blend_func_separate 
         // GL_EXT_blend_minmax 
         // GL_EXT_blend_subtract 
         // GL_EXT_compiled_vertex_array 
         // GL_EXT_Cg_shader 
         // GL_EXT_depth_bounds_test 
         // GL_EXT_direct_state_access 
         // GL_EXT_draw_buffers2 
         // GL_EXT_draw_instanced 
         // GL_EXT_draw_range_elements 
         // GL_EXT_fog_coord GL_EXT_framebuffer_blit GL_EXT_framebuffer_multisample 
         // GL_EXTX_framebuffer_mixed_formats 
         // GL_EXT_framebuffer_multisample_blit_scaled 
         // GL_EXT_framebuffer_object 
         // GL_EXT_framebuffer_sRGB 
         // GL_EXT_geometry_shader4 
         // GL_EXT_gpu_program_parameters 
         // GL_EXT_gpu_shader4 
         // GL_EXT_multi_draw_arrays 
         // GL_EXT_multiview_texture_multisample 
         // GL_EXT_multiview_timer_query 
         // GL_EXT_packed_depth_stencil 
         // GL_EXT_packed_float 
         // GL_EXT_packed_pixels 
         // GL_EXT_pixel_buffer_object 
         // GL_EXT_point_parameters 
         // GL_EXT_polygon_offset_clamp 
         // GL_EXT_post_depth_coverage 
         // GL_EXT_provoking_vertex 
         // GL_EXT_raster_multisample 
         // GL_EXT_rescale_normal 
         // GL_EXT_secondary_color 
         // GL_EXT_separate_shader_objects 
         // GL_EXT_separate_specular_color 
         // GL_EXT_shader_image_load_formatted 
         // GL_EXT_shader_image_load_store 
         // GL_EXT_shader_integer_mix 
         // GL_EXT_shadow_funcs 
         // GL_EXT_sparse_texture2 
         // GL_EXT_stencil_two_side 
         // GL_EXT_stencil_wrap 
         // GL_EXT_texture3D 
         // GL_EXT_texture_array 
         // GL_EXT_texture_buffer_object 
         // GL_EXT_texture_compression_dxt1 
         // GL_EXT_texture_compression_latc 
         // GL_EXT_texture_compression_rgtc 
         // GL_EXT_texture_compression_s3tc 
         // GL_EXT_texture_cube_map 
         // GL_EXT_texture_edge_clamp 
         // GL_EXT_texture_env_combine 
         // GL_EXT_texture_env_dot3 
         // GL_EXT_texture_filter_anisotropic 
         // GL_EXT_texture_filter_minmax 
         // GL_EXT_texture_integer 
         // GL_EXT_texture_lod 
         // GL_EXT_texture_lod_bias 
         // GL_EXT_texture_mirror_clamp 
         // GL_EXT_texture_object 
         // GL_EXT_texture_shadow_lod 
         // GL_EXT_texture_shared_exponent 
         // GL_EXT_texture_sRGB 
         // GL_EXT_texture_sRGB_R8 
         // GL_EXT_texture_sRGB_decode 
         // GL_EXT_texture_storage 
         // GL_EXT_texture_swizzle 
         // GL_EXT_timer_query 
         // GL_EXT_transform_feedback2 
         // GL_EXT_vertex_array 
         // GL_EXT_vertex_array_bgra 
         // GL_EXT_vertex_attrib_64bit 
         // GL_EXT_window_rectangles 
         // GL_EXT_import_sync_object 
         // GL_IBM_rasterpos_clip 
         // GL_IBM_texture_mirrored_repeat 
         // GL_KHR_context_flush_control 
         // GL_KHR_debug 
         // GL_EXT_memory_object 
         // GL_EXT_memory_object_win32 
         // GL_NV_memory_object_sparse 
         // GL_EXT_win32_keyed_mutex 
         // GL_KHR_parallel_shader_compile 
         // GL_KHR_no_error 
         // GL_KHR_robust_buffer_access_behavior 
         // GL_KHR_robustness 
         // GL_EXT_semaphore 
         // GL_EXT_semaphore_win32 
         // GL_NV_timeline_semaphore 
         // GL_KHR_shader_subgroup 
         // GL_KTX_buffer_region 
         // GL_NV_alpha_to_coverage_dither_control 
         // GL_NV_bindless_multi_draw_indirect 
         // GL_NV_bindless_multi_draw_indirect_count 
         // GL_NV_bindless_texture 
         // GL_NV_blend_equation_advanced 
         // GL_NV_blend_equation_advanced_coherent 
         // GL_NVX_blend_equation_advanced_multi_draw_buffers 
         // GL_NV_blend_minmax_factor 
         // GL_NV_blend_square 
         // GL_NV_clip_space_w_scaling 
         // GL_NV_command_list 
         // GL_NV_compute_program5 
         // GL_NV_compute_shader_derivatives 
         // GL_NV_conditional_render 
         // GL_NV_conservative_raster 
         // GL_NV_conservative_raster_dilate 
         // GL_NV_conservative_raster_pre_snap 
         // GL_NV_conservative_raster_pre_snap_triangles 
         // GL_NV_conservative_raster_underestimation 
         // GL_NV_copy_depth_to_color 
         // GL_NV_copy_image 
         // GL_NV_depth_buffer_float 
         // GL_NV_depth_clamp 
         // GL_NV_draw_texture 
         // GL_NV_draw_vulkan_image 
         // GL_NV_ES1_1_compatibility 
         // GL_NV_ES3_1_compatibility 
         // GL_NV_explicit_multisample 
         // GL_NV_feature_query 
         // GL_NV_fence 
         // GL_NV_fill_rectangle 
         // GL_NV_float_buffer 
         // GL_NV_fog_distance 
         // GL_NV_fragment_coverage_to_color 
         // GL_NV_fragment_program 
         // GL_NV_fragment_program_option 
         // GL_NV_fragment_program2 
         // GL_NV_fragment_shader_barycentric 
         // GL_NV_fragment_shader_interlock 
         // GL_NV_framebuffer_mixed_samples 
         // GL_NV_framebuffer_multisample_coverage 
         // GL_NV_geometry_shader4 
         // GL_NV_geometry_shader_passthrough 
         // GL_NV_gpu_program4 
         // GL_NV_internalformat_sample_query 
         // GL_NV_gpu_program4_1 
         // GL_NV_gpu_program5 
         // GL_NV_gpu_program5_mem_extended 
         // GL_NV_gpu_program_fp64 
         // GL_NV_gpu_shader5 
         // GL_NV_half_float 
         // GL_NV_light_max_exponent 
         // GL_NV_memory_attachment 
         // GL_NV_mesh_shader 
         // GL_NV_multisample_coverage 
         // GL_NV_multisample_filter_hint 
         // GL_NV_occlusion_query 
         // GL_NV_packed_depth_stencil 
         // GL_NV_parameter_buffer_object 
         // GL_NV_parameter_buffer_object2 
         // GL_NV_path_rendering 
         // GL_NV_path_rendering_shared_edge 
         // GL_NV_pixel_data_range 
         // GL_NV_point_sprite 
         // GL_NV_primitive_restart 
         // GL_NV_query_resource 
         // GL_NV_query_resource_tag 
         // GL_NV_register_combiners 
         // GL_NV_register_combiners2 
         // GL_NV_representative_fragment_test 
         // GL_NV_sample_locations 
         // GL_NV_sample_mask_override_coverage 
         // GL_NV_scissor_exclusive 
         // GL_NV_shader_atomic_counters 
         // GL_NV_shader_atomic_float 
         // GL_NV_shader_atomic_float64 
         // GL_NV_shader_atomic_fp16_vector 
         // GL_NV_shader_atomic_int64 
         // GL_NV_shader_buffer_load 
         // GL_NV_shader_storage_buffer_object 
         // GL_NV_shader_subgroup_partitioned 
         // GL_NV_shader_texture_footprint 
         // GL_NV_shading_rate_image 
         // GL_NV_stereo_view_rendering 
         // GL_NV_texgen_reflection 
         // GL_NV_texture_barrier 
         // GL_NV_texture_compression_vtc 
         // GL_NV_texture_env_combine4 
         // GL_NV_texture_multisample 
         // GL_NV_texture_rectangle 
         // GL_NV_texture_rectangle_compressed 
         // GL_NV_texture_shader 
         // GL_NV_texture_shader2 
         // GL_NV_texture_shader3 
         // GL_NV_transform_feedback 
         // GL_NV_transform_feedback2 
         // GL_NV_uniform_buffer_unified_memory 
         // GL_NV_vertex_array_range 
         // GL_NV_vertex_array_range2 
         // GL_NV_vertex_attrib_integer_64bit 
         // GL_NV_vertex_buffer_unified_memory 
         // GL_NV_vertex_program 
         // GL_NV_vertex_program1_1 
         // GL_NV_vertex_program2 
         // GL_NV_vertex_program2_option 
         // GL_NV_vertex_program3 
         // GL_NV_viewport_array2 
         // GL_NV_viewport_swizzle 
         // GL_NVX_conditional_render 
         // GL_NVX_linked_gpu_multicast 
         // GL_NV_gpu_multicast 
         // GL_NVX_gpu_multicast2 
         // GL_NVX_progress_fence 
         // GL_NVX_gpu_memory_info 
         // GL_NVX_multigpu_info 
         // GL_NVX_nvenc_interop 
         // GL_NV_shader_thread_group 
         // GL_NV_shader_thread_shuffle 
         // GL_KHR_blend_equation_advanced 
         // GL_KHR_blend_equation_advanced_coherent 
         // GL_OVR_multiview 
         // GL_OVR_multiview2 
         // GL_SGIS_generate_mipmap 
         // GL_SGIS_texture_lod 
         // GL_SGIX_depth_texture 
         // GL_SGIX_shadow 
         // GL_SUN_slice_accum 
         // GL_WIN_swap_hint 
         // WGL_EXT_swap_control