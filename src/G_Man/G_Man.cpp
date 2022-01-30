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
#include <CFXS/CNC/G_Man.hpp>
#include <CFXS/Base/Debug.hpp>

#define IS_SPACE(x) (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0)

namespace CFXS::CNC {

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    G_Man::G_Man() {
        CFXS_printf("Initialize G-Code Processor [0x%p]\n", this);
    }

    G_Man::~G_Man() {
        CFXS_printf("Delete G-Code Processor [0x%p]\n", this);
    }

    /// Get line number of the current data stream
    __always_inline int G_Man::GetCurrentLineNumber() const {
        return m_CurrentLineNumber;
    }

    ///////////////////////////////////////////////////////////////////////
    // Parser

    /// Process null terminated G-Code command.
    /// Push fully decoded command to execution queue.
    /// \param cmd Single G-Code command (multiple commans on a single line will cause a parsing error)
    /// \param len(optional) Length of cmd if known (strlen is used if len == -1)
    /// \returns Status of parser after taking this data block
    G_Man::ParseResult G_Man::ProcessCommand(const char* cmd, int len) {
        if (len == -1)
            len = strlen(cmd);

        int readPos   = 0;                               // Index of currently processed char
        m_ParserState = ParserState::READ_COMMAND_CLASS; // First step is to find what kind of command this is (G/M/...)

        CFXS_printf("[G_Man] Process line: \"%s\"\n", cmd);

        while (readPos < len) {
            char c = cmd[readPos];

            if (IS_SPACE(c)) {
                readPos++;
                continue;
            } else {
                if (c == 'G') {
                    return ProcessCommand_G(cmd + readPos, len - readPos);
                } else if (c == 'M') {
                    return ProcessCommand_M(cmd + readPos, len - readPos);
                } else if (c == 'N') {
                    return ProcessCommand_N(cmd + readPos, len - readPos);
                } else if (c == 'O') {
                    return ProcessCommand_O(cmd + readPos, len - readPos);
                } else {
                    return ParseResult::UNKNOWN_COMMAND;
                }
                readPos++;
            }
        }

        return ParseResult::EMPTY_COMMAND;
    }

    G_Man::ParseResult G_Man::ProcessCommand_G(const char* cmd, int len) {
        return ParseResult::INVALID_ARGUMENTS;
    }

    // End = M02 or M30
    G_Man::ParseResult G_Man::ProcessCommand_M(const char* cmd, int len) {
        return ParseResult::INVALID_ARGUMENTS;
    }

    G_Man::ParseResult G_Man::ProcessCommand_N(const char* cmd, int len) {
        return ParseResult::INVALID_ARGUMENTS;
    }

    G_Man::ParseResult G_Man::ProcessCommand_O(const char* cmd, int len) {
        return ParseResult::INVALID_ARGUMENTS;
    }

} // namespace CFXS::CNC