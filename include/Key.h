#pragma once
//-----------------------------------------------------------------------------
#include "StaticObject.h"
#include "Thief.h"
//-----------------------------------------------------------------------------
class Key : public StaticObject
{
public:
    using StaticObject::StaticObject;
    using StaticObject::handleCollision;

    virtual void handleCollision(GameObject& currObject) override;
    virtual void handleCollision(Thief& theThief) override;

private:

};
//-----------------------------------------------------------------------------