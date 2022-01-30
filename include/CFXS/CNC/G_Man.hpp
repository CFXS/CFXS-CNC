// ---------------------------------------------------------------------
// CFXS Framework CNC Module <https://github.com/CFXS/CFXS-CNC>
// Copyright (C) 2022 | CFXS / Rihards Veips
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
// ---------------------------------------------------------------------
// [CFXS] //
#pragma once
#include "G_Man/G_Man_Errors.hpp"
#include "G_Man/G_Man_Parser.hpp"

namespace CFXS::CNC {

    class G_Man {
        using ParserState = internal::G_Man::ParserState;

    public:
        using ParseResult = internal::G_Man::ParseResult;

    public:
        G_Man();
        ~G_Man();

        /// Process null terminated G-Code command.
        /// Push fully decoded command to execution queue.
        /// \param cmd Single G-Code command (multiple commans on a single line will cause a parsing error)
        /// \param len(optional) Length of cmd if known (strlen is used if len == -1)
        /// \returns Status of parser after taking this data block
        ParseResult ProcessCommand(const char* cmd, int len = -1);

        /// Get line number of the current data stream
        int GetCurrentLineNumber() const;

    private:
        ParseResult ProcessCommand_G(const char* cmd, int len);
        ParseResult ProcessCommand_M(const char* cmd, int len);
        ParseResult ProcessCommand_N(const char* cmd, int len);
        ParseResult ProcessCommand_O(const char* cmd, int len);

    private:
        ParserState m_ParserState;    // Parser StateMachine main state
        ParserState m_ParserSubState; // Parser StateMachine sub state
        int m_CurrentLineNumber = -1; // Line number of current data stream (-1 = no line number available)
    };

} // namespace CFXS::CNC