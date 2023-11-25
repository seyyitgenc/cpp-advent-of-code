cmake_minimum_required(VERSION 3.5)

project(advent_of_code)

set(CMAKE_CXX_STANDAR 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(YEARS
    2022
    2023)

set(2022
    1.question
    )

set(2023
    )

function(create_project_from_sources year question)
    file(GLOB SOURCE
        "src/${year}/${question}/*.h"
        "src/${year}/${question}/*.cpp"
        )
    if(question STREQUAL "")
        set(replaced "")
        string(REPLACE "/" "_" replaced ${year})
    else()
        set(NAME "${year}_${question}")
    endif()
    add_executable(${NAME} ${SOURCE})
    if(WIN32)
        set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
        set_target_properties(${NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
    elseif(UNIX AND NOT APPLE)
        set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
    endif(WIN32)
endfunction()

# ceate project file per problem
foreach(YEAR ${YEARS})
    foreach(QUESTION ${${YEAR}})
        create_project_from_sources(${YEAR} ${QUESTION})
    endforeach()
endforeach()
