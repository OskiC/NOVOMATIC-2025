//
// Created by xoska on 19.04.2025.
//

#ifndef STATE_COIN_INSERTION_H
#define STATE_COIN_INSERTION_H

#include <iostream>
#include "machine_state.h"
#include "../helper/clear.h"

namespace oc {

    class MachineStateCoinInsertion : public MachineState {
    private:
        int balance_ = 0;
    public:
        void HandleInsertCoin() override;
        void HandleSelectTicket() override;
        void HandlePrintTicket() override;
        void HandleGiveChange() override;
        void HandleFinishAndReset() override;

        int get_balance() const;
    };

} // oc

#endif //STATE_COIN_INSERTION_H
