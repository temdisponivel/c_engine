//
// Created by temdisponivel on 28/02/2018.
//

#ifndef ENGINE_TRANSFORM_H
#define ENGINE_TRANSFORM_H

#include "core.h"

typedef struct transform {
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;

    glm::mat4 _matrix;
} transform_t;

glm::vec3 world_forward();

glm::vec3 world_backwards();

glm::vec3 world_up();

glm::vec3 world_down();

glm::vec3 world_right();

glm::vec3 world_left();

transform_t *create_transform();

void destroy_transform(transform_t *transform);

void update_transform_matrix(transform_t *transform);

glm::vec3 get_forward(transform_t *transform);
glm::vec3 get_backwards(transform_t *transform);

void set_forward(transform_t *transform, glm::vec3 forward);
void set_backwards(transform_t *transform, glm::vec3 backwards);

glm::vec3 get_up(transform_t *transform);
glm::vec3 get_down(transform_t *transform);

void set_up(transform_t *transform, glm::vec3 up);
void set_down(transform_t *transform, glm::vec3 down);

glm::vec3 get_right(transform_t *transform);
glm::vec3 get_left(transform_t *transform);

void set_right(transform_t *transform, glm::vec3 right);
void set_left(transform_t *transform, glm::vec3 left);

void look_at(transform_t *transform, glm::vec3 dir);

#endif //ENGINE_TRANSFORMS_H
