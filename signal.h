#ifndef SIGNAL_H
#define SIGNAL_H

class Signal
{
    public :
        Signal();
        Signal(double rayon, double strength, double frequency);

        void setRayon(double rayon);
        void setStrength(double strength);
        void setFrequency(double frequency);

        double getStrength();
        double getRayon();
        double getFrequency();

        double getStrengthOfDensity(double distanceFromTransmettor);
        double getAvailableStrength(double distanceFromTransmettor);

        double getAttenuationOfSignal(double emettorStrength, double receivedStrength);

    private :
        double _rayon;
        double _strength;
        double _frequency;

        double _antennaGain;
        double _antennaEffectiveArea;
};

#endif // SIGNAL_H
