//
// Created by xoska on 19.04.2025.
//

#include "state_coin_insertion.h"

#include "exit_override.h"


namespace oc {
    void MachineStateCoinInsertion::HandleInsertCoin() {

        int coin;
        while (true) {
            std::cout << "==Coin insertion==\n";
            std::cout << "Enter coin you want to insert(example: 1, 3, 8)\n";
            std::cout << "If you want to buy ticket enter: 0\n";
            std::cout << "To go back enter: -1\n";
            std::cout << "To exit the bus(if you don't want to buy ticket), enter -2!\n";
            std::cout << "Balance: " << balance_ << "\n";

            if (!(std::cin >> coin)) {
                Clear();
                std::cout << "INVALID INPUT!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (coin == -2) {
                std::cout << "Returning coins...\n";
                std::cout << "Leaving the bus....\n";
                context_->Shutdown();
                ExitProgram(0);
            }
            if (coin == -1) {
                Clear();
                balance_ = 0;

                continue;
            }

            if (coin == 0) {
                if (balance_ == 0) {
                    std::cout << "Please insert some coins first\n";
                    continue;
                }
                Clear();
                context_->TransitionTo(new MachineStateBuyTicket(balance_));
                return;
            }
            if (coin > 0) {
                balance_ += coin;
                Clear();
            } else {
                Clear();
                std::cout << "Wrong amount!\n";
            }
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