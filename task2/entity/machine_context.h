//
// Created by xoska on 19.04.2025.
//

#ifndef MACHINE_CONTEXT_H
#define MACHINE_CONTEXT_H

#include "machine_state.h"
#include <stack>

namespace oc {

    class Context {
    private:
        MachineState* machineState_;
        std::stack<MachineState*> history_;

    public:
        explicit Context(MachineState* machineState);
        ~Context();

        void TransitionTo(MachineState* state);
        void goBack();

        void InsertCoin();
        void SelectTicket();
        void PrintTicket();
        void GiveChange();
        void FinishAndReset();

        std::stack<MachineState *>& getHistory(){
            return history_;
        }
        MachineState* getCurrentState() const {
            return machineState_;
        }

        void Shutdown();
    };


} // oc

#endif //MACHINE_CONTEXT_H
