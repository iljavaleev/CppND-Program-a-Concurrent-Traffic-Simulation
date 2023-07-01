//#include <mutex>
//
//double res;
//std::mutex _mutex;
//
//void print_res(int denom){
//    std::cout << "for denom = " << denom << ", the result is " << res << std::endl;
//}
//
//void divide(double num, double denum){
//    std::lock_guard<std::mutex> lck(_mutex);
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
//int main() {
//    std::vector<std::future<void>> futures;
//
//    for (double i{-5}; i <= 5; ++i) {
//        futures.emplace_back(
//            std::async(std::launch::async, divide, 50.0, i));
//      }
//
//      // wait for the results
//      for (std::future<void> &ftr : futures) {
//        ftr.wait();
//      }
//
//  return 0;
//}
//#include <mutex>
//
//double res;
//std::mutex _mutex;
//
//void print_res(int denom){
//    std::cout << "for denom = " << denom << ", the result is " << res << std::endl;
//}
//
//void divide(double num, double denum){
//    std::unique_lock<std::mutex> lck(_mutex);
//    try{
//        if(denum == 0)
//            throw std::invalid_argument("Exception from thread: Division by zero!");
//
//        res = num/denum;
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//        print_res(denum);
//        lck.unlock();
//
//        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // do something outside of the lock
//
//        lck.lock();
//        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // do someting else under the lock
//
//    }catch (std::invalid_argument &e){
//        std::cout << e.what() << std::endl;
//        return;
//    }
//
//}
//
//int main() {
//    std::vector<std::future<void>> futures;
//
//    for (double i{-5}; i <= 5; ++i) {
//        futures.emplace_back(
//            std::async(std::launch::async, divide, 50.0, i));
//      }
//
//      // wait for the results
//      for (std::future<void> &ftr : futures) {
//        ftr.wait();
//      }
//
//  return 0;
//}
//#include <mutex>
//
//std::mutex m1, m2;
//
//void threadA(){
//    // Creates deadlock problem
//    std::lock_guard<std::mutex> l2(m2);
//    std::cout << "Thread A" << std::endl;
//    std::lock_guard<std::mutex> l1(m1);
//}
//
//void threadB(){
//    // Creates deadlock problem
//    std::lock_guard<std::mutex> l1(m1);
//    std::cout << "Thread A" << std::endl;
//    std::lock_guard<std::mutex> l2(m2);
//}
//
//void ExecuteThreads(){
//    std::thread t1(threadA);
//    std::thread t2(threadB);
//    
//    t1.join();
//    t2.join();
//    
//    std::cout << "Finished" << std::endl;
//    
//}
//
//
//
//int main() {
//    ExecuteThreads();
//    
//    return 0;
//}

//#include <mutex>
//
//std::mutex m1, m2;
//
//void threadA(){
//    // Ensure that locks are always executed in the same order
//    std::lock(m1, m2);
//    std::lock_guard<std::mutex> l2(m2, std::adopt_lock);
//    std::cout << "Thread A" << std::endl;
//    std::lock_guard<std::mutex> l1(m1, std::adopt_lock);
//}
//
//void threadB(){
//    // Creates deadlock problem
//    std::lock(m1, m2);
//    std::lock_guard<std::mutex> l1(m1, std::adopt_lock);
//    std::cout << "Thread A" << std::endl;
//    std::lock_guard<std::mutex> l2(m2, std::adopt_lock);
//}
//
//void ExecuteThreads(){
//    std::thread t1(threadA);
//    std::thread t2(threadB);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Finished" << std::endl;
//
//}
//
//
//
//int main() {
//    ExecuteThreads();
//
//    return 0;
//}
