// [CFXS] //
#pragma once

namespace CFXS::CNC::internal::G_Man {

    enum class ParserState {
        IDLE,               // Ready for data processing
        ERROR,              // Something bad happened
        READ_COMMAND_CLASS, // Find char that starts a command (G/M/F/...)
        READ_WORD,          // Find word char (X/Y/Z/A/B/...)
        READ_INTEGER_VALUE, // Read integer
        READ_FLOAT_VALUE,   // Read float
    };

}