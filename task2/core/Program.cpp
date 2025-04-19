//
// Created by xoska on 19.04.2025.
//

#include "Program.h"

#include "../entity/state_buy_ticket.h"
#include "../entity/state_give_change.h"
#include "../entity/state_print_ticket.h"
#include "../entity/state_ticket_printed.h"

namespace oc {
    void Program::run() {
        Context context(new MachineStateCoinInsertion());
        while (true) {
            if (dynamic_cast<MachineStateCoinInsertion*>(context.getCurrentState())) {
                context.InsertCoin();
            }
            else if (dynamic_cast<MachineStateBuyTicket*>(context.getCurrentState())) {
                context.SelectTicket();
            }
            else if (dynamic_cast<MachineStatePrintTicket*>(context.getCurrentState())) {
                context.PrintTicket();
            }
            else if (dynamic_cast<MachineStateGiveChange*>(context.getCurrentState())) {
                context.GiveChange();
            }
            else if (dynamic_cast<MachineStateTicketPrinted*>(context.getCurrentState())) {
                context.FinishAndReset();
            }
        }
    }

} // oc
