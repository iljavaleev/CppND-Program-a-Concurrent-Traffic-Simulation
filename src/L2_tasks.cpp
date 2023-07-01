//#include <stdio.h>
//double divide(double num, double denum){
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//    if (denum == 0)
//        throw std::runtime_error("Exception from thread: Division by zero!");
//    return num / denum;
//}
//
//int main(){
//
//    // use async to start a task
//    double num{42}, denum{12};
//
//    std::future<double> ftr = std::async(divide, num, denum);
//
//
//    std::cout << "some work" << std::endl;
//    try{
//        double res = ftr.get();
//        std::cout << "Result = " << res<< std::endl;
//    }catch (std::runtime_error e){
//        std::cout << e.what() << std::endl;
//    }
//
//    return 0;
//}

//double divide(double num, double denum){
//    std::cout << "Worker id " << std::this_thread::get_id() << std::endl;
//    
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//        
//    if (denum == 0)
//        throw std::runtime_error("Exception from thread: Division by zero!");
//    return num / denum;
//}
//
//int main(){
//    std::cout << "Main thread id is " << std::this_thread::get_id() << std::endl;
//    // use async to start a task
//    double num{42}, denum{12};
//    //launch::deferred will invoke the function on the calling thread
//    //std::future<double> ftr = std::async(std::launch::deferred, divide, num, denum);
//    
//    std::future<double> ftr = std::async(divide, num, denum);
//    
//    try{
//        double res = ftr.get();
//        std::cout << "Result = " << res<< std::endl;
//    }catch (std::runtime_error e){
//        std::cout << e.what() << std::endl;
//    }
//    
//    return 0;
//}

//#include <iostream>
//#include <thread>
//#include <future>
//#include <cmath>
//#include <memory>
//#include <vector>
//
//void work(int times){
//    std::cout << "Worker id " << std::this_thread::get_id() << std::endl;
//
//
//
//    for (int i{}; i<times; i++)
//        sqrt(12345.6789);
//}
//
//int main(){
//    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;
//    auto t1 = std::chrono::high_resolution_clock::now();
//
//    std::vector<std::future<void>> futures;
//
//    int nLoops{10}, nThreads{5};
//
//    for (int i{}; i<nThreads; i++){
//        futures.emplace_back(std::async(std::launch::async, work, nLoops));
//    }
//
//    // wait for tasks to complete
//    for (const std::future<void> &f:futures)
//        f.wait();
//
//    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
//
//    auto duration =
//          std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
//      std::cout << "Execution finished after " << duration << " microseconds"
//                << std::endl;
//
//
//    return 0;
//}
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
