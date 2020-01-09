#include "pch.h"
#include "property_manager.hpp"

fe::PropertyManager::PropertyManager() :
    properties()
{
}

fe::PropertyManager::~PropertyManager()
{
    auto purge = [](std::pair<unsigned __int64, fe::PropertyContainer*>&& it)
    {
        if (it.second != nullptr)
        {
            delete it.second;
            it.second = nullptr;
        }
    };
    std::for_each(properties.begin(), properties.end(), purge);
    properties.clear();
}

void fe::PropertyManager::push(unsigned __int64 id, fe::PropertyContainer* prop) noexcept
{
    if (prop == nullptr)
        return;
    if (properties.find(id) == properties.end())
    {
        auto data = std::make_pair(id, prop);
        properties.insert(data);
    }
    else
    {
        properties.at(id) = prop;
    }
}

fe::PropertyContainer* fe::PropertyManager::get(unsigned __int64 id) noexcept
{
    auto it = properties.find(id);
    if (it == properties.end())
        return nullptr;
    return it->second;
}

void fe::PropertyManager::remove(unsigned __int64 id) noexcept
{
    auto prop = get(id);
    if (prop)
    {
        properties.erase(id);
        delete prop;
        prop = nullptr;
    }
}

