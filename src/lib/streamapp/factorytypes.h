/******************************************************************************
 * Copyright (C) 2008  Tom Francart <tom.francart@med.kuleuven.be>            *
 *                                                                            *
 * This file is part of APEX 4.                                               *
 *                                                                            *
 * APEX 4 is free software: you can redistribute it and/or modify             *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 2 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * APEX 4 is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with APEX 4.  If not, see <http://www.gnu.org/licenses/>.            *
 *****************************************************************************/

#ifndef _APEX_SRC_LIB_STREAMAPP_FACTORYTYPES_H__
#define _APEX_SRC_LIB_STREAMAPP_FACTORYTYPES_H__

namespace streamapp
{

/**
  * Devictypes for soundcards
  */
enum gt_eDeviceType {
    NODEV, //!< TODO implement this for testing
    ASIO,  //!< SteinBerg ASIO; see www.steinberg.net/Steinberg/Developers.asp
           //! for the license !!!
    PORTAUDIO, //!< PortAudio
    JACK,      //!< Jack
    COREAUDIO, //!< OsX CoreAudio
    QTAUDIO,   //!< Qt Multimedia framework
    DUMMY      //!< Dummy soundcard
};
}

#endif //#ifndef _APEX_SRC_LIB_STREAMAPP_FACTORYTYPES_H__
