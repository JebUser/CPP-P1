#file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.cc)

file(GLOB_RECURSE SOURCES Candidate.cpp Candidate.h Country.cpp Country.h Interview.cpp Interview.h Program.cpp Program.h)  #Todas las fuentes sin el Main


set(BINARY ${CMAKE_PROJECT_NAME})  # El nombre va a a estar en el CMake principal

# Definicion variable sources
set(SOURCES ${SOURCES})

# STATIC libraries are archives of object files for use when linking other targets
#add_library(${CMAKE_PROJECT_NAME}_lib Calculator.h Calculator.cpp)  #construye una libraria que tiene los test que vamos a ejecutar

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_lib)


# Instrucción que define el ejecutable a partir de las fuentes definidas
add_executable(${BINARY}_exe ${SOURCES}  main.cpp)  # Las fuentes mas el archivo main