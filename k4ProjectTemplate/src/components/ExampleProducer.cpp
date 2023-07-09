#include "Gaudi/Property.h"
#include "GaudiAlg/GaudiAlgorithm.h"
#include "GaudiAlg/Producer.h"

#include <string>

using BaseClass_t = Gaudi::Functional::Traits::BaseClass_t<Gaudi::Algorithm>;

class ExampleProducer final : Gaudi::Functional::Producer<int(), BaseClass_t> {

  ExampleProducer( const std::string& name, ISvcLocator* svcLoc )
    : Producer( name, svcLoc, KeyValue( "OutputLocation", "/ExampleInt" ) ) {}

  int operator()() const override {
    return m_exampleInt;
  }

private:
  Gaudi::Property<std::string> m_outputLocation{this, "OutputLocation", "/ExampleInt",
                                                "Location of the ExampleInt"};
  Gaudi::Property<int> m_exampleInt{this, "ExampleInt", 3,
                                    "Example int to be produced"};

};
 
DECLARE_COMPONENT(ExampleProducer)
