//
// Created by xoska on 19.04.2025.
//

#ifndef MACHINE_CONTEXT_H
#define MACHINE_CONTEXT_H

#include "machine_state.h"

namespace oc {

    class Context {
    private:
        MachineState* machineState_;

    public:
        explicit Context(MachineState* machineState);
        ~Context();

        void TransitionTo(MachineState* state);

        void InsertCoin();
        void SelectTicket();
        void PrintTicket();
        void GiveChange();
        void FinishAndReset();
    };


} // oc

#endif //MACHINE_CONTEXT_H
