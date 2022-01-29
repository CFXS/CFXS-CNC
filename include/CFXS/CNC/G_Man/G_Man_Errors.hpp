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