//#include <stdio.h>
//#include <future>
//#include <iostream>
//#include <mutex>
//#include <thread>
//#include <vector>
//
//class Vehicle1 {
//  public:
//    Vehicle1(int id):_id(id){};
//
//    int getID() {
//      return _id;
//    }
//
//  private:
//    int _id;
//};
//
//class WaitingVehicles1{
//public:
//    WaitingVehicles1(){}
//    
//    void printIDs(){
//        std::lock_guard<std::mutex> lck(_mtx); // lock is released when myLock goes out of scope
//        for (auto &v:_vehicles){
//            std::cout << "Vehicle #" << v.getID() << " is now waiting in the queue" << std::endl;
//        }
//    }
//    
//    void pushBack(Vehicle1 &&v){
//        std::lock_guard<std::mutex> lck(_mtx); // perform vector modification under the lock
//        std::cout << "Vehicle #" << v.getID() << " will be added to the queue" << std::endl;
//        _vehicles.emplace_back(v);
//        std::this_thread::sleep_for(std::chrono::milliseconds(500));
//    }
//    
//private:
//    std::vector<Vehicle1> _vehicles;
//    std::mutex _mtx;
//};
//
//int main() {
//    // create monitor object as a shared pointer to enable access by multiple threads
//    std::shared_ptr<WaitingVehicles1> queue{new WaitingVehicles1};
//    std::vector<std::future<void>> ftrs;
//    
//    std::cout << "Spawning threads..." << std::endl;
//    
//    for (int i{}; i<10; i++){
//        ftrs.emplace_back(std::async(std::launch::async, &WaitingVehicles1::pushBack, queue, Vehicle1(i)));
//    }
//    
//    for (std::future<void> &ftr : ftrs) {
//        ftr.wait();
//      }
//
//    std::cout << "Collecting results..." << std::endl;
//    queue->printIDs();
//    
//
//    return 0;
//}
//int main() {
//    // create monitor object as a shared pointer to enable access by multiple threads
//    std::shared_ptr<WaitingVehicles1> queue{new WaitingVehicles1};
//    std::vector<std::future<void>> ftrs;
//    
//    std::cout << "Spawning threads..." << std::endl;
//    
//    for (int i{}; i<10; i++){
//        ftrs.emplace_back(std::async(std::launch::async, &WaitingVehicles1::pushBack, queue, Vehicle1(i)));
//    }
//    
//    std::cout << "Collecting results..." << std::endl;
//    
////    for (std::future<void> &ftr : ftrs) {
////        ftr.wait();
////      }
////
//    while(true){
//        if(queue->dataIsAvailable()){
//            Vehicle1 v{queue->popBack()};
//            std::cout << "Vehicle #" << v.getID() << " has been removed from the queue" << std::endl;
//        }else if(queue->len() <= 0){
//            std::this_thread::sleep_for(std::chrono::milliseconds(200));
////            break;
//        }
//    }
//    for (std::future<void> &ftr : ftrs) {
//        ftr.wait();
//      }
//    
//
//    std::cout << "Finished : " << queue->len()
//                << " vehicle(s) left in the queue" << std::endl;
//
//    return 0;
//}

//#include <future>
//#include <iostream>
//#include <mutex>
//#include <thread>
//#include <vector>
//
//class Vehicle1 {
//  public:
//    Vehicle1(int id):_id(id){};
//
//    int getID() {
//      return _id;
//    }
//
//  private:
//    int _id;
//};
//
//class WaitingVehicles1{
//public:
//    WaitingVehicles1(){}
//    
//    int len(){
//        std::lock_guard<std::mutex> lck(_mtx);
//        return _len;
//    }
//    
//    bool dataIsAvailable(){
//        std::lock_guard<std::mutex> lck(_mtx);
//        return !_vehicles.empty();
//    }
//    
//    Vehicle1 popBack(){
//        std::unique_lock<std::mutex> lck(_mtx);
//        _cond.wait(lck, [this]{
//            return !_vehicles.empty();
//        });
//        
//        Vehicle1 v = std::move(_vehicles.back());
//        _vehicles.pop_back();
//        
//        --_len;
//        
//        return v;
//    }
//    
//    
//    void printIDs(){
//        std::lock_guard<std::mutex> lck(_mtx); // lock is released when myLock goes out of scope
//        for (auto &v:_vehicles){
//            std::cout << "Vehicle #" << v.getID() << " is now waiting in the queue" << std::endl;
//        }
//    }
//    
//    void pushBack(Vehicle1 &&v){
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//        
//        std::lock_guard<std::mutex> lck(_mtx); // perform vector modification under the lock
//        std::cout << "Vehicle #" << v.getID() << " will be added to the queue" << std::endl;
//        _vehicles.emplace_back(std::move(v));
//       
//        ++_len;
//        _cond.notify_one(); // notify client after pushing new Vehicle into vector
//    }
//    
//private:
//    std::vector<Vehicle1> _vehicles;
//    std::mutex _mtx;
//    int _len;
//    std::condition_variable _cond;
//};
//
//int main() {
//    // create monitor object as a shared pointer to enable access by multiple threads
//    std::shared_ptr<WaitingVehicles1> queue{new WaitingVehicles1};
//    std::vector<std::future<void>> ftrs;
//    
//    std::cout << "Spawning threads..." << std::endl;
//    
//    for (int i{}; i<10; i++){
//        ftrs.emplace_back(std::async(std::launch::async, &WaitingVehicles1::pushBack, queue, Vehicle1(i)));
//    }
//    
//    std::cout << "Collecting results..." << std::endl;
//    
//    bool strt{true};
//    while(strt){
//        // popBack wakes up when a new element is available in the queue
//        if(queue->dataIsAvailable()){
//            Vehicle1 v{queue->popBack()};
//            std::cout << "Vehicle #" << v.getID() << " has been removed from the queue" << std::endl;
//        }
//    }
//    
//    for (std::future<void> &ftr : ftrs) {
//        ftr.wait();
//      }
//  
//
//    std::cout << "Finished : " << queue->len()
//                << " vehicle(s) left in the queue" << std::endl;
//
//    return 0;
//}

//#include <future>
//#include <iostream>
//#include <mutex>
//#include <queue>
//#include <thread>
//
//template <class T>
//class MessageQueue {
//  public:
//    T receive() {
//      // perform queue modification under the lock
//        std::unique_lock<std::mutex> lck{_mutex};
//        _cond.wait(lck, [this]{
//            return !_messages.empty();
//        });
//
//        T msg = std::move(_messages.back());
//        _messages.pop_back();
//      // remove last vector element from queue
//
//
//      return msg;  // will not be copied due to
//                   // return value optimization (RVO)
//                   // in C++
//    }
//
//    void send(T &&msg) {
//      // simulate some work
//      std::this_thread::sleep_for(std::chrono::milliseconds(100));
//
//
//        std::lock_guard<std::mutex> lck{_mutex};
//
//
//      std::cout << "   Message " << msg << " has been sent to the queue"
//                << std::endl;
//        _messages.push_back(msg);
//        _cond.notify_one();
//
//    }
//
//  private:
//    std::mutex _mutex;
//    std::condition_variable _cond;
//    std::deque<T> _messages;
//};
//
//int main() {
//  // create monitor object as a shared pointer to enable access by multiple
//  // threads
//  std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);
//
//  std::cout << "Spawning threads..." << std::endl;
//  std::vector<std::future<void>> futures;
//
//  for (int i = 0; i < 10; ++i) {
//
//    futures.emplace_back(std::async(std::launch::async,
//                                    &MessageQueue<int>::send, queue,
//                                    i));
//  }
//
//  std::cout << "Collecting results..." << std::endl;
//
//  while (true) {
//    int message = queue->receive();
//    std::cout << "   Message #" << message << " has been removed from the queue"
//              << std::endl;
//  }
//
//  // wait for the results
//  for (std::future<void> &ftr : futures) {
//    ftr.wait();
//  }
//
//  std::cout << "Finished!" << std::endl;
//
//  return 0;
//}
