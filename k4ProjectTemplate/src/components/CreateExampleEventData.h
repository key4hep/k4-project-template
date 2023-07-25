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
#ifndef TESTFWCORE_CREATEEXAMPLEEVENTDATA
#define TESTFWCORE_CREATEEXAMPLEEVENTDATA

// GAUDI
#include "GaudiAlg/GaudiAlgorithm.h"

#include "podio/UserDataCollection.h"

// edm4hep
#include "TTree.h"
#include "k4FWCore/DataHandle.h"

// datamodel
namespace edm4hep {
  class MCParticleCollection;
  class SimTrackerHitCollection;
  class SimCaloHit;
}  // namespace edm4hep

/** @class CreateExampleEventData
 *  Lightweight producer for edm data for tests that do not depend on the actual
 *  data content and therefore do not need the simulation machinery.
 *  Fills data members with increasing integers, together with some offset so that different
 *  events can be easily distinguished.
 *
 */
class CreateExampleEventData : public GaudiAlgorithm {
public:
  explicit CreateExampleEventData(const std::string&, ISvcLocator*);
  virtual ~CreateExampleEventData();
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
  /// integer to add to the dummy values written to the edm
  Gaudi::Property<int> m_magicNumberOffset{this, "magicNumberOffset", 0,
                                           "Integer to add to the dummy values written to the edm"};
  /// Handle for the genparticles to be written
  DataHandle<edm4hep::MCParticleCollection> m_mcParticleHandle{"MCParticles", Gaudi::DataHandle::Writer, this};
  /// Handle for the genvertices to be written
  DataHandle<edm4hep::SimTrackerHitCollection> m_simTrackerHitHandle{"SimTrackerHit", Gaudi::DataHandle::Writer, this};

  DataHandle<podio::UserDataCollection<float>> m_vectorFloatHandle{"VectorFloat", Gaudi::DataHandle::Writer, this};
};
#endif /* TESTFWCORE_CREATEEXAMPLEEVENTDATA */
