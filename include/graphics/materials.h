//
// Created by temdisponivel on 27/02/2018.
//

#ifndef ENGINE_MATERIALS_H
#define ENGINE_MATERIALS_H

#include "core/core.h"
#include "utilities/util.h"
#include "main_gl.h"
#include "textures.h"

typedef struct vertex_attrib_names {
    char *position_name;
    char *tex_coord_name;
    char *normal_name;
    char *color_name;
} vertex_attrib_names_t;

enum UNIFORM_TYPE {
    UNIFORM_BOOLEAN,
    UNIFORM_BYTE,
    UNIFORM_UBYTE,
    UNIFORM_SHORT,
    UNIFORM_USHORT,
    UNIFORM_INT,
    UNIFORM_UINT,
    UNIFORM_LONG,
    UNIFORM_FLOAT,
    UNIFORM_DOUBLE,

    UNIFORM_VEC2,
    UNIFORM_VEC3,
    UNIFORM_VEC4,

    UNIFORM_MATRIX,

    UNIFORM_TEXTURE2D,
};

typedef union uniform_values {
    bool bool_value;
    byte byte_value;
    ubyte ubyte_value;
    short short_value;
    ushort ushort_value;
    int int_value;
    uint uint_value;
    long long_value;
    float float_value;
    double double_value;
    glm::vec2 vector2_value;
    glm::vec3 vector3_value;
    glm::vec4 vector4_value;
    glm::mat4 matrix_value;
    texture_material_propery_t texture_value;
} uniform_values_t;

typedef struct uniform_definition {
    UNIFORM_TYPE type;
    uniform_values_t default_value;
    char *name;
} uniform_definition_t;

typedef struct uniform {
    int id;
    gl_handle handle;
    UNIFORM_TYPE type;
    uniform_values_t value;
} uniform_t;

typedef struct material_definition {
    char *vertex_code;
    char *fragment_code;
    char *geometry_code;
    list<uniform_definition_t> uniforms;
    vertex_attrib_names_t vertex_attrib_names;
} material_definition_t;

typedef struct shader_program {
    gl_uhandle program;
    gl_uhandle vertex_handle;
    gl_uhandle fragment_handle;
    gl_uhandle geometry_handle;
} shader_program_t;

typedef struct material {
    shader_program_t shader;
    list<uniform_t> uniforms;
} material_t;

void setup_default_material_definition(material_definition_t *definition);

void get_default_material(material_t *material);

void create_material(material_t *material, const material_definition_t *definition);

void destroy_material(material_t material);

void gl_set_bool(material_t *material, const char *uniform_name, bool value);

void gl_set_byte(material_t *material, const char *uniform_name, byte value);

void gl_set_ubyte(material_t *material, const char *uniform_name, ubyte value);

void gl_set_short(material_t *material, const char *uniform_name, short value);

void gl_set_ushort(material_t *material, const char *uniform_name, ushort value);

void gl_set_int(material_t *material, const char *uniform_name, int value);

void gl_set_uint(material_t *material, const char *uniform_name, uint value);

void gl_set_long(material_t *material, const char *uniform_name, long value);

void gl_set_float(material_t *material, const char *uniform_name, float value);

void gl_set_double(material_t *material, const char *uniform_name, double value);

void gl_set_vec2(material_t *material, const char *uniform_name, glm::vec2 value);

void gl_set_vec3(material_t *material, const char *uniform_name, glm::vec3 value);

void gl_set_vec4(material_t *material, const char *uniform_name, glm::vec4 value);

void gl_set_matrix(material_t *material, const char *uniform_name, glm::mat4 value);

void gl_set_texture(material_t *material, const char *uniform_name, texture_t texture);

void gl_set_texture_full(material_t *material, const char *uniform_name, texture_material_propery_t texture);

bool gl_get_bool(material_t *material, const char *uniform_name);

byte gl_get_byte(material_t *material, const char *uniform_name);

ubyte gl_get_ubyte(material_t *material, const char *uniform_name);

short gl_get_short(material_t *material, const char *uniform_name);

ushort gl_get_ushort(material_t *material, const char *uniform_name);

int gl_get_int(material_t *material, const char *uniform_name);

uint gl_get_uint(material_t *material, const char *uniform_name);

long gl_get_long(material_t *material, const char *uniform_name);

float gl_get_float(material_t *material, const char *uniform_name);

double gl_get_double(material_t *material, const char *uniform_name);

glm::vec2 gl_get_vec2(material_t *material, const char *uniform_name);

glm::vec3 gl_get_vec3(material_t *material, const char *uniform_name);

glm::vec4 gl_get_vec4(material_t *material, const char *uniform_name);

glm::mat4 gl_get_matrix(material_t *material, const char *uniform_name);

texture_t gl_get_texture(material_t *material, const char *uniform_name);

texture_material_propery_t gl_get_texture_full(material_t *material, const char *uniform_name);

void use_material(material_t *material);

#endif //ENGINE_MATERIALS_H
