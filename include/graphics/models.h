//
// Created by temdisponivel on 27/02/2018.
//

#ifndef ENGINE_MODELS_H
#define ENGINE_MODELS_H

#include <core/core.h>
#include "materials.h"

typedef struct vertex_data {
    glm::vec3 position;
    glm::vec2 tex_coord;
    glm::vec3 normal;
    glm::vec3 color;
} vertex_data_t;

// TODO: Maybe we should move the material to model_data instead of leaving on mesh_data
typedef struct model_data {
    list<vertex_data_t> vertices;
    list<uint> indices;
    char *material_name;
} model_data_t;

typedef struct model {
    list<model_data_t> childs;
} model_t;

typedef struct mesh_data {
    bool use_element_array;
    uint element_count;
    material_t material;
} mesh_data_t;

typedef struct mesh {
    gl_handle vao_handle;
    gl_handle vbo_handle;
    gl_handle vio_handle;

    list<mesh_data_t> childs;
} mesh_t;

model_t create_model_from_obj(const char *file_path);
void destroy_model(model_t model);

mesh_t create_mesh(const model_t *model);
void destroy_mesh(mesh_t mesh);

void draw_mesh(mesh_t *mesh);

#endif //ENGINE_MODELS_H
