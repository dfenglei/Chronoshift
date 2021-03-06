/**
 * @file
 *
 * @author CCHyper
 *
 * @brief Class holding regional threat information on the map.
 *
 * @copyright Chronoshift is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#if !defined(REGION_H)
#define REGION_H

#include	"always.h"

class NoInitClass;

class RegionClass
{
    public:
        RegionClass() : m_Value(0) {}
        RegionClass(const RegionClass &that) {}
        RegionClass(const NoInitClass &noinit) {}
        ~RegionClass() {}

        int Get_Value() const { return m_Value; }
        
        void Adjust_Value(int value, bool a2)
        {
            if ( a2 ) {
                m_Value -= value;
            } else {
                m_Value += value;
            }
        }

    private:
        int m_Value;
};

#endif // REGION_H
