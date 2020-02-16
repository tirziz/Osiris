#include "GlobalVars.h"
#include "UserCmd.h"
#include "../Interfaces.h"
#include "Engine.h"
#include "Entity.h"
#include "EntityList.h"

float GlobalVars::serverTime(UserCmd* cmd) noexcept
{
    static int tick;
    static UserCmd* lastCmd;

    if (cmd) {
        if (!lastCmd || lastCmd->hasbeenpredicted)
            tick = interfaces.entityList->getEntity(interfaces.engine->getLocalPlayer())->tickBase();
        else
            tick++;
        lastCmd = cmd;
    }
    return tick * intervalPerTick;
}
