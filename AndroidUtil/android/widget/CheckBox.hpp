
#pragma once

#include "CompoundButton.hpp"

namespace android{
    namespace widget{
        struct CheckBox:public CompoundButton{
            using CompoundButton::CompoundButton;
#ifdef __APPLE__
            STATIC_VAR(const std::string, signature, "android/widget/CheckBox");
#endif
        };
    }
}
