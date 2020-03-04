################################################################################
# Package: TestFWCore
################################################################################

find_package(EDM4HEP)
find_package(podio)


gaudi_subdir(TestFWCore v1r0)

gaudi_depends_on_subdirs(GaudiAlg GaudiKernel FWCore)


gaudi_add_module(TestFWCorePlugins
                 src/components/*.cpp
                 INCLUDE_DIRS FWCore EDM4HEP::edm4hep
                 LINK_LIBRARIES GaudiKernel FWCore EDM4HEP::edm4hep)


include(CTest)

gaudi_add_test(CreateExampleEventData
               WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
               COMMAND gaudirun.py TestFWCore/options/createExampleEventData.py)

