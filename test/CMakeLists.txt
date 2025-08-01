add_test(NAME CreateExampleEventData
               WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
               COMMAND k4run k4ProjectTemplate/options/createExampleEventData.py)

add_test(NAME ReadExampleEventData
               WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
               COMMAND k4run k4ProjectTemplate/options/readExampleEventData.py)
set_property(TEST ReadExampleEventData APPEND PROPERTY DEPENDS CreateExampleEventData)

add_test(NAME HelloWorldAlg
               WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
               COMMAND k4run k4ProjectTemplate/options/createHelloWorld.py)

# For LD_LIBRARY_PATH
# ${PROJECT_BINARY_DIR}:\                                         # The files <plugins>.components and <plugins>.confdb are here
# ${PROJECT_BINARY_DIR}/${PROJECT_NAME}:\                         # The plugins (.so) are here
# ${CMAKE_CURRENT_BINARY_DIR}:\                                   # The tests (.so) are here if there are algorithms in the tests
# ${CMAKE_CURRENT_BINARY_DIR}/genConfDir/${CURRENT_DIR_NAME}:\  # The files <test>.components and <test>.confdb are here
# For PYTHONPATH
# ${PROJECT_BINARY_DIR}/${PROJECT_NAME}/genConfDir:\              # The genConfDir of the plugins
# ${CMAKE_CURRENT_BINARY_DIR}/genConfDir:\                        # The genConfDir of the tests if there are algorithms in the tests

# If the package also includes python code to be imported in a module with the same as the package name,
# then the Python files have to be copied in the build directory to
# ${PROJECT_BINARY_DIR}/${PROJECT_NAME}/genConfDir
# after genConfDir has been populated by Gaudi
# See, for example:
# https://github.com/key4hep/k4FWCore/blob/42497b71c23425a3a26648f30a1285a499dcda28/test/k4FWCoreTest/CMakeLists.txt#L71

get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(test_environment "\
LD_LIBRARY_PATH=\
${PROJECT_BINARY_DIR}:\
${PROJECT_BINARY_DIR}/${PROJECT_NAME}:\
${CMAKE_CURRENT_BINARY_DIR}:\
${CMAKE_CURRENT_BINARY_DIR}/genConfDir/${CURRENT_DIR_NAME}:\
$ENV{LD_LIBRARY_PATH};\
\
PYTHONPATH=\
${PROJECT_BINARY_DIR}/${PROJECT_NAME}/genConfDir:\
${CMAKE_CURRENT_BINARY_DIR}/genConfDir:\
$ENV{PYTHONPATH};\
"
)
get_property(test_names DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY TESTS)
set_tests_properties(
  ${test_names}
  PROPERTIES ENVIRONMENT "${test_environment}"
)

