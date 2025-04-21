//
// Created by xoska on 19.04.2025.
//

#ifndef MACHINESTATE_H
#define MACHINESTATE_H

#include <iostream>

namespace oc {
    class Context;

    class MachineState {
    protected:
        Context* context_ = nullptr;

    public:
        virtual ~MachineState() = default;

        void setContext(Context* context) {
            context_ = context;
        }

        virtual void HandleInsertCoin() = 0;
        virtual void HandleSelectTicket() = 0;
        virtual void HandlePrintTicket() = 0;
        virtual void HandleGiveChange() = 0;
        virtual void HandleFinishAndReset() = 0;
    };

} // oc

#endif //MACHINESTATE_H
