// [CFXS] //
#pragma once

namespace CFXS {

    namespace CNC::internal::G_Man {

        /// Return values of G_Man::ProcessCommandDataBlock
        enum class ParseStatus : int {
            OK,                  // Everything is good :)
            EMPTY_COMMAND,       // Command did not contain known parsing patterns
            QUEUE_FULL,          // Execution queue full
            UNSUPPORTED_COMMAND, // Unsupported G/M/WhateverElse command
            INVALID_PARAMETERS,  // Invalid command parameters
            _COUNT,
        };

    } // namespace CNC::internal::G_Man

    static const char* ToString(CNC::internal::G_Man::ParseStatus parserStatus) {
        using CNC::internal::G_Man::ParseStatus;
        static constexpr char* PARSE_STATUS_TO_STRING[] = {
            "OK",
            "Empty Command",
            "Queue Full",
            "Unsupported Command",
            "Invalid Parameters",
        };

        if ((int)parserStatus < (int)ParseStatus::_COUNT) {
            return PARSE_STATUS_TO_STRING[(int)parserStatus];
        } else {
            return "???";
        }
    }

} // namespace CFXS