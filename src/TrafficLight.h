#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <mutex>
#include <deque>
#include <condition_variable>
#include "TrafficObject.h"


// forward declarations to avoid include cycle
class Vehicle;

enum TrafficLightPhase
{
    red,
    green
};


template <class T>
class MessageQueue
{
public:
    void send(T &&msg);
    T receive();
private:
    std::deque<TrafficLightPhase> _queue;
    std::condition_variable _cond;
    std::mutex _mutex;
};




class TrafficLight: public TrafficObject
{
public:
    
    TrafficLight();
   
    
    
    void setCurrentPhase(TrafficLightPhase phase);
    TrafficLightPhase getCurrentPhase();
    
    void waitForGreen();
    void simulate();
    
private:
    // typical behaviour methods
    void cycleThroughPhases();

    std::shared_ptr<MessageQueue<TrafficLightPhase>> messageQueue{new MessageQueue<TrafficLightPhase>};
    
    TrafficLightPhase _currentPhase;
    std::condition_variable _condition;
    std::mutex _mutex;
    
};

#endif
