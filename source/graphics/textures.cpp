//
// Created by temdisponivel on 27/02/2018.
//

#include "graphics/textures.h"
#include "utilities/util.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

void get_texture_gl_formats(image_t *image, uint *internal_format, uint *format, uint *pixel_type) {
    switch (image->format) {
        case TEXTURE_RGB:
            *internal_format = TEXTURE_RGB;
            *format = TEXTURE_RGB;
            *pixel_type = GL_UNSIGNED_BYTE;

            break;
        case TEXTURE_RGBA:
            *internal_format = TEXTURE_RGBA;
            *format = TEXTURE_RGBA;
            *pixel_type = GL_UNSIGNED_BYTE;
            break;
        case TEXTURE_DEPTH:
            *internal_format = GL_DEPTH24_STENCIL8;
            *format = GL_DEPTH_STENCIL;
            *pixel_type = GL_UNSIGNED_INT_24_8;
            break;
    }
}


void send_texture_config_to_gl(uint handle, texture_config_t config) {
    glBindTexture(GL_TEXTURE_2D, handle);

    if (config.depth_stencil_texture_mode != DEPTH_STENCIL_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_STENCIL_TEXTURE_MODE, config.depth_stencil_texture_mode);
        CHECK_GL_ERROR();
    }

    if (config.texture_base_level > 0) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, config.texture_base_level);
        CHECK_GL_ERROR();
    }

    if (config.texture_border_color.length() > 0) {
        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(config.texture_border_color));
        CHECK_GL_ERROR();
    }

    if (config.texture_compare_func != COMPARE_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, config.texture_compare_func);
        CHECK_GL_ERROR();
    }

    if (config.texture_compare_mode != TEX_COMPARE_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, config.texture_compare_mode);
        CHECK_GL_ERROR();
    }

    if (config.texture_min_filter != TEX_MIN_FILTER_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, config.texture_min_filter);
        CHECK_GL_ERROR();
    }

    if (config.texture_mag_filter != TEX_MAG_FILTER_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, config.texture_mag_filter);
        CHECK_GL_ERROR();
    }

    if (config.texture_lod_bias > 0) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, config.texture_lod_bias);
        CHECK_GL_ERROR();
    }

    if (config.texture_min_lod > 0) {
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_LOD, config.texture_min_lod);
        CHECK_GL_ERROR();
    }

    if (config.texture_max_lod > 0) {
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_LOD, config.texture_max_lod);
        CHECK_GL_ERROR();
    }

    if (config.texture_max_level > 0) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, config.texture_max_level);
        CHECK_GL_ERROR();
    }

    if (config.texture_swizzle_r != TEX_SWIZZLE_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_R, config.texture_swizzle_r);
        CHECK_GL_ERROR();
    }

    if (config.texture_swizzle_g != TEX_SWIZZLE_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_G, config.texture_swizzle_g);
        CHECK_GL_ERROR();
    }

    if (config.texture_swizzle_b != TEX_SWIZZLE_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_B, config.texture_swizzle_b);
        CHECK_GL_ERROR();
    }

    if (config.texture_swizzle_a != TEX_SWIZZLE_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_A, config.texture_swizzle_a);
        CHECK_GL_ERROR();
    }

    if (config.texture_swizzle_rgba != TEX_SWIZZLE_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, config.texture_swizzle_rgba);
        CHECK_GL_ERROR();
    }

    if (config.texture_wrap_s != TEX_WRAP_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, config.texture_wrap_s);
        CHECK_GL_ERROR();
    }

    if (config.texture_wrap_t != TEX_WRAP_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, config.texture_wrap_t);
        CHECK_GL_ERROR();
    }

    if (config.texture_wrap_r != TEX_WRAP_DEFAULT) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, config.texture_wrap_r);
        CHECK_GL_ERROR();
    }

    glBindTexture(GL_TEXTURE_2D, HANDLE_NONE);
}

image_t create_image(const char *image_file, bool invert_y) {
    long file_length;
    ubyte *file_data = read_file_content(image_file, &file_length, false);
    return create_image_mem(file_data, file_length, invert_y);
}

image_t create_image_mem(const ubyte *image_data, long data_length, bool invert_y) {
    stbi_set_flip_vertically_on_load(invert_y);

    int channels;
    glm::ivec2 size;
    ubyte *data = stbi_load_from_memory(image_data, data_length, &size.x, &size.y, &channels, 0);

    image_t image;
    image.data = data;
    image.size = size;

    if (channels == 3)
        image.format = TEXTURE_RGB;
    else if (channels == 4)
        image.format = TEXTURE_RGBA;
    else
        image.format = UNKNOWN;

    return image;
}

void destroy_image(image_t image) {
    stbi_image_free(image.data);
}

texture_config_t get_default_tex_config() {
    texture_config_t default_config = {};

    default_config.texture_wrap_r = TEX_WRAP_CLAMP_TO_EDGE;
    default_config.texture_wrap_s = TEX_WRAP_CLAMP_TO_EDGE;
    default_config.texture_wrap_t = TEX_WRAP_CLAMP_TO_EDGE;

    default_config.texture_min_filter = TEX_MIN_FILTER_NEAREST;
    default_config.texture_mag_filter = TEX_MAG_FILTER_NEAREST;

    return default_config;
}

texture_t create_texture(image_t image, texture_config_t config) {
    uint handle;
    glGenTextures(1, &handle);
    glBindTexture(GL_TEXTURE_2D, handle);

    uint internal_format;
    uint format;
    uint pixel_format;

    get_texture_gl_formats(&image, &internal_format, &format, &pixel_format);

    glTexImage2D(
            GL_TEXTURE_2D,
            0,
            internal_format,
            image.size.x,
            image.size.y,
            0,
            format,
            pixel_format,
            image.data
    );

    glBindTexture(GL_TEXTURE_2D, HANDLE_NONE);

    send_texture_config_to_gl(handle, config);

    texture_t texture;
    texture.image = image;
    texture.handle = handle;
    texture.config = config;
    return texture;
}

texture_t create_texture_from_file(const char *file_name, bool invert_y) {
    image_t image = create_image(file_name, invert_y);
    texture_config_t config = get_default_tex_config();
    return create_texture(image, config);
}

texture_t create_texture_from_mem(const ubyte *image_data, long data_length, bool invert_y) {
    image_t image = create_image_mem(image_data, data_length, invert_y);
    texture_config_t config = get_default_tex_config();
    destroy_image(image);
    return create_texture(image, config);
}

void destroy_texture(texture_t texture) {
    ENSURE(texture.handle >= 0);

    glDeleteTextures(1, (uint *) &texture.handle);
}
