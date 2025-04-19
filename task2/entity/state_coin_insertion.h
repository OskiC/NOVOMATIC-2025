//
// Created by xoska on 19.04.2025.
//

#ifndef STATE_COIN_INSERTION_H
#define STATE_COIN_INSERTION_H

#include "machine_state.h"

namespace oc {

    class MachineStateCoinInsertion : public MachineState {
    public:
        void HandleInsertCoin() override;
        void HandleSelectTicket() override;
        void HandlePrintTicket() override;
        void HandleGiveChange() override;
        void HandleFinishAndReset() override;

    };

} // oc

#endif //STATE_COIN_INSERTION_H
