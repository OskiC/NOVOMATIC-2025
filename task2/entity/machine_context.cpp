//
// Created by xoska on 19.04.2025.
//

#include "machine_context.h"

namespace oc {
    Context::Context(MachineState* machineState) : machineState_(nullptr) {
        TransitionTo(machineState);
    }

    Context::~Context() {
        delete machineState_;
    }

    void Context::TransitionTo(MachineState* state) {
        if (machineState_) {
            delete machineState_;
        }
        machineState_ = state;
        machineState_->setContext(this);
    }

    void Context::InsertCoin() {
        machineState_->HandleInsertCoin();
    }

    void Context::SelectTicket() {
        machineState_->HandleSelectTicket();
    }

    void Context::PrintTicket() {
        machineState_->HandlePrintTicket();
    }

    void Context::GiveChange() {
        machineState_->HandleGiveChange();
    }

    void Context::FinishAndReset() {
        machineState_->HandleFinishAndReset();
    }
} // oc