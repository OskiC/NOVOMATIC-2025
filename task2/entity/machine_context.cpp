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
        while (!history_.empty()) {
            delete history_.top();
            history_.pop();
        }
    }

    void Context::TransitionTo(MachineState* state) {
        if (machineState_) {
            history_.push(machineState_);
        }
        machineState_ = state;
        machineState_->setContext(this);
    }

    void Context::goBack() {
        if (history_.empty()) {
            std::cout << "Returning coins...\n";
            delete machineState_;
            machineState_ = nullptr;
            return;
        }

        delete machineState_;
        machineState_ = history_.top();
        history_.pop();
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

    void Context::Shutdown() {
        delete machineState_;
        machineState_ = nullptr;

        while (!history_.empty()) {
            delete history_.top();
            history_.pop();
        }
    }
    void Context::ReplaceCurrentState(MachineState* state) {
        if (machineState_) {
            delete machineState_;
        }
        machineState_ = state;
        machineState_->setContext(this);
    }

} // oc