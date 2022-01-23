// [CFXS] //
#pragma once

namespace CFXS {

    namespace CNC::internal::G_Man {

        enum class ParserState {
            IDLE,               // Ready for data processing
            ERROR,              // Something bad happened
            READ_COMMAND_CLASS, // Find char that starts a command (G/M/F/...)
            READ_WORD,          // Find word char (X/Y/Z/A/B/...)
            READ_NUMBER,        // Read number
            _COUNT,
        };

    }

    static const char* ToString(CNC::internal::G_Man::ParserState parserStatus) {
        using CNC::internal::G_Man::ParserState;
        static constexpr char* PARSE_STATE_TO_STRING[] = {
            "Idle",
            "Error",
            "Read Command Class",
            "Read Number",
        };

        if ((int)parserStatus < (int)ParserState::_COUNT) {
            return PARSE_STATE_TO_STRING[(int)parserStatus];
        } else {
            return "???";
        }
    }

} // namespace CFXS