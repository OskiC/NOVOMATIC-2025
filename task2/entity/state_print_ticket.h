//
// Created by xoska on 19.04.2025.
//

#ifndef STATE_PRINT_TICKET_H
#define STATE_PRINT_TICKET_H

#include "machine_state.h"

namespace oc {

    class MachineStatePrintTicket : public MachineState {
        void HandleInsertCoin() override;
        void HandleSelectTicket() override;
        void HandlePrintTicket() override;
        void HandleGiveChange() override;
        void HandleFinishAndReset() override;
    };

} // oc

#endif //STATE_PRINT_TICKET_H
