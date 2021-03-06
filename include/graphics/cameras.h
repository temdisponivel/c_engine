//
// Created by temdisponivel on 28/02/2018.
//

#ifndef ENGINE_CAMERAS_H
#define ENGINE_CAMERAS_H

#include "core/video.h"
#include "core/transform.h"
#include "core/time.h"

#define ZOOM_VELOCITY 100
#define CAM_DRAG_VELOCITY 8.f
#define CAM_MOVEMENT_VELOCITY 50.f
#define CAM_ROTATION_VELOCITY 60.f

enum CAMERA_TYPE {
    ORTHO,
    PERSPECTIVE
};

typedef struct perspective_params {
    float field_of_view;
    float aspect_ratio;
    float near_plane;
    float far_plane;
} perspective_params_t;

typedef struct orthogonal_params {
    float left;
    float right;
    float bottom;
    float top;
    float near_plane;
    float far_plane;
} orthogonal_params_t;

typedef struct camera {
    transform_t transform;
    CAMERA_TYPE type;

    view_port_t view_port;

    glm::mat4 projection;
    glm::mat4 view;

    union {
        orthogonal_params_t ortho;
        perspective_params_t perspetive;
    };
} camera_t;

typedef struct orbital_camera {
    camera_t camera;
    glm::vec2 acumulated_rotation;
} orbital_camera_t;

void setup_perspetive(camera_t *camera, perspective_params_t params);
void setup_ortho(camera_t *camera, orthogonal_params_t params);

void use_camera(camera_t *camera);

void update_orbital_camera(orbital_camera_t *camera);

#endif //ENGINE_CAMERAS_H
