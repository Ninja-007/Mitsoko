//
//  Data.cpp
//  Groozim
//
//  Created by John Zakharov on 14.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Data.hpp"

#ifdef __APPLE__

const std::string NS::Data::className="NSData";

NS::Data NS::Data::createWithContentsOfFile(const std::string &path){
    auto s = CF::String::create(path);
    return createWithContentsOfFile(s);
}

NS::Data NS::Data::createWithContentsOfFile(const CF::String &path){
    auto cls = NS::getClass(className);
    assert(cls);
    return sendMessage<Handle>(cls, "dataWithContentsOfFile:",path.handle);
}

NS::Data NS::Data::createWithBytes(const void *bytes, int length) {
    auto cls = NS::getClass(className);
    assert(cls);
    return sendMessage<Handle>(cls, "dataWithBytes:length:", bytes, NSUInteger(length));
}

int NS::Data::length(){
    return int(this->sendMessage<NSUInteger>("length"));
}

const void* NS::Data::bytes(){
    return this->sendMessage<const void*>("bytes");
}

bool NS::Data::writeToFile(const std::string &path, bool useAuxiliaryFile){
    auto p = CF::String::create(path);
    return this->sendMessage<BOOL>("writeToFile:atomically:", p.handle, BOOL(useAuxiliaryFile));
}

#endif  //__APPLE__
