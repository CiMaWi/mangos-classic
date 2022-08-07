/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MAP_DATA_CONTAINER_H
#define MAP_DATA_CONTAINER_H

#include "Platform/Define.h"
#include <memory>

struct CreatureSpellListContainer;
struct CreatureSpellList;
struct SpawnGroupEntry;
struct SpawnGroupEntryContainer;
struct CreatureEventAI_Event;
struct CreatureEventAI_EventComputedData;

// Event_Map
typedef std::vector<CreatureEventAI_Event> CreatureEventAI_Event_Vec;
typedef std::unordered_map<uint32, CreatureEventAI_Event_Vec> CreatureEventAI_Event_Map;
typedef std::unordered_map<uint32, CreatureEventAI_EventComputedData> CreatureEventAI_EventComputedData_Map;

class MapDataContainer
{
    public:
        MapDataContainer();
        void SetCreatureSpellListContainer(std::shared_ptr<CreatureSpellListContainer> container);
        CreatureSpellList* GetCreatureSpellList(uint32 Id) const;
        SpawnGroupEntry* GetSpawnGroup(uint32 Id) const;
        SpawnGroupEntry* GetSpawnGroupByGuid(uint32 dbGuid, uint32 high) const;
        std::shared_ptr<SpawnGroupEntryContainer> GetSpawnGroups() const;

        void SetEventAIContainers(std::shared_ptr<CreatureEventAI_Event_Map> entryContainer, std::shared_ptr<CreatureEventAI_Event_Map> guidContainer, std::shared_ptr<CreatureEventAI_EventComputedData_Map> computedContainer);
        std::shared_ptr<CreatureEventAI_Event_Map> GetCreatureEventEntryAIMap() const;
        std::shared_ptr<CreatureEventAI_Event_Map> GetCreatureEventGuidAIMap() const;
        std::shared_ptr<CreatureEventAI_EventComputedData_Map> GetEAIComputedDataMap() const;
    private:
        std::shared_ptr<CreatureSpellListContainer> m_spellListContainer;
        std::shared_ptr<SpawnGroupEntryContainer> m_spawnGroupContainer;

        std::shared_ptr<CreatureEventAI_Event_Map>  m_CreatureEventAIEventEntryMap;
        std::shared_ptr<CreatureEventAI_Event_Map>  m_CreatureEventAIEventGuidMap;
        std::shared_ptr<CreatureEventAI_EventComputedData_Map>  m_creatureEventAIComputedDataMap;
};

#endif