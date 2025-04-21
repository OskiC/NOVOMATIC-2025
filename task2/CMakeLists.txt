cmake_minimum_required(VERSION 3.28)
project(task2)

set(CMAKE_CXX_STANDARD 17)

add_executable(task2 main.cpp
        core/Program.cpp
        core/Program.h
        entity/machine_state.h
        entity/machine_context.cpp
        entity/machine_context.h
        entity/state_coin_insertion.cpp
        entity/state_coin_insertion.h
        entity/state_buy_ticket.cpp
        entity/state_buy_ticket.h
        entity/state_print_ticket.cpp
        entity/state_print_ticket.h
        entity/state_give_change.cpp
        entity/state_give_change.h
        entity/state_ticket_printed.cpp
        entity/state_ticket_printed.h
        helper/clear.h
        entity/exit_override.cpp
        entity/exit_override.h)