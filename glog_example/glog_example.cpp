#include "glog/logging.h"

int main(int argc, char* argv[]) {
    int num_cookies = 15;
    google::InitGoogleLogging(argv[0]); 


    LOG(ERROR) << "Found " << num_cookies << " cookies"; 


}