
#pragma once

#include "Responder.hpp"
#include "View.hpp"
#include "TabBarItem.hpp"
#include "NavigationItem.hpp"

namespace UI {
    template<class NavC>
    struct _ViewController:public UI::Responder{
        using Responder::Responder;
#ifdef __APPLE__
        STATIC_VAR(const std::string, className, "UIViewController");
        
        typedef _ViewController<NavC> Self;
        
        void setTabBarItem(const UI::TabBarItem &newValue){
            this->sendMessage<void>("setTabBarItem:",newValue.handle);
        }
        
        UI::TabBarItem tabBarItem(){
            return this->sendMessage<Handle>("tabBarItem");
        }
        
        UI::View view(){
            return this->sendMessage<Handle>("view");
        }
        
        NavigationItem navigationItem(){
            return this->sendMessage<Handle>("navigationItem");
        }
        
        NavC navigationController(){
            return this->sendMessage<Handle>("navigationController");
        }
        
        void presentViewController(const Self &vc,bool animated){
            this->sendMessage<void>("presentViewController:animated:completion:", vc.handle, animated);
        }
        
        Self presentingViewController(){
            return this->sendMessage<Handle>("presentingViewController");
        }
        
        void dismissViewControllerAnimated(bool animated){
            this->sendMessage<void>("dismissViewControllerAnimated:completion:", animated, nullptr);
        }
#endif
    };
}
