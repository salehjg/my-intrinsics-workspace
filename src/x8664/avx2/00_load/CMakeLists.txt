set(target_name x86_avx2_00_load)

add_executable(${target_name} "")

target_compile_options(${target_name} PRIVATE
        $<$<CONFIG:Debug>:-O0 -g -march=core-avx2>
        $<$<CONFIG:Release>:-O3 -fno-tree-vectorize -march=core-avx2>
)

target_sources(${target_name}
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/00_load.cpp
)

target_include_directories(${target_name}
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(${target_name}
        PUBLIC
        common
)