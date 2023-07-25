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
#include "CreateExampleEventData.h"

// datamodel
#include "edm4hep/MCParticleCollection.h"
#include "edm4hep/SimTrackerHitCollection.h"

DECLARE_COMPONENT(CreateExampleEventData)

CreateExampleEventData::CreateExampleEventData(const std::string& aName, ISvcLocator* aSvcLoc)
    : GaudiAlgorithm(aName, aSvcLoc) {
  declareProperty("mcparticles", m_mcParticleHandle, "Dummy Particle collection (output)");
  declareProperty("trackhits", m_simTrackerHitHandle, "Dummy Hit collection (output)");
}

CreateExampleEventData::~CreateExampleEventData() {}

StatusCode CreateExampleEventData::initialize() {
  if (GaudiAlgorithm::initialize().isFailure()) {
    return StatusCode::FAILURE;
  }
  return StatusCode::SUCCESS;
}

StatusCode CreateExampleEventData::execute() {
  auto* floatVector = m_vectorFloatHandle.createAndPut();
  floatVector->push_back(125.);
  floatVector->push_back(25.);

  edm4hep::MCParticleCollection* particles = m_mcParticleHandle.createAndPut();

  auto particle = particles->create();

  auto& p4 = particle.momentum();
  p4.x     = m_magicNumberOffset + 5;
  p4.y     = m_magicNumberOffset + 6;
  p4.z     = m_magicNumberOffset + 7;
  particle.setMass(m_magicNumberOffset + 8);

  auto* hits = m_simTrackerHitHandle.createAndPut();
  auto  hit  = hits->create();
  hit.setPosition({3, 4, 5});

  return StatusCode::SUCCESS;
}

StatusCode CreateExampleEventData::finalize() { return GaudiAlgorithm::finalize(); }
