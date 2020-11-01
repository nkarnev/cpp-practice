#include <cxxopts.hpp>


/*
options.add_options()
  ("d,debug", "Enable debugging") // a bool parameter
  ("i,integer", "Int param", cxxopts::value<int>())
  ("f,file", "File name", cxxopts::value<std::string>())
  ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
  ;

/**/

int main(int argc, char** argv) {
    cxxopts::Options options("Test", "A brief description");

    options.add_options()
        ("b, bar", "Param bar", cxxopts::value<std::string>())
        ("d, debug", "Enable debugging")
        ("h,help", "Print usage");
    auto args = options.parse(argc, argv);

    if (args.count("help")) {
      std::cout << options.help() << std::endl;
      exit(0);
    }
    std::string bar;
    if (args.count("bar"))
        bar = args["bar"].as<std::string>();
    
    std::cout << "Arg bar:  " << bar << std::endl;

    bool debug;
    if (args.count("debug"))
        debug = args["debug"].as<bool>();
        
    if (debug)
        std::cout << "Debug: " << debug <<std::endl;
    else {
        std::cout << "No Debug" << std::endl;
    }


    return 0; 
}