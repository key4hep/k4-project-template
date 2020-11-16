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
  int m_member = 0; 
  std::string message = "How can I say Hello, for this kinda ";
};
