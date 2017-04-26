//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

#include "IYieldInstruction.h"

namespace vd {

class WaitForSeconds : public IYieldInstruction {

public:

    WaitForSeconds(double seconds);

    //region Implementation of IYieldInstruction

    void Update() override;

    bool IsDone() const override;

    //endregion

private:

    const double _seconds;

    bool _done;

    double _endTime;

};

}