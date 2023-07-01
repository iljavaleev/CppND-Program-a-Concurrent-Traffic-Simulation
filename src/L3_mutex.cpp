#include <stdio.h>

//class Vehicle1{
//public:
//    Vehicle1(int id):_id(id){};
//private:
//    int _id{};
//};
//
//class WaitingVehicles1{
//public:
//    WaitingVehicles1():_tmpVehicles(0){};
//    void printSize(){
//        std::cout <<  "#vehicles = " << _tmpVehicles << std::endl;
//    }
//
//    void pushBack(Vehicle1 &&v){
//        _vehicles.push_back(std::move(v));
//        std::this_thread::sleep_for(std::chrono::microseconds(1));
//        _tmpVehicles += 1;
//    }
//
//private:
//    std::vector<Vehicle1> _vehicles;
//    int _tmpVehicles;
//
//};
//
//int main(){
//    std::shared_ptr<WaitingVehicles1> queue{new WaitingVehicles1};
//    std::vector<std::future<void>> ftr;
//
//    for (int i{}; i<100; i++){
//        ftr.emplace_back(std::async(std::launch::async, &WaitingVehicles1::pushBack, queue, Vehicle1{i}));
//    }
//
//    for (auto &f:ftr)
//        f.wait();
//
//    queue->printSize();
//
//    return 0;
//};

//#include <mutex>
//
//class Vehicle1{
//public:
//    Vehicle1(int id):_id(id){};
//private:
//    int _id{};
//};
//
//class WaitingVehicles1{
//public:
//    WaitingVehicles1():_tmpVehicles(0){};
//    void printSize(){
//        _mutex.lock();
//        std::cout <<  "#vehicles = " << _tmpVehicles << std::endl;
//        _mutex.unlock();
//    }
//
//    void pushBack(Vehicle1 &&v){
//        _mutex.lock();
//        _vehicles.push_back(std::move(v));
//        _tmpVehicles += 1;
//        _mutex.unlock();
//    }
//
//private:
//    std::vector<Vehicle1> _vehicles;
//    int _tmpVehicles;
//    std::mutex _mutex;
//};
//
//int main(){
//    std::shared_ptr<WaitingVehicles1> queue{new WaitingVehicles1};
//    std::vector<std::future<void>> ftr;
//
//    for (int i{}; i<100; i++){
//        ftr.emplace_back(std::async(std::launch::async, &WaitingVehicles1::pushBack, queue, Vehicle1{i}));
//    }
//
//    for (auto &f:ftr)
//        f.wait();
//
//    queue->printSize();
//
//    return 0;
//};


//#include <mutex>
//double res;
//
//void print_res(int denom){
//    std::cout << "for denom = " << denom << ", the result is " << res << std::endl;
//}
//
//void divide(double num, double denum){
//    try{
//        if(denum == 0)
//            throw std::invalid_argument("Exception from thread: Division by zero!");
//
//        res = num/denum;
//        std::this_thread::sleep_for(std::chrono::milliseconds(1));
//        print_res(denum);
//
//    }catch (std::invalid_argument &e){
//        std::cout << e.what() << std::endl;
//        return;
//    }
//
//}
//
//int main(){
//    std::vector<std::future<void>> ftrs;
//
//    for (double i{-5}; i < 5; i++){
//        ftrs.emplace_back(std::async(std::launch::async, &divide, 50.0, i));
//    }
//
//    for(auto &f: ftrs)
//        f.wait();
//
//    return 0;
//};
//#include <mutex>
//double res;
//std::mutex _mutex;
//
//void print_res(int denom){
//    std::cout << "for denom = " << denom << ", the result is " << res << std::endl;
//}
//
//void divide(double num, double denum){
//    try{
//        if(denum == 0)
//            throw std::invalid_argument("Exception from thread: Division by zero!");
//        _mutex.lock();
//        res = num/denum;
//        std::this_thread::sleep_for(std::chrono::milliseconds(1));
//        print_res(denum);
//        _mutex.unlock();
//        
//    }catch (std::invalid_argument &e){
//        std::cout << e.what() << std::endl;
//        return;
//    }
//        
//}
//
//int main(){
//    std::vector<std::future<void>> ftrs;
//    
//    for (double i{-5}; i < 5; i++){
//        ftrs.emplace_back(std::async(std::launch::async, &divide, 50.0, i));
//    }
//    
//    for(auto &f: ftrs)
//        f.wait();
//    
//    return 0;
//};

/*
Please adapt the code from the previous example (example_2.cpp) in a way that a
timed_mutex is used. Also, in the function pushBack, please use the method
try_lock_for instead of lock, which should be executed until a maximum number of
attempts is reached (e.g. 3 times) or until it succeeds. When an attempt fails,
you should print an error message to the console that also contains the
respective vehicle id and then put the thread to sleep for an amount of time
before the next attempt is trief. Also, to expose the timing issues in this
example, please introduce a call to sleep_for with a delay of several
milliseconds before releasing the lock on the mutex. When done, experiment with
the timing parameters to see how many vehicles will be added to the vector in
the end.
 */

//#include <mutex>
//
//class Vehicle1 {
//  public:
//    Vehicle1(int id):_id(id) {}
//    int getID(){return _id;}
//
//  private:
//    int _id;
//};
//
//class WaitingVehicles1 {
//  public:
//    WaitingVehicles1() {}
//
//    // getters / setters
//    void printSize() {
//      _mutex.lock();
//      std::cout << "#vehicles = " << _vehicles.size() << std::endl;
//      _mutex.unlock();
//    }
//
//    // typical behaviour methods
//    void pushBack(Vehicle1 &&v) {
//        int i{};
//        bool success{false};
//        while (!success && i < 3){
//            try{
//                success = _mutex.try_lock_for(std::chrono::milliseconds(100));
//            }catch (const std::system_error &e){
//                std::cout << e.what() << std::endl;
//                i++;
//            }
//            if (success){
//                _vehicles.emplace_back(std::move(v));
//                _mutex.unlock();
//                                
//            }else{
//                std::cout << "Vehicle id = " << v.getID();
//                std::this_thread::sleep_for(std::chrono::milliseconds(10));
//                i++;
//            }
//       }
//      
//    }
//
//  private:
//    std::vector<Vehicle1>
//      _vehicles;  // list of all vehicles waiting to enter this intersection
//    std::timed_mutex _mutex;
//};
//
//int main() {
//  std::shared_ptr<WaitingVehicles1> queue(new WaitingVehicles1);
//  std::vector<std::future<void>> futures;
//
//  for (int i = 0; i < 1000; ++i) {
//    Vehicle1 v(i);
//    futures.emplace_back(std::async(
//        std::launch::async, &WaitingVehicles1::pushBack, queue, std::move(v)));
//  }
//
//  for (std::future<void> &ftr : futures) {
//    ftr.wait();
//  }
//
//  queue->printSize();
//
//  return 0;
//}
