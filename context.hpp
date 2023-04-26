#pragma once
#include "CameraFunction.hpp"
#include <iostream>
#include <memory>
#include <utility>

class Context {
    std::unique_ptr<CameraFunction> strat{};                 
public:                                              
    void setStrategy(std::unique_ptr<CameraFunction> strat_)  { 
        strat = std::move(strat_); }
    void start()
    { 
        if (strat){
            strat->start();
         }
     }   

      void stop()
    { 
        if (strat){
            strat->stop();
         }
     }   

};