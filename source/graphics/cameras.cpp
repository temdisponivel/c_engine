//
// Created by temdisponivel on 28/02/2018.
//

#include <core/input.h>
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

    camera->view_port.size = get_video_size();
    camera->view_port.position = glm::ivec2(0, 0);

    camera->perspetive = params;

    set_perspetive_matrices(camera);
}

void setup_ortho(camera_t *camera, orthogonal_params_t params) {
    camera->type = ORTHO;

    camera->view_port.size = get_video_size();
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

void update_orbital_camera(orbital_camera_t *camera) {
    //TODO: CLEANUP

    float lerp_dt = fmax((get_dt() * 30.f), 1.f);
    transform_t *trans = &camera->camera.transform;

    if (is_key_down(KEY_LEFT_CONTROL)) {
        if (is_key_pressed(KEY_KP_2) || is_key_pressed(KEY_2)) {
            look_at(trans, world_backwards());
        } else if (is_key_pressed(KEY_KP_4) || is_key_pressed(KEY_4)) {
            look_at(trans, world_left());
        } else if (is_key_pressed(KEY_KP_8) || is_key_pressed(KEY_8)) {
            look_at(trans, world_forward());
        } else if (is_key_pressed(KEY_KP_6) || is_key_pressed(KEY_6)) {
            look_at(trans, world_right());
        } else if (is_key_pressed(KEY_KP_5) || is_key_pressed(KEY_5)) {
            look_at(trans, world_down());
        } else if (is_key_pressed(KEY_SLASH) || is_key_pressed(KEY_KP_DIVIDE)) {
            look_at(trans, world_up());
        }
    }

    glm::vec2 mouse_pos = get_mouse_screen_pos();
    glm::vec2 mouse_delta = get_mouse_delta_screen_pos();

    glm::vec3 cam_forward = get_forward(trans);
    glm::vec3 cam_right = get_right(trans);
    trans->position += cam_forward * get_mouse_delta_scroll().y * (get_dt() * ZOOM_VELOCITY);

    if (is_mouse_button_down(MOUSE_BUTTON_RIGHT)) {
        if (fabsf(mouse_delta.x) > .1f || fabsf(mouse_delta.y) > .1f) {
            glm::vec2 rotation = camera->acumulated_rotation - (mouse_delta * get_dt() * .3f);

            glm::quat current_rot = trans->rotation;

            glm::vec3 rot_dir = glm::vec3(rotation.y, rotation.x, 0);
            //rot_dir = glm::normalize(rot_dir);

            // TODO: smoth this
            trans->rotation = glm::quat(rot_dir);

            camera->acumulated_rotation = rotation;
        }

        glm::vec3 current_pos = trans->position;
        glm::vec3 desired_pos = current_pos;
        if (is_key_down(KEY_W)) {
            desired_pos += (cam_forward * CAM_MOVEMENT_VELOCITY * get_dt());
        }

        if (is_key_down(KEY_S)) {
            desired_pos -= (cam_forward * CAM_MOVEMENT_VELOCITY * get_dt());
        }

        if (is_key_down(KEY_D)) {
            desired_pos += (cam_right * CAM_MOVEMENT_VELOCITY * get_dt());
        }

        if (is_key_down(KEY_A)) {
            desired_pos -= (cam_right * CAM_MOVEMENT_VELOCITY * get_dt());
        }

        trans->position = glm::mix(current_pos, desired_pos, lerp_dt);
    }

    if (is_mouse_button_down(MOUSE_BUTTON_MIDDLE)) {
        glm::vec2 mouse_movement = glm::vec3(mouse_delta.x, mouse_delta.y, 0) * CAM_DRAG_VELOCITY * get_dt();

        if (fabsf(mouse_movement.x) > .001f || fabsf(mouse_movement.y) > .001f) {
            glm::vec3 right = -get_right(trans) * mouse_movement.x;
            glm::vec3 up = get_up(trans) * mouse_movement.y;

            glm::vec3 movement = right + up;

            glm::vec3 current_pos = trans->position;
            glm::vec3 desired_pos = current_pos + movement;

            trans->position = glm::mix(current_pos, desired_pos, lerp_dt);
        }
    }
}