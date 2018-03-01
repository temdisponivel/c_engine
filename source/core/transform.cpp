//
// Created by temdisponivel on 28/02/2018.
//


// TODO: INLINE ALL THESE FUNCTIONS AND OPTIMIZE TO NOT!! USE MATRIX~QUAT CONVERSION!! ALSO TEST
// TODO: INLINE ALL THESE FUNCTIONS AND OPTIMIZE TO NOT!! USE MATRIX~QUAT CONVERSION!! ALSO TEST
// TODO: INLINE ALL THESE FUNCTIONS AND OPTIMIZE TO NOT!! USE MATRIX~QUAT CONVERSION!! ALSO TEST
// TODO: INLINE ALL THESE FUNCTIONS AND OPTIMIZE TO NOT!! USE MATRIX~QUAT CONVERSION!! ALSO TEST

#include "core/transform.h"

glm::vec3 world_forward() {
    return glm::vec3(0, 0, -1);
}

glm::vec3 world_backwards() {
    return -world_forward();
}

glm::vec3 world_up() {
    return glm::vec3(0, 1, 0);
}

glm::vec3 world_down() {
    return -world_up();
}

glm::vec3 world_right() {
    return glm::vec3(1, 0, 0);
}

glm::vec3 world_left() {
    return -world_right();
}

transform_t *create_transform() {
    transform_t *transform = (transform_t *) memalloc(sizeof(transform_t));
    transform->position = glm::vec3();
    transform->rotation = glm::quat();
    transform->scale = glm::vec3(1, 1, 1);
    transform->_matrix = glm::mat4();
    set_forward(transform, world_forward());
    set_up(transform, world_up());

    return transform;
}
void destroy_transform(transform_t *transform) {
    memfree(transform);
}

void update_transform_matrix(transform_t *transform) {
    transform->_matrix = glm::mat4();
    transform->_matrix = glm::translate(transform->_matrix, transform->position);
    transform->_matrix = transform->_matrix * glm::mat4_cast(transform->rotation);
    transform->_matrix = glm::scale(transform->_matrix, transform->scale);
}

glm::vec3 get_forward(transform_t *transform) {
    return glm::normalize(transform->rotation * world_forward());
}

glm::vec3 get_backwards(transform_t *transform) {
    return -get_forward(transform);
}

void set_forward(transform_t *transform, glm::vec3 forward) {
    glm::vec3 pos = transform->position + (forward * 10000000.f);
    transform->rotation = glm::quat_cast(glm::lookAt(transform->position, pos, world_up()));
}

void set_backwards(transform_t *transform, glm::vec3 backwards) {
    set_forward(transform, -backwards);
}

glm::vec3 get_up(transform_t *transform) {
    return glm::normalize(transform->rotation * world_up());
}

glm::vec3 get_down(transform_t *transform) {
    return -get_up(transform);
}

void set_up(transform_t *transform, glm::vec3 up) {
    glm::vec3 forward = glm::cross(up, world_right());
    set_forward(transform, forward);
}

void set_down(transform_t *transform, glm::vec3 down) {
    set_up(transform, -down);
}

glm::vec3 get_right(transform_t *transform) {
    return glm::normalize(transform->rotation * world_right());
}

glm::vec3 get_left(transform_t *transform) {
    return -get_right(transform);
}

void set_right(transform_t *transform, glm::vec3 right) {
    glm::vec3 forward = glm::cross(right, world_up());
    set_forward(transform, forward);
}
void set_left(transform_t *transform, glm::vec3 left) {
    set_right(transform, -left);
}

void look_at(transform_t *transform, glm::vec3 dir) {
    dir = glm::normalize(dir);
    set_forward(transform, dir);
}