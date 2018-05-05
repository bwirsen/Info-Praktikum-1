#ifndef MAPIOFILEINPUT_H
#define MAPIOFILEINPUT_H

#include "mapio.h"

class MapIoFileinput : public MapIo
{
public:
	MapIoFileinput(QString pathToCityFile, QString pathToStreetFile);
	~MapIoFileinput();

	virtual void fillMap(AbstractMap &map);

	/**
	 * @brief A static helper function to initialize the Map from two files.
	 * @param map Map to add the streets and citys to.
	 * @param path_to_city_file Path of the file that contains the informations about the citys
	 * @param path_to_street_file Path of the file that contains the informations about the streets.
	 */
	static void map_init_from_file(AbstractMap &map, QString path_to_city_file, QString pathToStreetFile);
//	static void save_changes_to_file(QString path_to_city_file, QString path_to_street_file,
//										 AbstractMap::CityList new_cities, AbstractMap::StreetList new_streets);
private:
	QString pathToCityFile;
	QString pathToStreetFile;
};

#endif // MAPIOFILEINPUT_H
