//
// Created by xoska on 19.04.2025.
//

#include "state_coin_insertion.h"

#include "machine_context.h"
#include "state_buy_ticket.h"

namespace oc {
    void MachineStateCoinInsertion::HandleInsertCoin() {
        std::cout << "==Coin insertion==\n";
        std::cout << "Enter coin you want to insert(example: 1, 3, 7)\n";
        std::cout << "If you want to buy ticket enter: 0\n";
        std::cout << "To go back enter: -1\n";

        int coin;
        while (true) {
            std::cout << "Balance: " << balance_ << "\n";
            std::cin >> coin;

            if (coin == -1) {
                context_->goBack();
                return;
            }

            if (coin == 0) {
                context_->TransitionTo(new MachineStateBuyTicket(balance_));
                return;
            }
            if (coin > 0) {
                balance_ += coin;
                Clear();
            } else {
                std::cout << "Wrong amount!\n";
            }
            std::cout << "If you want to buy ticket enter: 0\n";
            std::cout << "To go back enter: -1\n\n";
        }
    }

    void MachineStateCoinInsertion::HandleSelectTicket() {}


    void MachineStateCoinInsertion::HandlePrintTicket() {}

    void MachineStateCoinInsertion::HandleGiveChange() {}

    void MachineStateCoinInsertion::HandleFinishAndReset() {}

    int MachineStateCoinInsertion::get_balance() const {
        return this->balance_;
    }

} // oc