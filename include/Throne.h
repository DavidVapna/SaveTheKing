#pragma once
//-----------------------------------------------------------------------------
#include "StaticObject.h"
//-----------------------------------------------------------------------------
class Throne : public StaticObject
{
public:
    using StaticObject::StaticObject;
    using StaticObject::handleCollision;

    virtual void handleCollision(GameObject& currObject) override;
    virtual void handleCollision(King& theKing) override;

private:

};
//-----------------------------------------------------------------------------