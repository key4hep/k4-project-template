/*
 * Copyright (c) 2020-2023 Key4hep-Project.
 *
 * This file is part of Key4hep.
 * See https://key4hep.github.io/key4hep-doc/ for further info.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Gaudi/Property.h"
#include "GaudiAlg/Producer.h"

// Define BaseClass_t
#include "k4FWCore/BaseClass.h"

#include <string>

struct ExampleProducer final : Gaudi::Functional::Producer<int(), BaseClass_t> {
  ExampleProducer(const std::string& name, ISvcLocator* svcLoc)
      : Producer(name, svcLoc, KeyValue("OutputLocation", "/ExampleInt")) {}

  int operator()() const override {
    info() << "Producing ExampleInt = " << m_exampleInt << endmsg;
    return m_exampleInt;
  }

  Gaudi::Property<int> m_exampleInt{this, "ExampleInt", 3, "Example int to be produced"};
};

DECLARE_COMPONENT(ExampleProducer)
