set(TARGET_NAME jsonwrapper)

set(JSON_WRAPPER_SRC
    version.cpp
    )

add_library(${TARGET_NAME} STATIC ${JSON_WRAPPER_SRC})

if (USE_CJSON)
    add_subdirectory(impl/cjson)
    target_link_libraries(${TARGET_NAME} PRIVATE cjson)
    target_include_directories(${TARGET_NAME} PRIVATE ${PROJECT_ROOT_PATH}/third-party/cJSON)
endif()

target_include_directories(${TARGET_NAME} PUBLIC ${PROJECT_ROOT_PATH}/include/)
target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib/)
