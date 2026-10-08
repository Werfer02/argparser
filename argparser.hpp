#pragma once

#include <vector>
#include <unordered_map>
#include <string>

namespace argparser {
    struct Args {
        std::unordered_map<std::string, std::string> singleDashArgs;
        std::vector<std::string> doubleDashArgs;
        std::vector<std::string> noDashArgs;
    };

    Args parseArgv(int argc, char** argv){
        Args args;
        for(int i = 0; i < argc; i++){
            if(std::string(argv[i]).length() > 1){
                if (argv[i][0] == '-'){ 
                    if (argv[i][1] == '-'){ // --arg
                        std::string doubleDashArg = "";
                        for(int c = 2; argv[i][c] != 0; c++){
                            doubleDashArg += argv[i][c];
                        }
                        args.doubleDashArgs.push_back(doubleDashArg);
                    } else { // -a (single dash, single char, key value args)
                        std::string singleDashArgKey = "";
                        singleDashArgKey += argv[i][1];

                        if(std::string(argv[i]).length() > 2){ // consume rest of arg as value
                            std::string singleDashArgValue = "";
                            for(int c = 2; argv[i][c] != 0; c++){
                                singleDashArgValue += argv[i][c];
                            }
                            args.singleDashArgs[singleDashArgKey] = singleDashArgValue;
                        } else if(i < (argc - 1)){ // argv has another arg to use as value
                            i++;
                            std::string singleDashArgValue = "";
                            for(int c = 0; argv[i][c] != 0; c++){
                                singleDashArgValue += argv[i][c];
                            }
                            args.singleDashArgs[singleDashArgKey] = singleDashArgValue;
                        } else {
                            args.singleDashArgs[singleDashArgKey] = "";
                        }
                    }
                } else { // arg (no dashes)
                    args.noDashArgs.push_back(argv[i]);
                }
            }
        }
        return args;
    }
}
