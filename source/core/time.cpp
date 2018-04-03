//
// Created by temdisponivel on 02/04/2018.
//

#include "core/time.h"

static time_state_t time_state = {};

void init_time() {
    // TODO: Do nothing for now, maybe remove this method?!
}

float get_dt() {
    return time_state.dt;
}

void time_start_frame() {
    time_state.time = glfwGetTime();    
}

void time_finish_frame() {
    double time = glfwGetTime();
    time_state.dt = (float) (time - time_state.time);
}