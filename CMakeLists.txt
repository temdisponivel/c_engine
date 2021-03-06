cmake_minimum_required(VERSION 3.8)
project(engine)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DDEV)
add_definitions(-DGLM_COORDINATE_SYSTEM=GLM_RIGHT_HANDED)

set(plataform "x32")
#set(plataform "x64")

### DEPS
set(deps_dir "${CMAKE_SOURCE_DIR}/deps")
set(deps_include_dir "${CMAKE_SOURCE_DIR}/deps/include")
set(deps_bin_dir "${CMAKE_SOURCE_DIR}/deps/bin/${plataform}")
set(deps_lib_dir "${CMAKE_SOURCE_DIR}/deps/lib/${plataform}")

### LIBS
set(libs "-lopengl32 -lglu32 -lgdi32 -lglfw3dll -lglew32 -luser32 -lkernel32 -lOpenAl32")

include_directories("include;${deps_include_dir}")
set(SOURCE_FILES include/core/core.h include/core/types.h include/graphics/materials.h include/utilities/collections.h main.cpp include/graphics/textures.h include/graphics/main_gl.h include/graphics/models.h source/graphics/materials.cpp source/utilities/util.cpp include/utilities/util.h source/graphics/textures.cpp source/graphics/models.cpp include/graphics/obj_loader.h source/graphics/main_gl.cpp include/graphics/cameras.h include/core/transform.h source/core/transform.cpp source/graphics/cameras.cpp include/core/video.h source/core/video.cpp include/core/input.h source/core/input.cpp include/core/engine_manager.h source/core/engine_manager.cpp data/shaders/gui_vertex_shader.glsl include/core/time.h source/core/time.cpp)
add_executable(engine ${SOURCE_FILES})
target_link_libraries(engine -L${deps_lib_dir} ${libs})

file(COPY ${deps_bin_dir}/ DESTINATION .)
file(COPY data DESTINATION .)