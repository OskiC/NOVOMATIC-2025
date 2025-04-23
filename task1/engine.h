//
// Created by xoska on 23.04.2025.
//

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <algorithm>

namespace oc {

    class Engine {
    private:
        std::unordered_map<std::string, int> queries_list;
        std::string filename;

        void addQuery(const std::string& query);
        std::vector<std::string> ask(const std::string& asked_query);

        void load_from_file(const std::string& filename);
        void save_to_file();

        void choice_parser(const std::string& question);
        static void format_results(const std::vector<std::string>& results);
    public:
        Engine(const std::string& filename);
        [[noreturn]] void run();
    };

} // oc

#endif //ENGINE_H
