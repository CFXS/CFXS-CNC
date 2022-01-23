// [CFXS] //
#pragma once

namespace CFXS {

    namespace CNC::internal::G_Man {

        /// Return values of G_Man::ProcessCommandDataBlock
        enum class ParseResult : int {
            OK,                // Everything is good :)
            EMPTY_COMMAND,     // Command did not contain known parsing patterns
            QUEUE_FULL,        // Execution queue full
            UNKNOWN_COMMAND,   // Unknown !G/!M/... command
            INVALID_ARGUMENTS, // Invalid command parameters
            _COUNT,
        };

    } // namespace CNC::internal::G_Man

    static const char* ToString(CNC::internal::G_Man::ParseResult parserStatus) {
        using CNC::internal::G_Man::ParseResult;
        static constexpr char* PARSE_RESULT_TO_STRING[] = {
            "OK",
            "Empty Command",
            "Queue Full",
            "Unknown Command",
            "Invalid Arguments",
        };

        if ((int)parserStatus < (int)ParseResult::_COUNT) {
            return PARSE_RESULT_TO_STRING[(int)parserStatus];
        } else {
            return "???";
        }
    }

} // namespace CFXS