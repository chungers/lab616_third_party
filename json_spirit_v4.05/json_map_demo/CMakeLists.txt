SET(JSON_MAP_DEMO_SRCS
json_map_demo.cpp)

FIND_PACKAGE(Boost 1.34 REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

ADD_EXECUTABLE(json_map_demo ${JSON_MAP_DEMO_SRCS})
TARGET_LINK_LIBRARIES(json_map_demo json_spirit boost_system boost_thread)

