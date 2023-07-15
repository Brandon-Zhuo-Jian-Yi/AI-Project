#pragma once
#include "BehaviorNode.h"

class D_CheckNearestAlive : public BaseNode<D_CheckNearestAlive>
{
protected:
    virtual void on_enter() override;
    virtual void on_update(float dt) override;
    //virtual void on_exit() override;

private:
    float nearest = 100.f;
    Agent* NearestAgent = nullptr;
};