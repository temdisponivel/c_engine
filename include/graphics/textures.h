//
// Created by temdisponivel on 27/02/2018.
//

#ifndef ENGINE_TEXTURES_H
#define ENGINE_TEXTURES_H

#include "core/core.h"
#include "main_gl.h"

enum TEXTURE_FORMAT {
    UNKNOWN = 0,
    TEXTURE_RGB = GL_RGB,
    TEXTURE_RGBA = GL_RGBA,
    TEXTURE_DEPTH = GL_DEPTH24_STENCIL8,
};

typedef struct image {
    TEXTURE_FORMAT format;
    glm::ivec2 size;
    void *data;
} image_t;

enum TEXTURE_INDEX {
    ZERO = GL_TEXTURE0,
    ONE = GL_TEXTURE1,
    TWO = GL_TEXTURE2,
    THREE = GL_TEXTURE3,
    FOUR = GL_TEXTURE4,
    FIVE = GL_TEXTURE5,
    SIX = GL_TEXTURE6,
    SEVEN = GL_TEXTURE7,
    EIGHT = GL_TEXTURE8,
    NINE = GL_TEXTURE9,
    TEN = GL_TEXTURE10,
};

enum TEXTURE_DEPTH_STENCIAL_VALUES {
    DEPTH_STENCIL_DEFAULT,
    DEPTH_STENCIL_DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
    DEPTH_STENCIL_STENCIL_COMPONENT = GL_STENCIL_COMPONENTS,
};

enum TEXTURE_COMPARE_MODE {
    TEX_COMPARE_DEFAULT,
    TEX_COMPARE_COMPARE_REF_TO_TEXTURE = GL_COMPARE_REF_TO_TEXTURE,
    TEX_COMPARE_NONE = GL_NONE
};

enum TEXTURE_MIN_FILTER_VALUES {
    TEX_MIN_FILTER_DEFAULT,
    TEX_MIN_FILTER_NEAREST = GL_NEAREST,
    TEX_MIN_FILTER_LINEAR = GL_LINEAR,
    TEX_MIN_FILTER_NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,
    TEX_MIN_FILTER_LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST,
    TEX_MIN_FILTER_NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR,
    TEX_MIN_FILTER_LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR,
};

enum TEXTURE_MAG_FILTER_VALUES {
    TEX_MAG_FILTER_DEFAULT,
    TEX_MAG_FILTER_NEAREST = GL_NEAREST,
    TEX_MAG_FILTER_LINEAR = GL_LINEAR,
};

enum TEXTURE_SWIZZLE_VALUES {
    TEX_SWIZZLE_DEFAULT,
    TEX_SWIZZLE_RED = GL_RED,
    TEX_SWIZZLE_GREEN = GL_GREEN,
    TEX_SWIZZLE_BLUE = GL_BLUE,
    TEX_SWIZZLE_ALPHA = GL_ALPHA,
    TEX_SWIZZLE_ZERO = GL_ZERO,
    TEX_SWIZZLE_ONE = GL_ONE
};

enum TEXTURE_WRAP_VALUES {
    TEX_WRAP_DEFAULT,
    TEX_WRAP_CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
    TEX_WRAP_CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER,
    TEX_WRAP_MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
    TEX_WRAP_REPEAT = GL_REPEAT,
    TEX_WRAP_MIRROR_CLAMP_TO_EDGE = GL_MIRROR_CLAMP_TO_EDGE,
};

typedef struct texture_config {
    TEXTURE_DEPTH_STENCIAL_VALUES depth_stencil_texture_mode;
    uint texture_base_level;
    glm::vec4 texture_border_color;
    COMPARE_FUNCTIONS texture_compare_func;
    TEXTURE_COMPARE_MODE texture_compare_mode;
    int texture_lod_bias;
    TEXTURE_MIN_FILTER_VALUES texture_min_filter;
    TEXTURE_MAG_FILTER_VALUES texture_mag_filter;
    float texture_min_lod;
    float texture_max_lod;
    int texture_max_level;
    TEXTURE_SWIZZLE_VALUES texture_swizzle_r;
    TEXTURE_SWIZZLE_VALUES texture_swizzle_g;
    TEXTURE_SWIZZLE_VALUES texture_swizzle_b;
    TEXTURE_SWIZZLE_VALUES texture_swizzle_a;
    TEXTURE_SWIZZLE_VALUES texture_swizzle_rgba;
    TEXTURE_WRAP_VALUES texture_wrap_s;
    TEXTURE_WRAP_VALUES texture_wrap_t;
    TEXTURE_WRAP_VALUES texture_wrap_r;
} texture_config_t;

typedef struct texture {
    gl_handle handle;
    texture_config_t config;
    image_t image;
} texture_t;

typedef struct texture_material_property {
    texture_t texture;
    TEXTURE_INDEX index;
} texture_material_propery_t;

image_t create_image(const char *image_file, bool invert_y);

image_t create_image_mem(const ubyte *image_data, long data_length, bool invert_y);

void destroy_image(image_t image);

texture_config_t get_default_tex_config();

texture_t create_texture(image_t image, texture_config_t config);

texture_t create_texture_from_file(const char *file_name, bool invert_y);

texture_t create_texture_from_mem(const ubyte *image_data, long data_length, bool invert_y);

void destroy_texture(texture_t texture);

#endif //ENGINE_TEXTURES_H
