//
//  thread2.cpp
//  traffic_simulation
//
//  Created by Илья Валеев on 21.06.2023.
//

//#include <stdio.h>
//#include <iostream>
//#include <thread>
//#include <string>
//
//
//void printID(int id) {
//  std::this_thread::sleep_for(std::chrono::milliseconds(50));
//  std::cout << "ID = " << id << std::endl;
//}
//
//void printIDAndName(int id, std::string name) {
//  std::this_thread::sleep_for(std::chrono::milliseconds(100));
//  std::cout << "ID = " << id << ", name = " << name << std::endl;
//}
//
//
//int main() {
//
//    int id{};
//    std::thread t1{printID, id};
//    std::thread t2(printIDAndName, ++id, "name");
//
//
//    // std::thread t3(printIDAndName, ++id);  // this procudes a compiler error
//    t1.join();
//    t2.join();
//
//    return 0;
//}

//void printName(int waitTime, std::string name) {
//  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
//  std::cout << "name = " << name << std::endl;
//}
//
//
//int main() {
//    
//    
//    std::string s1{"n1"};
//    std::string s2{"n2"};
//    
//    std::thread t{printName, 100, s1};
//    std::thread t1{printName, 100, std::move(s2)};
//    
//    t.join();
//    t1.join();
//    std::cout << "Name (from Main) = " << s1 << std::endl;
//    std::cout << "Name (from Main) = " << s2 << std::endl;
//    
//    return 0;
//}


//void printName(int waitTime, std::string &name) {
//    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
//    name += " (from Thread)";
//    std::cout << name << std::endl;
//}
//
//
//int main() {
//
//
//    std::string s1{"n1"};
//
//    std::thread t1{printName, 100, std::ref(s1)};
//    std::thread t1{printName, 100, s1}; //fail to compile
//
//    t1.join();
//
//    std::cout << s1 << std::endl;
//    return 0;
//}

//class Vehicl_{
//    int id_;
//public:
//    Vehicl_():id_(0){};
//    void printId(){
//        std::cout << id_ << std::endl;
//    }
//    void addId(int id){
//        id_ = id;
//    }
//};
//
//
//
//int main() {
//
//    Vehicl_ v1, v2;
//
//    std::thread t1{&Vehicl_::addId, v1, 10}; // v1 stay the same
//
//    std::thread t2{&Vehicl_::addId, &v2, 20}; // v2 has been changed
//
//    t1.join();
//    t2.join();
//
//    v1.printId();
//    v2.printId();
//
//    return 0;
//}
//int main() {
//    
//    std::shared_ptr<Vehicl_> v_ptr{new Vehicl_};
//    
//    std::thread t{&Vehicl_::addId, v_ptr, 2};
//    
//    t.join();
//    
//    v_ptr->printId();
//    return 0;
//}
//class Vehicl_ {
//  public:
//    Vehicl_() {};
//    void addID(int id) {
//      _id = id;
//    }
//    void setName(std::string name){_name = name;}
//    void printID() {
//      std::cout << "Vehicle ID = " << _id << std::endl;
//    }
//    void printName() {
//      std::cout << "Vehicle Name = " << _name << std::endl;
//      }
//    // TODO: Modify the Vehicle class as indicated in the instructions:
//    /*
//      Change the code from the previous example in a way that a new member _name
//      variable of type std::string is added to the Vehicle class. Then, define a
//      function setName which takes a string as an argument and assigns this to _name.
//      The function setName needs to be started as a thread from main. Also, add a
//      function printName to the Vehicle class which is used at the end of main to
//      print the name to the console.
//    */
//   private:
//    int _id{};
//    std::string _name{};
//};



//int main() {
//
//    std::shared_ptr<Vehicl_> v_ptr{new Vehicl_};
//
//    std::thread t{&Vehicl_::addID, v_ptr, 2};
//    std::thread t1{&Vehicl_::setName, v_ptr, "some name"};
//
//
//
//    t.join();
//    t1.join();
//    v_ptr->printID();
//    v_ptr->printName();
//    return 0;
//}

//void printHello() {
//    std::cout << "Hello from Worker thread #"
//              << std::this_thread::get_id()
//              << std::endl;
//  }
//
//
//
//  int main() {
//      
//      std::vector<std::thread> cont;
//      
//      for (int i{}; i<5; i++){
//          std::thread t{printHello};
//          cont.emplace_back(std::move(t)); // copying thread objects causes a compile error
//      }
//      std::cout << "Hello from Main thread #"
//                 << std::this_thread::get_id()
//                 << std::endl;
//      
//      for (auto &t:cont)
//          t.join();
//      
//      return 0;
//  }



//int main() {
//
//    std::vector<std::thread> cont;
//
//    for (int i{}; i<5; i++){
//        cont.emplace_back([i](){
//            std::this_thread::sleep_for(std::chrono::milliseconds(10 * i));
//            std::cout << "Hello from Worker thread #" << i << std::endl;
//        });
//    }
//
//    std::cout << "Hello from Main thread" << std::endl;
//
//    for (auto &t:cont)
//        t.join();
//
//    return 0;
//}
