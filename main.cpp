//  Gearoid Hanrahan
//  27/09/2017
//  Lab 15
//  C00108964

/** Preprocessor directives */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;

class Waveform
{
    private:
                double amp, freq, phase, dcOff, instantVol, time, period, vrms, radPhase;

    public:
                Waveform(void)
                {
                    amp = 1;
                    freq = 1000;
                    phase = 0;
                    dcOff = 0;
                }

                /** Function member to read in values */
                void getValues (void)
                {
                    cout << "Amplitude :\t" ;
                    cin >> amp;
                    cout << "\nFrequency :\t" ;
                    cin >> freq;
                    cout << "\nPhase angle :\t" ;
                    cin >> phase;
                    cout << "\nDC offset :\t" ;
                    cin >> dcOff;
                    cout << "\nTime :\t" ;
                    cin >> time;
                }

                /** Instantaneous voltage member function */
                double Vinst(void)
                {
                    radPhase = phase * (M_PI / 180);
                    instantVol = amp * sin((2 * M_PI * freq * time) + radPhase) + dcOff;
                    cout << "\nInstantaneous Voltage of Sinewave : \t" << instantVol << endl;
                    return instantVol;
                }

                /** Period member function */
                double periodCal (void)
                {
                    period = 1.0 / freq;
                    cout << "\nPeriod :\t" << period << endl;
                    return period;
                }

                /** Vrms member function */
                double vrmsCal (void)
                {
                    vrms = amp / sqrt(2.0);
                    cout << "\nVrms :\t" << vrms << endl << endl;
                    return vrms;
                }

};

/** Main function */
int main()
{

    Waveform sinewave;

    cout << "Sinewave Calculations\n\n";

    /** Call classes to calculate waveform parameters */
    sinewave.getValues();
    sinewave.Vinst();
    sinewave.periodCal();
    sinewave.vrmsCal();

    /** Terminate main function */
    return 0;
}
