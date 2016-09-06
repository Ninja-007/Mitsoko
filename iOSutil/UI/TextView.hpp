
#ifndef __VIPER__IOS_UTIL__UI__TEXTVIEW__
#define __VIPER__IOS_UTIL__UI__TEXTVIEW__

#include "ScrollView.hpp"
#include "Viper/Util.hpp"
#include "Viper/iOSutil/CF/String.hpp"
#include "Viper/iOSutil/NS/Range.hpp"
#include "Viper/iOSutil/NS/String.hpp"
#include "Viper/iOSutil/NS/TextAttachment.hpp"
#include "Viper/iOSutil/NS/URL.hpp"
#include "Viper/Disposable.hpp"
#include <map>
#include <vector>

namespace UI {
    
    struct TextView:public UI::ScrollView{
        
        using ScrollView::ScrollView;
        
#ifdef __APPLE__
        
        typedef std::function<bool()> ShouldBeginEditing;
        typedef std::function<void()> DidBeginEditing;
        typedef std::function<bool()> ShouldEndEditing;
        typedef std::function<void()> DidEndEditing;
        typedef std::function<bool(NS::Range,NS::String)> ShouldChangeTextInRange;
        typedef std::function<void()> DidChange;
        typedef std::function<void()> DidChangeSelection;
        typedef std::function<bool(NS::TextAttachment,NS::Range)> ShouldInteractWithTextAttachment;
        typedef std::function<bool(NS::URL,NS::Range)> ShouldInteractWithURL;
        
        static const std::string className;
//        STATIC_VAR(const std::string, className, "UITextView");
        
        void setText(const CF::String &newValue);
        
        void setText(const std::string &newValue);
        
        std::string text();
        
        void setShouldBeginEditing(ShouldBeginEditing value, const Viper::Disposable &disposable);
        
        void setDidBeginEditing(DidBeginEditing value, const Viper::Disposable &disposable);
        
        void setShouldEndEditing(ShouldEndEditing value, const Viper::Disposable &disposable);
        
        void setDidEndEditing(DidEndEditing value, const Viper::Disposable &disposable);
        
        void setShouldChangeTextInRange(ShouldChangeTextInRange value, const Viper::Disposable &disposable);
        
        void setDidChange(DidChange value, const Viper::Disposable &disposable);
        
        void setDidChangeSelection(DidChangeSelection value, const Viper::Disposable &disposable);
        
        void setShouldInteractWithTextAttachment(ShouldInteractWithTextAttachment value, const Viper::Disposable &disposable);
        
        void setShouldInteractWithURL(ShouldInteractWithURL value, const Viper::Disposable &disposable);
        
        struct DelegateEventHandler{
            ShouldBeginEditing shouldBeginEditing;
            DidBeginEditing didBeginEditing;
            ShouldEndEditing shouldEndEditing;
            DidEndEditing didEndEditing;
            ShouldChangeTextInRange shouldChangeTextInRange;
            DidChange didChange;
            DidChangeSelection didChangeSelection;
            ShouldInteractWithTextAttachment shouldInteractWithTextAttachment;
            ShouldInteractWithURL shouldInteractWithURL;
            
            static DelegateEventHandler& getOrCreate(const void *sender);
            
            static DelegateEventHandler* get(const void *tv);
            
            static bool textViewShouldBeginEditing(Handle sender);
            
            static void textViewDidBeginEditing(Handle sender);
            
            static bool textViewShouldEndEditing(Handle sender);
            
            static void textViewDidEndEditing(Handle sender);
            
            static bool textViewShouldChangeTextInRange(Handle sender, NSRange range, Handle text);
            
            static void textViewDidChange(Handle sender);
            
            static void textViewDidChangeSelection(Handle sender);
            
            static bool textViewShouldInteractWithTextAttachment(Handle sender,Handle textAttachment,NSRange characterRange);
            
            static bool textViewShouldInteractWithURL(Handle sender, Handle url, NSRange characterRange);
            
        protected:
            friend class TextView;
            
            typedef std::map<Handle, DelegateEventHandler> DelegateEventHandlersMap;
            static DelegateEventHandlersMap delegateEventHandlers;
            
            typedef std::map<Viper::Disposable::Id, std::vector<Handle>> DisposablesMap;
            static DisposablesMap disposablesMap;
            
            static void remove(const void *tv);
            
            struct Observer:public Viper::Disposable::Observer{
                
                virtual void disposableDidDispose(Viper::Disposable::Id id) override;
                
            };
            
            static Observer observer;
        };
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__TEXTVIEW__
