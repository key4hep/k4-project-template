#include "Gaudi/Property.h"
#include "GaudiAlg/GaudiAlgorithm.h"
#include "GaudiAlg/Producer.h"

#include <string>

using BaseClass_t = Gaudi::Functional::Traits::BaseClass_t<Gaudi::Algorithm>;

struct ExampleProducer final : Gaudi::Functional::Producer<int(), BaseClass_t> {

  ExampleProducer( const std::string& name, ISvcLocator* svcLoc )
      : Producer( name, svcLoc, KeyValue( "OutputLocation", m_outputLocation ) ) {}

  int operator()() const override {
    return m_exampleInt;
  }

  Gaudi::Property<std::string> m_outputLocation{this, "OutputLocation", "/ExampleInt"};
  Gaudi::Property<int> m_exampleInt{this, "ExampleInt", 3};

};
 
DECLARE_COMPONENT(ExampleProducer)
