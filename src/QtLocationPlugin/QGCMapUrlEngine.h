/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


/**
 *  @file
 *  @author Gus Grubba <mavlink@grubba.com>
 */

#ifndef QGC_MAP_URL_ENGINE_H
#define QGC_MAP_URL_ENGINE_H


#include "GoogleMapProvider.h"
#include "BingMapProvider.h"
#include "GenericMapProvider.h"
#include "EsriMapProvider.h"
#include "MapboxMapProvider.h"

#define MAX_MAP_ZOOM (20.0)

class UrlFactory : public QObject {
    Q_OBJECT
public:
//
//        /*
//        MapQuestMap             = 700,
//        MapQuestSat             = 701,
//        */
//
//        VWorldMap                = 800,
//        VWorldSatellite          = 801,
//        VWorldStreet             = 802,
//
//        MapboxStreets           = 6000,
//        MapboxLight             = 6001,
//        MapboxDark              = 6002,
//        MapboxSatellite         = 6003,
//        MapboxHybrid            = 6004,
//        MapboxWheatPaste        = 6005,
//        MapboxStreetsBasic      = 6006,
//        MapboxComic             = 6007,
//        MapboxOutdoors          = 6008,
//        MapboxRunBikeHike       = 6009,
//        MapboxPencil            = 6010,
//        MapboxPirates           = 6011,
//        MapboxEmerald           = 6012,
//        MapboxHighContrast      = 6013,
//
//
//        AirmapElevation         = 8001
//    };

    UrlFactory      ();
    ~UrlFactory     ();

    QNetworkRequest getTileURL          (QString type, int x, int y, int zoom, QNetworkAccessManager* networkManager);
    QNetworkRequest getTileURL          (int id, int x, int y, int zoom, QNetworkAccessManager* networkManager);

    QString         getImageFormat      (QString type, const QByteArray& image);
    QString         getImageFormat      (int id , const QByteArray& image);

    quint32  averageSizeForType  (QString type);

    QHash<QString, MapProvider*> getProviderTable(){return _providersTable;}

    int getIdFromType(QString type);
    QString getTypeFromId(int id);

private:
    int             _timeout;
    QHash<QString, MapProvider*> _providersTable;
    void registerProvider(QString Name, MapProvider* provider);

    // BingMaps
    //QString         _versionBingMaps;


};

#endif
