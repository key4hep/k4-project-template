#include "Gaudi/Property.h"
#include "GaudiAlg/GaudiAlgorithm.h"
#include "GaudiAlg/Consumer.h"

#include <string>

using BaseClass_t = Gaudi::Functional::Traits::BaseClass_t<Gaudi::Algorithm>;

struct ExampleConsumer final : Gaudi::Functional::Consumer<void( const int& ), BaseClass_t> {

  ExampleConsumer( const std::string& name, ISvcLocator* svcLoc )
    : Consumer( name, svcLoc, KeyValue( "InputLocation", "/ExampleInt" ) ) {}

  void operator()(const int& input) const override {
    info() << "ExampleInt = " << input << endmsg;
  }

  Gaudi::Property<std::string> m_outputLocation{this, "InputLocation", "/ExampleInt",
                                                "Location of the ExampleInt"};

};
 
DECLARE_COMPONENT(ExampleConsumer)
