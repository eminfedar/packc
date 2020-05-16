#include "ProjectBuilder.hpp"
#include <fstream>
#include "json.hpp"
#include <string>
#include <iostream>

using json = nlohmann::json;

ProjectBuilder::ProjectBuilder(/* args */) {
    std::ifstream packcFile("./packc.json");
    json j;
    packcFile >> j;
    for (auto i : j["commands"].items()) {
        jsonData.insert(std::pair<std::string, std::string>(i.key(), i.value()));
        // std::cout << i.key() << " " << std::endl;
    }
    packcFile.close();
}

void ProjectBuilder::runCommands(std::string argument) {
    std::multimap<std::string, std::string>::iterator itr;

    for (itr = jsonData.begin(); itr != jsonData.end(); ++itr) {
        std::string command = itr->second;
        if (itr->first == argument) {
            // std::cout << itr->first << "\t" << command;
            system(command.c_str());
        }
    }
}

ProjectBuilder::~ProjectBuilder() {
    delete this;
}