set(srcs "main.c" "ble_mesh_init.c" "led.c")

idf_component_register(SRCS "${srcs}" INCLUDE_DIRS  ".")
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
