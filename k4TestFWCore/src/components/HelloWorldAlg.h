#ifndef TESTFWCORE_HELLOWORLDALG
#define TESTFWCORE_HELLOWORLDALG

#pragma once 

#include<string>

// GAUDI
#include "GaudiAlg/GaudiAlgorithm.h"
#include "Gaudi/Property.h"


class HelloWorldAlg : public GaudiAlgorithm {
public:
  explicit HelloWorldAlg(const std::string&, ISvcLocator*);
  virtual ~HelloWorldAlg();
  /**  Initialize.
   *   @return status code
   */
  virtual StatusCode initialize() final;
  /**  Execute.
   *   @return status code
   */
  virtual StatusCode execute() final;
  /**  Finalize.
   *   @return status code
   */
  virtual StatusCode finalize() final;

private:
  // member variable 
  std::string message = "Hello ";
};

#endif /* TESTFWCORE_HELLOWORLDALG */
