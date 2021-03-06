
#ifndef __VIPER__ANDROID_UTIL__ANDROID__VIEW__VIEW_GROUP__
#define __VIPER__ANDROID_UTIL__ANDROID__VIEW__VIEW_GROUP__

#include "View.hpp"
#include <type_traits>

namespace android{
    
    namespace view{
        
        struct ViewGroup : public View {
            
            using View::View;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            void removeAllViews();
            
            void addView(const android::view::View &v);
            
            struct LayoutParams : public java::lang::Object {
                
                using Object::Object;
                
                static const std::string signature;
                
                static LayoutParams create(int width, int height);
                
                static int MATCH_PARENT();
                
                static int WRAP_CONTENT();
            };
            
            struct MarginLayoutParams : public LayoutParams {
                
                using LayoutParams::LayoutParams;
                
                static const std::string signature;
                
            };
            
#endif  //__ANDROID__
            
        };
        
#ifdef __ANDROID__
        template<class T>
        void View::setLayoutParams(const T &params){
            auto baseParams = (ViewGroup::LayoutParams)params;
            this->sendMessage<void>("setLayoutParams",baseParams);
        }
        
        template<>
        void View::setLayoutParams<ViewGroup::LayoutParams>(const ViewGroup::LayoutParams &params);
        
#endif  //__ANDROID__
        
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__VIEW__VIEW_GROUP__
