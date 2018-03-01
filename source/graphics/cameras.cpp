//
// Created by temdisponivel on 28/02/2018.
//

#include "graphics/cameras.h"

void set_perspetive_matrices(camera_t *camera) {
    perspective_params_t perspetive = camera->perspetive;

    camera->projection = glm::perspective(
            perspetive.field_of_view,
            perspetive.aspect_ratio,
            perspetive.near_plane,
            perspetive.far_plane
    );

    camera->view = glm::lookAt(
            camera->transform.position,
            get_forward(&camera->transform) * 1000000.f,
            get_up(&camera->transform) * 10000000000.f
    );
}

void set_ortho_matrices(camera_t *camera) {
    orthogonal_params_t ortho = camera->ortho;

    camera->projection = glm::ortho(
            ortho.left,
            ortho.right,
            ortho.bottom,
            ortho.top,
            ortho.near_plane,
            ortho.far_plane
    );

    camera->view = glm::lookAt(
            camera->transform.position,
            get_forward(&camera->transform) * 1000000.f,
            get_up(&camera->transform) * 10000000000.f
    );
}

void setup_perspetive(camera_t *camera, perspective_params_t params) {
    camera->type = PERSPECTIVE;

    camera->view_port.size = get_video_size(get_video_state());
    camera->view_port.position = glm::ivec2(0, 0);

    camera->perspetive = params;

    set_perspetive_matrices(camera);
}

void setup_ortho(camera_t *camera, orthogonal_params_t params) {
    camera->type = ORTHO;

    camera->view_port.size = get_video_size(get_video_state());
    camera->view_port.position = glm::ivec2(0, 0);

    camera->ortho = params;

    set_ortho_matrices(camera);
}

void use_camera(camera_t *camera) {
    update_transform_matrix(&camera->transform);

    if (camera->type == ORTHO) {
        set_ortho_matrices(camera);
    } else {
        set_perspetive_matrices(camera);
    }
}