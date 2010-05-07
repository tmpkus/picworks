//
// Copyright (C) 2006-2010  by the original authors of Galaxy
// and all its contributors ("Galaxy.org").
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

/*!
  \file singleton.h
  \ingroup Core
  \brief This file contains
  - class Core::Singleton declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-4-17 Created.
 */

#ifndef SINGLETON_H
#define SINGLETON_H

#include "util_global.h"

namespace Core {

template <typename T>

class CORESHARED_EXPORT Singleton
{
public:
    static inline T * instance()
    {
        static T _instance;
        return &_instance;
    }

private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton<T> &);
    Singleton<T>& operator=(const Singleton<T> &);

}; // end of class

} // end of namespace

#endif // SINGLETON_H
