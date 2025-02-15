#ifndef _INSTRUMENTPARAMETER_HPP_
#define _INSTRUMENTPARAMETER_HPP_

#include "pwiz/utility/misc/Export.hpp"
#include <cmath>
#include <string>


namespace DiaUmpire {

struct InstrumentParameter
{
    int Resolution = 0;
    float MS1PPM = 0;
    float MS2PPM = 0;
    float SN = 0;
    float MinMSIntensity = 0;
    float MinMSMSIntensity = 0;
    int NoPeakPerMin = 150;
    float MinRTRange = 0;
    int StartCharge = 2;
    int EndCharge = 5;
    int MS2StartCharge = 2;
    int MS2EndCharge = 4;
    float MaxCurveRTRange = 2;
    float RTtol = 0;
    float MS2SN = 0;
    int MaxNoPeakCluster = 4;
    int MinNoPeakCluster = 2;
    int MaxMS2NoPeakCluster = 3;
    int MinMS2NoPeakCluster = 2;
    bool Denoise = true;
    bool EstimateBG = false;
    bool DetermineBGByID = false;
    bool RemoveGroupedPeaks = true;
    bool Deisotoping = false;
    bool BoostComplementaryIon = true;
    bool AdjustFragIntensity = true;
    int RPmax = 25;
    int RFmax = 300;
    float RTOverlap = (float) 0.3;
    float CorrThreshold = (float) 0.2;
    float DeltaApex = (float) 0.6;
    float SymThreshold = (float) 0.3;
    int NoMissedScan = 1;
    int MinPeakPerPeakCurve = 1;
    float MinMZ = 200;
    int MinFrag = 10;
    float MiniOverlapP = (float) 0.2;
    bool CheckMonoIsotopicApex = false;
    bool DetectByCWT = true;
    bool FillGapByBK = true;
    float IsoCorrThreshold = (float) 0.2;
    float RemoveGroupedPeaksCorr = (float) 0.3;
    float RemoveGroupedPeaksRTOverlap = (float) 0.3;
    float HighCorrThreshold = (float) 0.7;
    int MinHighCorrCnt = 10;
    int TopNLocal = 6;
    int TopNLocalRange = 100;
    float IsoPattern = (float) 0.3;
    float StartRT = 0;
    float EndRT = 9999;
    bool TargetIDOnly = false;
    bool MassDefectFilter = true;
    float MinPrecursorMass = 600;
    float MaxPrecursorMass = 15000;
    bool UseOldVersion = false;
    float RT_window_Targeted = -1;
    int SmoothFactor = 5;
    bool DetectSameChargePairOnly = false;
    float MassDefectOffset = (float) 0.1;
    int MS2PairTopN = 5;
    bool MS2Pairing = true;

    std::map<std::string, std::string> GetParameterMap() const;


    static float CalcPPM(float valueA, float valueB)
    {
        return std::fabs(valueA - valueB) * 1000000 / valueB;
    }

    static float GetMzByPPM(float valueA, int charge, float ppm)
    {
        float mwA = valueA * charge - charge * 1.00727;
        float premass = mwA - (ppm * mwA / 1000000);
        return (premass + charge * 1.00727) / charge;
    }

    static float CalcSignedPPM(float valueA, float valueB)
    {
        return (valueA - valueB) * 1000000 / valueB;
    }
};

struct PWIZ_API_DECL MzRange
{
    constexpr MzRange(float begin = 0, float end = 0) : begin(begin), end(end) {}

    float begin, end;

    bool operator== (const MzRange& rhs) const
    {
        return begin == rhs.begin && end == rhs.end;
    }

    bool operator< (const MzRange& rhs) const
    {
        return begin == rhs.begin ? end < rhs.end : begin < rhs.begin;
    }

    bool empty() const { return this == &Empty; }

    static MzRange Empty;
};

} // namespace DiaUmpire

#endif // _INSTRUMENTPARAMETER_HPP_
