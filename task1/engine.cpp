//
// Created by xoska on 23.04.2025.
//

#include "engine.h"

namespace oc {
    Engine::Engine(const std::string& filename){
        this->filename = filename;
        load_from_file(filename);
    }

    bool Engine::load_from_file(const std::string& filename) {
        std::ifstream file(filename);
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

    void Engine::save_to_file() {
        std::ofstream file(this->filename);
        if (!file.is_open()) {
            std::cout << "Error opening file!\n";
            return;
        }

        for (const auto& [key, value] : queries_list) {
            for (int i = 0; i < value; i++) {
                file << key << "\n";
            }
        }
        file.close();
    }

    void Engine::addQuery(const std::string& query) {
        queries_list[query]++;
    }

    std::vector<std::string> Engine::ask(const std::string& asked_query) {
        std::vector<std::string> result;
        std::vector<std::pair<std::string, int>> pair_results;

        for (const auto& [key, value] : queries_list) {
            if (key.starts_with(asked_query)) {
                pair_results.emplace_back(key, value);
            }
        }

        std::ranges::sort(pair_results,
                          [](auto a, auto b) {
                              return a.second > b.second;
                          });

        for (const auto& [query, _] : pair_results) {
            result.push_back(query);
        }

        return result;
    }

    void Engine::choice_parser(const std::string& question) {
        if (question == "0") {
            save_to_file();
            exit(0);
        }

        if (question.starts_with("> add:")) {
            auto n = question.find(':');
            std::string query = question.substr(n + 2);
            addQuery(query);
        }
        else if (question.starts_with("> ask:")) {
            auto n = question.find(':');
            std::string query = question.substr(n + 2);
            std::vector<std::string> results = ask(query);
            format_results(results);
        }
        else {
            std::cout << "Wrong command\n";
        }
    }

    void Engine::format_results(const std::vector<std::string>& results) {
        for (const auto& s : results) {
            std::cout << "result: " << s << "\n";
        }
    }


    [[noreturn]] void Engine::run() {
        std::cout << "Welcome back in 1997! :D\n";

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