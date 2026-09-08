#ifndef JOVIAN_OBJECTS_H
#define JOVIAN_OBJECTS_H

namespace JovianObjects
{
    struct SatelliteState
    {
        double x;
        double y;
        double orbital_radius;
        double orbital_longitude;
    };

    struct PlanetState
    {
        double distance_earth_au;
        double distance_sun_au;
        double sub_earth_tilt;
        double sub_sun_tilt;
        double phase_angle;
    };
};

#endif