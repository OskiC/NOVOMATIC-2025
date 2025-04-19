//
// Created by xoska on 19.04.2025.
//

#include "state_buy_ticket.h"

#include "machine_context.h"
#include "state_print_ticket.h"
#include "state_ticket_printed.h"

namespace oc {
    MachineStateBuyTicket::MachineStateBuyTicket(int balance) {
        this->balance_ = balance;
    }


    void MachineStateBuyTicket::HandleInsertCoin() {}

    void MachineStateBuyTicket::HandleSelectTicket() {
        std::cout << "==Ticket selection==\n";
        std::cout << "Available tickets:\n";
        std::cout << "1. 3 PLN\n";
        std::cout << "2. 4 PLN\n";
        std::cout << "3. 8 PLN\n";
        std::cout << "4. 10 PLN\n";
        std::cout << "5. 15 PLN\n";
        std::cout << "To go back enter: -1\n\n";

        int choice;
        while (true) {
            std::cout << "Your balance: " << balance_ << " PLN\n";
            std::cout << "Select ticket (1-5): ";
            std::cin >> choice;

            if (choice == -1) {
                context_->goBack();
                return;
            }

            if (choice >= 1 && choice <= 5) {
                int prices[] = {3, 4, 8, 10, 15};
                int selectedPrice = prices[choice - 1];

                if (balance_ >= selectedPrice) {
                    balance_ -= selectedPrice;
                    Clear();
                    context_->TransitionTo(new MachineStatePrintTicket(balance_));
                    return;
                }
                std::cout << "Insufficient funds!\n";
            } else {
                std::cout << "Invalid choice!\n";
            }
        }
    }


    void MachineStateBuyTicket::HandlePrintTicket() {}

    void MachineStateBuyTicket::HandleGiveChange() {}

    void MachineStateBuyTicket::HandleFinishAndReset() {}
} // oc