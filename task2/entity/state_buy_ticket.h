//
// Created by xoska on 19.04.2025.
//

#ifndef STATE_BUY_TICKET_H
#define STATE_BUY_TICKET_H

#include "machine_state.h"

namespace oc {

    class MachineStateBuyTicket : public MachineState {
    private:
        int balance_;

    public:
        explicit MachineStateBuyTicket(int balance);

        void HandleInsertCoin() override;
        void HandleSelectTicket() override;
        void HandlePrintTicket() override;
        void HandleGiveChange() override;
        void HandleFinishAndReset() override;
    };

} // oc

#endif //STATE_BUY_TICKET_H
