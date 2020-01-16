#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

#pragma warning( disable : 4251 )

namespace fe
{
    struct API_DECLSPEC PropCtrl : PropertyContainer
    {
        fe::type::_uint     id = 0;
        std::string         name = "";
        fe::type::_uint     ctrlKind1 = 0;
        fe::type::_uint     ctrlKind2 = 0;
        fe::type::_uint     ctrlKind3 = 0;
        fe::type::_uint     sfxCtrl = 0;
        fe::type::_uint     soundDamage = 0;
        std::string         comment = "";

        PropCtrl(const PropCtrl* o) : PropCtrl(*o)
        {
        }
        PropCtrl() = default;
        PropCtrl(const PropCtrl&) = default;
        PropCtrl(PropCtrl&&) = default;
        PropCtrl& operator=(const PropCtrl&) = default;
        PropCtrl& operator=(PropCtrl&&) = default;
        ~PropCtrl() = default;

    };
}
#pragma warning( default : 4251 )
