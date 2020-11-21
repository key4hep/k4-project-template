from Gaudi.Configuration import *

from Configurables import HelloWorldAlg
producer = HelloWorldAlg()

from Configurables import ApplicationMgr
ApplicationMgr( TopAlg=[producer],
                EvtSel="NONE",
                EvtMax=1,                
                OutputLevel=INFO,
                )

