//
// Created by xoska on 23.04.2025.
//

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>

namespace oc {

    class Engine {
    private:
        std::unordered_map<std::string, int> queries_list;
        bool isSaved;

        void addQuery(const std::string& query);
        std::vector<std::string> ask(std::string asked_query);

        bool load_from_file(const std::string& filename);
        void save_to_file(const std::string& filename);

        void choice_parser(const std::string& question);
        static void format_results(const std::vector<std::string>& results);
    public:
        Engine(const std::string& filename);
        void run();
    };

} // oc

#endif //ENGINE_H
