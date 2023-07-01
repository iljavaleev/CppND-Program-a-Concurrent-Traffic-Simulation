//
//  L2_data_races.cpp
//  traffic_simulation
//
//  Created by Илья Валеев on 25.06.2023.
//

#include <stdio.h>
//class Vehicle1{
//public:
//    Vehicle1():_id(0){
//        std::cout << "Vehicle #" << _id
//        << " Default constructor called"
//        << std::endl;
//    }
//    Vehicle1(int id):_id(id){
//        std::cout << "Vehicle #" << _id
//        << " Initializing constructor called"
//        << std::endl;
//    }
//    void setId(int id){
//        std::cout << id << std::endl;
//        _id = id;
//    }
//    int getId(){
//        return _id;
//    }
//    
//private:
//    int _id{};
//};
//
//
//int main(){
//    Vehicle1 v;
//    Vehicle1 v1{2};
//    
//    std::future<void> t = std::async([](Vehicle1 vz){
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        vz.setId(3);
//    }, v);
//    
//    v.setId(33);
//    
//    t.wait();
//    
//    std::cout << v.getId() << std::endl;
//    
//    return 0;
//};

//#include <iostream>
//#include <thread>
//#include <future>
//#include <cmath>
//#include <memory>
//#include <vector>
//
//class Vehicle1{
//public:
//    Vehicle1():_id(0), _name{new std::string("Default name")}{
//        std::cout << "Vehicle #" << _id
//        << " Default constructor called"
//        << std::endl;
//    }
//    Vehicle1(int id, std::string name):_id(id), _name(new std::string(name)){
//        std::cout << "Vehicle #" << _id
//        << " Initializing constructor called"
//        << std::endl;
//    }
//
//    // copy constructor
//    Vehicle1(const Vehicle1 &c){
//        std::cout << "Vehicle #" << _id << " copy constructor called" << std::endl;
//    }
//
//    // move constructor
//    Vehicle1(Vehicle1 &&m){
//        _id = m.getId();
//        _name = new std::string(m.getName());
//
//        m.setId(0);
//        m.setName("Default name");
//
//        std::cout << "Vehicle #" << _id << " move constructor called" << std::endl;
//    }
//
//    void setId(int id){
//        _id = id;
//    }
//    int getId(){
//        return _id;
//    }
//
//    void setName(std::string name){
//        *_name = name;
//    }
//
//    std::string getName(){
//        return *_name;
//    }
//private:
//    int _id{};
//    std::string * _name;
//};
//
//
//int main(){
//    Vehicle1 v;
//    Vehicle1 v1{2, "Vehicle 1"};
//
//    std::future<void> t = std::async([](Vehicle1 vz){
//        vz.setName("new Name for Vehicle1");
//    }, std::move(v));
//
//    v.setName("V3");
//
//    t.wait();
//
//    std::cout << v.getName() << std::endl;
//
//    return 0;
//};

//#include <iostream>
//#include <thread>
//#include <future>
//#include <cmath>
//#include <memory>
//#include <vector>
//
//class Vehicle1{
//public:
//    Vehicle1():_id(0), _name{new std::string("Default name")}{
//        std::cout << "Vehicle #" << _id
//        << " Default constructor called"
//        << std::endl;
//    }
//    Vehicle1(int id, std::string name):_id(id), _name(new std::string(name)){
//        std::cout << "Vehicle #" << _id
//        << " Initializing constructor called"
//        << std::endl;
//    }
//    
//    // copy constructor
//    Vehicle1(const Vehicle1 &c){
//        std::cout << "Vehicle #" << _id << " copy constructor called" << std::endl;
//    }
//    
//    // move constructor
//    Vehicle1(Vehicle1 &&m):_name(std::move(m._name)){
//        _id = m.getId();
//                
//        m.setId(0);
//                
//        std::cout << "Vehicle #" << _id << " move constructor called" << std::endl;
//    }
//    
//    void setId(int id){
//        _id = id;
//    }
//    int getId(){
//        return _id;
//    }
//    
//    void setName(std::string name){
//        *_name = name;
//    }
//    
//    std::string getName(){
//        return *_name;
//    }
//private:
//    int _id{};
//    std::unique_ptr<std::string> _name;
//};
//
//
//int main(){
//    Vehicle1 v;
//    Vehicle1 v1{2, "Vehicle 1"};
//    
//    std::future<void> t = std::async([](Vehicle1 vz){
//        vz.setName("new Name for Vehicle1");
//    }, std::move(v));
//    
//    t.wait();
//    
//    std::cout << v.getName() << std::endl; // this will now cause an exception
//    
//    return 0;
//};

