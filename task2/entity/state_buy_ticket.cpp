//
// Created by xoska on 19.04.2025.
//

#include "state_buy_ticket.h"

namespace oc {
    MachineStateBuyTicket::MachineStateBuyTicket(int balance) {
        this->balance_ = balance;
    }


    void MachineStateBuyTicket::HandleInsertCoin() {}

    void MachineStateBuyTicket::HandleSelectTicket() {

    }


    void MachineStateBuyTicket::HandlePrintTicket() {}

    void MachineStateBuyTicket::HandleGiveChange() {}

    void MachineStateBuyTicket::HandleFinishAndReset() {}
} // oc