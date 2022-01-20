// [CFXS] //
#pragma once
#include "G_Man/G_Man_Errors.hpp"
#include "G_Man/G_Man_Parser.hpp"

namespace CFXS::CNC {

    class G_Man {
        using ParserState = internal::G_Man::ParserState;

    public:
        using ParseStatus = internal::G_Man::ParseStatus;

    public:
        G_Man();
        ~G_Man();

        /// Process null terminated G-Code command.
        /// Push fully decoded command to execution queue.
        /// \param cmd Single G-Code command (multiple commans on a single line will cause a parsing error)
        /// \param len(optional) Length of cmd if known (strlen is used if len == -1)
        /// \returns Status of parser after taking this data block
        ParseStatus ProcessCommand(const char* cmd, int len = -1);

        /// Get line number of the current data stream
        int GetCurrentLineNumber() const;

    private:
        ParserState m_ParserState;    // Parser StateMachine main state
        ParserState m_ParserSubState; // Parser StateMachine sub state
        int m_CurrentLineNumber = -1; // Line number of current data stream (-1 = no line number available)
    };

} // namespace CFXS::CNC