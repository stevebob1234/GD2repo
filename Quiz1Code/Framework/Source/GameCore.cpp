#include "CoreHeaders.h"
#include "GameCore.h"
#include "Events/EventManager.h"

namespace fw {

GameCore::GameCore()
{
    m_pEventManager = new EventManager( this );
}

GameCore::~GameCore()
{
    delete m_pEventManager;
}

}
