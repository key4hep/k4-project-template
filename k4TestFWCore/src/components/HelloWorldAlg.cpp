#include <iostream>
#include "HelloWorldAlg.h"


DECLARE_COMPONENT(HelloWorldAlg)

HelloWorldAlg::HelloWorldAlg(const std::string& aName, ISvcLocator* aSvcLoc) : GaudiAlgorithm(aName, aSvcLoc) {
}

HelloWorldAlg::~HelloWorldAlg() {}

StatusCode HelloWorldAlg::initialize() {
  message = message + "new thingy ?";
  return StatusCode::SUCCESS;
}

StatusCode HelloWorldAlg::execute() {
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << message << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  return StatusCode::SUCCESS;
}

StatusCode HelloWorldAlg::finalize() {
  return StatusCode::SUCCESS;
}
