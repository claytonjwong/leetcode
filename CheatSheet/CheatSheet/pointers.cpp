//
//  pointers.cpp
//  CheatSheet
//
//  Created by CLAYTON WONG on 5/13/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <memory>

using namespace std;

template<typename T>
void sink(unique_ptr<T> releaseMe) {}

int main(int argc, const char * argv[]) {
    
    unique_ptr<int> up{new int(13)};
    int* p=up.get();    // p points towards the address owned by up
    sink(move(up));     // sink releases the memory pointed towards by up

    return 0;
}
