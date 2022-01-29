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