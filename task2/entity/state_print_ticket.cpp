//
// Created by xoska on 19.04.2025.
//

#include "state_print_ticket.h"

#include "machine_context.h"
#include "state_give_change.h"

namespace oc {
    MachineStatePrintTicket::MachineStatePrintTicket(int balance) {
        this->balance_ = balance;
    }


    void MachineStatePrintTicket::HandleInsertCoin() {}

    void MachineStatePrintTicket::HandleSelectTicket() {}


    void MachineStatePrintTicket::HandlePrintTicket() {
        std::cout << "BRRRRR*BRRRR*\n";
        std::cout << "Take ticket!\n";
        context_->TransitionTo(new MachineStateGiveChange(balance_));
    }

    void MachineStatePrintTicket::HandleGiveChange() {}

    void MachineStatePrintTicket::HandleFinishAndReset() {}
} // oc