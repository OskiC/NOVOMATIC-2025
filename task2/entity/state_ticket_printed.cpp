//
// Created by xoska on 19.04.2025.
//

#include "state_ticket_printed.h"

namespace oc {
    void MachineStateTicketPrinted::HandleInsertCoin() {}

    void MachineStateTicketPrinted::HandleSelectTicket() {}

    void MachineStateTicketPrinted::HandlePrintTicket() {}

    void MachineStateTicketPrinted::HandleGiveChange() {}

    void MachineStateTicketPrinted::ResetToInitialState(Context* context) {
        while (!context->getHistory().empty()) {
            delete context->getHistory().top();
            context->getHistory().pop();
        }

        context->ReplaceCurrentState(new MachineStateCoinInsertion());
    }

    void MachineStateTicketPrinted::HandleFinishAndReset() {
        std::cout << "Thank you for buying ticket in Krakow public trasnport!\n";
        std::cout << "Have a good day! :)\n";
        std::cout << "Enter any key to continue\n";

        if (std::cin.peek() == '\n') {
            std::cin.ignore();
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::string choice;
        std::getline(std::cin, choice);
        ResetToInitialState(context_);

        context_->InsertCoin();

    }
} // oc