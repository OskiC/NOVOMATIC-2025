//
// Created by xoska on 19.04.2025.
//

#ifndef STATE_TICKET_PRINTED_H
#define STATE_TICKET_PRINTED_H

#include "machine_state.h"

namespace oc {

    class MachineStateTicketPrinted : public MachineState {
        void HandleInsertCoin() override;
        void HandleSelectTicket() override;
        void HandlePrintTicket() override;
        void HandleGiveChange() override;
        void HandleFinishAndReset() override;
    };

} // oc

#endif //STATE_TICKET_PRINTED_H
