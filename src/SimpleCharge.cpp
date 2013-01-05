#include "SimpleCharge.h"
#include "ProgramData.h"
#include "Screen.h"
#include "Hardware.h"


SimpleCharge simpleCharge;


void SimpleCharge::powerOn()
{
    smps.powerOn();
    smps.setRealValue(ProgramData::currentProgramData.battery.Ic);
}

void SimpleCharge::powerOff()
{
    smps.powerOff();
}

Strategy::statusType SimpleCharge::doStrategy()
{
    if(smps.getIcharge() >= ProgramData::currentProgramData.battery.Ic) {
        smps.powerOff(SMPS::ERROR);
        return ERROR;
    }

    if(testVout_ && smps.getVout() >= ProgramData::currentProgramData.getVoltage(ProgramData::VCharge)) {
        smps.powerOff(SMPS::CHARGING_COMPLETE);
        return COMPLETE;
    }

    if(smps.getCharge() > ProgramData::currentProgramData.battery.C) {
        smps.powerOff(SMPS::CHARGING_COMPLETE);
        return COMPLETE;
    }
    return RUNNING;
}


bool SimpleCharge::isStable() const
{
    return analogInputs.isStable(smps.VName) && analogInputs.isStable(smps.IName) && balancer.isStable();
}


