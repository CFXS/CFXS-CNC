// [CFXS] //
#pragma once
#include "G_Man/G_Man_Errors.hpp"
#include "G_Man/G_Man_Parser.hpp"

namespace CFXS::CNC {

    // TODO(CFXS-CNC): ProcessCommandDataBlock -> ProcessCommandDataLine (easier parsing, no need for block processing)
    // TODO(CFXS-CNC): Get last parse error enum/string
    class G_Man {
        using ParserState = internal::G_Man::ParserState;

    public:
        using ParseStatus = internal::G_Man::ParseStatus;

    public:
        G_Man();
        ~G_Man();

        /// Process terminated or non-terminated block off G-Code data.
        /// Push fully decoded commands to execution queue.
        /// \param charBlock block of chars to parse.
        /// \param len length of charBlock.
        /// \returns Status of parser after taking this data block
        ParseStatus ProcessCommandDataBlock(const char* charBlock, size_t len);

        /// Get line number of the current data stream
        int GetCurrentLineNumber() const;

    private:
        ParserState m_ParserState;    // Parser StateMachine main state
        ParserState m_ParserSubState; // Parser StateMachine sub state
        int m_CurrentLineNumber = -1; // Line number of current data stream (-1 = no line number available)
    };

} // namespace CFXS::CNC