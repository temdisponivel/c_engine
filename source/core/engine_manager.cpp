//
// Created by temdisponivel on 01/03/2018.
//

#include "core/engine_manager.h"

static engine_state_t engine_state = {};

static void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

INIT_ENGINE_RESULT init_engine(init_engine_params_t params) {
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        return INIT_ENGINE_FAIL;

    if (init_video(&engine_state.video_state, params.video_params) != INIT_VIDEO_OK) {
        glfwTerminate();
        return INIT_ENGINE_FAIL;
    }

    glewInit();

    // Init other systems

    if (init_input(&engine_state.input_state) != INIT_INPUT_OK) {
        // Release systems already initialized
        release_video(&engine_state.video_state);
        return INIT_ENGINE_FAIL;
    }
}

void release_engine() {
    // Release all systems
    release_video(&engine_state.video_state);
    release_input(&engine_state.input_state);

    glfwTerminate();
}

void run_one_frame() {
    update_video(&engine_state.video_state);
    update_intput(&engine_state.input_state);

    // TODO: Update & draw world

    swap_windows_buffers(&engine_state.video_state);
}

void loop() {
    while (!engine_state.engine_state.should_break) {
        run_one_frame();
    }
}

void stop_loop() {
    engine_state.engine_state.should_break = true;
}

const video_state_t *get_video_state() {
    return &engine_state.video_state;
}