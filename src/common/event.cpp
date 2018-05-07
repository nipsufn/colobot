/*
 * This file is part of the Colobot: Gold Edition source code
 * Copyright (C) 2001-2018, Daniel Roux, EPSITEC SA & TerranovaTeam
 * http://epsitec.ch; http://colobot.info; http://github.com/colobot
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://gnu.org/licenses
 */


#include "common/event.h"

#include "common/logger.h"

#include <boost/lexical_cast.hpp>

namespace
{
const char* EVENT_TYPE_TEXT[EVENT_STD_MAX];
}

EventType GetUniqueEventType()
{
    static EventType uniqueEventType = EVENT_USER;
    int nextUniqueEventType = static_cast<int>(uniqueEventType+1);
    uniqueEventType = static_cast<EventType>(nextUniqueEventType);
    return uniqueEventType;
}

void InitializeEventTypeTexts()
{
    for (int i = 0; i < EVENT_STD_MAX; ++i)
        EVENT_TYPE_TEXT[i] = "";

    EVENT_TYPE_TEXT[EVENT_NULL]              = "EVENT_NULL";

    EVENT_TYPE_TEXT[EVENT_QUIT]              = "EVENT_QUIT";

    EVENT_TYPE_TEXT[EVENT_FRAME]             = "EVENT_FRAME";

    EVENT_TYPE_TEXT[EVENT_MOUSE_BUTTON_DOWN] = "EVENT_MOUSE_BUTTON_DOWN";
    EVENT_TYPE_TEXT[EVENT_MOUSE_BUTTON_UP]   = "EVENT_MOUSE_BUTTON_UP";
    EVENT_TYPE_TEXT[EVENT_MOUSE_WHEEL]       = "EVENT_MOUSE_WHEEL";
    EVENT_TYPE_TEXT[EVENT_MOUSE_MOVE]        = "EVENT_MOUSE_MOVE";
    EVENT_TYPE_TEXT[EVENT_MOUSE_ENTER]       = "EVENT_MOUSE_ENTER";
    EVENT_TYPE_TEXT[EVENT_MOUSE_LEAVE]       = "EVENT_MOUSE_LEAVE";

    EVENT_TYPE_TEXT[EVENT_KEY_DOWN]          = "EVENT_KEY_DOWN";
    EVENT_TYPE_TEXT[EVENT_KEY_UP]            = "EVENT_KEY_UP";
    EVENT_TYPE_TEXT[EVENT_TEXT_INPUT]        = "EVENT_TEXT_INPUT";

    EVENT_TYPE_TEXT[EVENT_JOY_AXIS]          = "EVENT_JOY_AXIS";
    EVENT_TYPE_TEXT[EVENT_JOY_BUTTON_DOWN]   = "EVENT_JOY_BUTTON_DOWN";
    EVENT_TYPE_TEXT[EVENT_JOY_BUTTON_UP]     = "EVENT_JOY_BUTTON_UP";

    EVENT_TYPE_TEXT[EVENT_FOCUS_GAINED]      = "EVENT_FOCUS_GAINED";
    EVENT_TYPE_TEXT[EVENT_FOCUS_LOST]        = "EVENT_FOCUS_LOST";


    EVENT_TYPE_TEXT[EVENT_UPDINTERFACE]      = "EVENT_UPDINTERFACE";
    EVENT_TYPE_TEXT[EVENT_RESOLUTION_CHANGED]= "EVENT_RESOLUTION_CHANGED";
    EVENT_TYPE_TEXT[EVENT_RELOAD_TEXTURES]   = "EVENT_RELOAD_TEXTURES";
    EVENT_TYPE_TEXT[EVENT_WIN]               = "EVENT_WIN";
    EVENT_TYPE_TEXT[EVENT_LOST]              = "EVENT_LOST";

    EVENT_TYPE_TEXT[EVENT_FOCUS]             = "EVENT_FOCUS";

    EVENT_TYPE_TEXT[EVENT_BUTTON_OK]         = "EVENT_BUTTON_OK";
    EVENT_TYPE_TEXT[EVENT_BUTTON_CANCEL]     = "EVENT_BUTTON_CANCEL";
    EVENT_TYPE_TEXT[EVENT_BUTTON_NEXT]       = "EVENT_BUTTON_NEXT";
    EVENT_TYPE_TEXT[EVENT_BUTTON_PREV]       = "EVENT_BUTTON_PREV";

    EVENT_TYPE_TEXT[EVENT_BUTTON0]           = "EVENT_BUTTON0";
    EVENT_TYPE_TEXT[EVENT_BUTTON1]           = "EVENT_BUTTON1";
    EVENT_TYPE_TEXT[EVENT_BUTTON2]           = "EVENT_BUTTON2";
    EVENT_TYPE_TEXT[EVENT_BUTTON3]           = "EVENT_BUTTON3";
    EVENT_TYPE_TEXT[EVENT_BUTTON4]           = "EVENT_BUTTON4";
    EVENT_TYPE_TEXT[EVENT_BUTTON5]           = "EVENT_BUTTON5";
    EVENT_TYPE_TEXT[EVENT_BUTTON6]           = "EVENT_BUTTON6";
    EVENT_TYPE_TEXT[EVENT_BUTTON7]           = "EVENT_BUTTON7";
    EVENT_TYPE_TEXT[EVENT_BUTTON8]           = "EVENT_BUTTON8";
    EVENT_TYPE_TEXT[EVENT_BUTTON9]           = "EVENT_BUTTON9";
    EVENT_TYPE_TEXT[EVENT_BUTTON10]          = "EVENT_BUTTON10";
    EVENT_TYPE_TEXT[EVENT_BUTTON11]          = "EVENT_BUTTON11";
    EVENT_TYPE_TEXT[EVENT_BUTTON12]          = "EVENT_BUTTON12";
    EVENT_TYPE_TEXT[EVENT_BUTTON13]          = "EVENT_BUTTON13";
    EVENT_TYPE_TEXT[EVENT_BUTTON14]          = "EVENT_BUTTON14";
    EVENT_TYPE_TEXT[EVENT_BUTTON15]          = "EVENT_BUTTON15";
    EVENT_TYPE_TEXT[EVENT_BUTTON16]          = "EVENT_BUTTON16";
    EVENT_TYPE_TEXT[EVENT_BUTTON17]          = "EVENT_BUTTON17";
    EVENT_TYPE_TEXT[EVENT_BUTTON18]          = "EVENT_BUTTON18";
    EVENT_TYPE_TEXT[EVENT_BUTTON19]          = "EVENT_BUTTON19";

    EVENT_TYPE_TEXT[EVENT_EDIT0]             = "EVENT_EDIT0";
    EVENT_TYPE_TEXT[EVENT_EDIT1]             = "EVENT_EDIT1";
    EVENT_TYPE_TEXT[EVENT_EDIT2]             = "EVENT_EDIT2";
    EVENT_TYPE_TEXT[EVENT_EDIT3]             = "EVENT_EDIT3";
    EVENT_TYPE_TEXT[EVENT_EDIT4]             = "EVENT_EDIT4";
    EVENT_TYPE_TEXT[EVENT_EDIT5]             = "EVENT_EDIT5";
    EVENT_TYPE_TEXT[EVENT_EDIT6]             = "EVENT_EDIT6";
    EVENT_TYPE_TEXT[EVENT_EDIT7]             = "EVENT_EDIT7";
    EVENT_TYPE_TEXT[EVENT_EDIT8]             = "EVENT_EDIT8";
    EVENT_TYPE_TEXT[EVENT_EDIT9]             = "EVENT_EDIT9";

    EVENT_TYPE_TEXT[EVENT_WINDOW0]           = "EVENT_WINDOW0";
    EVENT_TYPE_TEXT[EVENT_WINDOW1]           = "EVENT_WINDOW1";
    EVENT_TYPE_TEXT[EVENT_WINDOW2]           = "EVENT_WINDOW2";
    EVENT_TYPE_TEXT[EVENT_WINDOW3]           = "EVENT_WINDOW3";
    EVENT_TYPE_TEXT[EVENT_WINDOW4]           = "EVENT_WINDOW4";
    EVENT_TYPE_TEXT[EVENT_WINDOW5]           = "EVENT_WINDOW5";
    EVENT_TYPE_TEXT[EVENT_WINDOW6]           = "EVENT_WINDOW6";
    EVENT_TYPE_TEXT[EVENT_WINDOW7]           = "EVENT_WINDOW7";
    EVENT_TYPE_TEXT[EVENT_WINDOW8]           = "EVENT_WINDOW8";
    EVENT_TYPE_TEXT[EVENT_WINDOW9]           = "EVENT_WINDOW9";

    EVENT_TYPE_TEXT[EVENT_LABEL0]            = "EVENT_LABEL0";
    EVENT_TYPE_TEXT[EVENT_LABEL1]            = "EVENT_LABEL1";
    EVENT_TYPE_TEXT[EVENT_LABEL2]            = "EVENT_LABEL2";
    EVENT_TYPE_TEXT[EVENT_LABEL3]            = "EVENT_LABEL3";
    EVENT_TYPE_TEXT[EVENT_LABEL4]            = "EVENT_LABEL4";
    EVENT_TYPE_TEXT[EVENT_LABEL5]            = "EVENT_LABEL5";
    EVENT_TYPE_TEXT[EVENT_LABEL6]            = "EVENT_LABEL6";
    EVENT_TYPE_TEXT[EVENT_LABEL7]            = "EVENT_LABEL7";
    EVENT_TYPE_TEXT[EVENT_LABEL8]            = "EVENT_LABEL8";
    EVENT_TYPE_TEXT[EVENT_LABEL9]            = "EVENT_LABEL9";
    EVENT_TYPE_TEXT[EVENT_LABEL10]           = "EVENT_LABEL10";
    EVENT_TYPE_TEXT[EVENT_LABEL11]           = "EVENT_LABEL11";
    EVENT_TYPE_TEXT[EVENT_LABEL12]           = "EVENT_LABEL12";
    EVENT_TYPE_TEXT[EVENT_LABEL13]           = "EVENT_LABEL13";
    EVENT_TYPE_TEXT[EVENT_LABEL14]           = "EVENT_LABEL14";
    EVENT_TYPE_TEXT[EVENT_LABEL15]           = "EVENT_LABEL15";
    EVENT_TYPE_TEXT[EVENT_LABEL16]           = "EVENT_LABEL16";
    EVENT_TYPE_TEXT[EVENT_LABEL17]           = "EVENT_LABEL17";
    EVENT_TYPE_TEXT[EVENT_LABEL18]           = "EVENT_LABEL18";
    EVENT_TYPE_TEXT[EVENT_LABEL19]           = "EVENT_LABEL19";

    EVENT_TYPE_TEXT[EVENT_LIST0]             = "EVENT_LIST0";
    EVENT_TYPE_TEXT[EVENT_LIST1]             = "EVENT_LIST1";
    EVENT_TYPE_TEXT[EVENT_LIST2]             = "EVENT_LIST2";
    EVENT_TYPE_TEXT[EVENT_LIST3]             = "EVENT_LIST3";
    EVENT_TYPE_TEXT[EVENT_LIST4]             = "EVENT_LIST4";
    EVENT_TYPE_TEXT[EVENT_LIST5]             = "EVENT_LIST5";
    EVENT_TYPE_TEXT[EVENT_LIST6]             = "EVENT_LIST6";
    EVENT_TYPE_TEXT[EVENT_LIST7]             = "EVENT_LIST7";
    EVENT_TYPE_TEXT[EVENT_LIST8]             = "EVENT_LIST8";
    EVENT_TYPE_TEXT[EVENT_LIST9]             = "EVENT_LIST9";

    EVENT_TYPE_TEXT[EVENT_LOADING]           = "EVENT_LOADING";

    EVENT_TYPE_TEXT[EVENT_TOOLTIP]           = "EVENT_TOOLTIP";

    EVENT_TYPE_TEXT[EVENT_DIALOG_OK]         = "EVENT_DIALOG_OK";
    EVENT_TYPE_TEXT[EVENT_DIALOG_CANCEL]     = "EVENT_DIALOG_CANCEL";
    EVENT_TYPE_TEXT[EVENT_DIALOG_LABEL]      = "EVENT_DIALOG_LABEL";
    EVENT_TYPE_TEXT[EVENT_DIALOG_LABEL1]     = "EVENT_DIALOG_LABEL1";
    EVENT_TYPE_TEXT[EVENT_DIALOG_LABEL2]     = "EVENT_DIALOG_LABEL2";
    EVENT_TYPE_TEXT[EVENT_DIALOG_LABEL3]     = "EVENT_DIALOG_LABEL3";
    EVENT_TYPE_TEXT[EVENT_DIALOG_LIST]       = "EVENT_DIALOG_LIST";
    EVENT_TYPE_TEXT[EVENT_DIALOG_EDIT]       = "EVENT_DIALOG_EDIT";
    EVENT_TYPE_TEXT[EVENT_DIALOG_CHECK1]     = "EVENT_DIALOG_CHECK1";
    EVENT_TYPE_TEXT[EVENT_DIALOG_CHECK2]     = "EVENT_DIALOG_CHECK2";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_TRAINER] = "EVENT_INTERFACE_TRAINER";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_DEFI]    = "EVENT_INTERFACE_DEFI";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_MISSION] = "EVENT_INTERFACE_MISSION";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_FREE]    = "EVENT_INTERFACE_FREE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_CODE_BATTLES] = "EVENT_INTERFACE_CODE_BATTLES";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_NAME]    = "EVENT_INTERFACE_NAME";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SETUP]   = "EVENT_INTERFACE_SETUP";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_QUIT]    = "EVENT_INTERFACE_QUIT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_BACK]    = "EVENT_INTERFACE_BACK";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_AGAIN]   = "EVENT_INTERFACE_AGAIN";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_WRITE]   = "EVENT_INTERFACE_WRITE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_READ]    = "EVENT_INTERFACE_READ";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_ABORT]   = "EVENT_INTERFACE_ABORT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_USER]    = "EVENT_INTERFACE_USER";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SATCOM]  = "EVENT_INTERFACE_SATCOM";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_CHAP]    = "EVENT_INTERFACE_CHAP";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_LIST]    = "EVENT_INTERFACE_LIST";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_RESUME]  = "EVENT_INTERFACE_RESUME";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PLAY]    = "EVENT_INTERFACE_PLAY";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_SETUPd]  = "EVENT_INTERFACE_SETUPd";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SETUPg]  = "EVENT_INTERFACE_SETUPg";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SETUPp]  = "EVENT_INTERFACE_SETUPp";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SETUPc]  = "EVENT_INTERFACE_SETUPc";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SETUPs]  = "EVENT_INTERFACE_SETUPs";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_DEVICE]  = "EVENT_INTERFACE_DEVICE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_RESOL]   = "EVENT_INTERFACE_RESOL";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_FULL]    = "EVENT_INTERFACE_FULL";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_APPLY]   = "EVENT_INTERFACE_APPLY";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_DIRTY]   = "EVENT_INTERFACE_DIRTY";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_LIGHT]   = "EVENT_INTERFACE_LIGHT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PARTI]   = "EVENT_INTERFACE_PARTI";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_CLIP]    = "EVENT_INTERFACE_CLIP";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_RAIN]    = "EVENT_INTERFACE_RAIN";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_GLINT]   = "EVENT_INTERFACE_GLINT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_TOOLTIP] = "EVENT_INTERFACE_TOOLTIP";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_MOVIES]  = "EVENT_INTERFACE_MOVIES";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SCROLL]  = "EVENT_INTERFACE_SCROLL";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_INVERTX] = "EVENT_INTERFACE_INVERTX";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_INVERTY] = "EVENT_INTERFACE_INVERTY";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_EFFECT]  = "EVENT_INTERFACE_EFFECT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_BGPAUSE] = "EVENT_INTERFACE_BGPAUSE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_FOG]     = "EVENT_INTERFACE_FOG";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_EDITMODE]= "EVENT_INTERFACE_EDITMODE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_EDITVALUE]= "EVENT_INTERFACE_EDITVALUE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SOLUCE4] = "EVENT_INTERFACE_SOLUCE4";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_BLOOD]   = "EVENT_INTERFACE_BLOOD";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_AUTOSAVE_ENABLE]    = "EVENT_INTERFACE_AUTOSAVE_ENABLE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_AUTOSAVE_INTERVAL]  = "EVENT_INTERFACE_AUTOSAVE_INTERVAL";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_AUTOSAVE_SLOTS]     = "EVENT_INTERFACE_AUTOSAVE_SLOTS";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_TEXTURE_FILTER]     = "EVENT_INTERFACE_TEXTURE_FILTER";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_TEXTURE_MIPMAP]     = "EVENT_INTERFACE_TEXTURE_MIPMAP";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_TEXTURE_ANISOTROPY] = "EVENT_INTERFACE_TEXTURE_ANISOTROPY";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_MSAA]               = "EVENT_INTERFACE_MSAA";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SHADOW_SPOTS]       = "EVENT_INTERFACE_SHADOW_SPOTS";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SHADOW_MAPPING]     = "EVENT_INTERFACE_SHADOW_MAPPING";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SHADOW_MAPPING_QUALITY]     = "EVENT_INTERFACE_SHADOW_MAPPING_QUALITY";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SHADOW_MAPPING_BUFFER]      = "EVENT_INTERFACE_SHADOW_MAPPING_BUFFER";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_LANGUAGE] = "EVENT_INTERFACE_LANGUAGE";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_KINFO1]  = "EVENT_INTERFACE_KINFO1";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_KINFO2]  = "EVENT_INTERFACE_KINFO2";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_KGROUP]  = "EVENT_INTERFACE_KGROUP";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_KSCROLL] = "EVENT_INTERFACE_KSCROLL";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_KDEF]    = "EVENT_INTERFACE_KDEF";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_VOLSOUND]= "EVENT_INTERFACE_VOLSOUND";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_VOLMUSIC]= "EVENT_INTERFACE_VOLMUSIC";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_MIN]     = "EVENT_INTERFACE_MIN";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_NORM]    = "EVENT_INTERFACE_NORM";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_MAX]     = "EVENT_INTERFACE_MAX";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_SILENT]  = "EVENT_INTERFACE_SILENT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_NOISY]   = "EVENT_INTERFACE_NOISY";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK]= "EVENT_INTERFACE_JOYSTICK";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_SOLUCE]  = "EVENT_INTERFACE_SOLUCE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_DEADZONE]= "EVENT_INTERFACE_JOYSTICK_DEADZONE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_X]= "EVENT_INTERFACE_JOYSTICK_X";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_Y]= "EVENT_INTERFACE_JOYSTICK_Y";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_Z]= "EVENT_INTERFACE_JOYSTICK_Z";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_CAM_X]= "EVENT_INTERFACE_JOYSTICK_CAM_X";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_CAM_Y]= "EVENT_INTERFACE_JOYSTICK_CAM_Y";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_CAM_Z]= "EVENT_INTERFACE_JOYSTICK_CAM_Z";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_X_INVERT]= "EVENT_INTERFACE_JOYSTICK_X_INVERT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_Y_INVERT]= "EVENT_INTERFACE_JOYSTICK_Y_INVERT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_Z_INVERT]= "EVENT_INTERFACE_JOYSTICK_Z_INVERT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_CAM_X_INVERT]= "EVENT_INTERFACE_JOYSTICK_CAM_X_INVERT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_CAM_Y_INVERT]= "EVENT_INTERFACE_JOYSTICK_CAM_Y_INVERT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_JOYSTICK_CAM_Z_INVERT]= "EVENT_INTERFACE_JOYSTICK_CAM_Z_INVERT";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_GLINTl]  = "EVENT_INTERFACE_GLINTl";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_GLINTr]  = "EVENT_INTERFACE_GLINTr";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_GLINTu]  = "EVENT_INTERFACE_GLINTu";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_GLINTb]  = "EVENT_INTERFACE_GLINTb";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_NEDIT]   = "EVENT_INTERFACE_NEDIT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_NLIST]   = "EVENT_INTERFACE_NLIST";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_NOK]     = "EVENT_INTERFACE_NOK";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_NDELETE] = "EVENT_INTERFACE_NDELETE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_NLABEL]  = "EVENT_INTERFACE_NLABEL";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_IOWRITE] = "EVENT_INTERFACE_IOWRITE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_IOREAD]  = "EVENT_INTERFACE_IOREAD";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_IOLIST]  = "EVENT_INTERFACE_IOLIST";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_IONAME]  = "EVENT_INTERFACE_IONAME";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_IOLABEL] = "EVENT_INTERFACE_IOLABEL";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_IOIMAGE] = "EVENT_INTERFACE_IOIMAGE";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_IODELETE]= "EVENT_INTERFACE_IODELETE";

    EVENT_TYPE_TEXT[EVENT_INTERFACE_PERSO]   = "EVENT_INTERFACE_PERSO";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_POK]     = "EVENT_INTERFACE_POK";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PCANCEL] = "EVENT_INTERFACE_PCANCEL";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PDEF]    = "EVENT_INTERFACE_PDEF";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PHEAD]   = "EVENT_INTERFACE_PHEAD";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PBODY]   = "EVENT_INTERFACE_PBODY";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PLROT]   = "EVENT_INTERFACE_PLROT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PRROT]   = "EVENT_INTERFACE_PRROT";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC0a]    = "EVENT_INTERFACE_PC0a";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC1a]    = "EVENT_INTERFACE_PC1a";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC2a]    = "EVENT_INTERFACE_PC2a";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC3a]    = "EVENT_INTERFACE_PC3a";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC4a]    = "EVENT_INTERFACE_PC4a";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC5a]    = "EVENT_INTERFACE_PC5a";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC6a]    = "EVENT_INTERFACE_PC6a";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC7a]    = "EVENT_INTERFACE_PC7a";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC8a]    = "EVENT_INTERFACE_PC8a";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC9a]    = "EVENT_INTERFACE_PC9a";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PCRa]    = "EVENT_INTERFACE_PCRa";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PCGa]    = "EVENT_INTERFACE_PCGa";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PCBa]    = "EVENT_INTERFACE_PCBa";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC0b]    = "EVENT_INTERFACE_PC0b";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC1b]    = "EVENT_INTERFACE_PC1b";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC2b]    = "EVENT_INTERFACE_PC2b";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC3b]    = "EVENT_INTERFACE_PC3b";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC4b]    = "EVENT_INTERFACE_PC4b";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC5b]    = "EVENT_INTERFACE_PC5b";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC6b]    = "EVENT_INTERFACE_PC6b";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC7b]    = "EVENT_INTERFACE_PC7b";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC8b]    = "EVENT_INTERFACE_PC8b";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PC9b]    = "EVENT_INTERFACE_PC9b";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PCRb]    = "EVENT_INTERFACE_PCRb";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PCGb]    = "EVENT_INTERFACE_PCGb";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PCBb]    = "EVENT_INTERFACE_PCBb";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PFACE1]  = "EVENT_INTERFACE_PFACE1";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PFACE2]  = "EVENT_INTERFACE_PFACE2";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PFACE3]  = "EVENT_INTERFACE_PFACE3";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PFACE4]  = "EVENT_INTERFACE_PFACE4";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PGLASS0] = "EVENT_INTERFACE_PGLASS0";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PGLASS1] = "EVENT_INTERFACE_PGLASS1";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PGLASS2] = "EVENT_INTERFACE_PGLASS2";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PGLASS3] = "EVENT_INTERFACE_PGLASS3";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PGLASS4] = "EVENT_INTERFACE_PGLASS4";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PGLASS5] = "EVENT_INTERFACE_PGLASS5";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PGLASS6] = "EVENT_INTERFACE_PGLASS6";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PGLASS7] = "EVENT_INTERFACE_PGLASS7";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PGLASS8] = "EVENT_INTERFACE_PGLASS8";
    EVENT_TYPE_TEXT[EVENT_INTERFACE_PGLASS9] = "EVENT_INTERFACE_PGLASS9";

    EVENT_TYPE_TEXT[EVENT_DT_GROUP0]         = "EVENT_DT_GROUP0";
    EVENT_TYPE_TEXT[EVENT_DT_GROUP1]         = "EVENT_DT_GROUP1";
    EVENT_TYPE_TEXT[EVENT_DT_GROUP2]         = "EVENT_DT_GROUP2";
    EVENT_TYPE_TEXT[EVENT_DT_GROUP3]         = "EVENT_DT_GROUP3";
    EVENT_TYPE_TEXT[EVENT_DT_GROUP4]         = "EVENT_DT_GROUP4";
    EVENT_TYPE_TEXT[EVENT_DT_LABEL0]         = "EVENT_DT_LABEL0";
    EVENT_TYPE_TEXT[EVENT_DT_LABEL1]         = "EVENT_DT_LABEL1";
    EVENT_TYPE_TEXT[EVENT_DT_LABEL2]         = "EVENT_DT_LABEL2";
    EVENT_TYPE_TEXT[EVENT_DT_LABEL3]         = "EVENT_DT_LABEL3";
    EVENT_TYPE_TEXT[EVENT_DT_LABEL4]         = "EVENT_DT_LABEL4";
    EVENT_TYPE_TEXT[EVENT_DT_VISIT0]         = "EVENT_DT_VISIT0";
    EVENT_TYPE_TEXT[EVENT_DT_VISIT1]         = "EVENT_DT_VISIT1";
    EVENT_TYPE_TEXT[EVENT_DT_VISIT2]         = "EVENT_DT_VISIT2";
    EVENT_TYPE_TEXT[EVENT_DT_VISIT3]         = "EVENT_DT_VISIT3";
    EVENT_TYPE_TEXT[EVENT_DT_VISIT4]         = "EVENT_DT_VISIT4";
    EVENT_TYPE_TEXT[EVENT_DT_END]            = "EVENT_DT_END";

    EVENT_TYPE_TEXT[EVENT_CMD]               = "EVENT_CMD";
    EVENT_TYPE_TEXT[EVENT_SPEED]             = "EVENT_SPEED";

    EVENT_TYPE_TEXT[EVENT_HYPER_PREV]        = "EVENT_HYPER_PREV";
    EVENT_TYPE_TEXT[EVENT_HYPER_NEXT]        = "EVENT_HYPER_NEXT";
    EVENT_TYPE_TEXT[EVENT_HYPER_HOME]        = "EVENT_HYPER_HOME";
    EVENT_TYPE_TEXT[EVENT_HYPER_COPY]        = "EVENT_HYPER_COPY";
    EVENT_TYPE_TEXT[EVENT_HYPER_SIZE1]       = "EVENT_HYPER_SIZE1";
    EVENT_TYPE_TEXT[EVENT_HYPER_SIZE2]       = "EVENT_HYPER_SIZE2";
    EVENT_TYPE_TEXT[EVENT_HYPER_SIZE3]       = "EVENT_HYPER_SIZE3";
    EVENT_TYPE_TEXT[EVENT_HYPER_SIZE4]       = "EVENT_HYPER_SIZE4";
    EVENT_TYPE_TEXT[EVENT_HYPER_SIZE5]       = "EVENT_HYPER_SIZE5";

    EVENT_TYPE_TEXT[EVENT_SATCOM_HUSTON]     = "EVENT_SATCOM_HUSTON";
    EVENT_TYPE_TEXT[EVENT_SATCOM_SAT]        = "EVENT_SATCOM_SAT";
    EVENT_TYPE_TEXT[EVENT_SATCOM_LOADING]    = "EVENT_SATCOM_LOADING";
    EVENT_TYPE_TEXT[EVENT_SATCOM_OBJECT]     = "EVENT_SATCOM_OBJECT";
    EVENT_TYPE_TEXT[EVENT_SATCOM_PROG]       = "EVENT_SATCOM_PROG";
    EVENT_TYPE_TEXT[EVENT_SATCOM_SOLUCE]     = "EVENT_SATCOM_SOLUCE";

    EVENT_TYPE_TEXT[EVENT_OBJECT_DESELECT]   = "EVENT_OBJECT_DESELECT";
    EVENT_TYPE_TEXT[EVENT_OBJECT_LEFT]       = "EVENT_OBJECT_LEFT";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RIGHT]      = "EVENT_OBJECT_RIGHT";
    EVENT_TYPE_TEXT[EVENT_OBJECT_UP]         = "EVENT_OBJECT_UP";
    EVENT_TYPE_TEXT[EVENT_OBJECT_DOWN]       = "EVENT_OBJECT_DOWN";
    EVENT_TYPE_TEXT[EVENT_OBJECT_GASUP]      = "EVENT_OBJECT_GASUP";
    EVENT_TYPE_TEXT[EVENT_OBJECT_GASDOWN]    = "EVENT_OBJECT_GASDOWN";
    EVENT_TYPE_TEXT[EVENT_OBJECT_HTAKE]      = "EVENT_OBJECT_HTAKE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_MTAKE]      = "EVENT_OBJECT_MTAKE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_MFRONT]     = "EVENT_OBJECT_MFRONT";
    EVENT_TYPE_TEXT[EVENT_OBJECT_MBACK]      = "EVENT_OBJECT_MBACK";
    EVENT_TYPE_TEXT[EVENT_OBJECT_MPOWER]     = "EVENT_OBJECT_MPOWER";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BHELP]      = "EVENT_OBJECT_BHELP";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BTAKEOFF]   = "EVENT_OBJECT_BTAKEOFF";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BDESTROY]   = "EVENT_OBJECT_BDESTROY";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BDERRICK]   = "EVENT_OBJECT_BDERRICK";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BSTATION]   = "EVENT_OBJECT_BSTATION";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BFACTORY]   = "EVENT_OBJECT_BFACTORY";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BCONVERT]   = "EVENT_OBJECT_BCONVERT";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BTOWER]     = "EVENT_OBJECT_BTOWER";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BREPAIR]    = "EVENT_OBJECT_BREPAIR";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BRESEARCH]  = "EVENT_OBJECT_BRESEARCH";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BRADAR]     = "EVENT_OBJECT_BRADAR";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BENERGY]    = "EVENT_OBJECT_BENERGY";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BLABO]      = "EVENT_OBJECT_BLABO";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BNUCLEAR]   = "EVENT_OBJECT_BNUCLEAR";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BPARA]      = "EVENT_OBJECT_BPARA";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BINFO]      = "EVENT_OBJECT_BINFO";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BDESTROYER] = "EVENT_OBJECT_BDESTROYER";
    EVENT_TYPE_TEXT[EVENT_OBJECT_GFLAT]      = "EVENT_OBJECT_GFLAT";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FCREATE]    = "EVENT_OBJECT_FCREATE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FDELETE]    = "EVENT_OBJECT_FDELETE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FCOLORb]    = "EVENT_OBJECT_FCOLORb";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FCOLORr]    = "EVENT_OBJECT_FCOLORr";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FCOLORg]    = "EVENT_OBJECT_FCOLORg";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FCOLORy]    = "EVENT_OBJECT_FCOLORy";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FCOLORv]    = "EVENT_OBJECT_FCOLORv";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYwa]  = "EVENT_OBJECT_FACTORYwa";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYta]  = "EVENT_OBJECT_FACTORYta";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYfa]  = "EVENT_OBJECT_FACTORYfa";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYia]  = "EVENT_OBJECT_FACTORYia";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYwc]  = "EVENT_OBJECT_FACTORYwc";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYtc]  = "EVENT_OBJECT_FACTORYtc";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYfc]  = "EVENT_OBJECT_FACTORYfc";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYic]  = "EVENT_OBJECT_FACTORYic";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYwi]  = "EVENT_OBJECT_FACTORYwi";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYti]  = "EVENT_OBJECT_FACTORYti";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYfi]  = "EVENT_OBJECT_FACTORYfi";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYii]  = "EVENT_OBJECT_FACTORYii";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYws]  = "EVENT_OBJECT_FACTORYws";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYts]  = "EVENT_OBJECT_FACTORYts";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYfs]  = "EVENT_OBJECT_FACTORYfs";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYis]  = "EVENT_OBJECT_FACTORYis";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYrt]  = "EVENT_OBJECT_FACTORYrt";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYrc]  = "EVENT_OBJECT_FACTORYrc";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYrr]  = "EVENT_OBJECT_FACTORYrr";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYrs]  = "EVENT_OBJECT_FACTORYrs";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FACTORYsa]  = "EVENT_OBJECT_FACTORYsa";
    EVENT_TYPE_TEXT[EVENT_OBJECT_SEARCH]     = "EVENT_OBJECT_SEARCH";
    EVENT_TYPE_TEXT[EVENT_OBJECT_TERRAFORM]  = "EVENT_OBJECT_TERRAFORM";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FIRE]       = "EVENT_OBJECT_FIRE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_FIREANT]    = "EVENT_OBJECT_FIREANT";
    EVENT_TYPE_TEXT[EVENT_OBJECT_SPIDEREXPLO]= "EVENT_OBJECT_SPIDEREXPLO";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RECOVER]    = "EVENT_OBJECT_RECOVER";
    EVENT_TYPE_TEXT[EVENT_OBJECT_BEGSHIELD]  = "EVENT_OBJECT_BEGSHIELD";
    EVENT_TYPE_TEXT[EVENT_OBJECT_ENDSHIELD]  = "EVENT_OBJECT_ENDSHIELD";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RTANK]      = "EVENT_OBJECT_RTANK";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RFLY]       = "EVENT_OBJECT_RFLY";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RTHUMP]     = "EVENT_OBJECT_RTHUMP";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RCANON]     = "EVENT_OBJECT_RCANON";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RTOWER]     = "EVENT_OBJECT_RTOWER";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RPHAZER]    = "EVENT_OBJECT_RPHAZER";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RSHIELD]    = "EVENT_OBJECT_RSHIELD";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RATOMIC]    = "EVENT_OBJECT_RATOMIC";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RiPAW]      = "EVENT_OBJECT_RiPAW";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RiGUN]      = "EVENT_OBJECT_RiGUN";
    EVENT_TYPE_TEXT[EVENT_OBJECT_RESET]      = "EVENT_OBJECT_RESET";
    EVENT_TYPE_TEXT[EVENT_OBJECT_DIMSHIELD]  = "EVENT_OBJECT_DIMSHIELD";
    EVENT_TYPE_TEXT[EVENT_OBJECT_TARGET]     = "EVENT_OBJECT_TARGET";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PROGLIST]   = "EVENT_OBJECT_PROGLIST";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PROGRUN]    = "EVENT_OBJECT_PROGRUN";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PROGEDIT]   = "EVENT_OBJECT_PROGEDIT";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PROGSTART]  = "EVENT_OBJECT_PROGSTART";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PROGSTOP]   = "EVENT_OBJECT_PROGSTOP";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PROGADD]    = "EVENT_OBJECT_PROGADD";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PROGCLONE]  = "EVENT_OBJECT_PROGCLONE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PROGREMOVE] = "EVENT_OBJECT_PROGREMOVE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PROGMOVEUP] = "EVENT_OBJECT_PROGMOVEUP";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PROGMOVEDOWN] = "EVENT_OBJECT_PROGMOVEDOWN";
    EVENT_TYPE_TEXT[EVENT_OBJECT_INFOOK]     = "EVENT_OBJECT_INFOOK";
    EVENT_TYPE_TEXT[EVENT_OBJECT_DELETE]     = "EVENT_OBJECT_DELETE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_GENERGY]    = "EVENT_OBJECT_GENERGY";
    EVENT_TYPE_TEXT[EVENT_OBJECT_GSHIELD]    = "EVENT_OBJECT_GSHIELD";
    EVENT_TYPE_TEXT[EVENT_OBJECT_GRANGE]     = "EVENT_OBJECT_GRANGE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_MAP]        = "EVENT_OBJECT_MAP";
    EVENT_TYPE_TEXT[EVENT_OBJECT_MAPZOOM]    = "EVENT_OBJECT_MAPZOOM";
    EVENT_TYPE_TEXT[EVENT_OBJECT_GPROGRESS]  = "EVENT_OBJECT_GPROGRESS";
    EVENT_TYPE_TEXT[EVENT_OBJECT_GRADAR]     = "EVENT_OBJECT_GRADAR";
    EVENT_TYPE_TEXT[EVENT_OBJECT_GINFO]      = "EVENT_OBJECT_GINFO";
    EVENT_TYPE_TEXT[EVENT_OBJECT_TYPE]       = "EVENT_OBJECT_TYPE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_CROSSHAIR]  = "EVENT_OBJECT_CROSSHAIR";
    EVENT_TYPE_TEXT[EVENT_OBJECT_CORNERul]   = "EVENT_OBJECT_CORNERul";
    EVENT_TYPE_TEXT[EVENT_OBJECT_CORNERur]   = "EVENT_OBJECT_CORNERur";
    EVENT_TYPE_TEXT[EVENT_OBJECT_CORNERdl]   = "EVENT_OBJECT_CORNERdl";
    EVENT_TYPE_TEXT[EVENT_OBJECT_CORNERdr]   = "EVENT_OBJECT_CORNERdr";
    EVENT_TYPE_TEXT[EVENT_OBJECT_MAPi]       = "EVENT_OBJECT_MAPi";
    EVENT_TYPE_TEXT[EVENT_OBJECT_MAPg]       = "EVENT_OBJECT_MAPg";
    EVENT_TYPE_TEXT[EVENT_OBJECT_CAMERA]     = "EVENT_OBJECT_CAMERA";
    EVENT_TYPE_TEXT[EVENT_OBJECT_HELP]       = "EVENT_OBJECT_HELP";
    EVENT_TYPE_TEXT[EVENT_OBJECT_SOLUCE]     = "EVENT_OBJECT_SOLUCE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_SHORTCUT_MODE] = "EVENT_OBJECT_SHORTCUT_MODE";
    EVENT_TYPE_TEXT[EVENT_OBJECT_MOVIELOCK]  = "EVENT_OBJECT_MOVIELOCK";
    EVENT_TYPE_TEXT[EVENT_OBJECT_EDITLOCK]   = "EVENT_OBJECT_EDITLOCK";
    EVENT_TYPE_TEXT[EVENT_OBJECT_SAVING]     = "EVENT_OBJECT_SAVING";
    EVENT_TYPE_TEXT[EVENT_OBJECT_LIMIT]      = "EVENT_OBJECT_LIMIT";

    EVENT_TYPE_TEXT[EVENT_OBJECT_PEN0]       = "EVENT_OBJECT_PEN0";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PEN1]       = "EVENT_OBJECT_PEN1";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PEN2]       = "EVENT_OBJECT_PEN2";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PEN3]       = "EVENT_OBJECT_PEN3";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PEN4]       = "EVENT_OBJECT_PEN4";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PEN5]       = "EVENT_OBJECT_PEN5";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PEN6]       = "EVENT_OBJECT_PEN6";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PEN7]       = "EVENT_OBJECT_PEN7";
    EVENT_TYPE_TEXT[EVENT_OBJECT_PEN8]       = "EVENT_OBJECT_PEN8";
    EVENT_TYPE_TEXT[EVENT_OBJECT_REC]        = "EVENT_OBJECT_REC";
    EVENT_TYPE_TEXT[EVENT_OBJECT_STOP]       = "EVENT_OBJECT_STOP";

    EVENT_TYPE_TEXT[EVENT_STUDIO_OK]         = "EVENT_STUDIO_OK";
    EVENT_TYPE_TEXT[EVENT_STUDIO_CANCEL]     = "EVENT_STUDIO_CANCEL";
    EVENT_TYPE_TEXT[EVENT_STUDIO_EDIT]       = "EVENT_STUDIO_EDIT";
    EVENT_TYPE_TEXT[EVENT_STUDIO_LIST]       = "EVENT_STUDIO_LIST";
    EVENT_TYPE_TEXT[EVENT_STUDIO_CLONE]      = "EVENT_STUDIO_CLONE";
    EVENT_TYPE_TEXT[EVENT_STUDIO_NEW]        = "EVENT_STUDIO_NEW";
    EVENT_TYPE_TEXT[EVENT_STUDIO_OPEN]       = "EVENT_STUDIO_OPEN";
    EVENT_TYPE_TEXT[EVENT_STUDIO_SAVE]       = "EVENT_STUDIO_SAVE";
    EVENT_TYPE_TEXT[EVENT_STUDIO_UNDO]       = "EVENT_STUDIO_UNDO";
    EVENT_TYPE_TEXT[EVENT_STUDIO_CUT]        = "EVENT_STUDIO_CUT";
    EVENT_TYPE_TEXT[EVENT_STUDIO_COPY]       = "EVENT_STUDIO_COPY";
    EVENT_TYPE_TEXT[EVENT_STUDIO_PASTE]      = "EVENT_STUDIO_PASTE";
    EVENT_TYPE_TEXT[EVENT_STUDIO_SIZE]       = "EVENT_STUDIO_SIZE";
    EVENT_TYPE_TEXT[EVENT_STUDIO_TOOL]       = "EVENT_STUDIO_TOOL";
    EVENT_TYPE_TEXT[EVENT_STUDIO_HELP]       = "EVENT_STUDIO_HELP";
    EVENT_TYPE_TEXT[EVENT_STUDIO_COMPILE]    = "EVENT_STUDIO_COMPILE";
    EVENT_TYPE_TEXT[EVENT_STUDIO_RUN]        = "EVENT_STUDIO_RUN";
    EVENT_TYPE_TEXT[EVENT_STUDIO_REALTIME]   = "EVENT_STUDIO_REALTIME";
    EVENT_TYPE_TEXT[EVENT_STUDIO_STEP]       = "EVENT_STUDIO_STEP";

    EVENT_TYPE_TEXT[EVENT_WRITE_SCENE_FINISHED] = "EVENT_WRITE_SCENE_FINISHED";

    EVENT_TYPE_TEXT[EVENT_CODE_BATTLE_START] = "EVENT_CODE_BATTLE_START";
    EVENT_TYPE_TEXT[EVENT_CODE_BATTLE_SPECTATOR] = "EVENT_CODE_BATTLE_SPECTATOR";

    EVENT_TYPE_TEXT[EVENT_VIEWPOINT0] = "EVENT_VIEWPOINT0";
    EVENT_TYPE_TEXT[EVENT_VIEWPOINT1] = "EVENT_VIEWPOINT1";
    EVENT_TYPE_TEXT[EVENT_VIEWPOINT2] = "EVENT_VIEWPOINT2";
    EVENT_TYPE_TEXT[EVENT_VIEWPOINT3] = "EVENT_VIEWPOINT3";
    EVENT_TYPE_TEXT[EVENT_VIEWPOINT4] = "EVENT_VIEWPOINT4";
    EVENT_TYPE_TEXT[EVENT_VIEWPOINT5] = "EVENT_VIEWPOINT5";
    EVENT_TYPE_TEXT[EVENT_VIEWPOINT6] = "EVENT_VIEWPOINT6";
    EVENT_TYPE_TEXT[EVENT_VIEWPOINT7] = "EVENT_VIEWPOINT7";
    EVENT_TYPE_TEXT[EVENT_VIEWPOINT8] = "EVENT_VIEWPOINT8";
    EVENT_TYPE_TEXT[EVENT_VIEWPOINT9] = "EVENT_VIEWPOINT9";
}

std::string ParseEventType(EventType eventType)
{
    auto Other = [&](const char* name)
    {
        std::stringstream str;
        str << name << "(" << static_cast<int>(eventType) << ")";
        return str.str();
    };

    if (eventType < EVENT_STD_MAX)
    {
        if(eventType >= EVENT_INTERFACE_KEY && eventType <= EVENT_INTERFACE_KEY_END)
        {
            return "EVENT_INTERFACE_KEY"+boost::lexical_cast<std::string>(eventType-EVENT_INTERFACE_KEY);
        }

        if(eventType >= EVENT_OBJECT_SHORTCUT && eventType <= EVENT_OBJECT_SHORTCUT_MAX)
        {
            return "EVENT_OBJECT_SHORTCUT"+boost::lexical_cast<std::string>(eventType-EVENT_OBJECT_SHORTCUT);
        }

        const char* stdEvent = EVENT_TYPE_TEXT[eventType];
        if (stdEvent[0] == 0)
            return Other("STD_UNDEFINED");

        return stdEvent;
    }

    if (eventType >= EVENT_USER)
    {
        return Other("USER_EVENT");
    }

    return Other("UNDEFINED");
}



CEventQueue::CEventQueue()
    : m_mutex{},
      m_fifo(),
      m_head{0},
      m_tail{0},
      m_total{0}
{}

CEventQueue::~CEventQueue()
{}

bool CEventQueue::IsEmpty()
{
    return m_head == m_tail;
}

/** If the maximum size of queue has been reached, returns \c false.
    Else, adds the event to the queue and returns \c true. */
bool CEventQueue::AddEvent(Event&& event)
{
    bool result{};

    SDL_LockMutex(*m_mutex);

    if (m_total >= MAX_EVENT_QUEUE)
    {
        GetLogger()->Warn("Event queue flood!\n");

        result = false;
    }
    else
    {
        m_fifo[m_head++] = std::move(event);

        if (m_head >= MAX_EVENT_QUEUE)
            m_head = 0;

        m_total++;

        result = true;
    }

    SDL_UnlockMutex(*m_mutex);

    return result;
}

Event CEventQueue::GetEvent()
{
    Event event;

    SDL_LockMutex(*m_mutex);

    if (m_head == m_tail)
    {
        event.type = EVENT_NULL;
    }
    else
    {
        event = std::move(m_fifo[m_tail++]);

        if (m_tail >= MAX_EVENT_QUEUE)
            m_tail = 0;

        m_total--;

    }

    SDL_UnlockMutex(*m_mutex);

    return event;
}
