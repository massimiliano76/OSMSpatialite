//
//  OSMDatabase.hpp
//  OSMSpatialite
//
//  Created by Nicholas Hallahan on 10/1/15.
//  Copyright © 2015 Nicholas Hallahan. All rights reserved.
//

#ifndef OSMDatabase_hpp
#define OSMDatabase_hpp

#include "AmigoCloud/Database.h"

namespace OSM
{
    
class OSMDatabase
{
public:
    explicit OSMDatabase(const std::string& dbPath);
    
    // OSM Element found at beginning of XML Document
    void addOSM(const std::string& version, const std::string& generator);
    
    void addNode(const std::string& idStr, const std::string& latStr, const std::string& lonStr, const std::string& versionStr,
                 const std::string& timestampStr, const std::string& changesetStr, const std::string& uidStr,
                 const std::string& userStr, const std::string& actionStr, const std::string& visibleStr);
    
private:
    // Initializes DB to have OSM Schema if needed.
    void _initDB();
    
    const std::string _dbPath;
    AmigoCloud::Database _db;
};
}

#endif /* OSMDatabase_hpp */
