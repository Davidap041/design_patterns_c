# CMakeList.txt: projeto de CMake para src, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

# Habilite a Recarga Dinâmica para compiladores MSVC, se houver suporte.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("src")

# Adicione a origem ao executável deste projeto.
add_executable (src "src.c" "src.h" "creation_patterns/factory_pattern/factory_pattern.h" "creation_patterns/factory_pattern/factory_pattern.c" "creation_patterns/factory_pattern/shape/shape.h" "creation_patterns/factory_pattern/shape/shape.c" "creation_patterns/opaque_pattern/opaque_pattern.c" "creation_patterns/opaque_pattern/opaque_pattern.h" "creation_patterns/object_pattern/my_object/my_object.h" "creation_patterns/opaque_pattern/opaque/opaque.c" "creation_patterns/opaque_pattern/opaque/opaque.h" "creation_patterns/singleton_pattern/singleton_pattern.c" "creation_patterns/singleton_pattern/singleton_pattern.h" "creation_patterns/singleton_pattern/singleton_object/singleton_object.c" "creation_patterns/singleton_pattern/singleton_object/singleton_object.h" "creation_patterns/utils_macros.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET src PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
