#include <iostream>
#include <sqlite3.h>
#include <spatialite/gaiageo.h>
#include <spatialite.h>
#include <vector>

#include <OSMSpatialite/XmlParser.hpp>
#include <OSMSpatialite/Way.hpp>
#include <core/RestClient.h>
#include <OSMSpatialite/EditingAPI.hpp>


int main(int argc, const char * argv[]) {
    
    std::string xmlStr = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><osm version=\"0.6\" generator=\"Overpass API\"><meta osm_base=\"2015-10-19T15:48:02Z\"/><node id=\"368174593\" lat=\"38.6393485\" lon=\"-121.3799524\" version=\"1\" timestamp=\"2009-04-01T07:58:57Z\" changeset=\"17182\" uid=\"28145\" user=\"amillar\"><tag k=\"addr:state\" v=\"CA\"/><tag k=\"ele\" v=\"22\"/><tag k=\"gnis:county_name\" v=\"Sacramento\"/><tag k=\"gnis:feature_id\" v=\"1817495\"/><tag k=\"gnis:import_uuid\" v=\"57871b70-0100-4405-bb30-88b2e001a944\"/><tag k=\"gnis:reviewed\" v=\"no\"/><tag k=\"name\" v=\"Discovery Museum Science and Space Center\"/><tag k=\"source\" v=\"USGS Geonames\"/><tag k=\"tourism\" v=\"museum\"/></node></osm>";
    
//    AmigoCloud::Database db("/temp/xmlstr.db", true);
//    OSM::XmlParser parser(db);
//    parser.xmlString(xmlStr).parse();
    
    std::shared_ptr<AmigoCloud::Database> db2 = std::make_shared<AmigoCloud::Database>("/temp/arcade.db", true);
    OSM::XmlParser parser2(db2);
    parser2.xmlFile("/temp/arcade.osm").parse();
   
    OSM::Way::fetchWays(db2, "-121.369328,38.649437,-121.369215,38.649527");
    
    std::vector<OSM::Node> nodes = OSM::Node::fetchNodesForWayId(db2, 349945505);
    
    std::shared_ptr<AmigoCloud::Database> db3 = std::make_shared<AmigoCloud::Database>("/temp/fbi.db", true);
    OSM::XmlParser parser3(db3);
    parser3.xmlFile("/temp/fbi.osm").parse();
    std::vector<OSM::Node> nodes3 = OSM::Node::fetchStandaloneNodes(db3, "-121.381330,38.634573,-121.350946,38.651735");

    AmigoCloud::RestClient restClient("OSMSpatialite/0.0.1");
    AmigoCloud::RestClient::response response = restClient.get("http://www.openstreetmap.org/api/0.6/map?bbox=-121.0359907102686,39.24774208062821,-121.00122928619385,39.27266344858914");
    
    OSM::EditingAPI api(db3);
    
    api.get("-121.369317,38.649377,-121.369202,38.649533");
    
    return 0;
}