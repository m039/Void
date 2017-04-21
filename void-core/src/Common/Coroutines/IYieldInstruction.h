//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

namespace vd {

class IYieldInstruction {

public:

    virtual void Update() = 0;

    virtual bool IsDone() const = 0;

    virtual ~IYieldInstruction() {}

};

}