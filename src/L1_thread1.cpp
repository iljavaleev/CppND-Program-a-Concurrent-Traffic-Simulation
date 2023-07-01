//#include <iostream>
//#include <thread>
//
//class Vehicle1{
//private:
//    int id_{};
//public:
//    Vehicle1(int id):id_(id){};
//    void operator()() {
//      std::cout << "Vehicle object has been created\n";
//    }
//
//};
//
//int main() {
//  // create thread
//  // std::thread t0(Vehicle()); // C++'s most vexing parse
//
//  std::thread t1((Vehicle1(1)));  // Add an extra pair of parantheses
//
//  std::thread t2 = std::thread(Vehicle1(12));  // Use copy initialization
//
//   std::thread t3{Vehicle1(13)};  // Use uniform initialization with braces
//
//  // do something in main()
//  std::cout << "Finished work in main\n";
//
//  // wait for thread to finish
//  t1.join();
//  t2.join();
//   t3.join();
//
//  return 0;
//}


// lambdas

//int main() {
//    int id{33};
//    
//    int id2{77};
//    
//    auto f1 = [id, id2](){
//        id = 666; // error when by copying
//        std::cout << id << std::endl;
//        std::cout << id2 << std::endl;
//    };
//    
//    f1();
//    std::cout << id << std::endl;
//    
//    
//    id = 44;
//    
//    f1();
//    std::cout << std::endl;
//    auto f2 = [id, id2]() mutable{
//        id = 999;
//        std::cout << id << std::endl;
//        std::cout << id2 << std::endl;
//    };
//        
//    f2();
//    std::cout << id << std::endl;
//    
//    
//    return 0;
//}


//int main() {
//    auto f1 = [](int const i){
//        std::cout << i << std::endl;
//    };
//    f1(33);
//    return 0;
//}

//int main() {
//    int id{};
//    
//    auto f1 = [&id](){
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        std::cout << "a) ID in Thread (call-by-reference) = " << id << std::endl;
//    };
//    
//    std::thread t{f1};
//    
//    std::thread t1{
//        [id]() mutable {
//            std::this_thread::sleep_for(std::chrono::seconds(2));
//            std::cout << "b) ID in Thread (call-by-value) = " << id << std::endl;
//        }
//    };
//    
//    id++;
//    std::cout << "c) ID in Main (call-by-value) = " << id << std::endl;
//
//    t.join();
//    t1.join();
//    
//    return 0;
//}
//int main() {
//    int id = 0;  // Define an integer variable
//
//      // capture by reference (immutable)
//    auto f1 = [&id](){
//        std::cout << "a) ID in Lambda = " << id << std::endl;
//    };
//
//      // capture by value (mutable)
//    auto f2 = [id]() mutable{
//        std::cout << "b) ID in Lambda = " << ++id << std::endl;
//    };
//
//    f2(); // call the closure and execute the code witin the Lambda
//    std::cout << "c) ID in Main = " << id << std::endl;
//
//      // capture by reference (mutable)
//    auto f3 = [&id](){
//        std::cout << "d) ID in Lambda = " << ++id << std::endl;
//    };
//
//    auto f4 = [](int const id){
//        std::cout << "f) ID in Lambda = " << id << std::endl;
//    };
//      // pass parameter
//    f4(++id);
//      // observe the effect of capturing by reference at an earlier point in time
//
//    f1();
//    return 0;
//}
