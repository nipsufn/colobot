/*
 * This file is part of the Colobot: Gold Edition source code
 * Copyright (C) 2001-2021, Daniel Roux, EPSITEC SA & TerranovaTeam
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

#pragma once

#include "CBot/CBotVar/CBotVar.h"

namespace CBot
{

/**
 * \brief CBotVar subclass for managing arrays (::CBotTypArrayPointer)
 *
 * Uses CBotVarClass for storing data internally
 */
class CBotVarArray : public CBotVar
{
public:
    /**
     * \brief Constructor. Do not call directly, use CBotVar::Create()
     */
    CBotVarArray(const CBotToken& name, CBotTypResult& type);
    /**
     * \brief Destructor. Do not call directly, use CBotVar::Destroy()
     */
    ~CBotVarArray();

    void SetPointer(CBotVar* p) override;
    CBotVarClass* GetPointer() override;

    void Copy(CBotVar* pSrc, bool bName = true) override;

    CBotVar* GetItem(int n, bool grow = false) override;
    CBotVar* GetItemList() override;

    std::string GetValString() const override;

    bool Save1State(std::ostream &ostr) override;

private:
    //! Array data
    CBotVarClass* m_pInstance;
};

} // namespace CBot