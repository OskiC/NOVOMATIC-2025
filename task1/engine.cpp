//
// Created by xoska on 23.04.2025.
//

#include "engine.h"

namespace oc {
    Engine::Engine(const std::string& filename) {
        if (load_from_file(filename)) {

        }
        else {
            isSaved = false;
        }
    }

    bool Engine::load_from_file(const std::string& filename) {
        std::fstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file!\n";
            return false;
        }

        std::string s;
        while (getline(file, s)) {
            queries_list[s]++;
        }
        file.close();
        return true;
    }

    void Engine::save_to_file(const std::string& filename) {
        std::fstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file!\n";
            return;
        }

        std::string s;
        for (const auto& [key, value] : queries_list) {
            s = key;
            for (int i = 0; i < value; i++) {
                file << s << "\n";
            }
        }
    }

    void Engine::addQuery(const std::string& query) {
        queries_list[query]++;
    }

    std::vector<std::string> Engine::ask(std::string asked_query) {
        std::vector<std::string> result;


        return result;
    }

    void Engine::choice_parser(const std::string& question) {
        if (question == "0") {
            exit(0);
        }

        if (question.starts_with("> add:")) {
            auto n = question.find(':');
            std::string query = question.substr(n + 2);
            addQuery(query);
        }

        if (question.starts_with("> ask:")) {
            auto n = question.find(':');
            std::string query = question.substr(n + 2);
            std::vector<std::string> results = ask(query);
            format_results(results);
        }

        else {
            std::cout << "Wrong command";
        }
    }

    void Engine::format_results(const std::vector<std::string>& results) {
        for (const auto& s : results) {
            std::cout << "result: " << s << "\n";
        }
    }


    [[noreturn]] void Engine::run() {
        std::string choice;
        while (true) {
            std::cout << "to add to list write: \"> add: QUERY\"\n";
            std::cout << "to get result write: \"> ask: QUERY\"\n";
            std::cout << "to leave write: \"0\"\n";

            std::getline(std::cin, choice);

            choice_parser(choice);
        }
    }

} // oc