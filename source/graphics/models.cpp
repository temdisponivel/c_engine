//
// Created by temdisponivel on 27/02/2018.
//

#include <graphics/obj_loader.h>
#include "graphics/models.h"

void fill_all_indices(const model_t *model, list<uint> *indice_list) {
    for (int i = 0; i < model->childs.length; ++i) {
        model_data_t data = model->childs.items[i];
        for (int j = 0; j < data.indices.length; ++j) {
            add(indice_list, data.indices.items[j]);
        }
    }
}

void fill_all_model_data(const model_t *model, list<float> *all_data_appended) {
    /*
     * Add all of the model's data into one array to buff to opengl
     * This array will have the following format
     * (Px Py Pz Tx Ty Nx Ny Nz Cr Cg Cb) (Px Py Pz Tx Ty Nx Ny Nz Cr Cg Cb) (Px Py Pz Tx Ty Nx Ny Nz Cr Cg Cb)
     * Each '()' is a vertex
     */
    for (int i = 0; i < model->childs.length; ++i) {
        model_data_t data = model->childs.items[i];

        for (int j = 0; j < data.vertices.length; ++j) {
            vertex_data_t vertice = data.vertices.items[j];

            add(all_data_appended, vertice.position.x);
            add(all_data_appended, vertice.position.y);
            add(all_data_appended, vertice.position.z);

            add(all_data_appended, vertice.tex_coord.x);
            add(all_data_appended, vertice.tex_coord.y);

            add(all_data_appended, vertice.normal.x);
            add(all_data_appended, vertice.normal.y);
            add(all_data_appended, vertice.normal.z);

            add(all_data_appended, vertice.color.x);
            add(all_data_appended, vertice.color.y);
            add(all_data_appended, vertice.color.z);
        }
    }
}

void destroy_model_data(model_data_t data) {
    release_list(&data.vertices);
    memfree(data.material_name);
}

model_data_t get_model_data_from_obj(objl::Mesh mesh) {
    model_data_t data = {};
    data.material_name = copy_string(mesh.MaterialName);

    uint size = mesh.Vertices.size();
    setup_list(&data.vertices, size);

    glm::vec3 default_color = glm::vec3(1, 1, 1); // Obj files have no color

    for (int i = 0; i < mesh.Vertices.size(); ++i) {
        objl::Vertex vertex = mesh.Vertices[i];

        glm::vec3 pos = glm::vec3(vertex.Position.X, vertex.Position.Y, vertex.Position.Z);
        glm::vec3 normal = glm::vec3(vertex.Normal.X, vertex.Normal.Y, vertex.Normal.Z);
        glm::vec2 tex_coord = glm::vec2(vertex.TextureCoordinate.X, vertex.TextureCoordinate.Y);

        vertex_data_t vertex_data = {};
        vertex_data.position = pos;
        vertex_data.tex_coord = tex_coord;
        vertex_data.normal = normal;
        vertex_data.color = default_color;

        add(&data.vertices, vertex_data);
    }

    setup_list(&data.indices, mesh.Indices.size());
    for (int j = 0; j < mesh.Indices.size(); ++j) {
        add(&data.indices, mesh.Indices[j]);
    }

    return data;
}

model_t create_model_from_obj(const char *file_path) {
    objl::Loader loader;
    if (!loader.LoadFile(file_path)) {
        ERROR("COULDN'T LOAD FILE!");
    }

    model_t model = {};
    std::vector<objl::Mesh> meshs = loader.LoadedMeshes;

    setup_list(&model.childs, meshs.size());
    for (int i = 0; i < meshs.size(); ++i) {
        objl::Mesh mesh = meshs[i];
        model_data_t data = get_model_data_from_obj(mesh);
        add(&model.childs, data);
    }

    return model;
}

void destroy_model(model_t model) {
    for (int i = 0; i < model.childs.length; ++i) {
        destroy_model_data(model.childs.items[i]);
    }
    release_list(&model.childs);
}

mesh_t create_mesh(const model_t *model) {
    uint vao = 0;
    uint vio = 0;
    uint vbo = 0;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    list<uint> indices;
    setup_list(&indices, 10); // TODO: adjust this number based on the model

    fill_all_indices(model, &indices);
    if (!null_or_empty(&indices)) {
        glGenBuffers(1, &vio);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio);
        glBufferData(
                GL_ELEMENT_ARRAY_BUFFER,
                indices.length * sizeof(uint),
                indices.items,
                GL_STATIC_DRAW
        );
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, HANDLE_NONE);
        CHECK_GL_ERROR();
    }

    list<float> all_model_data;
    setup_list(&all_model_data, 100); // TODO: adjust this number based on the model
    fill_all_model_data(model, &all_model_data);
    ENSURE(!null_or_empty(&all_model_data));

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(
            GL_ARRAY_BUFFER,
            all_model_data.length * sizeof(float),
            all_model_data.items,
            GL_STATIC_DRAW
    );
    CHECK_GL_ERROR();

    const int STRIDE = ((3 + 2 + 3 + 3) * sizeof(float));
    const int POSITION_OFFSET = 0; // doesn't have to skip any float
    const int TEX_COORD_OFFSET = (3 * sizeof(float)); // skip the 3 floats of position
    const int NORMAL_OFFSET = ((3 + 2) * sizeof(float)); // skip 3 floats of positions + 2 of uv
    const int COLOR_OFFSET = ((3 + 2 + 3) * sizeof(float)); // skip 3 of positions + 2 of uv + 3 of normals

    glVertexAttribPointer(
            POSITION_ATTRIBUTE_INDEX,
            3,
            GL_FLOAT,
            GL_FALSE,
            STRIDE,
            (void *) POSITION_OFFSET
    );
    CHECK_GL_ERROR();

    glVertexAttribPointer(
            TEX_COORD_ATTRIBUTE_INDEX,
            2,
            GL_FLOAT,
            GL_FALSE,
            STRIDE,
            (void *) TEX_COORD_OFFSET
    );
    CHECK_GL_ERROR();

    glVertexAttribPointer(
            NORMAL_ATTRIBUTE_INDEX,
            3,
            GL_FLOAT,
            GL_FALSE,
            STRIDE,
            (void *) NORMAL_OFFSET
    );
    CHECK_GL_ERROR();

    glVertexAttribPointer(
            COLOR_ATTRIBUTE_INDEX,
            3,
            GL_FLOAT,
            GL_FALSE,
            STRIDE,
            (void *) COLOR_OFFSET
    );
    CHECK_GL_ERROR();

    glBindBuffer(GL_ARRAY_BUFFER, HANDLE_NONE);

    glBindVertexArray(HANDLE_NONE);

    mesh_t mesh = {};

    list<mesh_data_t> childs = {};
    setup_list(&childs, model->childs.length);

    for (int i = 0; i < model->childs.length; ++i) {
        model_data_t model_data = model->childs.items[i];

        uint element_count = 0;
        bool use_element_array = false;

        if (null_or_empty(&model_data.indices)) {
            element_count = model_data.vertices.length;
            use_element_array = false;
        } else {
            element_count = model_data.indices.length;
            use_element_array = true;
        }

        mesh_data_t mesh_data = {};

        mesh_data.element_count = element_count;
        mesh_data.material = model_data.material;
        mesh_data.use_element_array = use_element_array;

        add(&childs, mesh_data);
    }

    mesh.childs = childs;
    mesh.vao_handle = vao;
    mesh.vbo_handle = vbo;
    mesh.vio_handle = vio;

    return mesh;
}

void destroy_mesh(mesh_t mesh) {
    if (mesh.vio_handle > 0) {
        glDeleteBuffers(1, &mesh.vio_handle);
    }

    if (mesh.vbo_handle > 0) {
        glDeleteBuffers(1, &mesh.vbo_handle);
    }

    if (mesh.vao_handle > 0) {
        glDeleteVertexArrays(1, &mesh.vao_handle);
    }

    release_list(&mesh.childs);
}

void enable_vertex_attributes() {
    glEnableVertexAttribArray(POSITION_ATTRIBUTE_INDEX);
    glEnableVertexAttribArray(TEX_COORD_ATTRIBUTE_INDEX);
    glEnableVertexAttribArray(NORMAL_ATTRIBUTE_INDEX);
    glEnableVertexAttribArray(COLOR_ATTRIBUTE_INDEX);
}

void disable_vertex_attributes() {
    glDisableVertexAttribArray(POSITION_ATTRIBUTE_INDEX);
    glDisableVertexAttribArray(TEX_COORD_ATTRIBUTE_INDEX);
    glDisableVertexAttribArray(NORMAL_ATTRIBUTE_INDEX);
    glDisableVertexAttribArray(COLOR_ATTRIBUTE_INDEX);
}

void draw_mesh(mesh_t *mesh) {

    ENSURE(mesh != null);

    glBindVertexArray(mesh->vao_handle);
    CHECK_GL_ERROR();

    enable_vertex_attributes();

    for (int i = 0; i < mesh->childs.length; ++i) {
        mesh_data_t mesh_data = mesh->childs.items[i];
        use_material(&mesh_data.material);

        if (mesh_data.use_element_array) {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->vio_handle);
            glDrawElements(GL_TRIANGLES, mesh_data.element_count, GL_UNSIGNED_INT, null);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, HANDLE_NONE);

            CHECK_GL_ERROR();
        } else {
            glDrawArrays(GL_TRIANGLES, 0, mesh_data.element_count);
            CHECK_GL_ERROR();
        }
    }

    disable_vertex_attributes();

    glBindVertexArray(HANDLE_NONE);
}

void create_quad(mesh_t *mesh, material_t material, glm::vec3 center, glm::vec2 size) {
    ENSURE(mesh != null);

    model_t model = {};
    setup_list(&model.childs, 1);

    model_data_t model_data = {};
    model_data.material_name = copy_string("quad_material");

    setup_list(&model_data.indices, 6);
    add(&model_data.indices, (uint) 0);
    add(&model_data.indices, (uint) 1);
    add(&model_data.indices, (uint) 2);
    add(&model_data.indices, (uint) 2);
    add(&model_data.indices, (uint) 1);
    add(&model_data.indices, (uint) 3);

    setup_list(&model_data.vertices, 4);
    vertex_data_t vertice;

    vertice.position = glm::vec3(center.x - size.x, center.y + size.y, center.z);
    vertice.tex_coord = glm::vec2(0, 1);
    vertice.color = glm::vec3(1, 0, 1);
    add(&model_data.vertices, vertice);

    vertice.position = glm::vec3(center.x - size.x, center.y - size.y, center.z);
    vertice.tex_coord = glm::vec2(0, 0);
    vertice.color = glm::vec3(1, 1, 1);
    add(&model_data.vertices, vertice);

    vertice.position = glm::vec3(center.x + size.x, center.y + size.y, center.z);
    vertice.tex_coord = glm::vec2(1, 1);
    vertice.color = glm::vec3(0, 0, 1);
    add(&model_data.vertices, vertice);

    vertice.position = glm::vec3(center.x + size.x, center.y - size.y, center.z);
    vertice.tex_coord = glm::vec2(1, 0);
    vertice.color = glm::vec3(0, 1, 1);
    add(&model_data.vertices, vertice);

    model_data.material = material;

    add(&model.childs, model_data);

    *mesh = create_mesh(&model);

    destroy_model(model);
}