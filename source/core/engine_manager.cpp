//
// Created by temdisponivel on 02/03/2018.
//

#include "core/engine_manager.h"

static engine_state_t engine_state = {};

static void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

INITIALIZE_ENGINE_RESULT init_engine(init_engine_params_t params) {

    glfwSetErrorCallback(&error_callback);

    if (!glfwInit()) {
        ERROR("Couldn't init GLFW!");
        return INIT_ENGINE_FAIL;
    }

    INIT_VIDEO_RESULT video_init = init_video(params.video_params);
    if (video_init != INIT_VIDEO_OK) {
        ERROR("Couldn't load video!");
        return INIT_ENGINE_FAIL;
    }

    if (init_input() != INIT_INPUT_OK) {
        ERROR("Couldn't load input!");
        return INIT_ENGINE_FAIL;
    }

    ENSURE(params.update_callback != null);

    engine_state.break_loop = false;
    engine_state.update_callback = params.update_callback;

    return INIT_ENGINE_OK;
}

void release_engine() {
    release_input();
    release_video();

    glfwTerminate();
}

void run_one_frame() {
    update_input();
    update_video();

    window_t window = get_window();
    if (window.state == WINDOW_SHOULD_BE_CLOSED || window.state == WINDOW_DESTROYED) {
        engine_state.break_loop = true;
    } else {
        // Simulate
        engine_state.update_callback();

        // Draw
    }
}

void loop() {
    while (!engine_state.break_loop) {
        run_one_frame();
    }
}