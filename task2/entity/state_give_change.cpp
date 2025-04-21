//
// Created by xoska on 19.04.2025.
//

#include "state_give_change.h"

namespace oc {

    void MachineStateGiveChange::HandleInsertCoin(){}
    void MachineStateGiveChange::HandleSelectTicket() {}
    void MachineStateGiveChange::HandlePrintTicket() {}
    void MachineStateGiveChange::HandleFinishAndReset() {}

    MachineStateGiveChange::MachineStateGiveChange(int balance) {
        this->balance_ = balance;
    }


    void MachineStateGiveChange::HandleGiveChange() {
        int change[3] = {0, 0, 0}; // index 0 - 5, 1 - 2, 3 - 1

        int temp = 0;
        if (balance_ >= 5) {
            temp = balance_ / 5;
            balance_ -= temp * 5;
            change[0] = temp;
        }
        if (balance_ >= 2) {
            temp = balance_ / 2;
            balance_ -= temp * 2;
            change[1] = temp;
        }
        if (balance_ >= 1) {
            change[2] = 1;
            balance_ = 0;
        }

        Clear();
        std::cout << "Take change:\n";
        std::cout << change[0] << "*5zl\n";
        std::cout << change[1] << "*2zl\n";
        std::cout << change[2] << "*1zl\n";
        context_->TransitionTo(new MachineStateTicketPrinted());
    }
} // oc