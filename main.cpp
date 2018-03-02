#include "core/engine_manager.h"

int main() {
    init_engine_params_t init_params = {};
    init_params.video_params.size = glm::ivec2(1600, 1024);
    init_params.video_params.title = (char *) "Hello world!";

    init_engine(init_params);
    loop();
    release_engine();

    return 0;
}