#include <graphics/cameras.h>
#include "core/engine_manager.h"
#include "graphics/materials.h"
#include "graphics/models.h"

orbital_camera_t camera;
mesh_t power_loader;
mesh_t quad;

void update() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    

    update_orbital_camera(&camera);
    use_camera(&camera.camera);

    for (int i = 0; i < power_loader.childs.length; ++i) {
        mesh_data_t *mesh = &power_loader.childs.items[i];
        gl_set_matrix(&mesh->material, "MVP", glm::mat4() * camera.camera.projection * camera.camera.view);
    }

    draw_mesh(&power_loader);

    for (int i = 0; i < quad.childs.length; ++i) {
        mesh_data_t *mesh = &quad.childs.items[i];
        gl_set_matrix(&mesh->material, "MVP", glm::mat4() * camera.camera.projection * camera.camera.view);
    }
    
    
    draw_mesh(&quad);

    swap_windows_buffers();
}

uniform_definition_t get_tex_uniform(char *tex_name, texture_t texture) {
    uniform_definition_t texture_uni = {};
    texture_uni.name = tex_name;
    texture_uni.type = UNIFORM_TEXTURE2D;
    texture_uni.default_value.texture_value.texture = texture;
    texture_uni.default_value.texture_value.index = TEX_TWO;
    return texture_uni;
}

int main() {
    init_engine_params_t init_params = {};
    init_params.update_callback = &update;
    init_params.video_params.size = glm::ivec2(1600, 1024);
    init_params.video_params.title = (char *) "Hello world!";

    if (init_engine(init_params) != INIT_ENGINE_OK)
        return -1;

    model_t model = create_model_from_obj("data/models/PowerLoader.obj");
    
    char *vertex_code = read_file_text((char *) "data/shaders/default_vertex_shader.glsl");
    char *fragment_code = read_file_text((char *) "data/shaders/default_fragment_shader.glsl");

    for (int i = 0; i < model.childs.length; ++i) {
        model_data_t *data = &model.childs.items[i];

        char *tex_name = null;
        if (strcmp(data->material_name, "PowerLoaderGrate") == 0) {
            tex_name = (char *) "data/models/PowerLoaderGrate_D.tga";
        } else if (strcmp(data->material_name, "PowerLoaderLower") == 0) {
            tex_name = (char *) "data/models/PowerLoaderLower_D.tga";
        } else if (strcmp(data->material_name, "PowerLoaderUpper") == 0) {
            tex_name = (char *) "data/models/PowerLoaderUpper_D.tga";
        }

        material_definition_t definition = {};
        setup_list(&definition.uniforms, 4);

        add_default_material_uniforms(&definition);

        definition.vertex_code = vertex_code;
        definition.fragment_code = fragment_code;

        texture_t texture = create_texture_from_file(tex_name, true);
        add(&definition.uniforms, get_tex_uniform((char *) "diffuse_texture", texture));

        create_material(&data->material, &definition);

        release_list(&definition.uniforms);
    }

    glm::ivec2 video_size = get_video_size();
    
    material_t mat = {};
    material_definition_t def = {};
    setup_list(&def.uniforms, 1);
    add_default_material_uniforms(&def);
    create_material(&mat, &def);
    
    create_quad(&quad, mat, glm::vec3(0, 0, 0), video_size);

    destroy_file_content(vertex_code);
    destroy_file_content(fragment_code);

    power_loader = create_mesh(&model);

    perspective_params_t perspective;
    perspective.aspect_ratio = 16/9.f;
    perspective.field_of_view = 45.0f;
    perspective.near_plane = .1f;
    perspective.far_plane = 10000;

    camera = {};

    
    orthogonal_params_t ortho;
    ortho.near_plane = -100000000;
    ortho.far_plane = 100000000;
    ortho.right = video_size.x / 2.f;
    ortho.left = -video_size.x / 2.f;
    ortho.top = video_size.y  / 2.f;
    ortho.bottom = -video_size.y / 2.f;
    setup_ortho(&camera.camera, ortho);
    //setup_perspetive(&camera.camera, perspective);

    camera.camera.transform.position = glm::vec3(0, 0, 10.f);

    loop();
    release_engine();

    return 0;
}