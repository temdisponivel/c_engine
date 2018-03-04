#include <graphics/cameras.h>
#include "core/engine_manager.h"
#include "graphics/materials.h"
#include "graphics/models.h"

material_t material;
camera_t camera;
mesh_t quad;

void update() {
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    use_camera(&camera);
    use_material(&material);
    draw_mesh(&quad);

    swap_windows_buffers();
}

int main() {
    init_engine_params_t init_params = {};
    init_params.update_callback = &update;
    init_params.video_params.size = glm::ivec2(1600, 1024);
    init_params.video_params.title = (char *) "Hello world!";

    if (init_engine(init_params) != INIT_ENGINE_OK)
        return -1;

    material_definition_t definition = {};
    setup_default_material_definition(&definition);

    definition.vertex_code = read_file_text((char *) "data/shaders/gui_vertex_shader.glsl");
    definition.fragment_code = read_file_text((char *) "data/shaders/vertex_color_frag_shader.glsl");

    create_material(&material, &definition);

    create_quad(&quad, material, glm::vec3(0, 0, 0), glm::vec2(.5f, .5f));

    orthogonal_params_t cam_params;
    cam_params.left = -1;
    cam_params.right = 1;
    cam_params.top = 1;
    cam_params.bottom = -1;
    cam_params.near_plane = -100;
    cam_params.far_plane = 100;

    setup_ortho(&camera, cam_params);

    loop();
    release_engine();

    return 0;
}