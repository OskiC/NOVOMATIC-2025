//
// Created by xoska on 19.04.2025.
//

#ifndef STATE_GIVE_CHANGE_H
#define STATE_GIVE_CHANGE_H

#include "machine_state.h"
#include "../helper/clear.h"
#include "machine_context.h"
#include "state_ticket_printed.h"

namespace oc {

    class MachineStateGiveChange : public MachineState {
    private:
        int balance_;

    public:
        explicit MachineStateGiveChange(int balance);

        void HandleInsertCoin() override;
        void HandleSelectTicket() override;
        void HandlePrintTicket() override;
        void HandleGiveChange() override;
        void HandleFinishAndReset() override;
    };

} // oc

#endif //STATE_GIVE_CHANGE_H
