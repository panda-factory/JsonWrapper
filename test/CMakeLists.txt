
SET(GTEST_ROOT ${PROJECT_SOURCE_DIR}/third_party/googletest/googletest)

FIND_PACKAGE(GTestSrc REQUIRED)

IF(GTESTSRC_FOUND)
    SET(TARGET_NAME unittests)
    enable_testing()

    IF (WIN32 AND (NOT CYGWIN) AND (NOT MINGW))
        SET(gtest_disable_pthreads ON)
        SET(gtest_force_shared_crt ON)
    ENDIF()


    ADD_SUBDIRECTORY(${GTEST_SOURCE_DIR} ${CMAKE_BINARY_DIR}/third_party/googletest)
    set(GTEST_LIBRARIES gtest gtest_main)

    INCLUDE_DIRECTORIES(${PROJECT_ROOT_PATH}/src)
    INCLUDE_DIRECTORIES(${PROJECT_ROOT_PATH}/include)

    ADD_EXECUTABLE(${TARGET_NAME}
        json_array_iterator_test.cpp
        json_array_put_test.cpp
        json_object_put_test.cpp
        json_type_test.cpp
        json_value_test.cpp
        )

    target_link_libraries(${TARGET_NAME} PRIVATE ${GTEST_LIBRARIES} jsonwrapper)

    IF(BUILDING_SHARED)
        #TARGET_COMPILE_DEFINITIONS(unittests PRIVATE USING_SHARED=1)
    ENDIF()
ENDIF(GTESTSRC_FOUND)
