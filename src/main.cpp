#include "App.h"

#include <iostream>

int main(){
    try{
        App::Init();
        App app;
        app.run();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    
    return EXIT_SUCCESS;
}