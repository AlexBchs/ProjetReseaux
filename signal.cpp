#include "signal.h"

const double PI = 3.14159265359;

Signal::Signal()
{}

Signal::Signal(double rayon, double strength, double frequency) : _rayon{rayon}, _strength {strength}, _frequency{frequency}
{}

void Signal::setRayon(double rayon)
{
    _rayon = rayon;
}

void Signal::setStrength(double strength)
{
    _strength = strength;
}

void Signal::setFrequency(double frequency)
{
    _frequency = frequency;
}

double Signal::getRayon()
{
    return _rayon;
}

double Signal::getStrength()
{
    return _strength;
}

double Signal::getFrequency()
{
    return _frequency;
}

double Signal::getStrengthOfDensity(double distanceFromTransmettor)
{
    return (_strength*_antennaGain)/(4 * PI * (distanceFromTransmettor*distanceFromTransmettor));
}

double Signal::getAvailableStrength(double distanceFromTransmettor)
{
    return ((_strength*_antennaGain)/(4 * PI * (distanceFromTransmettor*distanceFromTransmettor))) * _antennaEffectiveArea;
}

double Signal::getAttenuationOfSignal(double emettorStrength, double receivedStrength)
{
    return emettorStrength/receivedStrength;
}
