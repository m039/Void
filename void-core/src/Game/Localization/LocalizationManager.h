//
// Created by Dmitry Mozgin on 08/05/2017.
//

#pragma once

#include <string>
#include "TextId.h"

namespace vd {

class LocalizationManager {
public:

    static std::string ToText(TextId textId) {
        switch (textId) {
            case TextId::Void:
                return "Void";
            case TextId::TryAgainTitle:
                return "TRY AGAIN";
            case TextId::TryAgainCollidedWithPortal:
                return "AVOID RED PORTALS";
            case TextId::TryAgainMissedGate:
                return "ENTER THE GATE";
            case TextId::TryAgainFooter:
                return "RETRY FROM THE BEGINNING";
            case TextId::PressAnyButtonToStart:
                return "Press any button to start";
            case TextId::TouchScreenToStart:
                return "Touch the screen to start";
            case TextId::SwipeDownHelp:
                return "SWIPE DOWN";
            case TextId::SwipeLeftHelp:
                return "SWIPE LEFT";
            case TextId::MoveUpHelp:
                return "PRESS UP";
            case TextId::MoveRightHelp:
                return "PRESS RIGHT";
            case TextId::WelcomeInfo:
                return std::string {
                        "This demo is a simplified version of a second level of Last Voyage game." \
                       " Main differences are: the level is always the same and there are no checkpoints." \
                       " Headphones are must."
                };
            default:
                throw std::exception();
        }
    }

};

}