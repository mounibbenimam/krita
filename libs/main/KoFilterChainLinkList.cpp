/* This file is part of the KOffice libraries
   Copyright (C) 2009 Boudewijn Rempt <boud@valdyas.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/
#include "KoFilterChainLinkList.h"
#include "KoFilterChainLink.h"

namespace KOfficeFilter {

    ChainLinkList::ChainLinkList() {}

    ChainLinkList::~ChainLinkList()
    {
        deleteAll();
    }

    void ChainLinkList::deleteAll()
    {
        while(!m_chainLinks.isEmpty()) {
            delete m_chainLinks.takeFirst();
        }
    }

    int ChainLinkList::count() const
    {
        return m_chainLinks.count();
    }

    ChainLink* ChainLinkList::current() const
    {
        return m_chainLinks.at(m_current);
    }

    ChainLink* ChainLinkList::first()
    {
        m_current = 0;
        return current();
    }

    ChainLink* ChainLinkList::next()
    {
        if (m_current == count()) {
            return 0;
        }
        ++m_current;

        return current();
    }

    void ChainLinkList::prepend(ChainLink* link)
    {
        m_chainLinks.prepend(link);
        m_current = 0;
    }

    void ChainLinkList::append(ChainLink* link)
    {
        m_chainLinks.append(link);
        m_current = m_chainLinks.count();
    }
};
