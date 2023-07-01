//
//  L2_promises.cpp
//  traffic_simulation
//
//  Created by Илья Валеев on 25.06.2023.
//


//#include <iostream>
//#include <thread>
//
//void printMessage(std::string message){
//    std::this_thread::sleep_for(std::chrono::milliseconds(10));
//    std::cout << "Thread 1: " << message << std::endl;
//}
//
//int main(){
//    std::string m{"Message"};
//    
//    std::thread t1(printMessage, m);
//    
//    std::thread t2([m](){
//        std::this_thread::sleep_for(std::chrono::milliseconds(10));
//        std::cout << "Thread 2: " << m << std::endl;
//    });
//    
//    t1.join();
//    t2.join();
//    
//    return 0;
//}

//#include <iostream>
//#include <thread>
//#include <future>
//
//void modifiedMessage(std::promise<std::string> &&m, std::string message){
//    std::this_thread::sleep_for(std::chrono::milliseconds(10));
//    std::string newM{message + " has been modified"};
//    m.set_value(newM);
//}
//
//int main(){
//    std::string messageToThread{"Message"};
//
//    // create promise and future
//    std::promise<std::string> prms;
//    std::future<std::string> ftr{prms.get_future()};
//
//    // start thread and pass promise as argument
//    std::thread t(modifiedMessage, std::move(prms), messageToThread);
//
//
//    std::cout << "Original message from main(): "
//                << messageToThread
//                << std::endl;
//
//    std::string fMessage{ftr.get()};
//
//    std::cout << "From future message from main(): "
//                << fMessage
//                << std::endl;
//    t.join();
//
//    return 0;
//}

//#include <iostream>
//#include <thread>
//#include <future>
//#include <cmath>
//
//void modifiedMessage(std::promise<double> &&prms, double before){
//    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//    double after = sqrt(before);
//    prms.set_value(after);
//}
//
//int main(){
//    
//    double value_to{34};
//    
//    // create promise and future
//    std::promise<double> prms;
//    std::future<double> ftr{prms.get_future()};
//    
//    // start thread and pass promise as argument
//    std::thread t(modifiedMessage, std::move(prms), value_to);
//    
//    auto status = ftr.wait_for(std::chrono::milliseconds(3000));
//    
//    if(status == std::future_status::ready){
//        std::cout << ftr.get() << std::endl;
//    }else if (status == std::future_status::timeout || status == std::future_status::deferred){
//        std::cout << "Result unavailable" << std::endl;
//    }
//    
//    
//    t.join();
//    
//    return 0;
//}

//#include <iostream>
//#include <thread>
//#include <future>
//#include <cmath>
//#include <memory>
//
//void modifiedMessage(std::promise<double> &&prms, double before, double denom){
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//    try{
//        if (denom == 0){
//            throw std::runtime_error("Exception from thread: Division by zero!");
//        }else
//            prms.set_value(before/denom);
//
//    }catch (...){
//        prms.set_exception(std::current_exception());
//    }
//}
//
//int main(){
//
//    // create promise and future
//    std::promise<double> prms;
//    std::future<double> ftr{prms.get_future()};
//
//    double value_to{25}, denom{0};
//    // start thread and pass promise as argument
//    std::thread t(modifiedMessage, std::move(prms), value_to, denom);
//
//    try{
//        double res{ftr.get()};
//        std::cout << "Result = " << res << std::endl;
//    }catch (std::runtime_error e){
//        std::cout << e.what() << std::endl;
//    }
//    t.join();
//
//    return 0;
//}
