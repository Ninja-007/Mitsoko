
#ifndef __VIPER__IOS_UTIL__MK__ANNOTATION__
#define __VIPER__IOS_UTIL__MK__ANNOTATION__

#include "Mitsoko/iOSutil/NS/Object.hpp"
#include "Mitsoko/iOSutil/NS/MutableDictionary.hpp"
#include "Mitsoko/iOSutil/CL/Location.hpp"

#include <experimental/optional>

namespace MK {
    struct Annotation:public NS::Object{
        using Object::Object;
#ifdef __APPLE__
        
        static MK::Annotation create(CL::Location::Coordinate2D coordinate,
                                     std::experimental::optional<std::string> title={},
                                     std::experimental::optional<std::string> subtitle={});
        
        CL::Location::Coordinate2D coordinate();
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__MK__ANNOTATION__
