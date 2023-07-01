#include <iostream>
#include <random>
#include <future>
#include "TrafficLight.h"


template <typename T>
T MessageQueue<T>::receive()
{
   std::unique_lock<std::mutex> lck{_mutex};
    _cond.wait(lck, [this]{return !_queue.empty();
    });
   
    T msg = std::move(_queue.back());
    _queue.pop_back();
         
    return msg;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    std::lock_guard<std::mutex> lck{_mutex};
    _queue.push_back(msg);
    _cond.notify_one();
}


TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
}

void TrafficLight::waitForGreen()
{
    while(messageQueue->receive() != TrafficLightPhase::green)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    return;
    
}

TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}

void TrafficLight::setCurrentPhase(TrafficLightPhase phase)
{
    _currentPhase = phase;
}

void TrafficLight::simulate()
{
    threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));
}

void TrafficLight::cycleThroughPhases()
{
   
    
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(4, 6);
    
    while(true){
        
               
        auto s = (std::chrono::seconds) distrib(gen);
        
        std::this_thread::sleep_for(std::chrono::seconds(s));
        
        
        
        if(_currentPhase == TrafficLightPhase::red){
            _currentPhase = TrafficLightPhase::green;
        }else
            _currentPhase = TrafficLightPhase::red;
        
        messageQueue->send(std::move(_currentPhase));
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        
       
    }
}


