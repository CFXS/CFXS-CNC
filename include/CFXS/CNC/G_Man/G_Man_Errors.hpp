// [CFXS] //
#pragma once

namespace CFXS::CNC::internal::G_Man {

    /// Return values of G_Man::ProcessCommandDataBlock
    enum class ParseStatus {
        OK,                  // Everything is good :)
        BUFFER_FULL,         // Parser temp buffer is full
        QUEUE_FULL,          // Execution queue full
        UNSUPPORTED_COMMAND, // Unsupported G/M/WhateverElse command
        INVALID_PARAMETERS,  // Invalid command parameters
    };

} // namespace CFXS::CNC::internal::G_Man